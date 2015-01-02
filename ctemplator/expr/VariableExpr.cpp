#include "ctemplator/expr/VariableExpr.h"

namespace ctemplator {
namespace expr {

VariableExpr::VariableExpr(std::string expr) :
    expr_(expr)
{
}

std::string VariableExpr::evaluate(const Var& vars) const
{
    auto& var = vars[expr_];
    return var.isEmpty() ? "" : var.toString();
}

bool VariableExpr::equals(const AbstractExpr& expr) const
{
    auto rhs = dynamic_cast<const VariableExpr*>(&expr);
    return rhs && rhs->expr_ == expr_;
}

void VariableExpr::dump(std::ostream& stream) const
{
    stream << expr_;
}

} // namespace expr
} // namespace ctemplator
