#pragma once

#include "ctemplator/nodes/LeafNode.h"

#include <string>

namespace ctemplator {
namespace nodes {

class TextNode : public LeafNode
{
public:
    TextNode(std::string text);

    const std::string& value() const;


    virtual void render(const Var& vars, std::ostream& stream) const override;
    virtual bool equals(const AbstractNode& node) const override;
    virtual void dump(std::ostream& stream) const override;

private:
    std::string text_;
};

} // namespace nodes
} // namespace ctemplator
