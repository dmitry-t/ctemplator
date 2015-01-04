#include "ctemplator/nodes/LeafNode.h"

#include "ctemplator/nodes/Node.h"

#include <stdexcept>

namespace ctemplator {
namespace nodes {

AbstractNode& LeafNode::add(Node node)
{
    throw std::logic_error("Cannot add a child to leaf node");
}

bool LeafNode::isEmpty() const
{
    return false;
}

bool LeafNode::isList() const
{
    return false;
}

void LeafNode::release()
{
    delete this;
}

} // namespace nodes
} // namespace ctemplator
