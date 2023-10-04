#include <iostream>
#include "Window.h"

Engine::Window::Window(const std::string& title, int width, int height) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if(!window){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
}

Engine::Window::~Window() {
    if(window)
        glfwDestroyWindow(window);
    glfwTerminate();
}

void Engine:: Window::Update() {

    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Engine::Window::ShouldClose() {
    return glfwWindowShouldClose(window);
}

GLFWwindow *Engine::Window::getGLFWWindow() {
    return window;
}