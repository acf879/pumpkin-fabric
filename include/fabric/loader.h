#ifndef LOADER_H_
#define LOADER_H_

#include <stdlib.h>

#if __cplusplus
extern "C" {
#endif

typedef struct {
  int (*init)(void);
  int (*deinit)(void);
} Loader;

extern Loader loader;

#if __cplusplus
}
#endif
#endif
