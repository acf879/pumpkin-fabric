#ifndef FABRIC_PROPERTIES_H_
#define FABRIC_PROPERTIES_H_

#if __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct {
  bool (*is_dev_mode)(void);
} FabricProperties;

extern FabricProperties fabric_properties;

#if __cplusplus
}
#endif
#endif
