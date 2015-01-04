#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace ctemplator {
namespace vars {

class Var;

} // namespace vars
} // namespace ctemplator

namespace ctemplator {
namespace vars {

class Object
{
public:
    Object();
    Object(std::vector<std::pair<std::string, Var>>&& fields);

    Object(Object&&) = default;

    Object& operator=(Object&&) = default;

    Object&& set(std::string name, Var value);

    const Var& get(const std::string& name) const;
    bool operator==(const Object& rhs) const;
    void dump(std::ostream& stream) const;

private:
    typedef std::pair<std::string, Var> Field;
    std::vector<Field> fields_;
};

std::ostream& operator<<(std::ostream& lhs, const Object& rhs);

} // namespace vars
} // namespace ctemplator