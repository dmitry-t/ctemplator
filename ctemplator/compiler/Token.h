#pragma once

#include <string>

namespace ctemplator {
namespace compiler {

class Token
{
public:
    Token(std::string name);

    const std::string& name() const;

private:
    std::string name_;
};

} // namespace compiler
} // namespace ctemplator

