#pragma once

#define DLLExport __declspec(dllexport)

#include <string>
#include <GLFW/glfw3.h>

namespace Engine {
    class Window {
    public:
        DLLExport Window(const std::string& title, int width, int height);
        DLLExport ~Window();

        DLLExport bool Update();

    private:
        GLFWwindow* window = nullptr;
    };
}
