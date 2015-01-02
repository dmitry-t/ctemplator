#pragma once

#include "ctemplator/expr/AbstractExpr.h"

namespace ctemplator {
namespace expr {

class VariableExpr : public AbstractExpr
{
public:
    VariableExpr(std::string expr);

    virtual std::string evaluate(const Var& vars) const override;
    virtual bool equals(const AbstractExpr& expr) const override;
    virtual void dump(std::ostream& stream) const override;

private:
    std::string expr_;
};

} // namespace expr
} // namespace ctemplator
