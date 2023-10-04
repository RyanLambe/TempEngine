#include "AssetManager.h"
#include <fstream>
#include <vector>

std::string Engine::AssetManager::ReadFile(const std::string& filePath) {
    std::ifstream file{filePath, std::ios::ate | std::ios::binary};
    if (!file.is_open())
        return {};
    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize);
    file.seekg(0);
    file.read(buffer.data(), (long long)fileSize);
    file.close();
    return std::string(buffer.begin(), buffer.end());
}
