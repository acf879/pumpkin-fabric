#include <fabric/loader.h>
#include <jni.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#if _WIN32
#include <windows.h>
#else

#endif

static int init(void) {
  //
  return 0;
}

static int deinit(void) {
  //
  return 0;
}

Loader loader = {
    .init = init,
    .deinit = deinit,
};
