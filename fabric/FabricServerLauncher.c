#include <fabric/FabricServerLauncher.h>
#include <jni.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <dirent.h>
#include <windows.h>
#else
#include <sys/types.h>
#define _mkdir(x) mkdir(x, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#endif

// NOTE: will call fabric_server_launcher.init() and then the main function from
// rust (patch will paste the C ABI code right above the typical pumpkin
// "start")
static int init(void) {
  struct stat fs = {0};
  int ret = 0;

  /* Does the mods folder already exist? */
  if (stat(MODS_DIR, &fs) == -1) {
    /* Generate the mods folder as it does not exist */
    ret = _mkdir(MODS_DIR);
    if (ret < 0) {
      /* Failed to create mods folder */
      return -1;
    }
  }
  return 0;
}

static int deinit(void) {
  // TODO: Free any allocated memory and do some cleanup
  return 0;
}

FabricServerLauncher fabric_server_launcher = {
    .init = init,
    .deinit = deinit,
};
