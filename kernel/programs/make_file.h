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

#include <io.h>
#include <mem.h>
#include <drivers/display.h>
#include <fs/core.h>

void ksh_make_file() {
  printk("> ");
  char* file_to_make = (char*) kmalloc(512);
  scan(file_to_make);

  int response = file_make(file_to_make);

  if (response == FILE_ALREADY_EXISTS) {
    println("File already exists!");
  }
  else if (response == FILE_NAME_INVALID) {
    printf("File name can only contain the following characters:\n%s\n",
           FS_FILE_NAME_VALID_CHARS);
  }
  else if (response == FILE_COUNT_MAX_EXCEEDED) {
    println("There are too many files!");
  }

  kfree(file_to_make);
}