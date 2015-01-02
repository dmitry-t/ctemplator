#include "ctemplator/compiler/Parser.h"
#include "ctemplator/nodes/ListNode.h"
#include "ctemplator/nodes/TextNode.h"
#include "ctemplator/nodes/ExprNode.h"

#include "gtest/gtest.h"

namespace ctemplator {
namespace compiler {
namespace tests {

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
    ASSERT_EQ(Node(ExprNode("abc")), parser.parse("{abc}"));
}

TEST(compiler_Parser, textAndExpr)
{
    Parser parser;
    ASSERT_EQ(
            Node(ListNode()
                    .add(TextNode("abc"))
                    .add(ExprNode("ABC"))),
            parser.parse("abc{ABC}"));
}

} // namespace tests
} // namespace compiler
} // namespace ctemplator
