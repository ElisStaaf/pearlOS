#include <fs/fscore.h>
#include <kernel/version.h>

#define FS_SECTOR_DATA_SIZE FS_SECTOR_SIZE - sizeof(struct Sector*)

#define END_SECTOR 0

struct SectorStruct {
  struct Sector* next;
  byte data[FS_SECTOR_DATA_SIZE];
};
typedef struct SectorStruct Sector;

typedef struct {
  char name[FS_FILE_NAME_BUFFER];
  char tags[FS_FILE_TAGS_BUFFER];
  Sector* first_sector;
} File;

File* findex[sizeof(File*) * FS_MAX_FILE_COUNT];
int findex_end = 0;

File* find_file(char* name) {
  for (int i = 0; i <= findex_end; ++i) {
    if (strcmp(findex[i]->name, name)) {
      return findex[i];
    }
  }
  return (File*)FILE_NOT_FOUND;
}

bool file_exists(char* name) {
  for (int i = 0; i <= findex_end; ++i) {
    if (strcmp(findex[i]->name, name)) {
      return true;
    }
  }
  return false;
}

int file_count() {
  return findex_end;
}

char* file_get_name(int id) {
  if (findex[id] != 0) return findex[id]->name;
  return (char*) FILE_NOT_FOUND;
}

int file_get_id(char* name) {
  for (int i = 0; i < findex_end; ++i) {
    if (strcmp(findex[i]->name, name)) {
      return i;
    }
  }
  return 1;
}

Sector* init_sector() {
  Sector* fs = kmalloc(sizeof(Sector));
  fs->next = END_SECTOR;
  for (int i = 0; i < FS_SECTOR_DATA_SIZE; ++i) {  // delete potentional data in the sector
    fs->data[i] = 0;
  }
  return fs;
}

bool file_valid(char* filename) {
  char valid[] = FS_FILE_NAME_VALID_CHARS;
  for (int i = 0; i < strlen(filename); ++i) {
    bool is_any = false;
    for (int j = 0; j < strlen(valid); ++j) {
      if (filename[i] == valid[j]) is_any = true;
    }
    if (!is_any) return false;
  }
  return true;
}

// create new file
int file_make(char* name) {
  if (findex_end > FS_MAX_FILE_COUNT) {
    return FILE_COUNT_MAX_EXCEEDED;
  }
  if (file_exists(name)) {
    return FILE_ALREADY_EXISTS;
  }
  if (!file_valid(name)) {
    return FILE_NAME_INVALID;
  }
  // allocate the file
  File* fp = kmalloc(sizeof(File));
  strcpy(fp->name, name);
  // prepare the sector
  fp->first_sector = init_sector();
  // asign the file
  findex[findex_end] = fp;
  findex_end += 1;
  return OK;
}

// delete file
int file_remove(char* name) {
  for (int i = 0; i < findex_end; ++i) {
    if (strcmp(findex[i]->name, name)) {
      File* fp = findex[i];
      Sector* fs = fp->first_sector;
      Sector* last_fs;
      // free the data sectors
      do {
        last_fs = fs;
        kfree(last_fs);
        fs = (Sector*)fs->next;   
      } while(fs != END_SECTOR);
      kfree(fp);
      findex[i] = 0;
      return OK;
    }
  }
  return FILE_NOT_FOUND;
}

int file_size(char* name) {
  File* fp = find_file(name);
  Sector* fs = fp->first_sector;
  // find the size
  int size = sizeof(fs->data);
  while (fs->next != END_SECTOR) {
    fs = (Sector *)fs->next;   // jump to next sector
    size += sizeof(fs->data);
  }
  return size;
}

// write content of file to $output
int file_read(char* filename, char* output) {
  if (!file_exists(filename)) return FILE_NOT_FOUND;
  File* fp = find_file(filename);
  Sector* fs = fp->first_sector;
  do {
    for (int i = 0; i < FS_SECTOR_DATA_SIZE; ++i) {
      output[i] = fs->data[i];
    }
    output += FS_SECTOR_DATA_SIZE;
    Sector* next_fs = (Sector *)fs->next;
    fs = next_fs;
  } while(fs != 0);
  return OK;
}

int file_write(char* filename, char* data, uint32_t depth) {
  if (!file_exists(filename)) return FILE_NOT_FOUND;
  File* fp = find_file(filename);
  Sector* fs = fp->first_sector;

  char* end = depth + data;
  while (data < end) {
    if (end - data <= FS_SECTOR_DATA_SIZE) {
      for (int i = 0; i < end - data; ++i) {
        fs->data[i] = data[i];
      }
      data = end;
    }
    else {
      for (int i = 0; i < FS_SECTOR_DATA_SIZE; ++i) {
        fs->data[i] = data[i];
      }
      data += FS_SECTOR_DATA_SIZE;
      fs = (Sector *)init_sector();
    }
  }
  return OK;
}

int file_clean(char* filename)
{
  if (!file_exists(filename)) return FILE_NOT_FOUND;
  File* fp = find_file(filename);
  Sector* fs = fp->first_sector;
  do {
    for (int i = 0; i < FS_SECTOR_DATA_SIZE; ++i) {
      fs->data[i] = 0;
    }
    Sector* next_fs = (Sector *)fs->next;
    fs = next_fs;
  } while(fs != 0);
  return OK;
}

int file_writes(char* filename, char* text)
{
  return file_write(filename, text, strlen(text));
}

void fsinit()
{
  file_make("os-release");
  file_writes(
    "os-release", 
    "NAME=\"pearlOS\"\n"
    "VERSION=\"" OS_VERSION "\"\n"
    "REPO=\"github.com/ElisStaaf/pearlOS\"\n"
    "PRETTY_NAME=\"pearlOS " OS_VERSION "\"\n"
  );
  file_make("license");
  file_writes(
    "license",
    "pearlOS is released under the Apache-2.0 License\n\n"
    "A permissive license whose main conditions require preservation of\n"
    "copyright and license notices.Contributors provide an express grant\n"
    "of patent rights. Licensed works, modifications, and larger works \n"
    "may be distributed under different terms and without source code.\n"
  );
  file_make("readme");
  file_writes(
    "readme",
    "Thank you for using pearlOS! Many, many thanks!\n"
    "If you've got any questions, type \"help\" to open\n"
    "the KSH manual. You can check out the source code at\n"
    "\"github.com/ElisStaaf/pearlOS\", feel free to contribute!\n"
    "And with that, enjoy the OS!\n\n"
    "PEARLOS: Elis Staaf <elis.staaf@proton.me>, Nov 2024.\n"
    "PIDIOS: Filip Chovanec <\?\?\?>, Mar 2021.\n"
  );
}