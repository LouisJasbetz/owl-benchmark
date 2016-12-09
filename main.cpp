/**
 * @file    main.cpp
 * @author  LouisJasbetz
 * @version 1.0.1
 * 
 * @section LICENSE
 * 
 * BSD 3-Clause License
 *
 * Copyright (c) 2016, LouisJasbetz
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * @section DESCRIPTION
 * 
 * Computer benchmarking application.
 */

/********************************************//**
 * Includes
 ***********************************************/
#include <stdio.h>

#ifdef WIN32
// WIN32_LEAN_AND_MEAN: Exclude APIs such as Cryptography, DDE, RPC, Shell, and Windows Sockets.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#endif

/********************************************//**
 * Defines
 ***********************************************/
#ifndef uint8_t
#define uint8_t unsigned char
#endif

#ifndef uint32_t
#define uint32_t unsigned long int
#endif

/********************************************//**
 * Functions
 ***********************************************/

/**
 * Retrieves the number of milliseconds that have elapsed since the system was started.
 * @return Number in milliseconds.
 */
uint32_t GetTicks()
{
#ifdef WIN32
  return ::GetTickCount();
#else
  timeval timeNow;
  gettimeofday(&timeNow, NULL);
  return (uint32_t)((timeNow.tv_sec) * 1000 ) + ( (timeNow.tv_usec) / 1000);
#endif
}

/********************************************//**
 * Main
 ***********************************************/
int main()
{
  printf("Hello World! %ld\r\n", GetTicks());
  
  return 0;
}
