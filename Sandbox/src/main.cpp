#include <iostream>
#include <Window.h>

int main() {
    std::cout << "Hello World\n";

    Engine::Window window("Hello Window", 1280, 720);

    while(window.Update());

    return 0;
}