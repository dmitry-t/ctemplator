#pragma once

#include "ctemplator/nodes/AbstractNode.h"

#include <initializer_list>
#include <vector>

namespace ctemplator {
namespace nodes {

class ListNode : public AbstractNode
{
public:
    virtual ListNode& add(Node node) override;


    virtual void render(const Var& vars, std::ostream& stream) const override;
    virtual bool isList() const override;
    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;

private:
    std::vector<Node> nodes_;
};

} // namespace nodes
} // namespace ctemplator