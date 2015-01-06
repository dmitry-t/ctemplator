#pragma once

#include <iostream>
#include <vector>

namespace ctemplator {
namespace vars {

class Var;

} // namespace vars
} // namespace ctemplator

namespace ctemplator {
namespace vars {

class Array
{
public:
    typedef std::vector<Var> ContainerType;
    typedef ContainerType::const_iterator ConstIterator;

    Array();
    Array(std::vector<Var>&& values);

    Array&& add(Var&& var);

    ConstIterator begin() const;
    ConstIterator end() const;
    const Var& at(std::size_t index) const;
    bool operator==(const Array& rhs) const;
    void dump(std::ostream& stream) const;

private:
    ContainerType values_;
};

std::ostream& operator<<(std::ostream& lhs, const Array& rhs);

} // namespace vars
} // namespace ctemplator
