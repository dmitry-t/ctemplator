#include "ctemplator/FileStorage.h"

#include <fstream>
#include <stdexcept>

namespace ctemplator {

FileStorage::FileStorage(Path storageRoot) :
    storageRoot_(std::move(storageRoot))
{
}

std::string FileStorage::readFileContent(const std::string& relativePath)
{
    std::string content;

    std::string path = (storageRoot_ + relativePath).string();
    std::ifstream stream(
            path,
            std::ifstream::in | std::ifstream::binary);
    if (!stream)
    {
        throw std::runtime_error("Cannot read file");
    }
    stream.seekg(0, std::ifstream::end);
    content.resize(stream.tellg());
    stream.seekg(0, std::ifstream::beg);
    stream.read(const_cast<char*>(content.data()), content.size());

    return content;
}

} // namespace ctemplator
