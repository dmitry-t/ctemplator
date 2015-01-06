#include "ctemplator/vars/Var.h"

#include "ctemplator/vars/Object.h"
#include "ctemplator/vars/Array.h"

namespace ctemplator {
namespace vars {

namespace {

class Null { };

bool operator==(const Null& lhs, const Null& rhs)
{
    return true;
}

std::ostream& operator<<(std::ostream& lhs, const Null& rhs)
{
    return lhs << "null";
}

} // namespace

const Var Var::EMPTY;

Var::Var() :
    type_(Type::EMPTY)
{
}

Var::Var(const char* string) :
    type_(Type::STRING),
    string_(string)
{
}

Var::Var(std::string string) :
    type_(Type::STRING),
    string_(string)
{
}

Var::Var(Array&& array) :
    type_(Type::ARRAY),
    array_(std::move(array))
{
}

Var::Var(Object&& object) :
    type_(Type::OBJECT),
    object_(std::move(object))
{
}

Var::Var(DerivedObject&& derivedObject) :
    type_(Type::DERIVED_OBJECT),
    derivedObject_(std::move(derivedObject))
{
}

Var::Var(Var&& var) :
    type_(Type::EMPTY)
{
    *this = std::move(var);
}

Var::Var(const Var& var) :
    type_(Type::EMPTY)
{
    *this = var;
}

Var& Var::operator=(Var&& var)
{
    reset();
    switch (var.type_)
    {
    case Type::EMPTY:
        break;

    case Type::STRING:
        new (&string_) std::string(std::move(var.string_));
        break;

    case Type::ARRAY:
        new (&array_) Array(std::move(var.array_));
        break;

    case Type::OBJECT:
        new (&object_) Object(std::move(var.object_));
        break;

    case Type::DERIVED_OBJECT:
        new (&derivedObject_) DerivedObject(std::move(var.derivedObject_));
        break;
    }
    type_ = var.type_;
    var.reset();
}

Var& Var::operator=(const Var& var)
{
    reset();
    switch (var.type_)
    {
    case Type::EMPTY:
        break;

    case Type::STRING:
        new (&string_) std::string(var.string_);
        break;

    case Type::ARRAY:
        new (&array_) Array(var.array_);
        break;

    case Type::OBJECT:
        new (&object_) Object(var.object_);
        break;

    case Type::DERIVED_OBJECT:
        new (&derivedObject_) DerivedObject(var.derivedObject_);
        break;
    }
    type_ = var.type_;
}

Var::~Var()
{
    reset();
}

bool Var::isEmpty() const
{
    return type_ == Type::EMPTY;
}

bool Var::isString() const
{
    return type_ == Type::STRING;
}

const std::string& Var::string() const
{
    static const std::string EMPTY_STRING;
    return isString() ? string_ : EMPTY_STRING;
}

bool Var::isArray() const
{
    return type_ == Type::ARRAY;
}

namespace {
const Array::ContainerType EMPTY_CONTAINER;
} // namespace

Var::ConstIterator Var::begin() const
{
    return isArray() ? array_.begin() :EMPTY_CONTAINER.begin();
}

Var::ConstIterator Var::end() const
{
    return isArray() ? array_.end() :EMPTY_CONTAINER.end();
}

const Var& Var::at(size_t index) const
{
    return isArray() ? array_.at(index) : EMPTY;
}

Array& Var::array()
{
    if (!isArray())
    {
        throw std::logic_error("Var is not an array");
    }
    return array_;
}

bool Var::isObject() const
{
    return type_ == Type::OBJECT || type_ == Type::DERIVED_OBJECT;
}

const Var& Var::get(ConstString name) const
{
    switch (type_)
    {
    case Type::OBJECT:
        return object_.get(name);

    case Type::DERIVED_OBJECT:
        return derivedObject_.get(name);

    default:
        return EMPTY;
    }
}

Object& Var::object()
{
    if (type_ != Type::OBJECT)
    {
        throw std::logic_error("Var is not an object");
    }
    return object_;
}

DerivedObject& Var::derivedObject()
{
    if (type_ != Type::DERIVED_OBJECT)
    {
        throw std::logic_error("Var is not a derived object");
    }
    return derivedObject_;
}

bool Var::operator==(const Var& rhs) const
{
    if (type_ != rhs.type_)
    {
        return false;
    }
    switch (type_)
    {
    case Type::EMPTY:
        return true;

    case Type::STRING:
        return string_ == rhs.string_;

    case Type::ARRAY:
        return array_ == rhs.array_;

    case Type::OBJECT:
        return object_ == rhs.object_;
    }
}

DerivedObject Var::derive() const
{
    return DerivedObject(*this);
}

void Var::dump(std::ostream& stream) const
{
    switch (type_)
    {
    case Type::EMPTY:
        stream << Null();
        break;

    case Type::STRING:
        stream << string_;
        break;

    case Type::ARRAY:
        stream << array_;
        break;

    case Type::OBJECT:
        stream << object_;
        break;
    }
}

void Var::reset()
{
    switch (type_)
    {
    case Type::EMPTY:
        break;

    case Type::STRING:
        string_.~basic_string();
        break;

    case Type::ARRAY:
        array_.~Array();
        break;

    case Type::OBJECT:
        object_.~Object();
        break;
    }
    type_ = Type::EMPTY;
}

bool operator!=(const Var& lhs, const Var& rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& lhs, const Var& rhs)
{
    rhs.dump(lhs);
    return lhs;
}

} // namespace vars
} // namespace ctemplator
