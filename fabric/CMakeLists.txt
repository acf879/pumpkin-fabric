find_package (Java REQUIRED)
find_package (JNI REQUIRED)
include (UseJava)

target_include_directories (
 ${PROJECT_NAME} PRIVATE
 ${CMAKE_CURRENT_BINARY_DIR}
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${JNI_INCLUDE_DIRS}
)

target_sources(
  ${PROJECT_NAME} PRIVATE
  loader.c
)

target_link_libraries (${PROJECT_NAME} ${JAVA_JVM_LIBRARY})

add_jar (bridge Test.java)

add_dependencies(${PROJECT_NAME} bridge)
