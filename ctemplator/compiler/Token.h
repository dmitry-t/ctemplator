#pragma once

#include <string>

#include "ctemplator/compiler/Lexeme.h"
#include "ctemplator/compiler/TokenType.h"

namespace ctemplator {
namespace compiler {

class Token
{
public:
    Token(std::string value, TokenType type, Lexeme lexeme);

    std::string value_;
    TokenType type_;
    Lexeme lexeme_;
};

} // namespace compiler
} // namespace ctemplator
