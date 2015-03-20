/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (tcpliveplay_opts.h)
 *  
 *  It has been AutoGen-ed  December 17, 2014 at 03:12:43 PM by AutoGen 5.16.2
 *  From the definitions    tcpliveplay_opts.def
 *  and the template file   options
 *
 * Generated from AutoOpts 36:5:11 templates.
 *
 *  AutoOpts is a copyrighted work.  This header file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the tcpliveplay author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The tcpliveplay program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 2012 Yazan Siam, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  Modified (3 clause) Berkeley Software Distribution License
 *    <http://www.xfree86.org/3.3.6/COPYRIGHT2.html>
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name ``Yazan Siam'' nor the name of any other
 *     contributor may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *  
 *  tcpliveplay IS PROVIDED BY Yazan Siam ``AS IS'' AND ANY EXPRESS
 *  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED.  IN NO EVENT SHALL Yazan Siam OR ANY OTHER CONTRIBUTORS
 *  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 *  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the tcpliveplay program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_TCPLIVEPLAY_OPTS_H_GUARD
#define AUTOOPTS_TCPLIVEPLAY_OPTS_H_GUARD 1
#include "config.h"
#include <autoopts/options.h>

/*
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 147461
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/*
 *  Enumeration of each option:
 */
typedef enum {
    INDEX_OPT_DBUG        =  0,
    INDEX_OPT_VERSION     =  1,
    INDEX_OPT_LESS_HELP   =  2,
    INDEX_OPT_HELP        =  3,
    INDEX_OPT_MORE_HELP   =  4,
    INDEX_OPT_SAVE_OPTS   =  5,
    INDEX_OPT_LOAD_OPTS   =  6
} teOptIndex;

#define OPTION_CT    7

/*
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teOptIndex enumeration above).
 *  e.g. HAVE_OPT(DBUG)
 */
#define         DESC(n) (tcpliveplayOptions.pOptDesc[INDEX_OPT_## n])
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
#define      OPT_ARG(n) (DESC(n).optArg.argString)
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
#define    COUNT_OPT(n) (DESC(n).optOccCt)
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ((DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )

/* * * * * *
 *
 *  Enumeration of tcpliveplay exit codes
 */
typedef enum {
    TCPLIVEPLAY_EXIT_SUCCESS = 0,
    TCPLIVEPLAY_EXIT_FAILURE = 1,
    TCPLIVEPLAY_EXIT_NO_CONFIG_INPUT = 66,
    TCPLIVEPLAY_EXIT_LIBOPTS_FAILURE = 70
} tcpliveplay_exit_code_t;
/* * * * * *
 *
 *  Interface defines for specific options.
 */
#define VALUE_OPT_DBUG           'd'
#ifdef DEBUG
#define OPT_VALUE_DBUG           (DESC(DBUG).optArg.argInt)
#endif /* DEBUG */
#define VALUE_OPT_VERSION        'V'
#define VALUE_OPT_LESS_HELP      'h'
#define VALUE_OPT_HELP          'H'
#define VALUE_OPT_MORE_HELP     '!'
#define VALUE_OPT_SAVE_OPTS     INDEX_OPT_SAVE_OPTS
#define VALUE_OPT_LOAD_OPTS     INDEX_OPT_LOAD_OPTS
#define SET_OPT_SAVE_OPTS(a)   STMTS( \
        DESC(SAVE_OPTS).fOptState &= OPTST_PERSISTENT_MASK; \
        DESC(SAVE_OPTS).fOptState |= OPTST_SET; \
        DESC(SAVE_OPTS).optArg.argString = (char const*)(a) )
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS(tcpliveplayOptions.fOptSet &= ~OPTPROC_ERRSTOP)
#define ERRSTOP_OPTERR  STMTS(tcpliveplayOptions.fOptSet |= OPTPROC_ERRSTOP)
#define RESTART_OPT(n)  STMTS( \
                tcpliveplayOptions.curOptIdx = (n); \
                tcpliveplayOptions.pzCurOpt  = NULL)
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*tcpliveplayOptions.pUsageProc)(&tcpliveplayOptions, c)
/* extracted from opthead.tlib near line 484 */

#ifdef  __cplusplus
extern "C" {
#endif


/* * * * * *
 *
 *  Declare the tcpliveplay option descriptor.
 */
extern tOptions tcpliveplayOptions;

#if defined(ENABLE_NLS)
# ifndef _
#   include <stdio.h>
#   ifndef HAVE_GETTEXT
      extern char * gettext(char const *);
#   else
#     include <libintl.h>
#   endif

static inline char* aoGetsText(char const* pz) {
    if (pz == NULL) return NULL;
    return (char*)gettext(pz);
}
#   define _(s)  aoGetsText(s)
# endif /* _() */

# define OPT_NO_XLAT_CFG_NAMES  STMTS(tcpliveplayOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT_CFG;)
# define OPT_NO_XLAT_OPT_NAMES  STMTS(tcpliveplayOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)

# define OPT_XLAT_CFG_NAMES     STMTS(tcpliveplayOptions.fOptSet &= \
                                  ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
# define OPT_XLAT_OPT_NAMES     STMTS(tcpliveplayOptions.fOptSet &= \
                                  ~OPTPROC_NXLAT_OPT;)

#else   /* ENABLE_NLS */
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#endif  /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_TCPLIVEPLAY_OPTS_H_GUARD */
/* tcpliveplay_opts.h ends here */
