#include <string>

#include "ctemplator/compiler/Tokenizer.h"

namespace ctemplator {
namespace compiler {

Tokenizer::Tokenizer(std::vector<Token> tokens) :
    tokens_(std::move(tokens))
{
}

void Tokenizer::tokenize(const std::string& templateString)
{
    size_t cursor = 0;
    for (auto& token : tokens_)
    {
        size_t tokenPos = templateString.find(token.value_, cursor);
        if (tokenPos == std::string::npos)
        {
            continue;
        }


    }
}


} // namespace compiler
} // namespace ctemplator
