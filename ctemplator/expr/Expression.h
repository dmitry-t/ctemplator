#pragma once

#include "Poco/Dynamic/Var.h"
#include "AbstractExpr.h"

#include <iostream>
#include <memory>

namespace ctemplator {
namespace expr {

class Expression
{
public:
    typedef Poco::Dynamic::Var Var;

    template<class T>
    Expression(T expr) :
        expr_(new T(std::move(expr)))
    {
    }

    std::string evaluate(const Var& vars) const;
    bool operator==(const Expression& rhs) const;
    void dump(std::ostream& stream) const;

private:
    std::unique_ptr<AbstractExpr> expr_;
};

std::ostream& operator<<(std::ostream& lhs, const Expression& rhs);

} // namespace expr
} // namespace ctemplator
