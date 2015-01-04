#pragma once

#include "ctemplator/vars/Var.h"

#include <iostream>

namespace ctemplator {
namespace expr {

class AbstractExpr
{
public:
    typedef vars::Var Var;

    virtual std::string evaluate(const Var& vars) const = 0;
    virtual bool equals(const AbstractExpr& expr) const = 0;
    virtual void dump(std::ostream& stream) const = 0;
};

} // namespace expr
} // namespace ctemplator
