#include <fabric/FabricServerLauncher.h>
#include <stdlib.h>

int main(void) {
  fabric_server_launcher.init();
  fabric_server_launcher.deinit();
  return EXIT_SUCCESS;
}
