#pragma once

#include <string>

namespace ctemplator {
namespace compiler {

struct TokenDescription
{
    size_t id_;
    std::string begin_;
    std::string end_;
};

} // namespace compiler
} // namespace ctemplator
