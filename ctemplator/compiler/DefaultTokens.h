#pragma once

namespace ctemplator {
namespace compiler {

class DefaultTokens
{
public:
    DefaultTokens() :
        tokens_({
            {"{", TokenType::OPEN, Lexeme::VALUE},
            {"}", TokenType::CLOSE, Lexeme::VALUE},
        })
    {
    }

    std::vector<Token> get() const
    {
        return tokens_;
    }

private:
    std::vector<Token> tokens_;
};

} // namespace compiler
} // namespace ctemplator
