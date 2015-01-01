#pragma once

#include "ctemplator/FileStorage.h"
#include "ctemplator/compiler/Parser.h"

#include "Poco/Any.h"

#include <string>

namespace ctemplator {

class Engine
{
public:
    Engine(const std::string& templateStorageRoot);

    std::string render(
            const std::string& templatePath,
            const Poco::Dynamic::Var& vars);

private:
    FileStorage fileStorage_;
    compiler::Parser parser_;
};

} // namespace ctemplator
