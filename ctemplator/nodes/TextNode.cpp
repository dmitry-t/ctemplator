#include "ctemplator/nodes/TextNode.h"

namespace ctemplator {
namespace nodes {

namespace {
const size_t MAX_PRINT = 20;
} // namespace

TextNode::TextNode(std::string value) :
    value_(value)
{
}

const std::string& TextNode::value() const
{
    return value_;
}

bool TextNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const TextNode*>(&node);
    return rhs && rhs->value_ == value_;
}

void TextNode::dump(std::ostream& stream) const
{
    stream << "text: \"" << (value_.size() <= MAX_PRINT ?
                    value_ : value_.substr(0, MAX_PRINT))
            << "\"";
}


} // namespace nodes
} // namespace ctemplator
