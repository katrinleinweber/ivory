#  File src/library/utils/R/unix/download.file.R
#  Part of the R package, https://www.R-project.org
#
#  Copyright (C) 1995-2017 The R Core Team
#
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  A copy of the GNU General Public License is available at
#  https://www.R-project.org/Licenses/

download.file <-
    function(url, destfile, method, quiet = FALSE, mode = "w",
             cacheOK = TRUE, extra = getOption("download.file.extra"), ...)
{
    destfile # check supplied
    method <- if (missing(method))
	getOption("download.file.method", default = "auto")
    else
        match.arg(method, c("auto", "internal", "libcurl", "wget", "curl", "lynx"))

    if(method == "auto") {
        if(length(url) != 1L || typeof(url) != "character")
            stop(gettextf("'%s' argument must be a length-one character vector", "url"));
        ## As from 3.3.0 all Unix-alikes support libcurl.
	method <- if(grepl("^file:", url)) "internal" else "libcurl"
    }

    switch(method,
	   "internal" = {
	       status <- .External(C_download, url, destfile, quiet, mode, cacheOK)
	       ## needed for Mac GUI from download.packages etc
	       if(!quiet) flush.console()
	   },
	   "libcurl" = {
	       status <- .Internal(curlDownload(url, destfile, quiet, mode, cacheOK))
	       if(!quiet) flush.console()
	   },
	   "wget" = {
	       if(length(url) != 1L || typeof(url) != "character")
		   stop(gettextf("'%s' argument must be a length-one character vector", "url"));
	       if(length(destfile) != 1L || typeof(destfile) != "character")
		   stop(gettextf("'%s' argument must be a length-one character vector", "destfile"));
	       if(quiet) extra <- c(extra, "--quiet")
	       if(!cacheOK) extra <- c(extra, "--cache=off")
	       status <- system(paste("wget",
				      paste(extra, collapse = " "),
				      shQuote(url),
				      "-O", shQuote(path.expand(destfile))))
               if(status) stop("'wget()' call had nonzero exit status")
	   },
	   "curl" = {
	       if(length(url) != 1L || typeof(url) != "character")
		   stop(gettextf("'%s' argument must be a length-one character vector", "url"));
	       if(length(destfile) != 1L || typeof(url) != "character")
		   stop(gettextf("'%s' argument must be a length-one character vector", "destfile"));        if(quiet) extra <- c(extra, "-s -S")
	       if(quiet) extra <- c(extra, "-s -S")
	       if(!cacheOK) extra <- c(extra, "-H 'Pragma: no-cache'")
	       status <- system(paste("curl",
				      paste(extra, collapse = " "),
				      shQuote(url),
				      " -o", shQuote(path.expand(destfile))))
               if(status) stop("'curl()' call had nonzero exit status")
	   },
	   "lynx" =
	       stop("method 'lynx' is defunct", domain = "R-utils"))

    if(status) warning("download had nonzero exit status")

    invisible(status)
}

nsl <- function(hostname) .Call(C_nsl, hostname)
