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
    Array();
    Array(std::vector<Var>&& values);

    Array&& add(Var&& var);

    const Var& get(std::size_t index) const;
    bool operator==(const Array& rhs) const;
    void dump(std::ostream& stream) const;

private:
    std::vector<Var> values_;
};

std::ostream& operator<<(std::ostream& lhs, const Array& rhs);

} // namespace vars
} // namespace ctemplator
