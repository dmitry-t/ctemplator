#pragma once

#include "ctemplator/FileStorage.h"
#include "ctemplator/compiler/Parser.h"
#include "ctemplator/nodes/Node.h"
#include "ctemplator/vars/Var.h"
#include "ctemplator/utils/LRUCache.h"

#include <string>
#include <unordered_map>

namespace ctemplator {

class Engine
{
public:
    Engine(const std::string& templateStorageRoot);

    std::string render(
            const std::string& templatePath,
            const vars::Var& vars);

private:
    FileStorage fileStorage_;
    compiler::Parser parser_;
    LRUCache<std::string, nodes::Node, 20> cache_;
};

} // namespace ctemplator
