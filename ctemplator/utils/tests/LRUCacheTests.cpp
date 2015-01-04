#include "ctemplator/utils/LRUCache.h"

#include <gtest/gtest.h>

namespace ctemplator {
namespace utils {
namespace tests {

TEST(LRUCache, keepAllIfCapacityAllows)
{
    LRUCache<std::string, int, 2> cache;
    cache.put("a", 1);
    cache.put("b", 2);

    ASSERT_EQ(1, *cache.get("a"));
    ASSERT_EQ(2, *cache.get("b"));
}

TEST(LRUCache, dropOldestIfCapacityExceeded)
{
    LRUCache<std::string, int, 2> cache;
    cache.put("a", 1);
    cache.put("b", 2);
    cache.put("c", 3);

    ASSERT_EQ(nullptr, cache.get("a"));
    ASSERT_EQ(2, *cache.get("b"));
    ASSERT_EQ(3, *cache.get("c"));
}

TEST(LRUCache, moveToFrontOnAccess)
{
    LRUCache<std::string, int, 2> cache;
    cache.put("a", 1);
    cache.put("b", 2);
    ASSERT_EQ(1, *cache.get("a"));
    cache.put("c", 3);

    ASSERT_EQ(1, *cache.get("a"));
    ASSERT_EQ(nullptr, cache.get("b"));
    ASSERT_EQ(3, *cache.get("c"));
}

} // namespace tests
} // namespace utils
} // namespace ctemplator
