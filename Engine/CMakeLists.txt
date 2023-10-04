cmake_minimum_required(VERSION 3.5)

set(GLFWPath "C:/Dev/GLFW")
set(GLADPath "C:/Dev/GLAD")

# create Engine dll
project(Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_BUILD_TYPE})

add_library(Engine SHARED ${GLADPath}/glad.c src/Renderer/Window.cpp src/Renderer/Window.h
        src/Renderer/Renderer.cpp
        src/Renderer/Renderer.h
        src/Renderer/Graphics.h
        src/Renderer/OpenGL.cpp
        src/Renderer/OpenGL.h
        src/AssetManager.cpp
        src/AssetManager.h
        src/Math.h)

# Add GLFW
list(APPEND CMAKE_PREFIX_PATH ${GLFWPath})
find_library(glfw NAMES glfw3 REQUIRED)
target_link_libraries(${PROJECT_NAME} ${glfw})
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFWPath})

# Add GLAD
target_include_directories(${PROJECT_NAME} PUBLIC ${GLADPath})