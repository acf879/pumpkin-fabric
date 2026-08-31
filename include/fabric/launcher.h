#ifndef LAUNCHER_H_
#define LAUNCHER_H_

#include <stdlib.h>

#if __cplusplus
extern "C" {
#endif

typedef struct {
  int (*init)(void);
  int (*runTask)(void);

} InstallDevelopmentVersionTask;

extern InstallDevelopmentVersionTask install_development_version_task;

#if __cplusplus
}
#endif

#endif
