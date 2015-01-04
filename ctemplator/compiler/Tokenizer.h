#pragma once

#include "ctemplator/compiler/TokenDescription.h"
#include "ctemplator/compiler/TokenStrings.h"

#include <string>
#include <vector>

namespace ctemplator {
namespace compiler {

class Tokenizer
{
public:
    enum PredefinedTokenIds
    {
        EOS = 0,
        TEXT = 1,
    };

    typedef std::pair<size_t, std::string> Token;

    Tokenizer(std::string text, std::vector<TokenDescription> tokens);

    Token nextToken();

private:
    std::string text_;
    std::vector<TokenDescription> tokens_;
    size_t cursor_;
};

} // namespace compiler
} // namespace ctemplator
