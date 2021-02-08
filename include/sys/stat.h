/* This is an extract of sys/stat.h */
/*
 * Copyright (c) 2000-2014 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */
/* Copyright (c) 1995 NeXT Computer, Inc. All Rights Reserved */
/*-
 * Copyright (c) 1982, 1986, 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)stat.h	8.9 (Berkeley) 8/17/94
 */
 
 /*
 * Definitions of flags stored in file flags word.
 *
 * Super-user and owner changeable flags.
 */
#define UF_SETTABLE     0x0000ffff      /* mask of owner changeable flags */
#define UF_NODUMP       0x00000001      /* do not dump file */
#define UF_IMMUTABLE    0x00000002      /* file may not be changed */
#define UF_APPEND       0x00000004      /* writes to file may only append */
#define UF_OPAQUE       0x00000008      /* directory is opaque wrt. union */
/*
 * The following bit is reserved for FreeBSD.  It is not implemented
 * in Mac OS X.
 */
/* #define UF_NOUNLINK	0x00000010 */	/* file may not be removed or renamed */
#define UF_COMPRESSED   0x00000020      /* file is compressed (some file-systems) */

/* UF_TRACKED is used for dealing with document IDs.  We no longer issue
 *  notifications for deletes or renames for files which have UF_TRACKED set. */
#define UF_TRACKED              0x00000040

#define UF_DATAVAULT    0x00000080      /* entitlement required for reading */
                                        /* and writing */

/* Bits 0x0100 through 0x4000 are currently undefined. */
#define UF_HIDDEN       0x00008000      /* hint that this item should not be */
                                        /* displayed in a GUI */
/*
 * Super-user changeable flags.
 */
#define SF_SUPPORTED    0x009f0000      /* mask of superuser supported flags */
#define SF_SETTABLE     0x3fff0000      /* mask of superuser changeable flags */
#define SF_SYNTHETIC    0xc0000000      /* mask of system read-only synthetic flags */
#define SF_ARCHIVED     0x00010000      /* file is archived */
#define SF_IMMUTABLE    0x00020000      /* file may not be changed */
#define SF_APPEND       0x00040000      /* writes to file may only append */
#define SF_RESTRICTED   0x00080000      /* entitlement required for writing */
#define SF_NOUNLINK     0x00100000      /* Item may not be removed, renamed or mounted on */

/*
 * The following two bits are reserved for FreeBSD.  They are not
 * implemented in Mac OS X.
 */
/* #define SF_SNAPSHOT	0x00200000 */	/* snapshot inode */
/* NOTE: There is no SF_HIDDEN bit. */

#define SF_FIRMLINK     0x00800000      /* file is a firmlink */

/*
 * Synthetic flags.
 *
 * These are read-only.  We keep them out of SF_SUPPORTED so that
 * attempts to set them will fail.
 */
#define SF_DATALESS     0x40000000     /* file is dataless object */