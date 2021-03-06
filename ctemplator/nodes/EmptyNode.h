#pragma once

#include "ctemplator/nodes/LeafNode.h"

#include <string>

namespace ctemplator {
namespace nodes {

class EmptyNode : public LeafNode
{
public:
    static EmptyNode INSTANCE;

    virtual bool isEmpty() const override;
    virtual void render(const Var& vars, std::ostream& stream) const override;
    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;
    virtual void release() override;

private:
    ~EmptyNode();
};

} // namespace nodes
} // namespace ctemplator
