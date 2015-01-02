#pragma once

#include "Poco/Dynamic/Var.h"

#include <iostream>

namespace ctemplator {
namespace expr {

class AbstractExpr
{
public:
    typedef Poco::Dynamic::Var Var;

    virtual std::string evaluate(const Var& vars) const = 0;
    virtual bool equals(const AbstractExpr& expr) const = 0;
    virtual void dump(std::ostream& stream) const = 0;
};

} // namespace expr
} // namespace ctemplator
