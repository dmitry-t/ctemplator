#pragma once

#include <algorithm>
#include <iostream>

namespace ctemplator {
namespace utils {

template<class T1, class T2>
void dump(std::ostream& stream, const std::pair<T1, T2>& pair)
{
    stream << pair.first << ": " << pair.second;
}

template<class T>
void dump(std::ostream& stream, const T& value)
{
    stream << value;
}

template<class T>
void dump(std::ostream& stream, const T& collection, const char* delimiter)
{
    bool printDelimiter = false;
    for (auto& item : collection)
    {
        if (printDelimiter)
        {
            stream << delimiter;
        }
        else
        {
            printDelimiter = true;
        }
        dump(stream, item);
    }
}

template<class T1, class T2>
bool equal(const T1& collection1, const T2& collection2)
{
    return collection1.size() == collection2.size()
            && std::equal(
                    collection1.begin(),
                    collection1.end(),
                    collection2.begin());
}

} // namespace utils
} // namespace ctemplator
