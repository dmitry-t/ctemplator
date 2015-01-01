#pragma once

#include "ctemplator/nodes/Node.h"

#include <string>

namespace ctemplator {
namespace nodes {

class TextNode : public Node
{
public:
    const std::string& value() const;

private:
    std::string value_;
};

} // namespace nodes
} // namespace ctemplator
