#pragma once

#include "ctemplator/nodes/Node.h"
#include "ctemplator/compiler/TokenStrings.h"

#include <memory>

namespace ctemplator {
namespace compiler {

class Parser
{
public:
    Parser(TokenStrings tokenStrings = TokenStrings());

    nodes::Node parse(const std::string& text);

private:
    TokenStrings tokenStrings_;
};

} // namespace compiler
} // namespace ctemplator
