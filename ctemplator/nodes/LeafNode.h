#pragma once

#include "ctemplator/nodes/AbstractNode.h"

#include <initializer_list>

namespace ctemplator {
namespace nodes {

class LeafNode : public AbstractNode
{
public:
    virtual AbstractNode& add(Node node) override;

    virtual bool isEmpty() const override;
    virtual bool isList() const override;
};

} // namespace nodes
} // namespace ctemplator
