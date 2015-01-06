#include "ctemplator/compiler/Parser.h"

#include "ctemplator/compiler/TokenDescription.h"
#include "ctemplator/compiler/Tokenizer.h"
#include "ctemplator/expr/VariableExpr.h"
#include "ctemplator/nodes/ExprNode.h"
#include "ctemplator/nodes/ForNode.h"
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
    FOR,
    ENDFOR,
};

bool valueInList(size_t value, std::initializer_list<size_t>& list)
{
    return std::find(list.begin(), list.end(), value) != list.end();
}

} // namespace

Parser::Parser(TokenStrings tokens) :
    tokens_(std::move(tokens))
{
}

nodes::Node Parser::parse(const std::string& text)
{
    std::vector<TokenDescription> tokens {
        { EXPR, tokens_.expression_ },
        { IF, tokens_.if_ },
        { ELSE, tokens_.else_ },
        { ENDIF, tokens_.ifEnd_ },
        { FOR, tokens_.for_ },
        { ENDFOR, tokens_.forEnd_ },
    };
    Tokenizer tokenizer(text, tokens);
    Node rootNode;
    parseUntil(tokenizer, {}, rootNode);
    return rootNode;
}

size_t Parser::parseUntil(
        Tokenizer& tokenizer,
        std::initializer_list<size_t> tokenIds,
        Node& parent)
{
    Lexeme tokenId = EOS;
    for (;;)
    {
        auto token = tokenizer.nextToken();
        tokenId = static_cast<Lexeme>(token.first);
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

        case FOR:
            parent.add(parseFor(tokenizer, token.second));
            break;

        case ENDFOR:
            throw std::runtime_error("Unexpected 'endfor' clause");
            break;
        }
    }
    return tokenId;
}


Node Parser::parseIf(Tokenizer& tokenizer, std::string expr)
{
    IfNode ifNode(expr::VariableExpr(std::move(expr)));
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

Node Parser::parseFor(
        Tokenizer& tokenizer,
        const std::string& expr)
{
    // expr = "var in list"
    auto& in = tokens_.forIn_.first;
    auto inPos = expr.find(in);
    if (inPos < 2 ||
            expr.size() - in.size() - in.size() < 2 ||
            expr[inPos - 1] != ' ' ||
            expr[inPos + in.size()] != ' ')
    {
        throw std::runtime_error("Bad for expression");
    }
    ForNode forNode(
        expr.substr(0, inPos - 1),
        expr.substr(inPos + in.size() + 1));
    Node forRoutine;
    parseUntil(tokenizer, {ENDFOR}, forRoutine);
    forNode.setRoutine(std::move(forRoutine));
    return forNode;
}

} // namespace compiler
} // namespace ctemplator
