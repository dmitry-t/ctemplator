#include "ctemplator/nodes/ListNode.h"

#include "ctemplator/nodes/Node.h"

#include <algorithm>

namespace ctemplator {
namespace nodes {

ListNode& ListNode::add(Node node)
{
    nodes_.push_back(std::move(node));
    return *this;
}

bool ListNode::isList() const
{
    return true;
}

bool ListNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const ListNode*>(&node);
    return rhs &&
            nodes_.size() == rhs->nodes_.size() &&
            std::equal(
                    nodes_.begin(),
                    nodes_.end(),
                    rhs->nodes_.begin());
}

void ListNode::dump(std::ostream& stream) const
{
    bool printComma = false;
    for (auto& node : nodes_)
    {
        if (printComma)
        {
            stream << ", ";
        }
        else
        {
            printComma = true;
        }
        stream << node;
    }
}

} // namespace nodes
} // namespace ctemplator