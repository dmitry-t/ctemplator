#pragma once

#include "ctemplator/vars/Array.h"
#include "ctemplator/vars/DerivedObject.h"
#include "ctemplator/vars/Object.h"

#include "boost/const_string/const_string.hpp"

#include <memory>

namespace ctemplator {
namespace vars {

class Var
{
public:
    typedef boost::const_string<char> ConstString;
    typedef Array::ConstIterator ConstIterator;

    static const Var EMPTY;

    Var();
    Var(const char* string);
    Var(std::string string);
    Var(Array&& array);
    Var(Object&& object);
    Var(DerivedObject&& derivedObject);

    Var(Var&& var);
    Var(const Var& var);

    ~Var();

    Var& operator=(Var&& var);
    Var& operator=(const Var& var);

    DerivedObject derive() const;

    bool isEmpty() const;

    bool isString() const;
    const std::string& string() const;

    bool isObject() const;
    const Var& get(ConstString name) const;
    Object& object();
    DerivedObject& derivedObject();

    bool isArray() const;
    ConstIterator begin() const;
    ConstIterator end() const;
    const Var& at(size_t index) const;
    Array& array();

    bool operator==(const Var& rhs) const;
    void dump(std::ostream& stream) const;

private:
    enum class Type
    {
        EMPTY,
        STRING,
        ARRAY,
        OBJECT,
        DERIVED_OBJECT
    };

    class ValuePolicy;

    void reset();

    Type type_;
    union
    {
        std::string string_;
        Array array_;
        Object object_;
        DerivedObject derivedObject_;
    };
};

bool operator!=(const Var& lhs, const Var& rhs);
std::ostream& operator<<(std::ostream& lhs, const Var& rhs);

} // namespace vars
} // namespace ctemplator
