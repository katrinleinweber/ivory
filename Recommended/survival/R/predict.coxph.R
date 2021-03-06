# Automatically generated from the noweb directory
predict.coxph <- function(object, newdata, 
                       type=c("lp", "risk", "expected", "terms", "survival"),
                       se.fit=FALSE, na.action=na.pass,
                       terms=names(object$assign), collapse, 
                       reference=c("strata", "sample"), ...) {
    if (!inherits(object, 'coxph'))
        stop(gettextf("'%s' argument is not an object of class %s", "object", dQuote("coxph")))

    Call <- match.call()
    type <-match.arg(type)
    if (type=="survival") {
        survival <- TRUE
        type == "expected"  #this is to stop lots of "or" statements
    }
    else survival <- FALSE

    n <- object$n
    Terms <-  object$terms

    if (!missing(terms)) {
        if (is.numeric(terms)) {
            if (any(terms != floor(terms) | 
                    terms > length(object$assign) |
                    terms <1)) stop(gettextf("invalid '%s' argument", "terms"))
            }
        else if (any(is.na(match(terms, names(object$assign)))))
           stop("a name given in the 'terms' argument not found in the model")
        }

    # I will never need the cluster argument, if present delete it.
    #  Terms2 are terms I need for the newdata (if present), y is only
    #  needed there if type == 'expected'
    if (length(attr(Terms, 'specials')$cluster)) {
        temp <- untangle.specials(Terms, 'cluster', 1)
        Terms  <- object$terms[-temp$terms]
        }
    else Terms <- object$terms

    if (type != 'expected') Terms2 <- delete.response(Terms)
    else Terms2 <- Terms

    has.strata <- !is.null(attr(Terms, 'specials')$strata)
    has.offset <- !is.null(attr(Terms, 'offset'))
    has.weights <- any(names(object$call) == 'weights')
    na.action.used <- object$na.action
    n <- length(object$residuals)

    if (missing(reference) && type=="terms") reference <- "sample"
    else reference <- match.arg(reference)
    have.mf <- FALSE
    if (type == "expected") {
        y <- object[['y']]
        if (is.null(y)) {  # very rare case
            mf <- stats::model.frame(object)
            y <-  model.extract(mf, 'response')
            have.mf <- TRUE  #for the logic a few lines below, avoid double work
            }
        }

    if (se.fit || type=='terms' || (!missing(newdata) && type=="expected") ||
        (has.strata && (reference=="strata") || type=="expected")) {
        use.x <- TRUE
        if (is.null(object[['x']]) || has.weights || has.offset ||
             (has.strata && is.null(object$strata))) {
            # I need the original model frame
            if (!have.mf) mf <- stats::model.frame(object)
            if (nrow(mf) != n)
                stop("Data is not the same size as it was in the original fit")
            x <- model.matrix(object, data=mf)
            if (has.strata) {
                if (!is.null(object$strata)) oldstrat <- object$strata
                else {
                    stemp <- untangle.specials(Terms, 'strata')
                    if (length(stemp$vars)==1) oldstrat <- mf[[stemp$vars]]
                    else oldstrat <- strata(mf[,stemp$vars], shortlabel=TRUE)
                  }
            }
            else oldstrat <- rep(0L, n)

            weights <- model.weights(mf)
            if (is.null(weights)) weights <- rep(1.0, n)
            offset <- model.offset(mf)
            if (is.null(offset))  offset  <- 0
        }
        else {
            x <- object[['x']]
            if (has.strata) oldstrat <- object$strata
            else oldstrat <- rep(0L, n)
            weights <-  rep(1.,n)
            offset <-   0
        }
    }
    else {
        # I won't need strata in this case either
        if (has.strata) {
            stemp <- untangle.specials(Terms, 'strata', 1)
            Terms2  <- Terms2[-stemp$terms]
            has.strata <- FALSE  #remaining routine never needs to look
        }
        oldstrat <- rep(0L, n)
        offset <- 0
        use.x <- FALSE
    }
    if (!missing(newdata)) {
        use.x <- TRUE  #we do use an X matrix later
        tcall <- Call[c(1, match(c("newdata", "collapse"), names(Call), nomatch=0))]
        names(tcall)[2] <- 'data'  #rename newdata to data
        tcall$formula <- Terms2  #version with no response
        tcall$na.action <- na.action #always present, since there is a default
        tcall[[1L]] <- quote(stats::model.frame)  # change the function called
        
        if (!is.null(attr(Terms, "specials")$strata) && !has.strata) {
           temp.lev <- object$xlevels
           temp.lev[[stemp$vars]] <- NULL
           tcall$xlev <- temp.lev
        }
        else tcall$xlev <- object$xlevels
        mf2 <- eval(tcall, parent.frame())

        collapse <- model.extract(mf2, "collapse")
        n2 <- nrow(mf2)
        
        if (has.strata) {
            if (length(stemp$vars)==1) newstrat <- mf2[[stemp$vars]]
            else newstrat <- strata(mf2[,stemp$vars], shortlabel=TRUE)
            if (any(is.na(match(newstrat, oldstrat)))) 
                stop("New data has a strata not found in the original model")
            else newstrat <- factor(newstrat, levels=levels(oldstrat)) #give it all
            if (length(stemp$terms))
                newx <- model.matrix(Terms2[-stemp$terms], mf2,
                             contr=object$contrasts)[,-1,drop=FALSE]
            else newx <- model.matrix(Terms2, mf2,
                             contr=object$contrasts)[,-1,drop=FALSE]
             }
        else {
            newx <- model.matrix(Terms2, mf2,
                             contr=object$contrasts)[,-1,drop=FALSE]
            newstrat <- rep(0L, nrow(mf2))
            }

        newoffset <- model.offset(mf2) 
        if (is.null(newoffset)) newoffset <- 0
        if (type== 'expected') {
            newy <- model.response(mf2)
            if (attr(newy, 'type') != attr(y, 'type'))
                stop("New data has a different survival type than the model")
            }
        na.action.used <- attr(mf2, 'na.action')
        } 
    else n2 <- n
    if (type=="expected" || type== "surv") {
        if (missing(newdata))
            pred <- y[,ncol(y)] - object$residuals
        if (!missing(newdata) || se.fit) {
            ustrata <- unique(oldstrat)
            risk <- exp(object$linear.predictors)
            x <- x - rep(object$means, each=nrow(x))  #subtract from each column
            if (missing(newdata)) #se.fit must be true
                se <- double(n)
            else {
                pred <- se <- double(nrow(mf2))
                newx <- newx - rep(object$means, each=nrow(newx))
                newrisk <- c(exp(newx %*% object$coef) + newoffset)
                }

            survtype<- ifelse(object$method=='efron', 3,2)
            for (i in ustrata) {
                indx <- which(oldstrat == i)
                afit <- agsurv(y[indx,,drop=F], x[indx,,drop=F], 
                                              weights[indx], risk[indx],
                                              survtype, survtype)
                afit.n <- length(afit$time)
                if (missing(newdata)) { 
                    # In this case we need se.fit, nothing else
                    j1 <- approx(afit$time, seq_len(afit.n), y[indx,1], method='constant',
                                 f=0, yleft=0, yright=afit.n)$y
                    chaz <- c(0, afit$cumhaz)[j1 +1]
                    varh <- c(0, cumsum(afit$varhaz))[j1 +1]
                    xbar <- rbind(0, afit$xbar)[j1+1,,drop=F]
                    if (ncol(y)==2) {
                        dt <- (chaz * x[indx,]) - xbar
                        se[indx] <- sqrt(varh + rowSums((dt %*% object$var) *dt)) *
                            risk[indx]
                        }
                    else {
                        j2 <- approx(afit$time, seq_len(afit.n), y[indx,2], method='constant',
                                 f=0, yleft=0, yright=afit.n)$y
                        chaz2 <- c(0, afit$cumhaz)[j2 +1]
                        varh2 <- c(0, cumsum(afit$varhaz))[j2 +1]
                        xbar2 <- rbind(0, afit$xbar)[j2+1,,drop=F]
                        dt <- (chaz * x[indx,]) - xbar
                        v1 <- varh +  rowSums((dt %*% object$var) *dt)
                        dt2 <- (chaz2 * x[indx,]) - xbar2
                        v2 <- varh2 + rowSums((dt2 %*% object$var) *dt2)
                        se[indx] <- sqrt(v2-v1)* risk[indx]
                        }
                    }

                else {
                    #there is new data
                    use.x <- TRUE
                    indx2 <- which(newstrat == i)
                    j1 <- approx(afit$time, seq_len(afit.n), newy[indx2,1], 
                                 method='constant', f=0, yleft=0, yright=afit.n)$y
                    chaz <-c(0, afit$cumhaz)[j1+1]
                    pred[indx2] <- chaz * newrisk[indx2]
                    if (se.fit) {
                        varh <- c(0, cumsum(afit$varhaz))[j1+1]
                        xbar <- rbind(0, afit$xbar)[j1+1,,drop=F]
                        }
                    if (ncol(y)==2) {
                        if (se.fit) {
                            dt <- (chaz * newx[indx2,]) - xbar
                            se[indx2] <- sqrt(varh + rowSums((dt %*% object$var) *dt)) *
                                newrisk[indx2]
                            }
                        }
                    else {
                        j2 <- approx(afit$time, seq_len(afit.n), newy[indx2,2], 
                                 method='constant', f=0, yleft=0, yright=afit.n)$y
                                    chaz2 <- approx(-afit$time, afit$cumhaz, -newy[indx2,2],
                                   method="constant", rule=2, f=0)$y
                        chaz2 <-c(0, afit$cumhaz)[j2+1]
                        pred[indx2] <- (chaz2 - chaz) * newrisk[indx2]
                    
                        if (se.fit) {
                            varh2 <- c(0, cumsum(afit$varhaz))[j1+1]
                            xbar2 <- rbind(0, afit$xbar)[j1+1,,drop=F]
                            dt <- (chaz * newx[indx2,]) - xbar
                            dt2 <- (chaz2 * newx[indx2,]) - xbar2

                            v2 <- varh2 + rowSums((dt2 %*% object$var) *dt2)
                            v1 <- varh +  rowSums((dt %*% object$var) *dt)
                            se[indx2] <- sqrt(v2-v1)* risk[indx2]
                            }
                        }
                    }
                }
            }
        if (survival) { #it actually was type= survival, do one more step
            if (se.fit) se <- se * exp(-pred)
            pred <- exp(-pred)  # probablility of being in state 0
        }
        }
    else {
        if (is.null(object$coefficients))
            coef<-numeric(0)
        else {
            # Replace any NA coefs with 0, to stop NA in the linear predictor
            coef <- ifelse(is.na(object$coefficients), 0, object$coefficients)
            }

        if (missing(newdata)) {
            offset <- offset - mean(offset)
            if (has.strata && reference=="strata") {
                # We can't use as.integer(oldstrat) as an index, if oldstrat is
                #   a factor variable with unrepresented levels as.integer could
                #   give 1,2,5 for instance.
                xmeans <- rowsum(x*weights, oldstrat)/c(rowsum(weights, oldstrat))
                newx <- x - xmeans[match(oldstrat,row.names(xmeans)),]
                }
            else if (use.x) newx <- x - rep(object$means, each=nrow(x))
            }
        else {
            offset <- newoffset - mean(offset)
            if (has.strata && reference=="strata") {
                xmeans <- rowsum(x*weights, oldstrat)/c(rowsum(weights, oldstrat))
                newx <- newx - xmeans[match(newstrat, row.names(xmeans)),]
                }
            else newx <- newx - rep(object$means, each=nrow(newx))
            }

        if (type=='lp' || type=='risk') {
            if (use.x) pred <- drop(newx %*% coef) + offset
            else pred <- object$linear.predictors
            if (se.fit) se <- sqrt(rowSums((newx %*% object$var) *newx))

            if (type=='risk') {
                pred <- exp(pred)
                if (se.fit) se <- se * sqrt(pred)  # standard Taylor series approx
                }
            }
        else if (type=='terms') { 
            asgn <- object$assign
            nterms<-length(asgn)
            pred<-matrix(ncol=nterms,nrow=NROW(newx))
            dimnames(pred) <- list(rownames(newx), names(asgn))
            if (se.fit) se <- pred
            
            for (i in seq_len(nterms)) {
                tt <- asgn[[i]]
                tt <- tt[!is.na(object$coefficients[tt])]
                xtt <- newx[,tt, drop=F]
                pred[,i] <- xtt %*% object$coefficient[tt]
                if (se.fit)
                    se[,i] <- sqrt(rowSums((xtt %*% object$var[tt,tt]) *xtt))
                }
            pred <- pred[,terms, drop=F]
            if (se.fit) se <- se[,terms, drop=F]
            
            attr(pred, 'constant') <- sum(object$coefficients*object$means, na.rm=T)
            }
        }
    if (type != 'terms') {
        pred <- drop(pred)
        if (se.fit) se <- drop(se)
        }

    if (!is.null(na.action.used)) {
        pred <- napredict(na.action.used, pred)
        if (is.matrix(pred)) n <- nrow(pred)
        else               n <- length(pred)
        if(se.fit) se <- napredict(na.action.used, se)
        }

    if (!missing(collapse) && !is.null(collapse)) {
        if (length(collapse) != n2) stop("Collapse vector is of the wrong length")
        pred <- rowsum(pred, collapse)  # in R, rowsum is a matrix, always
        if (se.fit) se <- sqrt(rowsum(se^2, collapse))
        if (type != 'terms') {
            pred <- drop(pred)
            if (se.fit) se <- drop(se)
            }
        }

    if (se.fit) list(fit=pred, se.fit=se)
    else pred
    }
