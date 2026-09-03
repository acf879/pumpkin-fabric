#ifndef FABRIC_SERVER_LAUNCHER_H_
#define FABRIC_SERVER_LAUNCHER_H_

#if __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct {
  int (*init)(void);
} FabricServerLauncher;

extern FabricServerLauncher fabric_server_launcher;

#if __cplusplus
}
#endif
#endif
