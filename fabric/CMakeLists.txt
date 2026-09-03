cmake_minimum_required(VERSION 4.0)
project(fabric)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER "gcc")

add_library(
  ${PROJECT_NAME} SHARED
  FabricServerLauncher.c
  FabricServerModDiscovery.c
)

find_package (Java REQUIRED)
find_package (JNI REQUIRED)
include (UseJava)

include_directories (
   QUOTE
   ${CMAKE_CURRENT_BINARY_DIR}
   ${CMAKE_CURRENT_SOURCE_DIR}
   ${JNI_INCLUDE_DIRS}
   ${PROJECT_SOURCE_DIR}/../include/
)

target_link_libraries (${PROJECT_NAME} ${JAVA_JVM_LIBRARY})
