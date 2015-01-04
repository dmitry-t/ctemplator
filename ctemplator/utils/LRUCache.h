#pragma once

#include <algorithm>
#include <list>
#include <unordered_map>

namespace ctemplator {

template<class K, class V, size_t CAPACITY>
class LRUCache
{
public:

    void put(K key, V value)
    {
        entries_.emplace_front(std::move(key), std::move(value));
        if (entries_.size() > CAPACITY)
        {
            entries_.pop_back();
        }
    }

    const V* get(const K& key)
    {
        auto iterator = std::find_if(
                entries_.begin(),
                entries_.end(),
                [&key](const Entry& entry) { return entry.first == key; });
        if (iterator == entries_.end())
        {
            return nullptr;
        }
        entries_.splice(
                entries_.begin(),
                entries_,
                iterator);
        return &iterator->second;
    }

private:
    typedef std::pair<K, V> Entry;
    std::list<Entry> entries_;
};

} // namespace ctemplator
