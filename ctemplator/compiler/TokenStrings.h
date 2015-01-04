#pragma once

#include <string>
#include <utility>

namespace ctemplator {
namespace compiler {

struct TokenStrings
{
    typedef std::pair<std::string, std::string> TokenParts;
    TokenParts expression_ = { "{", "}" };
    TokenParts if_ = { "<#if", ">" };
    TokenParts else_ = { "<#else", "/>" };
    TokenParts endif_ = { "</#if", ">" };
};

} // namespace compiler
} // namespace ctemplator
