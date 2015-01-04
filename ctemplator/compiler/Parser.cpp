#include "ctemplator/compiler/Parser.h"

#include "ctemplator/compiler/TokenDescription.h"
#include "ctemplator/compiler/Tokenizer.h"
#include "ctemplator/expr/VariableExpr.h"
#include "ctemplator/nodes/ExprNode.h"
#include "ctemplator/nodes/TextNode.h"
#include "ctemplator/nodes/IfNode.h"

#include <algorithm>
#include <unordered_set>

namespace ctemplator {
namespace compiler {

using namespace nodes;

namespace {

enum Lexeme
{
    EOS = Tokenizer::EOS,
    TEXT = Tokenizer::TEXT,
    EXPR,
    IF,
    ELSE,
    ENDIF,
};

} // namespace

Parser::Parser(TokenStrings tokenStrings) :
    tokenStrings_(std::move(tokenStrings))
{
}

Node parseIf(Tokenizer& tokenizer, std::string ifExpr);

bool valueInList(size_t value, std::initializer_list<size_t>& list)
{
    return std::find(list.begin(), list.end(), value) != list.end();
}

size_t parseUntil(
        Tokenizer& tokenizer,
        std::initializer_list<size_t> tokenIds,
        Node& parent)
{
    size_t tokenId = EOS;
    for (;;)
    {
        auto token = tokenizer.nextToken();
        tokenId = token.first;
        if (tokenId == EOS || valueInList(tokenId, tokenIds))
        {
            break;
        }
        switch (tokenId)
        {
        case TEXT:
            parent.add(TextNode(std::move(token.second)));
            break;

        case EXPR:
            parent.add(ExprNode(expr::VariableExpr(token.second)));
            break;

        case IF:
            parent.add(parseIf(tokenizer, token.second));
            break;

        case ELSE:
            throw std::runtime_error("Unexpected 'else' clause");
            break;

        case ENDIF:
            throw std::runtime_error("Unexpected 'endif' clause");
            break;
        }
    }
    return tokenId;
}

Node parseIf(Tokenizer& tokenizer, std::string ifExpr)
{
    IfNode ifNode(expr::VariableExpr(std::move(ifExpr)));
    Node trueNode;
    size_t tokenId = parseUntil(tokenizer, {ELSE, ENDIF}, trueNode);
    ifNode.setTrue(std::move(trueNode));
    if (tokenId == ELSE)
    {
        Node falseNode;
        parseUntil(tokenizer, {ENDIF}, falseNode);
        ifNode.setFalse(std::move(falseNode));
    }
    return ifNode;
}


nodes::Node Parser::parse(const std::string& text)
{
    std::vector<TokenDescription> tokens {
        { EXPR, "{", "}" },
        { IF, "<#if ", ">" },
        { ELSE, "<#else", "/>" },
        { ENDIF, "</#if>" },
    };
    Tokenizer tokenizer(text, tokens);
    Node rootNode;
    parseUntil(tokenizer, {}, rootNode);
    return rootNode;
}

} // namespace compiler
} // namespace ctemplator
