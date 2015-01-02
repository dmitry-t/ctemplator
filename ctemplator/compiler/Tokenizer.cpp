#include "ctemplator/compiler/Tokenizer.h"

#include <string>
#include <stdexcept>

namespace ctemplator {
namespace compiler {

Tokenizer::Tokenizer(std::string text, TokenStrings tokenStrings) :
    text_(std::move(text)),
    tokens_({
        { TokenType::EXPR, tokenStrings.expression },
        { TokenType::OP_SINGLE, tokenStrings.operatorSingle },
        { TokenType::OP_BEGIN, tokenStrings.operatorBegin },
        { TokenType::OP_END, tokenStrings.operatorEnd },
    }),
    cursor_(0)
{
}

Tokenizer::Token Tokenizer::nextToken()
{
    if (cursor_ == text_.size())
    {
        return { TokenType::EOS, "" };
    }
    std::pair<TokenType, TokenStrings::TokenInfo>* found = nullptr;
    size_t tokenBegin = text_.size();
    for (auto& token : tokens_)
    {
        size_t pos = text_.find(token.second.first, cursor_);
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
            TokenType::TEXT,
            text_.substr(cursor_, tokenBegin - cursor_)
        };
        cursor_ = tokenBegin;
        return token;
    }
    size_t tokenEnd = text_.find(
            found->second.second,
            tokenBegin + found->second.first.size() + 1);
    if (tokenEnd == std::string::npos)
    {
        throw std::runtime_error("Unclosed token");
    }
    Token token {
        found->first,
        text_.substr(
                tokenBegin + found->second.first.size(),
                tokenEnd - tokenBegin - 1)
    };
    cursor_ = tokenEnd + found->second.second.size();
    return token;
}

} // namespace compiler
} // namespace ctemplator
