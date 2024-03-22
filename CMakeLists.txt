cmake_minimum_required(VERSION 3.16)
project(Plugin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG -w")

set(CDIR ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CDIR}/lib)
add_compile_definitions("CANLIB_PARKING=")
add_compile_definitions(CANLIB_TIMESTAMP)

file(GLOB_RECURSE plugin_src ${CDIR}/plugin/*.cpp)
add_library(
    ${PROJECT_NAME}
    ${plugin_src}
)
