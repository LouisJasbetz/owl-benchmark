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
#include <ctype.h>
#include <string.h>

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
#define STR_APPLICATION_VERSION "1.0.1"

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
uint32_t get_tick_count()
{
#ifdef WIN32
  return ::GetTickCount();
#else
  timeval timeNow;
  gettimeofday(&timeNow, NULL);
  return (uint32_t)((timeNow.tv_sec) * 1000 ) + ( (timeNow.tv_usec) / 1000);
#endif
}

/**
 * Display help.
 */
void help_show()
{
  printf("\r\n");
  printf("owl-benchmark v%s.\r\n\r\n", STR_APPLICATION_VERSION);
  printf("Usage:\r\n");
  printf("\towl-benchmark [--memory | --help]\r\n");
  printf("\r\n");
}

/**
 * Benchmark memory speed.
 */
void benchmark_memory()
{
  printf("Memory speed test:");

  uint32_t memorySize = 10000000; // 10MB
  
  uint8_t * pCh1 = new uint8_t[memorySize];
  uint8_t * pCh2 = new uint8_t[memorySize];

  uint32_t nCnt1 = 0;
  uint32_t nStart = 0;
  uint32_t nMilliSecondsTook = 0;
  double nMBPS = 0;

  int nMB = 1000;
  int i = 0;
  int x = 0;

  // WRITE
  nStart = get_tick_count();

  for(i=0; i<nMB; i++)
  {
    for(x=0; x<memorySize; x++)
    {
      pCh1[x] = (uint8_t)(nCnt1++) & 0xff;
    }
  }

  nMilliSecondsTook = (get_tick_count() - nStart);
  nMBPS = (double)(nMB*10) / ((double)nMilliSecondsTook / (double)1000);

  printf("\r\n\tWriting 10G of data took %ld s, speed %.3f MB/s", nMilliSecondsTook / 1000, nMBPS);

  
  // READ
  nStart = get_tick_count();

  char ch[5];
  int n = 0;
  for(i=0; i<nMB; i++)
  {
    for(x=0; x<memorySize; x++)
    {
      ch[n] = pCh1[x];
      n = (n + 1)& 3;
    }
  }

  nMilliSecondsTook = (get_tick_count() - nStart);
  nMBPS = (double)(nMB*10) / ((double)nMilliSecondsTook / (double)1000);

  printf("\r\n\tReading 10G of data took %ld s, speed %.3f MB/s", nMilliSecondsTook / 1000, nMBPS);

  
  // COPY
  nStart = get_tick_count();

  nMB = 1000;

  for(i=0; i<nMB; i++)
  {
    memcpy(pCh2, pCh1, memorySize);
  }

  nMilliSecondsTook = (get_tick_count() - nStart);
  nMBPS = (double)(nMB*10) / ((double)nMilliSecondsTook / (double)1000);

  printf("\r\n\tCopy 10G of data took %ld s, speed %.3f MB/s", nMilliSecondsTook / 1000, nMBPS);

  delete [] pCh1;
  delete [] pCh2;

  printf("\r\nDone.\r\n");
}

/********************************************//**
 * Main
 ***********************************************/
int main(int argc, char* argv[])
{
  if (argc==2)
  {
    char *pCommand = argv[1];
    
    if (strcmp(pCommand, "--memory") == 0)
    {
      benchmark_memory();
    }
    else //if (strcmp(pCommand, "--help") == 0)
    {
      help_show();
    }
  }
  else // no arguments || too many arguments
  {
    help_show();
  }
  
  return 0;
}
