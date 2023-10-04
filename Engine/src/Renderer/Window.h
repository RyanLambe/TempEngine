#pragma once



#include <string>
#include <GLFW/glfw3.h>

namespace Engine {
    class Window {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        void Update();
        bool ShouldClose();

        GLFWwindow* getGLFWWindow();

    private:
        GLFWwindow* window = nullptr;
    };
}
