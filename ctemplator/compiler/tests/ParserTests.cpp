#include "ctemplator/compiler/Parser.h"

#include "ctemplator/expr/VariableExpr.h"
#include "ctemplator/nodes/IfNode.h"
#include "ctemplator/nodes/ExprNode.h"
#include "ctemplator/nodes/ListNode.h"
#include "ctemplator/nodes/TextNode.h"

#include <gtest/gtest.h>

namespace ctemplator {
namespace compiler {
namespace tests {

using namespace expr;
using namespace nodes;

TEST(compiler_Parser, emptyContent)
{
    Parser parser;
    ASSERT_EQ(Node(), parser.parse(""));
}

TEST(compiler_Parser, textOnly)
{
    Parser parser;
    ASSERT_EQ(Node(TextNode("abc")), parser.parse("abc"));
}

TEST(compiler_Parser, exprOnly)
{
    Parser parser;
    ASSERT_EQ(Node(ExprNode(VariableExpr("abc"))), parser.parse("{abc}"));
}

TEST(compiler_Parser, textAndExpr)
{
    Parser parser;
    ASSERT_EQ(
            Node(ListNode()
                    .add(TextNode("abc"))
                    .add(ExprNode(VariableExpr("ABC")))),
            parser.parse("abc{ABC}"));
}

TEST(compiler_Parser, unexpectedEndifCausesException)
{
    Parser parser;
    ASSERT_THROW(parser.parse("</#if>"), std::runtime_error);
}

TEST(compiler_Parser, emptyIfWithoutElseOperator)
{
    Parser parser;
    ASSERT_EQ(
            Node(IfNode(Expression(VariableExpr("expr")))),
            parser.parse("<#if expr></#if>"));
}

TEST(compiler_Parser, ifWithoutElseOperator)
{
    Parser parser;
    ASSERT_EQ(
            Node(IfNode(Expression(VariableExpr("expr")))
                    .setTrue(Node(TextNode("abc")))),
            parser.parse("<#if expr>abc</#if>"));
}

TEST(compiler_Parser, unexpectedElseCausesException)
{
    Parser parser;
    ASSERT_THROW(parser.parse("<#else/>"), std::runtime_error);
}

TEST(compiler_Parser, ifWithEmptyElseOperator)
{
    Parser parser;
    ASSERT_EQ(
            Node(IfNode(Expression(VariableExpr("expr")))
                    .setTrue(Node(TextNode("abc")))),
            parser.parse("<#if expr>abc<#else/></#if>"));
}

TEST(compiler_Parser, ifWithElseOperator)
{
    Parser parser;
    ASSERT_EQ(
            Node(IfNode(Expression(VariableExpr("expr")))
                    .setTrue(TextNode("abc"))
                    .setFalse(TextNode("ABC"))),
            parser.parse("<#if expr>abc<#else/>ABC</#if>"));
}

} // namespace tests
} // namespace compiler
} // namespace ctemplator
