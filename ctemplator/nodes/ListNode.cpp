#include "ctemplator/nodes/ListNode.h"

#include "ctemplator/nodes/Node.h"
#include "ctemplator/utils/CollectionUtils.h"

#include <algorithm>

namespace ctemplator {
namespace nodes {

ListNode& ListNode::add(Node node)
{
    nodes_.push_back(std::move(node));
    return *this;
}

void ListNode::render(const Var& vars, std::ostream& stream) const
{
    for (auto& node : nodes_)
    {
        node.render(vars, stream);
    }
}

bool ListNode::isEmpty() const
{
    return false;
}

bool ListNode::isList() const
{
    return true;
}

bool ListNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const ListNode*>(&node);
    return rhs && utils::equal(nodes_, rhs->nodes_);
}

void ListNode::dump(std::ostream& stream) const
{
    utils::dump(stream, nodes_, ", ");
}

void ListNode::release()
{
    delete this;
}

} // namespace nodes
} // namespace ctemplator
