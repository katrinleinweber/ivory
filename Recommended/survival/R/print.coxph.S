print.coxph <-
 function(x, digits=max(options()$digits - 4, 3), ...)
    {
    if (!is.null(cl<- x$call)) {
	cat(gettext("Call:", domain = "R-survival"), "\n", sep = "")
	dput(cl)
	cat("\n")
	}
    if (!is.null(x$fail)) {
	cat(gettext(" Coxph failed. ", domain = "R-survival"), x$fail, "\n", sep = "")
	return()
	}
    savedig <- options(digits = digits)
    on.exit(options(savedig))

    coef <- x$coefficients
    se <- sqrt(diag(x$var))
    if(is.null(coef) | is.null(se))
        stop("input is not valid")

    if (is.null(x$naive.var)) {
	tmp <- cbind(coef, exp(coef), se, coef/se,
#	       signif(1 - pchisq((coef/ se)^2, 1), digits -1))
               1- pchisq((coef/se)^2, 1))
	dimnames(tmp) <- list(names(coef), c("coef", "exp(coef)",
	    "se(coef)", "z", "p"))
	}
    else {
	nse <- sqrt(diag(x$naive.var))
	tmp <- cbind(coef, exp(coef), nse, se, coef/se,
#	       signif(1 - pchisq((coef/se)^2, 1), digits -1))
	       1 - pchisq((coef/se)^2, 1))
	dimnames(tmp) <- list(names(coef), c("coef", "exp(coef)",
	    "se(coef)", "robust se", "z", "p"))
	}

    printCoefmat(tmp, signif.stars=FALSE, P.values=TRUE, has.Pvalue=TRUE)

    logtest <- -2 * (x$loglik[1] - x$loglik[2])
    if (is.null(x$df)) df <- sum(!is.na(coef))
    else  df <- round(sum(x$df),2)
    cat("\n")
    cat(gettextf("Likelihood ratio test = %s on %s df, p=%s", format(round(logtest, 2)), df, format(1 - pchisq(logtest, df)), domain = "R-survival"))
    cat("\n")
    omit <- x$na.action
    cat("n=", x$n)
    if (!is.null(x$nevent)) cat(", ", gettextf("number of events= %d", x$nevent, domain = "R-survival"), "\n", sep = "")
    else cat("\n")
    if (length(omit))
	cat("   (", naprint(omit), ")\n", sep="")
    invisible(x)
    }
