#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <vector>

#include "../Math.h"

namespace Engine {
    PackedStruct Vertex{
        Math::Vec3 pos;
    };

    PackedStruct Mesh{
        uint32_t startIndex;
        int32_t size;
    };

    class Graphics {
    public:
        virtual void Load(GLFWwindow* window) = 0;
        virtual void Unload() = 0;

        virtual void PrepFrame() = 0;
        virtual void Draw(const std::vector<Mesh>& meshes, int32_t instances) = 0;
        virtual void Present() = 0;

        virtual void LoadVertices(Vertex* data, int64_t count) = 0;
        virtual void LoadIndices(uint32_t* data, int64_t count) = 0;

        //virtual void SetUniform() = 0;

        virtual unsigned int CreateShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) = 0;
        virtual void LoadShader(unsigned int shaderProgram) = 0;
    };
}
