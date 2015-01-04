#pragma once

#include "ctemplator/vars/Var.h"

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
    typedef vars::Var Var;

    virtual AbstractNode& add(Node node) = 0;

    virtual void render(const Var& vars, std::ostream& stream) const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isList() const = 0;
    virtual bool equals(const AbstractNode& node) const = 0;
    virtual void dump(std::ostream& stream) const = 0;
};

} // namespace nodes
} // namespace ctemplator
