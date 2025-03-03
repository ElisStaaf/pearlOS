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

/* No external libs needed. */

/* We need this for the ``INF`` macro,
 * because x/0 = inf. DO NOT REMOVE. */
double divide(double x, double y);

/* Defines */
#define INF divide(10, 0)
#define PHI (1.61803398874989)
#define PI  (3.14159265358979)
#define E   (2.71828182845904)

/* Functions */
double pow(double base, double exponent);
double abs(double number);
double factorial(double number);