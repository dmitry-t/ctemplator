#include "ctemplator/nodes/ForNode.h"

#include "ctemplator/expr/VariableExpr.h"
#include "ctemplator/nodes/ExprNode.h"
#include "ctemplator/nodes/TextNode.h"
#include "ctemplator/vars/Var.h"

#include <gtest/gtest.h>

#include <sstream>

namespace ctemplator {
namespace nodes {
namespace tests {

using namespace expr;
using namespace vars;

TEST(nodes_ForNode, renderText)
{
    auto node = ForNode("i", "list")
            .setRoutine(TextNode("a"));
    Var vars(Object().set(
            "list",
            Array().add("1").add("2").add("3")));
    std::ostringstream stream;
    node.render(vars, stream);
    ASSERT_EQ("aaa", stream.str());
}

TEST(nodes_ForNode, renderForVariableValue)
{
    auto node = ForNode("i", "list")
            .setRoutine(ExprNode(VariableExpr("i")));
    Var vars(Object().set(
            "list",
            Array().add("1").add("2").add("3")));
    std::ostringstream stream;
    node.render(vars, stream);
    ASSERT_EQ("123", stream.str());
}

} // namespace tests
} // namespace nodes
} // namespace ctemplator
