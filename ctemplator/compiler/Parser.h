#pragma once

#include "ctemplator/nodes/Node.h"
#include "ctemplator/compiler/TokenStrings.h"

#include <initializer_list>
#include <memory>

namespace ctemplator {
namespace compiler {

class Tokenizer;

} // namespace compiler
} // namespace ctemplator

namespace ctemplator {
namespace compiler {

class Parser
{
public:
    Parser(TokenStrings tokens = TokenStrings());

    nodes::Node parse(const std::string& text);

private:
    size_t parseUntil(
            Tokenizer& tokenizer,
            std::initializer_list<size_t> tokenIds,
            nodes::Node& parent);
    nodes::Node parseIf(Tokenizer& tokenizer, std::string expr);
    nodes::Node parseFor(
            Tokenizer& tokenizer,
            const std::string& expr);

    const TokenStrings tokens_;
};

} // namespace compiler
} // namespace ctemplator
