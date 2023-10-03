#include "Window.h"

Engine::Window::Window(const std::string& title, int width, int height) {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
}

Engine::Window::~Window() {
    if(window)
        glfwDestroyWindow(window);
    glfwTerminate();
}

bool Engine:: Window::Update() {
    glfwPollEvents();
    return !glfwWindowShouldClose(window);
}