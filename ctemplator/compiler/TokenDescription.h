#pragma once

#include <string>

namespace ctemplator {
namespace compiler {

struct TokenDescription
{
    TokenDescription(
            size_t id,
            std::pair<std::string, std::string> beginAndEnd) :
        id_(id),
        begin_(beginAndEnd.first),
        end_(beginAndEnd.second)
    {
    }

    size_t id_;
    std::string begin_;
    std::string end_;
};

} // namespace compiler
} // namespace ctemplator
