#pragma once

#include "ctemplator/vars/Array.h"
#include "ctemplator/vars/Object.h"

#include "boost/const_string/const_string.hpp"

#include <memory>

namespace ctemplator {
namespace vars {

class Var
{
public:
    typedef boost::const_string<char> ConstString;

    static const Var EMPTY;

    Var();
    Var(const char* string);
    Var(std::string string);
    Var(Object&& object);
    Var(Array&& array);

    Var(Var&& var);
    Var(const Var&) = delete;

    ~Var();

    Var& operator=(Var&& var);
    Var& operator=(const Var&) = delete;

    bool isString() const;
    const std::string& string() const;

    bool isObject() const;
    const Var& get(const char* name) const;
    const Var& get(const std::string& name) const;
    const Var& get(ConstString name) const;

    bool isArray() const;
    const Var& at(size_t index) const;

    bool operator==(const Var& rhs) const;
    void dump(std::ostream& stream) const;

private:
    enum class Type
    {
        EMPTY,
        STRING,
        ARRAY,
        OBJECT,
    };

    class ValuePolicy;

    Type type_;
    union
    {
        std::string string_;
        Array array_;
        Object object_;
    };

    void reset();
};

bool operator!=(const Var& lhs, const Var& rhs);
std::ostream& operator<<(std::ostream& lhs, const Var& rhs);

} // namespace vars
} // namespace ctemplator
