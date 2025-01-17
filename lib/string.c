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


#include <string.h>
#include <stddef.h>
#include <kernel/kmsg.h>

/* Get string length */
uint strlen(char* string) {
  uint length = 0;
  while (*string != 0) {
    ++length;
    ++string;
  }
  return length;
}

/* Copy string.
 * [NOTE] Does NOT check for string size! -> 
 *        string overflow!!! */
void strcpy(char* dest, char* src) {
  uint size  = strlen(src) + 1;
  uint i = 0;

  do {
    dest[i] = src[i];
  } while (++i < size);
}

/* Compare 2 strings (checks if they are equal) */
bool strcmp(char* a, char* b) {
  uint32_t i = 0;
  while (1) {
    if (a[i] != b[i]) {
      return false;
    }
    else if (a[i] == 0 && b[i] == 0) {
      return true;
    }
    ++i;
  }
}

/* Add extension to base string.
 * [NOTE] As stradd() uses strcpy, this
 *        can also cause a string overflow!!!*/
void stradd(char* base, char* extension) {
  strcpy(base + strlen(base), extension);
}

/* Fill string with zero */
void strcls(char* string) {
  while (*string != 0) {
    *string = 0;
    ++string;
  }
}

/* Convert char to uppercase */
char char_to_upper(char character) {
  char offset = 'A' - 'a';
  if (character >= 'a' && character <= 'z') {
    return character + offset;
  }
  return character;
}

/* Do char_to_upper() on 
 * each character in a string. */
void strupp(char* string) {
  while (*string != 0) {
    *string = char_to_upper(*string);
    ++string;
  }
}