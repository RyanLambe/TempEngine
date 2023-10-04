#pragma once

#include "Window.h"
#include "Graphics.h"

#define DLLExport __declspec(dllexport)

namespace Engine{
    class Renderer {
    public:
        DLLExport Renderer(const std::string& title, int windowWidth, int windowHeight);
        DLLExport ~Renderer();

        DLLExport bool Render();

    private:
        Window window;
        Graphics* graphics;
    };
}