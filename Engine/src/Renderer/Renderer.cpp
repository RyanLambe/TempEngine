// must be included before Renderer.h
#include "OpenGL.h"
Engine::OpenGL openGl;

#include "Renderer.h"

Engine::Vertex vertices[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
};

uint32_t indices[] = {
        0, 1, 3,
        1, 2, 3
};

Engine::Renderer::Renderer(const std::string& title, int windowWidth, int windowHeight) : window(title, windowWidth, windowHeight){
    graphics = &openGl;

    graphics->Load(window.getGLFWWindow());

    unsigned int shaderProgram = graphics->CreateShader("../../Engine/shaders/first.vert", "../../Engine/shaders/first.frag");
    graphics->LoadShader(shaderProgram);

    graphics->LoadVertices(vertices, sizeof(vertices) / sizeof(Vertex));
    graphics->LoadIndices(indices, sizeof(indices) / sizeof(uint32_t));
}

Engine::Renderer::~Renderer() {
    graphics->Unload();
}

bool Engine::Renderer::Render() {
    if(window.ShouldClose())
        return false;

    graphics->PrepFrame();

    std::vector<Mesh> meshes;

    // start at index 6, for 6 indices
    meshes.push_back({0, 6});

    graphics->Draw(meshes, 1);

    window.Update();

    return true;
}