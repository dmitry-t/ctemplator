#include "ctemplator/nodes/Node.h"

#include "ctemplator/nodes/ListNode.h"

namespace ctemplator {
namespace nodes {

Node::Node(std::unique_ptr<AbstractNode> node) :
    node_(std::move(node))
{
}

void Node::add(Node node)
{
    if (!node_)
    {
        node_ = std::move(node.node_);
        return;
    }
    if (!node_->isList())
    {
        auto firstChild = std::move(node_);
        node_.reset(new ListNode());
        node_->add(Node(std::move(firstChild)));
    }
    node_->add(std::move(node));
}

void Node::render(const Var& vars, std::ostream& stream) const
{
    if (node_)
    {
        node_->render(vars, stream);
    }
}

bool Node::operator==(const Node& rhs) const
{
    if (!node_ || !rhs.node_)
    {
        return node_.get() == rhs.node_.get();
    }
    return node_->equals(*rhs.node_.get());
}

void Node::dump(std::ostream& stream) const
{
    if (!node_)
    {
        stream << "null";
        return;
    }
    stream << "{";
    node_->dump(stream);
    stream << "}";
}

std::ostream& operator<<(std::ostream& lhs, const Node& rhs)
{
    rhs.dump(lhs);
    return lhs;
}

} // namespace nodes
} // namespace ctemplator
