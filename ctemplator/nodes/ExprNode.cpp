#include "ctemplator/nodes/ExprNode.h"

namespace ctemplator {
namespace nodes {

ExprNode::ExprNode(expr::Expression expr) :
    expr_(std::move(expr))
{
}

void ExprNode::render(const Var& vars, std::ostream& stream) const
{
    stream << expr_.evaluate(vars);
}

bool ExprNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const ExprNode*>(&node);
    return rhs && rhs->expr_ == expr_;
}

void ExprNode::dump(std::ostream& stream) const
{
    stream << "expr: " << expr_;
}


} // namespace nodes
} // namespace ctemplator
