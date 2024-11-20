#pragma once

#include "../io.h"
#include "../../fs/fscore.h"

void ksh_list_files()
{
  char *name;
  for (int i = 0; i < file_count(); ++i)
  {
    name = file_get_name(i);
    if (name != (char *)FILE_NOT_FOUND)
    {
      kprints(name);
      kprintc('\n');
    }
  }
}
