#pragma once

#include "ctemplator/nodes/LeafNode.h"
#include "ctemplator/nodes/Node.h"

#include <string>

namespace ctemplator {
namespace nodes {

class ForNode : public LeafNode
{
public:
    ForNode(std::string varName, std::string arrayName);

    ForNode&& setRoutine(Node&& node);

    virtual void render(const Var& vars, std::ostream& stream) const override;
    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;

private:
    std::string varName_;
    std::string arrayName_;
    Node node_;
};

} // namespace nodes
} // namespace ctemplator
