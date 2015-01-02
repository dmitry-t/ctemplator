#pragma once

#include "ctemplator/expr/Expression.h"
#include "ctemplator/nodes/LeafNode.h"

#include <string>

namespace ctemplator {
namespace nodes {

class ExprNode : public LeafNode
{
public:
    ExprNode(expr::Expression expr);

    virtual void render(const Var& vars, std::ostream& stream) const override;
    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;

private:
    expr::Expression expr_;
};

} // namespace nodes
} // namespace ctemplator
