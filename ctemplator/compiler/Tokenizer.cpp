#include <string>

#include "ctemplator/compiler/Tokenizer.h"

namespace ctemplator {
namespace compiler {

Tokenizer::Tokenizer(std::string text, std::vector<Token> tokens) :
    text_(std::move(text)), tokens_(std::move(tokens))
{
}

std::pair<Token, std::string> Tokenizer::nextToken()
{
    size_t cursor = 0;
    for (auto& token : tokens_)
    {
        size_t tokenPos = text_.find(token.value_, cursor);
        if (tokenPos == std::string::npos)
        {
            continue;
        }
    }
    return {tokens_[0], ""};
}


} // namespace compiler
} // namespace ctemplator
