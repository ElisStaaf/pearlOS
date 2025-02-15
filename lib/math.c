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

#include <math.h>

/* x/y (x/y for y = 0: inf).
 * This way of accquiring infinity was
 * explored in my blog post, for more
 * info, see:
 *
 *     https://elisstaaf.github.io/ramblings/2025/01/31/infinity.html
 */
double divide(double x, double y) {
    return x / y;
}

/* do (1 *= base) * exponent */
double pow(double base, double exponent) {
  double result = 1;
  while (exponent > 0) {
    result *= base;
    --exponent;
  }
  return result;
}

double abs(double number) {
  if (number < 0) return -number;
  return number;
}

/* do while(--number != 1) 
 *     (number * (number - 1)) */
double factorial(double number) {
    if (number == 1) {
        return 1;
    }
    return number * factorial(number - 1);
}