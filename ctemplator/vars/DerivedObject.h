#pragma once

#include "boost/const_string/const_string.hpp"

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

class DerivedObject
{
public:
    typedef boost::const_string<char> ConstString;

    DerivedObject(const Var& baseObject);

    DerivedObject&& set(std::string name, Var value);

    const Var& get(ConstString name) const;
    bool operator==(const DerivedObject& rhs) const;
    void dump(std::ostream& stream) const;

private:
    typedef std::pair<std::string, Var> Field;

    std::vector<Field> fields_;
    const Var* baseObject_;
};

std::ostream& operator<<(std::ostream& lhs, const DerivedObject& rhs);

} // namespace vars
} // namespace ctemplator
