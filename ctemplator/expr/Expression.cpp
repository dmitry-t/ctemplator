#include "ctemplator/expr/Expression.h"

namespace ctemplator {
namespace expr {

std::string Expression::evaluate(const Var& vars) const
{
    return expr_ ? expr_->evaluate(vars) : "";
}

bool Expression::operator==(const Expression& rhs) const
{
    if (!expr_ || !rhs.expr_)
    {
        return expr_.get() == rhs.expr_.get();
    }
    return expr_->equals(*rhs.expr_.get());
}

void Expression::dump(std::ostream& stream) const
{
    if (expr_)
    {
        expr_->dump(stream);
    }
}

std::ostream& operator<<(std::ostream& lhs, const Expression& rhs)
{
    rhs.dump(lhs);
    return lhs;
}

} // namespace expr
} // namespace ctemplator
