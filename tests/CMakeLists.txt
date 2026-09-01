# Tests
include(CTest)
if (BUILD_TESTING)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

    add_executable(
        ${PROJECT_NAME}_test
        src/main.c
        src/test_java_abi.c
    )

    find_package (Java REQUIRED)
    find_package (JNI REQUIRED)
    include (UseJava)

    target_include_directories (
         ${PROJECT_NAME}_test PRIVATE
         ${CMAKE_CURRENT_BINARY_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}
         ${CMAKE_CURRENT_SOURCE_DIR}/src/
         ${JNI_INCLUDE_DIRS}
    )

    target_link_libraries (${PROJECT_NAME}_test ${JAVA_JVM_LIBRARY})

    add_jar (bridge_test src/Test.java)

    add_dependencies(${PROJECT_NAME}_test bridge_test)


    add_test(
        NAME json_serialization
        COMMAND ${PROJECT_NAME}_test test_json_serialization
    )
    add_test(
        NAME java_abi
        COMMAND ${PROJECT_NAME}_test test_java_abi
    )

    add_custom_target(run_tests ALL)
    add_custom_command(
       TARGET run_tests
       POST_BUILD
       COMMAND ${CMAKE_CTEST_COMMAND} --test-dir "${CMAKE_BINARY_DIR}/tests/"
       --output-on-failure
       COMMENT
       "Automatically running test suite via CTest..."
    )
    add_dependencies(run_tests ${PROJECT_NAME}_test)


    include_directories(
      QUOTE
      ${PROJECT_SOURCE_DIR}/include/
      ${CMAKE_CURRENT_BINARY_DIR}
    )
endif()


