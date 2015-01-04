#pragma once

#include "ctemplator/nodes/LeafNode.h"

#include <string>

namespace ctemplator {
namespace nodes {

class EmptyNode : public LeafNode
{
public:
    EmptyNode();

    virtual bool isEmpty() const override;
    virtual void render(const Var& vars, std::ostream& stream) const override;
    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;
};

} // namespace nodes
} // namespace ctemplator
