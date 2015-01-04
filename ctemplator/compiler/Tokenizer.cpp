#include "ctemplator/compiler/Tokenizer.h"

#include <algorithm>
#include <stdexcept>
#include <string>

namespace ctemplator {
namespace compiler {

Tokenizer::Tokenizer(std::string text, std::vector<TokenDescription> tokens) :
    text_(std::move(text)),
    tokens_(tokens),
    cursor_(0)
{
}

Tokenizer::Token Tokenizer::nextToken()
{
    if (cursor_ == text_.size())
    {
        return { EOS, "" };
    }
    TokenDescription* found = nullptr;
    size_t tokenBegin = text_.size();
    for (auto& token : tokens_)
    {
        size_t pos = text_.find(token.begin_, cursor_);
        if (pos == std::string::npos)
        {
            continue;
        }
        if (pos >= tokenBegin)
        {
            continue;
        }
        if (pos == cursor_)
        {
            found = &token;
        }
        tokenBegin = pos;
    }
    if (!found)
    {
        Token token {
            TEXT,
            text_.substr(cursor_, tokenBegin - cursor_)
        };
        cursor_ = tokenBegin;
        return token;
    }
    if (found->end_.empty())
    {
        cursor_ = tokenBegin + found->begin_.size();
        return { found->id_, "" };
    }
    size_t tokenEnd = text_.find(
            found->end_,
            tokenBegin + found->begin_.size());
    if (tokenEnd == std::string::npos)
    {
        throw std::runtime_error("Unclosed token");
    }
    Token token {
        found->id_,
        text_.substr(
                tokenBegin + found->begin_.size(),
                tokenEnd - tokenBegin - found->begin_.size())
    };
    cursor_ = tokenEnd + found->end_.size();
    return token;
}

} // namespace compiler
} // namespace ctemplator
