#include "ctemplator/vars/Array.h"

#include "ctemplator/vars/Var.h"
#include "ctemplator/utils/CollectionUtils.h"

namespace ctemplator {
namespace vars {

Array::Array()
{
}

Array::Array(std::vector<Var>&& values) :
    values_(std::move(values))
{
}

Array&& Array::add(Var&& var)
{
    values_.emplace_back(std::move(var));
    return std::move(*this);
}

Array::ConstIterator Array::begin() const
{
    return values_.begin();
}

Array::ConstIterator Array::end() const
{
    return values_.end();
}

const Var& Array::at(std::size_t index) const
{
    static const Var EMPTY;
    return index < values_.size() ? values_[index] : EMPTY;
}

bool Array::operator==(const Array& rhs) const
{
    return utils::equal(values_, rhs.values_);
}

void Array::dump(std::ostream& stream) const
{
    stream << "[";
    utils::dump(stream, values_, ", ");
    stream << "]";
}

std::ostream& operator<<(std::ostream& lhs, const Array& rhs)
{
    rhs.dump(lhs);
    return lhs;
}

} // namespace vars
} // namespace ctemplator
