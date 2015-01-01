#pragma once

#include "ctemplator/FileStorage.h"
#include "ctemplator/compiler/Tokenizer.h"

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
    compiler::Tokenizer tokenizer_;
};

} // namespace ctemplator
