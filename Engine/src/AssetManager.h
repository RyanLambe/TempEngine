#pragma once

#include <string>

namespace Engine {
    class AssetManager {
    public:
        static std::string ReadFile(const std::string& filePath);
    };
}
