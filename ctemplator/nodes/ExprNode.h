#pragma once

#include "ctemplator/nodes/LeafNode.h"

#include <string>

namespace ctemplator {
namespace nodes {

class ExprNode : public LeafNode
{
public:
    ExprNode(std::string value);

    const std::string& value() const;

    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;

private:
    std::string value_;
};

} // namespace nodes
} // namespace ctemplator
