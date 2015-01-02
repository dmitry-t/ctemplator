#include "ctemplator/nodes/ExprNode.h"

namespace ctemplator {
namespace nodes {

ExprNode::ExprNode(std::string value) :
    value_(value)
{
}

const std::string& ExprNode::value() const
{
    return value_;
}

bool ExprNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const ExprNode*>(&node);
    return rhs && rhs->value_ == value_;
}

void ExprNode::dump(std::ostream& stream) const
{
    stream << "expr: " << value_;
}


} // namespace nodes
} // namespace ctemplator
