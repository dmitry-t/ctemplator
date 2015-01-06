#include "ctemplator/nodes/TextNode.h"

namespace ctemplator {
namespace nodes {

namespace {
const size_t MAX_PRINT = 50;
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
    const std::string ELLIPSIS = "...";
    stream << "text: \"";
    if (text_.size() <= MAX_PRINT)
    {
        stream << text_;
    }
    else
    {
        stream << text_.substr(0, MAX_PRINT - ELLIPSIS.size()) << ELLIPSIS;
    }
    stream << "\"";
}


} // namespace nodes
} // namespace ctemplator
