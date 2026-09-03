#include <dirent.h>
#include <fabric/FabricServerModDiscovery.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#define _mkdir(x) mkdir(x, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#endif

int get_mods_list(const char *dir_path) {
  struct dirent *dir_ptr = NULL;
  DIR *dir = opendir(dir_path);
  if (dir == NULL) {
    return -1;
  }
  do {
    dir_ptr = readdir(dir);
    /* Ignore hidden files, previous directory and current direcetory */
    if (dir_ptr != NULL && dir_ptr->d_name[0] != '.') {
      printf("file found: %s\n", dir_ptr->d_name);
    }
  } while (dir_ptr != NULL);
  closedir(dir);
  return 0;
}
