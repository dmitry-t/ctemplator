#pragma once

namespace ctemplator {
namespace compiler {

enum class TokenType
{
    TEXT,
    EXPR,
    OP_SINGLE,
    OP_BEGIN,
    OP_END,
    EOS,
};

} // namespace compiler
} // namespace ctemplator
