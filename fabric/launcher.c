#include <fabric/launcher.h>
#include <stddef.h>
#include <stdlib.h>
#if _WIN32
#include <windows.h>
#else

#endif

static char *getDotMinecraftDirectory(char *path, size_t len) {
  if (path == NULL)
    return NULL;

  path[0] = '\0';
  // TODO: Get path of minecraft folder and store in path
  return path;
}

static int init(void) { return 0; }
static int runTask(void) { return 0; }

InstallDevelopmentVersionTask install_development_version_task = {
    .init = init,
    .runTask = runTask,
};
