#  File src/library/stats/R/diffinv.R
#  Part of the R package, https://www.R-project.org
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

## Cppyright (C) 2003-2017  R Core Team
## Copyright     1997-1999  Adrian Trapletti
## This version distributed under GPL (version 2 or later)

diffinv <- function (x, ...) { UseMethod("diffinv") }

## the workhorse of diffinv.default:
diffinv.vector <- function (x, lag = 1L, differences = 1L, xi, ...)
{
    if (!is.vector(x)) stop(gettextf("'%s' argument is not a vector", "x"))
    lag <- as.integer(lag); differences <- as.integer(differences)
    if (lag < 1L || differences < 1L) stop ("bad value for 'lag' or 'differences' argument")
    if(missing(xi)) xi <- rep(0., lag*differences)
    if (length(xi) != lag*differences)
        stop("'xi' does not have the right length")
    if (differences == 1L) {
        x <- as.double(x)
        xi <- as.double(xi)
        n <- as.integer(length(x))
        if (is.na(n)) stop(gettextf("invalid '%s' value", "length(x)"))
#        y <- c(xi[1L:lag], double(n))
#        z <- .C(C_R_intgrt_vec, x, y = y, as.integer(lag), n)$y
        .Call(C_intgrt_vec, x, xi, lag)
    }
    else
	diffinv.vector(diffinv.vector(x, lag, differences-1L,
				      diff(xi, lag=lag, differences=1L)),
		       lag, 1L, xi[seq_len(lag)])
}

diffinv.default <- function (x, lag = 1, differences = 1, xi, ...)
{
    if (is.matrix(x)) {
        n <- nrow(x)
        m <- ncol(x)
        y <- matrix(0, nrow = n+lag*differences, ncol = m)
        if(m >= 1) {
            if(missing(xi)) xi <- matrix(0.0, lag*differences, m)
            if(NROW(xi) != lag*differences || NCOL(xi) != m)
                stop("incorrect dimensions for 'xi'")
            for (i in seq_len(m))
                y[,i] <- diffinv.vector(as.vector(x[,i]), lag, differences,
                                        as.vector(xi[,i]))
        }
    }
    else if (is.vector(x))
        y <- diffinv.vector(x, lag, differences, xi)
    else
        stop(gettextf("'%s' argument is not a vector or matrix", "x"))
    y
}

diffinv.ts <- function (x, lag = 1, differences = 1, xi, ...)
{
    y <- diffinv.default(if(is.ts(x) && is.null(dim(x))) as.vector(x) else
                         as.matrix(x), lag, differences, xi)
    ts(y, frequency = frequency(x), end = end(x))
}

toeplitz <- function (x)
{
    if(!is.vector(x)) stop(gettextf("'%s' argument is not a vector", "x"))
    n <- length(x)
    A <- matrix(raw(), n, n)
    matrix(x[abs(col(A) - row(A)) + 1L], n, n)
}
