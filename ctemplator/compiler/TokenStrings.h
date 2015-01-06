#pragma once

#include <string>
#include <utility>

namespace ctemplator {
namespace compiler {

struct TokenStrings
{
    typedef std::pair<std::string, std::string> TokenParts;
    TokenParts expression_ = { "{", "}" };
    TokenParts if_ = { "<#if ", ">" }; // <#if expr>
    TokenParts else_ = { "<#else/>", "" };
    TokenParts ifEnd_ = { "</#if>", "" };
    TokenParts for_ = { "<#for ", ">" };
    TokenParts forIn_ = { "in" , "" }; // <#for i in list>
    TokenParts forEnd_ = { "</#for>", "" };
};

} // namespace compiler
} // namespace ctemplator
