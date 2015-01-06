#include "ctemplator/nodes/ForNode.h"

namespace ctemplator {
namespace nodes {

ForNode::ForNode(
        std::string varName,
        std::string arrayName) :
    varName_(std::move(varName)),
    arrayName_(std::move(arrayName))
{
}

ForNode&& ForNode::setRoutine(Node&& node)
{
    node_ = std::move(node);
    return std::move(*this);
}

void ForNode::render(const Var& vars, std::ostream& stream) const
{
    Var derived(vars.derive());
    auto& array = vars.get(arrayName_);
    for (auto& var : array)
    {
        derived.derivedObject().set(varName_, var);
        node_.render(derived, stream);
    }
}

bool ForNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const ForNode*>(&node);
    return rhs &&
            varName_ == rhs->varName_ &&
            arrayName_ == rhs->arrayName_ &&
            node_ == rhs->node_;
}

void ForNode::dump(std::ostream& stream) const
{
    stream << "for " << varName_ << " in " << arrayName_ << ": " << node_;
}

} // namespace nodes
} // namespace ctemplator
