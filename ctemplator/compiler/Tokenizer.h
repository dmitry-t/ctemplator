#pragma once

#include "ctemplator/compiler/TokenStrings.h"
#include "ctemplator/compiler/TokenType.h"

#include <string>
#include <vector>

namespace ctemplator {
namespace compiler {

class Tokenizer
{
public:
    typedef std::pair<TokenType, std::string> Token;

    Tokenizer(std::string text, TokenStrings tokenStrings);

    Token nextToken();

private:
    bool find(const TokenStrings::TokenInfo& token, size_t& begin);

    std::string text_;
    std::vector<std::pair<TokenType, TokenStrings::TokenInfo>> tokens_;
    size_t cursor_;
};

} // namespace compiler
} // namespace ctemplator
