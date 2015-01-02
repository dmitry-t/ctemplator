#pragma once

#include <iostream>

namespace ctemplator {
namespace nodes {

class Node;

} // namespace nodes
} // namespace ctemplator

namespace ctemplator {
namespace nodes {

class AbstractNode
{
public:
    virtual AbstractNode& add(Node node) = 0;

    virtual bool isList() const = 0;
    virtual bool equals(const AbstractNode& node) const = 0;
    virtual void dump(std::ostream& stream) const = 0;
};

} // namespace nodes
} // namespace ctemplator
