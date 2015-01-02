#include "ctemplator/nodes/TextNode.h"

namespace ctemplator {
namespace nodes {

namespace {
const size_t MAX_PRINT = 20;
} // namespace

TextNode::TextNode(std::string text) :
    text_(text)
{
}

void TextNode::render(const Var& vars, std::ostream& stream) const
{
    stream << text_;
}

bool TextNode::equals(const AbstractNode& node) const
{
    auto rhs = dynamic_cast<const TextNode*>(&node);
    return rhs && rhs->text_ == text_;
}

void TextNode::dump(std::ostream& stream) const
{
    stream << "text: \"" << (text_.size() <= MAX_PRINT ?
                    text_ : text_.substr(0, MAX_PRINT))
            << "\"";
}


} // namespace nodes
} // namespace ctemplator
