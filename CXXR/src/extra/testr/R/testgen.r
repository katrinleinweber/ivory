#' @title Test Case generator based on capture files
#'
#' @description This function works with the trace information generated by instrumented GNU-R. 
#' It is strictly oriented to that, please see readme for more information.
#'
#' @param root a directory containg capture information or capture file
#' @param output.dir directory where generated test cases will be saved
#' @param verbose wheater display debug output
#' @export
TestGen <- function(root, output.dir, verbose=testrOptions('verbose')) {
  if (verbose) {
    cat("Output:", output.dir, "\n");
    cat("Root:", root, "\n");
  }
  # input dir checks
  if (missing(root) || !file.exists(root)) stop("Input dir/file doesn't exist!");
  if (file.info(root)$isdir){
    all.capture <- lapply(list.files(root, recursive=TRUE, all.files = TRUE), function(x) file.path(root,x))
  } else {
    all.capture <- root
  }
  # output dir checks
  if (missing(output.dir)) stop("A output directory must be provided!");
  if (!file.exists(output.dir) || !file.info(output.dir)$isdir) dir.create(output.dir)
  cache$output.dir <- output.dir
  # bad.arguments file to store incorrect arguments
  cache$bad.argv.file <- file.path(cache$output.dir, "bad_arguments", fsep=.Platform$file.sep);
  if (!file.exists(cache$bad.argv.file) && !file.create(cache$bad.argv.file)) stop("Unable to create file: ", bad.argv.file);
  
  cache$tID <- list()
  Map(ProcessCapture, all.capture)
  
  rm(tID, envir = cache)
  rm(output.dir, envir = cache)
  rm(bad.argv.file, envir = cache)
}

#' @title Manage Test Case file
#'
#' @description This function creates a test case file if one does not exist already
#' @param path a directory containg capture information or capture file
#' @param name directory where generated test cases will be saved
#' @param cache environment for caching already created files
#' @seealso TestGen
EnsureTCFile <- function(name) {
  name <- gsub(.Platform$file.sep, "sep", name);
  tc.file <- file.path(cache$output.dir, paste("tc_", name, ".R", sep=""), fsep=.Platform$file.sep);
  if (!file.exists(tc.file) && !file.create(tc.file)) stop("Unable to create file: ", tc.file);
  return(tc.file);
}

#' @title Process File with Closure capture information
#'
#' @description This function parses file with closure capture information and generates test cases
#' @param capture.file path to closure capture file
#' @seealso TestGen GenClosureTC
ProcessCapture<- function(capture.file){
  lines <- readLines(capture.file)
  cache$i <- 1
  while (cache$i < length(lines)){
    # read test case information
    symbol.values <- ReadSymbolValues(lines)
    symb <- symbol.values[[1]]
    vsym <- symbol.values[[2]]
    func <- ReadValue(lines, kFuncPrefix)
    args <- ReadValue(lines, kArgsPrefix)
    
    cache$tID[[func]] <- ifelse(is.null(cache$tID[[func]]), 0, cache$tID[[func]] + 1)
    tc.file <- EnsureTCFile(func)
    feedback <- GenerateTC(symb, vsym, func, args)
    
    #### see what we get
    if (feedback$'type' == "err") {
      #### the captured information is not usable
      write(feedback$'msg', file=cache$bad.argv.file, append=TRUE);
    } else if (feedback$'type' == "src") {
      #### good, we get the source code
      write(feedback$'msg', file=tc.file, append=TRUE);
    } else {
      stop("Not reached!");
    }
    cache$i <- cache$i + 1
  }
}


ReadSymbolValues <- function(lines){
  k_sym <- 1
  k_value <- 1
  symb <- vector()
  vsym <- vector()
  symb[k_sym] <- ""
  vsym[k_value] <- ""
  while (StartsWith(kSymbPrefix, lines[cache$i])){
    symb[k_sym] <- paste(symb[k_sym], SubstrLine(lines[cache$i]), sep = "") 
    cache$i <- cache$i + 1
    k_sym <- k_sym + 1
    symb[k_sym] <- ""
    vsym[k_value] <- ReadValue(lines, kValSPrefix)
    k_value <- k_value + 1
    vsym[k_value] <- ""
  }
  length(symb) <- length(symb) - 1
  length(vsym) <- length(vsym) - 1
  return(list(symb, vsym))
}

ReadValue <- function(lines, prefix){
  value <- vector()
  j <- cache$i
  while (StartsWith(prefix, lines[j])){
    value <- c(value, SubstrLine(lines[j]))
    j <- j + 1
  }
  cache$i <- j
  return(paste(value, collapse="\n", sep=""))
}

#' @title Generates a testcase for closure function
#'
#' @description This function generates a test case for builtin function using supplied arguments. All elements should be given as text.
#' @param symb symbols to be initialized before the call
#' @param vsym values of the symbols
#' @param func function name
#' @param argv input arguments for a closure function call
#' @seealso TestGen ProcessClosure
GenerateTC<- function(symb, vsym, func, argv) {
  # check validity of symbol values and construct part of the test
  invalid.symbols <- vector()
  variables <- ""
  if (length(symb) > 0 && symb[1] != ""){
    for (i in 1:length(vsym)){
      symbol <- paste(symb[i], "<-", vsym[i])
      if (!ParseAndCheck(symbol)){
        invalid.symbols <- c(invalid.symbols, i)  
      } else {
        variables <- paste(variables, symbol, "\n")
      }
    }
    if (length(invalid.symbols) != 0){
      symb <- symb[-invalid.symbols]
      vsym <- vsym[-invalid.symbols]
    }
  }
  # check validity of arguments
  valid.argv <- ParseAndCheck(argv)
  
  # proper argument should always be packed in a list
  if (!valid.argv) 
    return(list(type="err", msg=paste("func:", func, "\nargv:", argv, "\n")))
  
  # TODO: potentially good arguments, alter it 
  #  argv.obj.lst <- alter.arguments(argv.obj);
  
  call <- ""
  where <- unique(gsub(".*:(.*)", "\\1", getAnywhere(func)$where))
  if (length(where) > 0 && where[1] != "base") {
    call <- paste(call, sprintf("require(%s)", where[1]), "\n", sep = "")
  }
  
  args <- eval(parse(text=argv));
  if (length(args) > 0) {
    args <- lapply(args, function(x) paste(deparse(x), collapse = "\n"))
    if (!is.null(names(args)) && length(names(args)) == length(args))
      call <- paste(call, sprintf("%s(%s)", func, paste(names(args), args, sep="=", collapse=",")), "\n", sep="")
    else
      call <- paste(call, sprintf("%s(%s)", func, paste(args, collapse=",")), "\n", sep="")
  } else {
    call <- paste(call, func, "()", "\n", sep="")
  }
  
  if (length(symb) > 0 && symb[1] != "")
    call <- paste(variables, call, sep="")
  cache$warns <- NULL
  cache$errs <- NULL
  retv <- withCallingHandlers(tryCatch(eval(parse(text=call), envir = new.env()), error=function(e){cache$errs <- e$message}, silent = T), 
                   warning=function(w) {
                     cache$warns <- ifelse(is.null(cache$warns), w$message, paste(cache$warns, w$message, sep="; "))
                     invokeRestart("muffleWarning")
                     })
  retv <- Quoter(retv)
  src <- ""
  src <- paste(src, "test(id=",cache$tID[[func]],", code={\n", call, "}, ", sep="")
  if (!is.null(cache$warns))
    src <- paste(src, 'w = ', shQuote(cache$warns), ', ',  sep = "")
  if (!is.null(cache$errs))
    src <- paste(src, 'e = ', shQuote(cache$errs), sep = "")
  else {
    src <- paste("expected <- ", paste(deparse(retv), collapse = "\n"), "\n", src, sep="");
    src <- paste(src, "o = expected")
  }
  src <- paste(src, ");\n", sep="")
  list(type="src", msg=src);
}

ParseAndCheck <- function(what) {
  tryCatch({eval(parse(text=what)); TRUE}, error=function(e){FALSE})
}

Quoter <- function(arg) {
  if (is.list(arg)) {
    org.attrs <- attributes(arg)
    res <- lapply(arg, function(x) if(is.language(x)) enquote(x) else Quoter(x))
    attributes(res) <- org.attrs
    res
  }
  else arg
}

#' @title Removes prefixes and quote from line
#'
#' @description Used for processing capture file information. Deletes prefixes to get essential information
#' @param l input line
#' @seealso ProcessClosure
SubstrLine <- function(l){
  if (grepl("^quote\\(", l)){
    ret.line <- strsplit(l, "\\(")[[1]][2];
    if (substr(ret.line, nchar(ret.line), nchar(ret.line)) == ")")
      ret.line <- substr(ret.line, 0, nchar(ret.line) - 1)
  }else{
    ret.line <- substr(l, 7, nchar(l));     
  }
  ret.line
}

StartsWith <- function(prefix, x) {
  grepl(paste("^", prefix, sep=""), x)
}