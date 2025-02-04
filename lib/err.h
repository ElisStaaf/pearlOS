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

/* [OLD/NEW]
 * Old exit codes are just like
 * every other thing, but the
 * *new* exit codes have a 
 * special type, and you
 * can access the function exit
 * code by using "func.code",
 * e.g: myfunc().code. Define
 * EXIT_OLD if you want the old
 * experience, though it is gone.
 */

#pragma once

/* Base exit code */
#ifndef EXIT_OLD
    typedef struct {
        int code;
    } excode;
#endif

/* Regular 'ol exit success */
#ifdef EXIT_OLD
#   define exitval 0
#else
    excode exitval = {
        .code = 0
    };
#endif

/* Old and new standard error */
#ifdef EXIT_OLD
#   define errval 1
#else
    excode errval = {
        .code = 1
    };
#endif

/* Another one for good measure */
#ifdef EXIT_OLD
#   define errval256 256
#else
    excode errval256 = {
        .code = 256
    };
#endif

/* Exit macro */
#ifdef EXIT_OLD
#   define fetch return
#else
#   define fetch(c) return c;
#endif