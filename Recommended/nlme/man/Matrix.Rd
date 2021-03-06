% File nlme/man/Matrix.Rd
% Part of the nlme package for R
% Distributed under GPL 2 or later: see nlme/LICENCE.note

\name{Matrix}
\title{Assign Matrix Values}
\usage{
matrix(object) <- value
}
\alias{matrix<-}
\arguments{
 \item{object}{any object to which \code{as.matrix} can be applied.}
 \item{value}{a matrix, or list of matrices, with the same dimensions as
   \code{as.matrix(object)} with the new values to be assigned to the
   matrix associated with \code{object}.}
}
\description{
  This function is generic; method functions can be written to handle
  specific classes of objects.  Classes which already have methods for
  this function include \code{pdMat}, \code{pdBlocked}, and
  \code{reStruct}.
}
\value{
  will depend on the method function; see the appropriate documentation.
}
\author{José Pinheiro and Douglas Bates \email{bates@stat.wisc.edu}}

\seealso{\code{\link{as.matrix}}, also for examples,
  \code{\link{matrix<-.pdMat}},%incl .pdBlocked
  \code{\link{matrix<-.reStruct}}.
}
\keyword{models}
