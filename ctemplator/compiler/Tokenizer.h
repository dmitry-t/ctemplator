#pragma once

#include "ctemplator/compiler/Token.h"

#include <vector>

namespace ctemplator {
namespace compiler {

class Tokenizer
{
public:
    Tokenizer(std::vector<Token> tokens);

    void tokenize(const std::string& templateString);

private:
    std::vector<Token> tokens_;
};

} // namespace compiler
} // namespace ctemplator
