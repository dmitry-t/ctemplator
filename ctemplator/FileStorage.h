#pragma once

#include "ctemplator/Path.h"

#include <string>

namespace ctemplator {

class FileStorage
{
public:
    FileStorage(Path storageRoot);

    std::string readFileContent(const std::string& relativePath);

private:
    Path storageRoot_;
};

} // namespace ctemplator
