#include <iostream>
#include <vector>
#include "OpenGL.h"

#include "../AssetManager.h"

void Engine::OpenGL::Load(GLFWwindow *window) {
    // load OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return;
    }

    // set size of frame buffer
    int32_t width, height;
    glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // create buffer objects
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glEnableVertexAttribArray(0);
}

void Engine::OpenGL::Unload() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    for(auto program : shaderPrograms)
        glDeleteProgram(program);
}

void Engine::OpenGL::PrepFrame() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Engine::OpenGL::Draw(const std::vector<Mesh>& meshes, int32_t instances) {
    for(auto mesh : meshes)
        glDrawElementsInstanced(GL_TRIANGLES, mesh.size, GL_UNSIGNED_INT, (void*)(mesh.startIndex * sizeof(uint32_t)), instances);
}

void Engine::OpenGL::Present() {

}

void Engine::OpenGL::LoadVertices(Vertex* data, int64_t count) {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, count * (int64_t)sizeof(Vertex), data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Math::Vec3), nullptr);
}

void Engine::OpenGL::LoadIndices(uint32_t* data, int64_t count) {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * (int64_t)sizeof(uint32_t), data, GL_STATIC_DRAW);
}


uint32_t Engine::OpenGL::CreateShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    std::string vertexShaderSource = Engine::AssetManager::ReadFile(vertexShaderPath);
    const char* vertexShaderSourceChar = vertexShaderSource.c_str();
    uint32_t vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSourceChar, nullptr);
    glCompileShader(vertexShader);

    std::string fragmentShaderSource = Engine::AssetManager::ReadFile(fragmentShaderPath);
    const char* fragmentShaderSourceChar = fragmentShaderSource.c_str();
    uint32_t fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSourceChar, nullptr);
    glCompileShader(fragmentShader);

    uint32_t shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    shaderPrograms.push_back(shaderProgram);
    return shaderProgram;
}

void Engine::OpenGL::LoadShader(uint32_t shaderProgram) {
    glUseProgram(shaderProgram);
}

void Engine::OpenGL::framebuffer_size_callback(GLFWwindow* window, int32_t width, int32_t height)
{
    glViewport(0, 0, width, height);
}
