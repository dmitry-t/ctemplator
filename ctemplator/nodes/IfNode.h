#pragma once

#include "ctemplator/expr/Expression.h"
#include "ctemplator/nodes/LeafNode.h"
#include "ctemplator/nodes/Node.h"

#include <string>

namespace ctemplator {
namespace nodes {

class IfNode : public LeafNode
{
public:
    IfNode(expr::Expression expr);

    IfNode& setTrue(Node&& node);
    IfNode& setFalse(Node&& node);

    virtual void render(const Var& vars, std::ostream& stream) const override;
    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;

private:
    Node trueNode_;
    Node falseNode_;
    expr::Expression expr_;
};

} // namespace nodes
} // namespace ctemplator
