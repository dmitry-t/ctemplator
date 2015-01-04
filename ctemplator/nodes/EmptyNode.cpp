#include "ctemplator/nodes/EmptyNode.h"

namespace ctemplator {
namespace nodes {

EmptyNode EmptyNode::INSTANCE;

EmptyNode::~EmptyNode()
{
}

bool EmptyNode::isEmpty() const
{
    return true;
}

void EmptyNode::render(const Var& vars, std::ostream& stream) const
{
}

bool EmptyNode::equals(const AbstractNode& node) const
{
    return dynamic_cast<const EmptyNode*>(&node) != nullptr;
}

void EmptyNode::dump(std::ostream& stream) const
{
}

void EmptyNode::release()
{
}

} // namespace nodes
} // namespace ctemplator
