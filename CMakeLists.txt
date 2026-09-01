cmake_minimum_required(VERSION 4.0)
project(pumpkin-fabric-exe)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_compile_options(
    -O2
    -fanalyzer
    -Wall
    -Wextra
    -Wpedantic
)

add_subdirectory(fabric)
add_subdirectory(tests)

add_executable(
    ${PROJECT_NAME}
    src/main.c
)

target_link_libraries(
  ${PROJECT_NAME}
  pumpkin-fabric
)

include_directories(
  QUOTE
  ${PROJECT_SOURCE_DIR}/include/
  ${CMAKE_CURRENT_BINARY_DIR}
)

# Rather than using the -flto link and compile flag,
# this will handle cross platform automatically
include(CheckIPOSupported)
check_ipo_supported(RESULT result OUTPUT error)
if(result)
    set_target_properties(${PROJECT_NAME}
    PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(WARNING "IPO/LTO is not supported: ${error}")
endif()

