#include "ctemplator/vars/DerivedObject.h"

#include "ctemplator/vars/Var.h"
#include "ctemplator/utils/CollectionUtils.h"

#include "boost/const_string/io.hpp"

#include <algorithm>

namespace ctemplator {
namespace vars {

DerivedObject::DerivedObject(const Var& baseObject) :
    baseObject_(&baseObject)
{
}

DerivedObject&& DerivedObject::set(std::string name, Var value)
{
    auto i = std::find_if(
            fields_.begin(),
            fields_.end(),
            [&name](const Field& field) { return name == field.first; });
    if (i == fields_.end())
    {
        fields_.emplace_back(std::move(name), std::move(value));
    }
    else
    {
        i->second = value;
    }
    return std::move(*this);
}

const Var& DerivedObject::get(ConstString name) const
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
    const Var& var = ownVar.get(name.substr(dotPos + 1));
    return var.isEmpty() ? baseObject_->get(name) : var;
}


bool DerivedObject::operator==(const DerivedObject& rhs) const
{
    return utils::equal(
            fields_,
            rhs.fields_,
            [](const Field& f1, const Field& f2)
            {
                return f1.first == f2.first && f1.second == f2.second;
            });
}

void DerivedObject::dump(std::ostream& stream) const
{
    stream << "{";
    utils::dump(
            stream,
            fields_,
            ", ",
            [](std::ostream& stream, const Field& field)
            {
                stream << field.first << ": " << field.second;
            });
    stream << "}";
}

std::ostream& operator<<(std::ostream& lhs, const DerivedObject& rhs)
{
    rhs.dump(lhs);
    return lhs;
}
} // namespace vars
} // namespace ctemplator
