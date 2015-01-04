#include "ctemplator/nodes/Node.h"

#include "ctemplator/nodes/EmptyNode.h"
#include "ctemplator/nodes/ListNode.h"

namespace ctemplator {
namespace nodes {

Node::Node() :
    node_(new EmptyNode())
{
}

Node::Node(std::unique_ptr<AbstractNode> node) :
    node_(std::move(node))
{
}

void Node::add(Node node)
{
    if (node_->isEmpty())
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
    node_->render(vars, stream);
}

bool Node::operator==(const Node& rhs) const
{
    return node_->equals(*rhs.node_.get());
}

void Node::dump(std::ostream& stream) const
{
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
