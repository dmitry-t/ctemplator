#pragma once

#include "ctemplator/vars/VarType.h"

#include <iostream>

namespace ctemplator {
namespace vars {

class AbstractVar
{
public:
    //virtual VarType type() const = 0;
    virtual bool equals(const AbstractVar& var) const = 0;
    virtual void dump(std::ostream& stream) const = 0;
};

} // namespace vars
} // namespace ctemplator
