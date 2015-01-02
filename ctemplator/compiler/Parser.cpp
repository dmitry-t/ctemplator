#include "ctemplator/compiler/Parser.h"

#include "ctemplator/compiler/Tokenizer.h"
#include "ctemplator/expr/VariableExpr.h"
#include "ctemplator/nodes/TextNode.h"
#include "ctemplator/nodes/ExprNode.h"

#include <stack>
#include <unordered_set>

namespace ctemplator {
namespace compiler {

using namespace nodes;

namespace {

Node createTextNode(Tokenizer::Token token)
{
    return TextNode(std::move(token.second));
}

Node createExprNode(Tokenizer::Token token)
{
    return ExprNode(expr::VariableExpr(token.second));
}

Node createOpSingleNode(Tokenizer::Token token)
{
    return {};
}

Node createOpBeginNode(Tokenizer::Token token)
{
    return {};
}

} // namespace

Parser::Parser(TokenStrings tokenStrings) :
    tokenStrings_(std::move(tokenStrings))
{
}

nodes::Node Parser::parse(const std::string& text)
{
    Node rootNode;
    std::stack<Node*> nodes;
    Tokenizer tokenizer(text, tokenStrings_);
    Node* node = &rootNode;

    for (;;)
    {
        auto token = tokenizer.nextToken();
        if (token.first == TokenType::EOS)
        {
            break;
        }
        switch (token.first)
        {
        case TokenType::TEXT:
            node->add(createTextNode(std::move(token)));
            break;

        case TokenType::EXPR:
            node->add(createExprNode(std::move(token)));
            break;

        case TokenType::OP_SINGLE:
            node->add(createOpSingleNode(std::move(token)));
            break;

        case TokenType::OP_BEGIN:
            node->add(createOpBeginNode(std::move(token)));
            break;

        case TokenType::OP_END:
            if (nodes.empty())
            {
                throw std::runtime_error("Unbalanced operator");
            }
            nodes.pop();
            break;
        }
    }
    return rootNode;
}

} // namespace compiler
} // namespace ctemplator
