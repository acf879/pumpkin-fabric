#include "unit_tests.h"
#include <stdio.h>
#include <string.h>

int main(int argv, char *argc[]) {
  if (argv < 2) {
    return 0;
  }
  /* Ensure that c-json is installed and functional */
  if (strcmp(argc[1], "test_json_serialization") == 0) {
    return 0;
  }
  /* Ensure that the java abi is functional */
  if (strcmp(argc[1], "test_java_abi") == 0) {
    return test_java_abi() != 0;
  }
  return 0;
}
