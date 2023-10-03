cmake_minimum_required(VERSION 3.5)

set(GLFWPath "C:/Dev/GLFW")
set(GLADPath "C:/Dev/GLAD")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})

project(Engine)
set(CMAKE_CXX_STANDARD 17)

add_library(Engine SHARED src/Window.cpp src/Window.h)

# Add GLFW
list(APPEND CMAKE_PREFIX_PATH ${GLFWPath})
find_library(glfw NAMES glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} ${glfw})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFWPath})

# todo: Add GLAD