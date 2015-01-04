#include "ctemplator/nodes/IfNode.h"

namespace ctemplator {
namespace nodes {

IfNode::IfNode(expr::Expression expr) :
    expr_(std::move(expr))
{
}

IfNode& IfNode::setTrue(Node&& node)
{
    trueNode_ = std::move(node);
    return *this;
}

IfNode& IfNode::setFalse(Node&& node)
{
    falseNode_ = std::move(node);
    return *this;
}

void IfNode::render(const Var& vars, std::ostream& stream) const
{
    if (!expr_.evaluate(vars).empty())
    {
        trueNode_.render(vars, stream);
    }
    else
    {
        falseNode_.render(vars, stream);
    }
}

bool IfNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const IfNode*>(&node);
    return rhs
            && rhs->expr_ == expr_
            && rhs->trueNode_ == trueNode_
            && rhs->falseNode_ == falseNode_;
}

void IfNode::dump(std::ostream& stream) const
{
    stream << "if: " << expr_
            << ", then: " << trueNode_
            << ", else: " << falseNode_;
}


} // namespace nodes
} // namespace ctemplator
