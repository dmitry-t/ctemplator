#pragma once

#include "ctemplator/compiler/Token.h"

#include <string>
#include <vector>

namespace ctemplator {
namespace compiler {

class Tokenizer
{
public:
    Tokenizer(std::string text, std::vector<Token> tokens);

    std::pair<Token, std::string> nextToken();

private:
    std::string text_;
    std::vector<Token> tokens_;
};

} // namespace compiler
} // namespace ctemplator
