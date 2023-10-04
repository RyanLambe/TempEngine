#include <iostream>

#include "Renderer/Renderer.h"

int main() {
    std::cout << "Hello World\n";

    Engine::Renderer renderer("Hello Window", 1280, 720);

    while(renderer.Render());

    return 0;
}