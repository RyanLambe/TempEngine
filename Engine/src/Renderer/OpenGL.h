#pragma once

#include <glad/glad.h>
#include "Graphics.h"

namespace Engine {
    class OpenGL : public Graphics {
    public:
        void Load(GLFWwindow* window) override;
        void Unload() override;

        void PrepFrame() override;
        void Draw(const std::vector<Mesh>& meshes, int32_t instances) override;
        void Present() override;

        void LoadVertices(Vertex* data, int64_t count) override;
        void LoadIndices(uint32_t* data, int64_t count) override;

        unsigned int CreateShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) override;
        void LoadShader(unsigned int shaderProgram) override;

    private:

        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;

        std::vector<unsigned int> shaderPrograms;

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    };
}
