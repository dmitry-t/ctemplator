#include "ctemplator/compiler/Token.h"

namespace ctemplator {
namespace compiler {

Token::Token(std::string name) :
    name_(std::move(name))
{
}

const std::string& Token::name() const
{
    return name_;
}

} // namespace compiler
} // namespace ctemplator
