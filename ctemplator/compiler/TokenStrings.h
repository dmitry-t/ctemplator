#pragma once

#include <string>
#include <utility>

namespace ctemplator {
namespace compiler {

struct TokenStrings
{
    typedef std::pair<std::string, std::string> TokenInfo;
    TokenInfo expression = { "{", "}" }; // TokenType::EXPR
    TokenInfo operatorSingle = { "<#", "/>" }; // TokenType::OP_SINGLE
    TokenInfo operatorBegin = { "<#", ">" }; // TokenType::OP_BEGIN
    TokenInfo operatorEnd = { "</#", ">" }; // TokenType::OP_END
};

} // namespace compiler
} // namespace ctemplator
