/*
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
#include <drivers/display.h>
#include <fs/fscore.h>

void ksh_make_file() {
  printk("> ");
  char* file_to_make = kmalloc(512);
  scan(file_to_make);

  int response = file_make(file_to_make);

  if (response == FILE_ALREADY_EXISTS) {
    printk("File already exists!\n");
  }
  else if (response == FILE_NAME_INVALID) {
    printk("File name can only contain the following characters:\n");
    printk(FS_FILE_NAME_VALID_CHARS);
    printnl();
  }
  else if (response == FILE_COUNT_MAX_EXCEEDED) {
    printk("There are too many files!\n");
  }

  kfree(file_to_make);
}