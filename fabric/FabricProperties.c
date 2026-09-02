#include <fabric/FabricProperties.h>
#include <stdbool.h>

// NOTE: On pumpkin the server.properties is pumpkin.toml

static bool fabric_in_developer_mode(void) {
  //
  return false;
}

FabricProperties fabric_properties = {
    .is_dev_mode = fabric_in_developer_mode,
};
