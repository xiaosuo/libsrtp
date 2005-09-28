/*
 * env.c
 *
 * prints out a brief report on the build environment
 *
 * David McGrew
 * Cisco Systems, Inc.
 */
/*
 *	
 * Copyright (c) 2001-2005 Cisco Systems, Inc.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *   Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * 
 *   Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * 
 *   Neither the name of the Cisco Systems, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <string.h>     /* for srtcmp() */
#include "config.h"

int 
main() {
  int err_count = 0;

#if WORDS_BIGENDIAN
  printf("CPU set to big-endian\t\t\t(WORDS_BIGENDIAN == 1)\n");
#else
  printf("CPU set to little-endian\t\t(WORDS_BIGENDIAN == 0)\n");
#endif

#if CPU_RISC
  printf("CPU set to RISC\t\t\t\t(CPU_RISC == 1)\n");
#elif CPU_CISC
  printf("CPU set to CISC\t\t\t\t(CPU_CISC == 1)\n");
#else
  printf("CPU set to an unknown type, probably due to a configuration error\n");
  err_count++;
#endif

#if CPU_ALTIVEC
  printf("CPU set to ALTIVEC\t\t\t\t(CPU_ALTIVEC == 0)\n");
#endif

#if HAVE_U_LONG_LONG
  printf("using native unsigned long long\t\t(HAVE_U_LONG_LONG == 1)\n");
#else
  printf("using built-in 64-bit math\t\t(HAVE_U_LONG_LONG == 0)\n");
#endif

#if ERR_REPORTING_STDOUT
  printf("using stdout for error reporting\t(ERR_REPORTING_STDOUT == 1)\n");
#endif

  printf("using %s as a random source\t(DEV_URANDOM == %s)\n",
	 DEV_URANDOM, DEV_URANDOM);
  if (strcmp("", DEV_URANDOM) == 0) {
    err_count++;
  }
  
  if (err_count)
    printf("warning: configuration is probably in error "
	   "(found %d problems)\n", err_count);

  return err_count;
}
