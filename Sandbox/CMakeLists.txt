cmake_minimum_required(VERSION 3.5)
project(Sandbox)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# dont show console if in release mode
IF(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "-mwindows")
ENDIF()

add_executable(Sandbox src/main.cpp)

include_directories(Sandbox ../Engine/src)
target_link_libraries(Sandbox Engine)