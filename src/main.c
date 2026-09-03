#include <fabric/FabricServerLauncher.h>
#include <fabric/FabricServerModDiscovery.h>
#include <stdlib.h>

int main(void) {
  fabric_server_launcher.init();
  get_mods_list("./mods/");
  return EXIT_SUCCESS;
}
