/* $Id$ */

/* 
 * timed_thread.h: Abstraction layer for timed threads
 *
 * Copyright (C) 2006-2007 Philip Kovacs pkovacs@users.sourceforge.net
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 * USA.
 *
 */

#ifndef _TIMED_THREAD_H_
#define _TIMED_THREAD_H_

#define MINIMUM_INTERVAL_USECS 50000  /* 50000 microseconds = 50 ms =  0.05 sec */

/* opaque structure for clients */
typedef struct _timed_thread timed_thread;

/* create a timed thread */
timed_thread* timed_thread_create (void *(*start_routine)(void*), void *arg, unsigned int interval_usecs);

/* destroy a timed thread */
void timed_thread_destroy (timed_thread* p_timed_thread, timed_thread** addr_of_p_timed_thread);

/* lock a timed thread for critical section activity */
int timed_thread_lock (timed_thread* p_timed_thread);

/* unlock a timed thread after critical section activity */
int timed_thread_unlock (timed_thread* p_timed_thread);

/* waits required interval for termination signal and returns 1 if got it, 0 otherwise */
int timed_thread_test (timed_thread* p_timed_thread);

/* exit a timed thread */
void timed_thread_exit (timed_thread* p_timed_thread);

/* register a timed thread for future destruction via timed_thread_destroy_registered_threads() */
int timed_thread_register (timed_thread* p_timed_thread, timed_thread** addr_of_p_timed_thread);

/* destroy all registered timed threads */
void timed_thread_destroy_registered_threads (void);

#endif /* #ifdef _TIMED_THREAD_H_ */