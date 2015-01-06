#pragma once

#include <algorithm>
#include <iostream>

namespace ctemplator {
namespace utils {

template<class T>
void dump(
        std::ostream& stream,
        const T& collection,
        const char* delimiter)
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
        stream << item;
    }
}

template<class T, class F>
void dump(std::ostream& stream,
        const T& collection,
        const char* delimiter,
        F dumpItemFunctor)
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
        dumpItemFunctor(stream, item);
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

template<class T1, class T2, class P>
bool equal(const T1& collection1, const T2& collection2, P equalPredicate)
{
    return collection1.size() == collection2.size()
            && std::equal(
                    collection1.begin(),
                    collection1.end(),
                    collection2.begin(),
                    equalPredicate);
}

} // namespace utils
} // namespace ctemplator
