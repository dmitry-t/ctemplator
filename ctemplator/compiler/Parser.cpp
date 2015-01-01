#include "ctemplator/compiler/Parser.h"

namespace ctemplator {
namespace compiler {

using nodes::Node;

std::unique_ptr<Node> Parser::parse(const std::string& text)
{
    Tokenizer tokenizer(text, {
                {"{", TokenType::OPEN, Lexeme::VALUE},
                {"}", TokenType::CLOSE, Lexeme::VALUE},
            });
    auto tokenValue = tokenizer.nextToken();
    return nullptr;
}



} // namespace compiler
} // namespace ctemplator
