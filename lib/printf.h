/*
Copyright 2025 Elis Staaf

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#pragma once

/* Includes */
#include <io.h>

/* Defines */
#ifndef putchar
#   define putchar(c) printc(c)
#endif

/* * * * * * * * * * * * * * * * * * *
 *     The first commandment.        *
 * * * * * * * * * * * * * * * * * * *
 * When you just need                *
 * printf, not the whole IO          *
 * library, do:                      *
 *                                   *
 *     #define PRINTF_IMPL           *
 *     #include <printf.h>           *
 *                                   *
 * If not, you have sinned,          *
 * and will be sent to programmer    *
 * hell forever (it's a              *
 * javascript repl).                 *
 * * * * * * * * * * * * * * * * * * */
#ifdef PRINTF_IMPL
#define printf  printf_
#define sprintf sprintf_
#endif

/* Functions */

/* Main ``printf`` function (true macro
 * defined in ``io.h`` though -_-). */
int printf_(const char *format, ...);

/* SPrintf (Stream Printf). Has *not*
 * been tested, thus should *not* be used. */
int sprintf_(char *out, const char *format, ...);