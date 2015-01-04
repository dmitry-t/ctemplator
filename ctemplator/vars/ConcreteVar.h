#pragma once

#include "ctemplator/vars/AbstractVar.h"

namespace ctemplator {
namespace vars {

template<class T>
class ConcreteVar : public AbstractVar
{
public:
    ConcreteVar(T value) : value_(std::move(value)) { }


    virtual bool equals(const AbstractVar& var) const override
    {
        auto rhs = dynamic_cast<const ConcreteVar<T>*>(&var);
        return rhs && rhs->value_ == value_;
    }

    virtual void dump(std::ostream& stream) const override
    {
        stream << value_;
    }

private:
    T value_;
};

} // namespace vars
} // namespace ctemplator
