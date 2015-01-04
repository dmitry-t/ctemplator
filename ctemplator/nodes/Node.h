#pragma once

#include "ctemplator/nodes/AbstractNode.h"
#include "ctemplator/vars/Var.h"

#include <iostream>
#include <memory>

namespace ctemplator {
namespace nodes {

class Node
{
public:
    typedef vars::Var Var;

    Node();
    Node(std::unique_ptr<AbstractNode> node);
    Node(Node&& other) = default;
    Node(const Node& other) = delete;

    template<class T>
    Node(T&& node)
    {
        reset(std::move(node));
    }

    template<class T>
    void reset(T&& node)
    {
        static_assert(
                std::is_base_of<AbstractNode, T>::value,
                "T must derive from AbstractNode");
        node_.reset(new T(std::move(node)));
    }

    void add(Node node);
    void add(std::unique_ptr<Node> node);

    void isEmpty() const;
    void render(const Var& vars, std::ostream& stream) const;

    Node& operator=(Node&& rhs) = default;
    Node& operator=(const Node& rhs) = delete;
    bool operator==(const Node& rhs) const;
    void dump(std::ostream& stream) const;

private:
    std::unique_ptr<AbstractNode> node_;
};

std::ostream& operator<<(std::ostream& lhs, const Node& rhs);

} // namespace nodes
} // namespace ctemplator
