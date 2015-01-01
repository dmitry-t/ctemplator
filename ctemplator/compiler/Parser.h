#pragma once

#include "ctemplator/compiler/Token.h"
#include "ctemplator/compiler/Tokenizer.h"
#include "ctemplator/nodes/Node.h"

#include <memory>

namespace ctemplator {
namespace compiler {

class Parser
{
public:
    std::unique_ptr<nodes::Node> parse(const std::string& text);
};

} // namespace compiler
} // namespace ctemplator
