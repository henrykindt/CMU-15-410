/*
 * assert.h
 * Modified for 15-410 at CMU
 * Zachary Anderson(zra)
 */

/*
 * Copyright (c) 1995, 1998 University of Utah and the Flux Group.
 * All rights reserved.
 * 
 * This file is part of the Flux OSKit.  The OSKit is free software, also known
 * as "open source;" you can redistribute it and/or modify it under the terms
 * of the GNU General Public License (GPL), version 2, as published by the Free
 * Software Foundation (FSF).  To explore alternate licensing terms, contact
 * the University of Utah at csl-dist@cs.utah.edu or +1-801-585-3271.
 * 
 * The OSKit is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GPL for more details.  You should have
 * received a copy of the GPL along with the OSKit; see the file COPYING.  If
 * not, write to the FSF, 59 Temple Place #330, Boston, MA 02111-1307, USA.
 */


#ifndef _ASSERT_H_
#define _ASSERT_H_

#ifdef NDEBUG

#define assert(ignore) ((void)0)

#else

extern void panic(const char *format, ...);

#define assert(expression)  \
	((void)((expression) ? 0 : \
		(panic(__FILE__":%u: failed assertion `"#expression"'", \
			__LINE__), 0)))

#endif

#endif /* _ASSERT_H_ */
