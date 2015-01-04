#include "ctemplator/vars/Object.h"

#include "ctemplator/vars/Var.h"
#include "ctemplator/utils/CollectionUtils.h"

namespace ctemplator {
namespace vars {

Object::Object()
{
}

Object::Object(std::vector<std::pair<std::string, Var>>&& fields) :
    fields_(std::move(fields))
{
}


Object&& Object::set(std::string name, Var value)
{
    fields_.emplace_back(std::move(name), std::move(value));
    return std::move(*this);
}


const Var& Object::get(const char* name) const
{
    return get(ConstString(name));
}

const Var& Object::get(const std::string& name) const
{
    return get(ConstString(name));
}

const Var& Object::get(ConstString name) const
{
    size_t dotPos = name.find(".");
    if (name.find(".") == std::string::npos)
    {
        auto i = std::find_if(
                fields_.begin(),
                fields_.end(),
                [&name](const Field& field) { return name == field.first; });
        return i != fields_.end() ? i->second : Var::EMPTY;
    }

    const Var& ownVar = get(name.substr(0, dotPos));
    return ownVar.get(name.substr(dotPos + 1));
}

bool Object::operator==(const Object& rhs) const
{
    return utils::equal(fields_, rhs.fields_);
}

void Object::dump(std::ostream& stream) const
{
    stream << "{";
    utils::dump(stream, fields_, ", ");
    stream << "}";
}

std::ostream& operator<<(std::ostream& lhs, const Object& rhs)
{
    rhs.dump(lhs);
    return lhs;
}

} // namespace vars
} // namespace ctemplator
