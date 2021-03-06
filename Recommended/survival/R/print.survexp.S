print.survexp <- function(x, scale=1, digits = max(options()$digits - 4, 3), naprint=FALSE, ...) {
    if (!inherits(x, 'survexp'))
	    stop(gettextf("'%s' argument is not an object of class %s", "x", dQuote("survexp")))
    savedig <- options(digits=digits)
    on.exit(options(savedig))

    if (!is.null(cl<- x$call)) {
	cat(gettext("Call:", domain = "R-survival"), "\n", sep = "")
	dput(cl)
	cat("\n")
	}

    if (!is.null(x$summ)) cat(x$summ)
    omit <- x$na.action
    if (length(omit))
	cat(naprint(omit), "\n")
    else cat("\n")

    if (is.null(x$strata))  { #print it as a matrix
	mat <- cbind(x$time/scale, x$n.risk, x$surv, x$std.err)
	if (!naprint) {
	    miss <- (is.na(mat)) %*% rep(1,ncol(mat))
	    mat <- mat[miss<(ncol(mat)-2),,drop=FALSE]
	    }
	if (is.matrix(x$surv)) cname <- dimnames(x$surv)[[2]]
	else                     cname <- "survival"
        if (is.matrix(x$n.risk)) 
            cname <- c(paste("nrisk", 1:ncol(x$n.risk), sep=''), cname)
        else cname <- c("n.risk", cname)
        cname <- c("time", cname)

	if (!is.null(x$std.err))
	      cname <- c(cname, paste("se(", cname, ")", sep=''))
        dimnames(mat) <- list(rep("", nrow(mat)), cname)
	print(mat)
	}
    else  { #print it out one strata at a time, since n's differ
	if (is.null(x$std.err)) tname <- 'survival'
	else                      tname <- c('survival', 'se(surv)')
	nstrat <- length(x$strata)
	levs <- names(x$strata)
	if (nrow(x$surv)==1) {
	    mat <- cbind(c(x$n.risk), c(x$surv), c(x$std.err*x$surv))
	    dimnames(mat) <- list(levs, c("n.risk", tname))
	    cat(gettextf(" Survival at time %s", x$time, domain = "R-survival"), "\n", sep = "")
	    print(mat)
	    }
	else {
	    for (i in 1:nstrat) {
		cat("       ", levs[i], "\n")
		mat <- cbind(x$time/scale, x$n.risk[,i], x$surv[,i])
		if (!is.null(x$std.err)) mat<- cbind(mat,
			   x$std.err[,i] * x$surv[,i])
		if (!naprint) mat <- mat[!is.na(mat[,3]),,drop=FALSE]
                dimnames(mat) <- list(rep("",nrow(mat)),
                                      c("Time", "n.risk", tname)) 
		print(mat)
		cat("\n")
		}
	    }
	}
    invisible(x)
    }
