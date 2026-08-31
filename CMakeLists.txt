cmake_minimum_required(VERSION 3.20.0)
project(pumpkinmc-fabric)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_compile_options(
    -O2
    -fanalyzer
    -Wall
    -Wextra
    -Wpedantic
    -ffunction-sections
    -fdata-sections
)

add_link_options(
    -Wl,--gc-sections
)

# Debug mode
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -fanalyzer -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address")

# Release mode
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Os -fno-asynchronous-unwind-tables -fno-ident")

# Previous linker flags
#set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wl,--strip-all")

# After adding more
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wl,--strip-all -Wl,-z,-Wl,--build-id=none")

# Suggested that causes issues with the current binary due to mbedtks dynamic linking
# set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -static -Wl,--strip-all -Wl,-z,norelro -Wl,--build-id=none")

add_executable(
    ${PROJECT_NAME}
    src/main.c
)

add_subdirectory(fabric)

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

