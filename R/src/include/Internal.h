/*
 *  R : A Computer Language for Statistical Data Analysis
 *  Copyright (C) 1997--2017  The R Core Team
 *  Copyright (C) 1995, 1996  Robert Gentleman and Ross Ihaka
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, a copy is available at
 *  https://www.R-project.org/Licenses/
 */

/* Names of  .Internal(.) and .Primitive(.)  R functions
 *
 * Must all return SEXP because of CCODE in Defn.h.
 * do_math*() and do_cmathfuns are in ../main/arithmetic.h
 */

#ifndef R_INTERNAL_H
#define R_INTERNAL_H


/* Function Names */

#if _WIN32
SEXP do_mkjunction(SEXP, SEXP, SEXP, SEXP);
SEXP do_shellexec(SEXP, SEXP, SEXP, SEXP);
SEXP do_syswhich(SEXP, SEXP, SEXP, SEXP);
SEXP do_tzone_name(SEXP, SEXP, SEXP, SEXP);
#else
SEXP do_X11(SEXP, SEXP, SEXP, SEXP);
#endif

SEXP do_abbrev(SEXP, SEXP, SEXP, SEXP);
SEXP do_abs(SEXP, SEXP, SEXP, SEXP);
SEXP do_addCondHands(SEXP, SEXP, SEXP, SEXP);
SEXP do_address(SEXP, SEXP, SEXP, SEXP);
SEXP do_addRestart(SEXP, SEXP, SEXP, SEXP);
SEXP do_addTryHandlers(SEXP, SEXP, SEXP, SEXP);
SEXP do_adist(SEXP, SEXP, SEXP, SEXP);
SEXP do_agrep(SEXP, SEXP, SEXP, SEXP);
SEXP do_allnames(SEXP, SEXP, SEXP, SEXP);
SEXP do_anyNA(SEXP, SEXP, SEXP, SEXP);
SEXP do_aperm(SEXP, SEXP, SEXP, SEXP);
SEXP do_aregexec(SEXP, SEXP, SEXP, SEXP);
SEXP do_args(SEXP, SEXP, SEXP, SEXP);
SEXP do_arith(SEXP, SEXP, SEXP, SEXP);
SEXP do_array(SEXP, SEXP, SEXP, SEXP);
SEXP do_asPOSIXct(SEXP, SEXP, SEXP, SEXP);
SEXP do_asPOSIXlt(SEXP, SEXP, SEXP, SEXP);
SEXP do_ascall(SEXP, SEXP, SEXP, SEXP);
SEXP do_as_environment(SEXP, SEXP, SEXP, SEXP);
SEXP do_asatomic(SEXP, SEXP, SEXP, SEXP);
SEXP do_asfunction(SEXP, SEXP, SEXP, SEXP);
SEXP do_asmatrixdf(SEXP, SEXP, SEXP, SEXP);
SEXP do_assign(SEXP, SEXP, SEXP, SEXP);
SEXP do_asvector(SEXP, SEXP, SEXP, SEXP);
SEXP do_asCharacterFactor(SEXP, SEXP, SEXP, SEXP);
SEXP do_AT(SEXP call, SEXP op, SEXP args, SEXP env);
SEXP do_attach(SEXP,SEXP,SEXP,SEXP);
SEXP do_attr(SEXP, SEXP, SEXP, SEXP);
SEXP do_attrgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_attributes(SEXP, SEXP, SEXP, SEXP);
SEXP do_attributesgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_backsolve(SEXP, SEXP, SEXP, SEXP);
SEXP do_baseenv(SEXP, SEXP, SEXP, SEXP);
SEXP do_basename(SEXP, SEXP, SEXP, SEXP);
SEXP do_bcprofcounts(SEXP, SEXP, SEXP, SEXP);
SEXP do_bcprofstart(SEXP, SEXP, SEXP, SEXP);
SEXP do_bcprofstop(SEXP, SEXP, SEXP, SEXP);
SEXP do_begin(SEXP, SEXP, SEXP, SEXP);
SEXP do_bincode(SEXP, SEXP, SEXP, SEXP);
SEXP do_bind(SEXP, SEXP, SEXP, SEXP);
SEXP do_bindtextdomain(SEXP, SEXP, SEXP, SEXP);
SEXP do_bitwise(SEXP, SEXP, SEXP, SEXP);
SEXP do_body(SEXP, SEXP, SEXP, SEXP);
SEXP do_bodyCode(SEXP, SEXP, SEXP, SEXP);
SEXP NORET do_break(SEXP, SEXP, SEXP, SEXP);
SEXP do_browser(SEXP, SEXP, SEXP, SEXP);
SEXP do_builtins(SEXP, SEXP, SEXP, SEXP);
SEXP do_c(SEXP, SEXP, SEXP, SEXP);
SEXP do_c_dflt(SEXP, SEXP, SEXP, SEXP);
SEXP do_call(SEXP, SEXP, SEXP, SEXP);
SEXP do_capabilities(SEXP, SEXP, SEXP, SEXP);
SEXP do_capabilitiesX11(SEXP, SEXP, SEXP, SEXP);
SEXP do_cat(SEXP, SEXP, SEXP, SEXP);
SEXP do_charmatch(SEXP, SEXP, SEXP, SEXP);
SEXP do_charToRaw(SEXP, SEXP, SEXP, SEXP);
SEXP do_chartr(SEXP, SEXP, SEXP, SEXP);
SEXP do_class(SEXP, SEXP, SEXP, SEXP);
SEXP do_classgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_colon(SEXP, SEXP, SEXP, SEXP);
SEXP do_colsum(SEXP, SEXP, SEXP, SEXP);
SEXP do_commandArgs(SEXP, SEXP, SEXP, SEXP);
SEXP do_comment(SEXP, SEXP, SEXP, SEXP);
SEXP do_commentgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_complex(SEXP, SEXP, SEXP, SEXP);
SEXP do_contourLines(SEXP, SEXP, SEXP, SEXP);
SEXP do_copyDFattr(SEXP, SEXP, SEXP, SEXP);
SEXP do_crc64(SEXP, SEXP, SEXP, SEXP);
SEXP do_Cstack_info(SEXP, SEXP, SEXP, SEXP);
SEXP do_cum(SEXP, SEXP, SEXP, SEXP);
SEXP do_curlDownload(SEXP, SEXP, SEXP, SEXP);
SEXP do_curlGetHeaders(SEXP, SEXP, SEXP, SEXP);
SEXP do_curlVersion(SEXP, SEXP, SEXP, SEXP);
SEXP do_D2POSIXlt(SEXP, SEXP, SEXP, SEXP);
SEXP do_date(SEXP, SEXP, SEXP, SEXP);
SEXP do_debug(SEXP, SEXP, SEXP, SEXP);
SEXP do_delayed(SEXP, SEXP, SEXP, SEXP);
SEXP do_deparse(SEXP, SEXP, SEXP, SEXP);
SEXP do_detach(SEXP,SEXP,SEXP,SEXP);
SEXP NORET do_dfltStop(SEXP, SEXP, SEXP, SEXP);
SEXP do_dfltWarn(SEXP, SEXP, SEXP, SEXP);
SEXP do_diag(SEXP, SEXP, SEXP, SEXP);
SEXP do_dim(SEXP, SEXP, SEXP, SEXP);
SEXP do_dimgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_dimnames(SEXP, SEXP, SEXP, SEXP);
SEXP do_dimnamesgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_dircreate(SEXP, SEXP, SEXP, SEXP);
SEXP do_direxists(SEXP, SEXP, SEXP, SEXP);
SEXP do_dirname(SEXP, SEXP, SEXP, SEXP);
SEXP do_docall(SEXP, SEXP, SEXP, SEXP);
SEXP do_dotcall(SEXP, SEXP, SEXP, SEXP);
SEXP do_dotsElt(SEXP, SEXP, SEXP, SEXP);
SEXP do_dotsLength(SEXP, SEXP, SEXP, SEXP);
SEXP do_dotcallgr(SEXP, SEXP, SEXP, SEXP);
SEXP do_dotCode(SEXP, SEXP, SEXP, SEXP);
SEXP do_dput(SEXP, SEXP, SEXP, SEXP);
SEXP do_drop(SEXP, SEXP, SEXP, SEXP);
SEXP do_dump(SEXP, SEXP, SEXP, SEXP);
SEXP do_duplicated(SEXP, SEXP, SEXP, SEXP);
SEXP do_dynload(SEXP, SEXP, SEXP, SEXP);
SEXP do_dynunload(SEXP, SEXP, SEXP, SEXP);
SEXP do_eapply(SEXP, SEXP, SEXP, SEXP);
SEXP do_edit(SEXP, SEXP, SEXP, SEXP);
SEXP do_emptyenv(SEXP, SEXP, SEXP, SEXP);
SEXP do_encoding(SEXP, SEXP, SEXP, SEXP);
SEXP do_encodeString(SEXP, SEXP, SEXP, SEXP);
SEXP do_enc2(SEXP, SEXP, SEXP, SEXP);
SEXP do_envir(SEXP, SEXP, SEXP, SEXP);
SEXP do_envirgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_envirName(SEXP, SEXP, SEXP, SEXP);
SEXP do_env2list(SEXP, SEXP, SEXP, SEXP);
SEXP do_eSoftVersion(SEXP, SEXP, SEXP, SEXP);
SEXP do_External(SEXP, SEXP, SEXP, SEXP);
SEXP do_Externalgr(SEXP, SEXP, SEXP, SEXP);
SEXP do_eval(SEXP, SEXP, SEXP, SEXP);
SEXP do_expression(SEXP, SEXP, SEXP, SEXP);
SEXP do_fileaccess(SEXP, SEXP, SEXP, SEXP);
SEXP do_fileappend(SEXP, SEXP, SEXP, SEXP);
SEXP do_filechoose(SEXP, SEXP, SEXP, SEXP);
SEXP do_filecopy(SEXP, SEXP, SEXP, SEXP);
SEXP do_filecreate(SEXP, SEXP, SEXP, SEXP);
SEXP do_fileexists(SEXP, SEXP, SEXP, SEXP);
SEXP do_fileinfo(SEXP, SEXP, SEXP, SEXP);
SEXP do_filelink(SEXP, SEXP, SEXP, SEXP);
SEXP do_filepath(SEXP, SEXP, SEXP, SEXP);
SEXP do_fileremove(SEXP, SEXP, SEXP, SEXP);
SEXP do_filerename(SEXP, SEXP, SEXP, SEXP);
SEXP do_fileshow(SEXP, SEXP, SEXP, SEXP);
SEXP do_filesymlink(SEXP, SEXP, SEXP, SEXP);
SEXP do_findinterval(SEXP, SEXP, SEXP, SEXP);
SEXP do_first_min(SEXP, SEXP, SEXP, SEXP);
SEXP do_flush(SEXP, SEXP, SEXP, SEXP);
SEXP do_for(SEXP, SEXP, SEXP, SEXP);
SEXP do_forceAndCall(SEXP, SEXP, SEXP, SEXP);
SEXP do_format(SEXP, SEXP, SEXP, SEXP);
SEXP do_formatC(SEXP, SEXP, SEXP, SEXP);
SEXP do_formatinfo(SEXP, SEXP, SEXP, SEXP);
SEXP do_formatPOSIXlt(SEXP, SEXP, SEXP, SEXP);
SEXP do_formals(SEXP, SEXP, SEXP, SEXP);
SEXP do_function(SEXP, SEXP, SEXP, SEXP);
SEXP do_gc(SEXP, SEXP, SEXP, SEXP);
SEXP do_gcinfo(SEXP, SEXP, SEXP, SEXP);
SEXP do_gctime(SEXP, SEXP, SEXP, SEXP);
SEXP do_gctorture(SEXP, SEXP, SEXP, SEXP);
SEXP do_gctorture2(SEXP, SEXP, SEXP, SEXP);
SEXP do_get(SEXP, SEXP, SEXP, SEXP);
SEXP do_getDllTable(SEXP, SEXP, SEXP, SEXP);
SEXP do_getVarsFromFrame(SEXP call, SEXP op, SEXP args, SEXP env);
SEXP do_getenv(SEXP, SEXP, SEXP, SEXP);
SEXP do_geterrmessage(SEXP, SEXP, SEXP, SEXP);
SEXP do_getGraphicsEvent(SEXP, SEXP, SEXP, SEXP);
SEXP do_getGraphicsEventEnv(SEXP, SEXP, SEXP, SEXP);
SEXP do_getlocale(SEXP, SEXP, SEXP, SEXP);
SEXP do_getOption(SEXP, SEXP, SEXP, SEXP);
SEXP do_getRegisteredRoutines(SEXP, SEXP, SEXP, SEXP);
SEXP do_getSymbolInfo(SEXP, SEXP, SEXP, SEXP);
SEXP do_getRestart(SEXP, SEXP, SEXP, SEXP);
SEXP do_gettext(SEXP, SEXP, SEXP, SEXP);
SEXP do_getwd(SEXP, SEXP, SEXP, SEXP);
SEXP do_glob(SEXP, SEXP, SEXP, SEXP);
SEXP do_globalenv(SEXP, SEXP, SEXP, SEXP);
SEXP do_grep(SEXP, SEXP, SEXP, SEXP);
SEXP do_grepraw(SEXP, SEXP, SEXP, SEXP);
SEXP do_gsub(SEXP, SEXP, SEXP, SEXP);
SEXP do_iconv(SEXP, SEXP, SEXP, SEXP);
SEXP do_ICUget(SEXP, SEXP, SEXP, SEXP);
SEXP do_ICUset(SEXP, SEXP, SEXP, SEXP);
SEXP do_identical(SEXP, SEXP, SEXP, SEXP);
SEXP do_if(SEXP, SEXP, SEXP, SEXP);
SEXP do_inherits(SEXP, SEXP, SEXP, SEXP);
SEXP do_inspect(SEXP, SEXP, SEXP, SEXP);
SEXP do_intToUtf8(SEXP, SEXP, SEXP, SEXP);
SEXP do_interactive(SEXP, SEXP, SEXP, SEXP);
SEXP do_internal(SEXP, SEXP, SEXP, SEXP);
SEXP do_internalsID(SEXP, SEXP, SEXP, SEXP);
SEXP do_interruptsSuspended(SEXP, SEXP, SEXP, SEXP);
SEXP do_intToBits(SEXP, SEXP, SEXP, SEXP);
SEXP do_invisible(SEXP, SEXP, SEXP, SEXP);
SEXP NORET do_invokeRestart(SEXP, SEXP, SEXP, SEXP);
SEXP do_is(SEXP, SEXP, SEXP, SEXP);
SEXP do_isatty(SEXP, SEXP, SEXP, SEXP);
SEXP do_isfinite(SEXP, SEXP, SEXP, SEXP);
SEXP do_isinfinite(SEXP, SEXP, SEXP, SEXP);
SEXP do_islistfactor(SEXP, SEXP, SEXP, SEXP);
SEXP do_isloaded(SEXP, SEXP, SEXP, SEXP);
SEXP do_isna(SEXP, SEXP, SEXP, SEXP);
SEXP do_isnan(SEXP, SEXP, SEXP, SEXP);
SEXP do_isunsorted(SEXP, SEXP, SEXP, SEXP);
SEXP do_isvector(SEXP, SEXP, SEXP, SEXP);
SEXP do_lapack(SEXP, SEXP, SEXP, SEXP);
SEXP do_lapply(SEXP, SEXP, SEXP, SEXP);
SEXP do_lazyLoadDBfetch(SEXP, SEXP, SEXP, SEXP);
SEXP do_lazyLoadDBflush(SEXP, SEXP, SEXP, SEXP);
SEXP do_lazyLoadDBinsertValue(SEXP call, SEXP op, SEXP args, SEXP env);
SEXP do_length(SEXP, SEXP, SEXP, SEXP);
SEXP do_lengthgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_lengths(SEXP, SEXP, SEXP, SEXP);
SEXP do_levelsgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_listdirs(SEXP, SEXP, SEXP, SEXP);
SEXP do_listfiles(SEXP, SEXP, SEXP, SEXP);
SEXP do_list2env(SEXP, SEXP, SEXP, SEXP);
SEXP do_load(SEXP, SEXP, SEXP, SEXP);
SEXP do_loadFromConn2(SEXP, SEXP, SEXP, SEXP);
SEXP do_loadInfoFromConn2(SEXP, SEXP, SEXP, SEXP);
SEXP do_localeconv(SEXP, SEXP, SEXP, SEXP);
SEXP do_log(SEXP, SEXP, SEXP, SEXP);
SEXP do_log1arg(SEXP, SEXP, SEXP, SEXP);
SEXP do_logic(SEXP, SEXP, SEXP, SEXP);
SEXP do_logic2(SEXP, SEXP, SEXP, SEXP);
SEXP do_logic3(SEXP, SEXP, SEXP, SEXP);
SEXP do_ls(SEXP, SEXP, SEXP, SEXP);
SEXP do_l10n_info(SEXP, SEXP, SEXP, SEXP);
SEXP do_machine(SEXP, SEXP, SEXP, SEXP);
SEXP do_makelazy(SEXP, SEXP, SEXP, SEXP);
SEXP do_makelist(SEXP, SEXP, SEXP, SEXP);
SEXP do_makenames(SEXP, SEXP, SEXP, SEXP);
SEXP do_makeunique(SEXP, SEXP, SEXP, SEXP);
SEXP do_makevector(SEXP, SEXP, SEXP, SEXP);
SEXP do_mapply(SEXP, SEXP, SEXP, SEXP);
SEXP do_match(SEXP, SEXP, SEXP, SEXP);
SEXP do_matchcall(SEXP, SEXP, SEXP, SEXP);
SEXP do_matprod(SEXP, SEXP, SEXP, SEXP);
SEXP do_Math2(SEXP, SEXP, SEXP, SEXP);
SEXP do_matrix(SEXP, SEXP, SEXP, SEXP);
SEXP do_maxcol(SEXP, SEXP, SEXP, SEXP);
SEXP do_memlimits(SEXP, SEXP, SEXP, SEXP);
SEXP do_memoryprofile(SEXP, SEXP, SEXP, SEXP);
SEXP do_merge(SEXP, SEXP, SEXP, SEXP);
SEXP do_mget(SEXP, SEXP, SEXP, SEXP);
SEXP do_missing(SEXP, SEXP, SEXP, SEXP);
SEXP do_mmap_file(SEXP, SEXP, SEXP, SEXP);
SEXP do_munmap_file(SEXP, SEXP, SEXP, SEXP);
SEXP do_named(SEXP, SEXP, SEXP, SEXP);
SEXP do_names(SEXP, SEXP, SEXP, SEXP);
SEXP do_namesgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_nargs(SEXP, SEXP, SEXP, SEXP);
SEXP do_nchar(SEXP,SEXP,SEXP,SEXP);
SEXP do_newenv(SEXP,SEXP,SEXP,SEXP);
SEXP do_nextmethod(SEXP,SEXP,SEXP,SEXP);
SEXP do_ngettext(SEXP, SEXP, SEXP, SEXP);
SEXP do_normalizepath(SEXP, SEXP, SEXP, SEXP);
SEXP do_nzchar(SEXP,SEXP,SEXP,SEXP);
SEXP do_onexit(SEXP, SEXP, SEXP, SEXP);
SEXP do_options(SEXP, SEXP, SEXP, SEXP);
SEXP do_order(SEXP, SEXP, SEXP, SEXP);
SEXP do_packBits(SEXP, SEXP, SEXP, SEXP);
SEXP do_paren(SEXP, SEXP, SEXP, SEXP);
SEXP do_parentenv(SEXP, SEXP, SEXP, SEXP);
SEXP do_parentenvgets(SEXP, SEXP, SEXP, SEXP);
SEXP do_parentframe(SEXP, SEXP, SEXP, SEXP);
SEXP do_parse(SEXP, SEXP, SEXP, SEXP);
SEXP do_paste(SEXP, SEXP, SEXP, SEXP);
SEXP do_pathexpand(SEXP, SEXP, SEXP, SEXP);
SEXP do_pcre_config(SEXP, SEXP, SEXP, SEXP);
SEXP do_pmatch(SEXP, SEXP, SEXP, SEXP);
SEXP do_pmin(SEXP, SEXP, SEXP, SEXP);
SEXP do_polyroot(SEXP, SEXP, SEXP, SEXP);
SEXP do_pos2env(SEXP, SEXP, SEXP, SEXP);
SEXP do_POSIXlt2D(SEXP, SEXP, SEXP, SEXP);
SEXP do_pretty(SEXP, SEXP, SEXP, SEXP);
SEXP do_primitive(SEXP, SEXP, SEXP, SEXP);
SEXP do_printdefault(SEXP, SEXP, SEXP, SEXP);
SEXP do_printDeferredWarnings(SEXP, SEXP, SEXP, SEXP);
SEXP do_printfunction(SEXP, SEXP, SEXP, SEXP);
SEXP do_prmatrix(SEXP, SEXP, SEXP, SEXP);
SEXP do_proctime(SEXP, SEXP, SEXP, SEXP);
SEXP do_psort(SEXP, SEXP, SEXP, SEXP);
SEXP do_qsort(SEXP, SEXP, SEXP, SEXP);
SEXP do_quit(SEXP, SEXP, SEXP, SEXP);
SEXP do_quote(SEXP, SEXP, SEXP, SEXP);
SEXP do_radixsort(SEXP, SEXP, SEXP, SEXP);
SEXP do_random1(SEXP, SEXP, SEXP, SEXP);
SEXP do_random2(SEXP, SEXP, SEXP, SEXP);
SEXP do_random3(SEXP, SEXP, SEXP, SEXP);
SEXP do_range(SEXP, SEXP, SEXP, SEXP);
SEXP do_rank(SEXP, SEXP, SEXP, SEXP);
SEXP do_rapply(SEXP, SEXP, SEXP, SEXP);
SEXP do_rawShift(SEXP, SEXP, SEXP, SEXP);
SEXP do_rawToBits(SEXP, SEXP, SEXP, SEXP);
SEXP do_rawToChar(SEXP, SEXP, SEXP, SEXP);
SEXP do_readDCF(SEXP, SEXP, SEXP, SEXP);
SEXP do_readEnviron(SEXP, SEXP, SEXP, SEXP);
SEXP do_readlink(SEXP, SEXP, SEXP, SEXP);
SEXP do_readLines(SEXP, SEXP, SEXP, SEXP);
SEXP do_readln(SEXP, SEXP, SEXP, SEXP);
SEXP do_recall(SEXP, SEXP, SEXP, SEXP);
SEXP do_refcnt(SEXP, SEXP, SEXP, SEXP);
SEXP do_recordGraphics(SEXP, SEXP, SEXP, SEXP);
SEXP do_regexec(SEXP, SEXP, SEXP, SEXP);
SEXP do_regexpr(SEXP, SEXP, SEXP, SEXP);
SEXP do_regFinaliz(SEXP, SEXP, SEXP, SEXP);
SEXP do_relop(SEXP, SEXP, SEXP, SEXP);
SEXP do_relop_dflt(SEXP, SEXP, SEXP, SEXP);
SEXP do_remove(SEXP, SEXP, SEXP, SEXP);
SEXP do_rep(SEXP, SEXP, SEXP, SEXP);
SEXP do_rep_int(SEXP, SEXP, SEXP, SEXP);
SEXP do_rep_len(SEXP, SEXP, SEXP, SEXP);
SEXP do_repeat(SEXP, SEXP, SEXP, SEXP);
SEXP do_resetCondHands(SEXP, SEXP, SEXP, SEXP);
SEXP NORET do_return(SEXP, SEXP, SEXP, SEXP);
SEXP do_returnValue(SEXP, SEXP, SEXP, SEXP);
SEXP do_rgb(SEXP, SEXP, SEXP, SEXP);
SEXP do_Rhome(SEXP, SEXP, SEXP, SEXP);
SEXP do_RNGkind(SEXP, SEXP, SEXP, SEXP);
SEXP do_rowsum(SEXP, SEXP, SEXP, SEXP);
SEXP do_rowscols(SEXP, SEXP, SEXP, SEXP);
SEXP do_S4on(SEXP, SEXP, SEXP, SEXP);
SEXP do_sample(SEXP, SEXP, SEXP, SEXP);
SEXP do_sample2(SEXP, SEXP, SEXP, SEXP);
SEXP do_save(SEXP, SEXP, SEXP, SEXP);
SEXP do_saveToConn(SEXP, SEXP, SEXP, SEXP);
SEXP do_saveplot(SEXP, SEXP, SEXP, SEXP);
SEXP do_scan(SEXP, SEXP, SEXP, SEXP);
SEXP do_search(SEXP, SEXP, SEXP, SEXP);
SEXP do_seq(SEXP, SEXP, SEXP, SEXP);
SEXP do_seq_along(SEXP, SEXP, SEXP, SEXP);
SEXP do_seq_len(SEXP, SEXP, SEXP, SEXP);
SEXP do_serialize(SEXP, SEXP, SEXP, SEXP);
SEXP do_serializeToConn(SEXP, SEXP, SEXP, SEXP);
SEXP do_serializeInfoFromConn(SEXP, SEXP, SEXP, SEXP);
SEXP do_set(SEXP, SEXP, SEXP, SEXP);
SEXP do_setS4Object(SEXP, SEXP, SEXP, SEXP);
SEXP do_setFileTime(SEXP, SEXP, SEXP, SEXP);
SEXP do_setencoding(SEXP, SEXP, SEXP, SEXP);
SEXP do_setenv(SEXP, SEXP, SEXP, SEXP);
SEXP do_seterrmessage(SEXP, SEXP, SEXP, SEXP);
SEXP do_setmaxnumthreads(SEXP, SEXP, SEXP, SEXP);
SEXP do_setnumthreads(SEXP, SEXP, SEXP, SEXP);
SEXP do_setGraphicsEventEnv(SEXP, SEXP, SEXP, SEXP);
SEXP do_setlocale(SEXP, SEXP, SEXP, SEXP);
SEXP do_setseed(SEXP, SEXP, SEXP, SEXP);
SEXP do_setSessionTimeLimit(SEXP, SEXP, SEXP, SEXP);
SEXP do_setTimeLimit(SEXP, SEXP, SEXP, SEXP);
SEXP do_setwd(SEXP, SEXP, SEXP, SEXP);
SEXP do_shortRowNames(SEXP, SEXP, SEXP, SEXP);
SEXP do_signalCondition(SEXP, SEXP, SEXP, SEXP);
SEXP do_sink(SEXP, SEXP, SEXP, SEXP);
SEXP do_sinknumber(SEXP, SEXP, SEXP, SEXP);
SEXP do_sort(SEXP, SEXP, SEXP, SEXP);
SEXP do_split(SEXP, SEXP, SEXP, SEXP);
SEXP do_sprintf(SEXP, SEXP, SEXP, SEXP);
SEXP do_standardGeneric(SEXP, SEXP, SEXP, SEXP);
SEXP do_startsWith(SEXP, SEXP, SEXP, SEXP);
SEXP NORET do_stop(SEXP, SEXP, SEXP, SEXP);
SEXP do_storage_mode(SEXP, SEXP, SEXP, SEXP);
SEXP do_strrep(SEXP, SEXP, SEXP, SEXP);
SEXP do_strsplit(SEXP,SEXP,SEXP,SEXP);
SEXP do_strptime(SEXP,SEXP,SEXP,SEXP);
SEXP do_strtrim(SEXP,SEXP,SEXP,SEXP);
SEXP do_strtoi(SEXP,SEXP,SEXP,SEXP);
SEXP do_syschmod(SEXP,SEXP,SEXP,SEXP);
SEXP do_sysinfo(SEXP,SEXP,SEXP,SEXP);
SEXP do_syssleep(SEXP,SEXP,SEXP,SEXP);
SEXP do_sysumask(SEXP,SEXP,SEXP,SEXP);
SEXP do_subassign(SEXP, SEXP, SEXP, SEXP);
SEXP do_subassign_dflt(SEXP, SEXP, SEXP, SEXP);
SEXP do_subassign2(SEXP, SEXP, SEXP, SEXP);
SEXP do_subassign2_dflt(SEXP, SEXP, SEXP, SEXP);
SEXP do_subassign3(SEXP, SEXP, SEXP, SEXP);
SEXP do_subset(SEXP, SEXP, SEXP, SEXP);
SEXP do_subset_dflt(SEXP, SEXP, SEXP, SEXP);
SEXP do_subset2(SEXP, SEXP, SEXP, SEXP);
SEXP do_subset2_dflt(SEXP, SEXP, SEXP, SEXP);
SEXP do_subset3(SEXP, SEXP, SEXP, SEXP);
SEXP do_substitute(SEXP, SEXP, SEXP, SEXP);
SEXP do_substr(SEXP,SEXP,SEXP,SEXP);
SEXP do_substrgets(SEXP,SEXP,SEXP,SEXP);
SEXP do_summary(SEXP, SEXP, SEXP, SEXP);
SEXP do_switch(SEXP, SEXP, SEXP, SEXP);
SEXP do_sys(SEXP, SEXP, SEXP, SEXP);
SEXP do_sysbrowser(SEXP, SEXP, SEXP, SEXP);
SEXP do_sysgetpid(SEXP, SEXP, SEXP, SEXP);
SEXP do_system(SEXP, SEXP, SEXP, SEXP);
SEXP do_systime(SEXP, SEXP, SEXP, SEXP);
SEXP do_tabulate(SEXP, SEXP, SEXP, SEXP);
SEXP do_tempdir(SEXP, SEXP, SEXP, SEXP);
SEXP do_tempfile(SEXP, SEXP, SEXP, SEXP);
SEXP do_tilde(SEXP, SEXP, SEXP, SEXP);
SEXP do_tolower(SEXP, SEXP, SEXP, SEXP);
SEXP do_topenv(SEXP, SEXP, SEXP, SEXP);
SEXP do_trace(SEXP, SEXP, SEXP, SEXP);
SEXP do_traceOnOff(SEXP, SEXP, SEXP, SEXP);
SEXP do_traceback(SEXP, SEXP, SEXP, SEXP);
SEXP do_transpose(SEXP, SEXP, SEXP, SEXP);
SEXP do_trunc(SEXP, SEXP, SEXP, SEXP);
SEXP do_tryCatchHelper(SEXP, SEXP, SEXP, SEXP);
SEXP do_typeof(SEXP, SEXP, SEXP, SEXP);
SEXP do_unclass(SEXP, SEXP, SEXP, SEXP);
SEXP do_unlink(SEXP, SEXP, SEXP, SEXP);
SEXP do_unlist(SEXP, SEXP, SEXP, SEXP);
SEXP do_unserializeFromConn(SEXP, SEXP, SEXP, SEXP);
SEXP do_unsetenv(SEXP, SEXP, SEXP, SEXP);
SEXP NORET do_usemethod(SEXP, SEXP, SEXP, SEXP);
SEXP do_utf8ToInt(SEXP, SEXP, SEXP, SEXP);
SEXP do_validEnc(SEXP, SEXP, SEXP, SEXP);
SEXP do_validUTF8(SEXP, SEXP, SEXP, SEXP);
SEXP do_vapply(SEXP, SEXP, SEXP, SEXP);
SEXP do_version(SEXP, SEXP, SEXP, SEXP);
SEXP do_warning(SEXP, SEXP, SEXP, SEXP);
SEXP do_while(SEXP, SEXP, SEXP, SEXP);
SEXP do_which(SEXP, SEXP, SEXP, SEXP);
SEXP do_withVisible(SEXP, SEXP, SEXP, SEXP);
SEXP do_wrap_meta(SEXP, SEXP, SEXP, SEXP);
SEXP do_xtfrm(SEXP, SEXP, SEXP, SEXP);

SEXP do_getSnapshot(SEXP, SEXP, SEXP, SEXP);
SEXP do_playSnapshot(SEXP, SEXP, SEXP, SEXP);

SEXP R_do_data_class(SEXP call, SEXP op, SEXP args, SEXP env);
SEXP R_do_set_class(SEXP call, SEXP op, SEXP args, SEXP env);
SEXP R_getS4DataSlot(SEXP obj, SEXPTYPE type);

/* bytecode */
SEXP do_mkcode(SEXP, SEXP, SEXP, SEXP);
SEXP do_bcclose(SEXP, SEXP, SEXP, SEXP);
SEXP do_is_builtin_internal(SEXP, SEXP, SEXP, SEXP);
SEXP do_disassemble(SEXP, SEXP, SEXP, SEXP);
SEXP do_bcversion(SEXP, SEXP, SEXP, SEXP);
SEXP do_loadfile(SEXP, SEXP, SEXP, SEXP);
SEXP do_savefile(SEXP, SEXP, SEXP, SEXP);
SEXP do_growconst(SEXP, SEXP, SEXP, SEXP);
SEXP do_putconst(SEXP, SEXP, SEXP, SEXP);
SEXP do_getconst(SEXP, SEXP, SEXP, SEXP);
SEXP do_enablejit(SEXP, SEXP, SEXP, SEXP);
SEXP do_compilepkgs(SEXP, SEXP, SEXP, SEXP);

/* Connections */
SEXP do_stdin(SEXP, SEXP, SEXP, SEXP);
SEXP do_stdout(SEXP, SEXP, SEXP, SEXP);
SEXP do_stderr(SEXP, SEXP, SEXP, SEXP);
SEXP do_writelines(SEXP, SEXP, SEXP, SEXP);
SEXP do_readbin(SEXP, SEXP, SEXP, SEXP);
SEXP do_writebin(SEXP, SEXP, SEXP, SEXP);
SEXP do_readchar(SEXP, SEXP, SEXP, SEXP);
SEXP do_writechar(SEXP, SEXP, SEXP, SEXP);
SEXP do_open(SEXP, SEXP, SEXP, SEXP);
SEXP do_isopen(SEXP, SEXP, SEXP, SEXP);
SEXP do_isincomplete(SEXP, SEXP, SEXP, SEXP);
SEXP do_isseekable(SEXP, SEXP, SEXP, SEXP);
SEXP do_close(SEXP, SEXP, SEXP, SEXP);
SEXP do_fifo(SEXP, SEXP, SEXP, SEXP);
SEXP do_pipe(SEXP, SEXP, SEXP, SEXP);
SEXP do_url(SEXP, SEXP, SEXP, SEXP);
SEXP do_gzfile(SEXP, SEXP, SEXP, SEXP);
SEXP do_unz(SEXP, SEXP, SEXP, SEXP);
SEXP do_seek(SEXP, SEXP, SEXP, SEXP);
SEXP do_truncate(SEXP, SEXP, SEXP, SEXP);
SEXP do_pushback(SEXP, SEXP, SEXP, SEXP);
SEXP do_pushbacklength(SEXP, SEXP, SEXP, SEXP);
SEXP do_clearpushback(SEXP, SEXP, SEXP, SEXP);
SEXP do_rawconnection(SEXP, SEXP, SEXP, SEXP);
SEXP do_rawconvalue(SEXP, SEXP, SEXP, SEXP);
SEXP do_textconnection(SEXP, SEXP, SEXP, SEXP);
SEXP do_textconvalue(SEXP, SEXP, SEXP, SEXP);
SEXP do_getconnection(SEXP, SEXP, SEXP, SEXP);
SEXP do_getallconnections(SEXP, SEXP, SEXP, SEXP);
SEXP do_sumconnection(SEXP, SEXP, SEXP, SEXP);
SEXP do_sockconn(SEXP, SEXP, SEXP, SEXP);
SEXP do_sockselect(SEXP, SEXP, SEXP, SEXP);
SEXP do_gzcon(SEXP, SEXP, SEXP, SEXP);
SEXP do_memCompress(SEXP, SEXP, SEXP, SEXP);
SEXP do_memDecompress(SEXP, SEXP, SEXP, SEXP);

SEXP do_lockEnv(SEXP, SEXP, SEXP, SEXP);
SEXP do_envIsLocked(SEXP, SEXP, SEXP, SEXP);
SEXP do_lockBnd(SEXP, SEXP, SEXP, SEXP);
SEXP do_bndIsLocked(SEXP, SEXP, SEXP, SEXP);
SEXP do_mkActiveBnd(SEXP, SEXP, SEXP, SEXP);
SEXP do_bndIsActive(SEXP, SEXP, SEXP, SEXP);
SEXP do_mkUnbound(SEXP, SEXP, SEXP, SEXP);
SEXP do_isNSEnv(SEXP call, SEXP op, SEXP args, SEXP rho);
SEXP do_regNS(SEXP call, SEXP op, SEXP args, SEXP rho);
SEXP do_unregNS(SEXP call, SEXP op, SEXP args, SEXP rho);
SEXP do_getRegNS(SEXP call, SEXP op, SEXP args, SEXP rho);
SEXP do_getNSRegistry(SEXP call, SEXP op, SEXP args, SEXP rho);
SEXP do_importIntoEnv(SEXP call, SEXP op, SEXP args, SEXP rho);
SEXP do_envprofile(SEXP call, SEXP op, SEXP args, SEXP rho);

SEXP do_tracemem(SEXP, SEXP, SEXP, SEXP);
SEXP do_retracemem(SEXP, SEXP, SEXP, SEXP);
SEXP do_untracemem(SEXP, SEXP, SEXP, SEXP);

/* ALTREP-related */

SEXP do_sorted_fpass(SEXP, SEXP, SEXP, SEXP);

#endif /* not R_INTERNAL_H */
