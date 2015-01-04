#include "ctemplator/vars/Var.h"
#include "ctemplator/vars/Array.h"
#include "ctemplator/vars/Object.h"

#include "gtest/gtest.h"

namespace ctemplator {
namespace vars {
namespace tests {

TEST(vars_Var, nullVar)
{
    ASSERT_EQ(Var(), Var());
}

TEST(vars_Var, stringVar)
{
    ASSERT_EQ(Var("abc"), Var(std::string("abc")));
    ASSERT_NE(Var("abc"), Var("Abc"));
}

TEST(vars_Var, arrayVar)
{
    ASSERT_EQ(
            Var(Array().add("a")),
            Var(Array().add("a")));
    ASSERT_NE(
            Var(Array().add("a")),
            Var(Array().add("a").add("b")));
    ASSERT_EQ(
            Var(Array().add(Object().set("a", "b").set("c", "d"))),
            Var(Array().add(Object().set("a", "b").set("c", "d"))));
    ASSERT_NE(
            Var(Array().add(Object().set("a", "b").set("c", "d"))),
            Var(Array().add(Object().set("a", "b").set("C", "d"))));
}

TEST(vars_Var, objectVar)
{
    ASSERT_EQ(
            Var(Object().set("a", "b")),
            Var(Object().set("a", "b")));
    ASSERT_NE(
            Var(Object().set("a", "b")),
            Var(Object().set("a", "c")));
    ASSERT_EQ(
            Var(Object().set("a", Array().add("b").add("c"))),
            Var(Object().set("a", Array().add("b").add("c"))));
    ASSERT_NE(
            Var(Object().set("a", Array().add("b").add("c"))),
            Var(Object().set("a", Array().add("c").add("b"))));
}

TEST(vars_Var, nullNotEqualsToOtherTypeVars)
{
    ASSERT_NE(Var(), Var(""));
    ASSERT_NE(Var(), Var(std::string("")));
    ASSERT_NE(Var(), Var(Array()));
    ASSERT_NE(Var(), Var(Object()));
}

TEST(vars_Var, stringNotEqualsToOtherTypeVars)
{
    ASSERT_NE(Var(""), Var());
    ASSERT_NE(Var(""), Var(Array()));
    ASSERT_NE(Var(""), Var(Object()));
    ASSERT_NE(Var(std::string()), Var());
    ASSERT_NE(Var(std::string()), Var(Array()));
    ASSERT_NE(Var(std::string()), Var(Object()));
}

TEST(vars_Var, arrayNotEqualsToOtherTypeVars)
{
    ASSERT_NE(Var(Array()), Var());
    ASSERT_NE(Var(Array()), Var(""));
    ASSERT_NE(Var(Array()), Var(std::string("")));
    ASSERT_NE(Var(Array()), Var(Object()));
}

TEST(vars_Var, objectNotEqualsToOtherTypeVars)
{
    ASSERT_NE(Var(Object()), Var());
    ASSERT_NE(Var(Object()), Var(""));
    ASSERT_NE(Var(Object()), Var(std::string("")));
    ASSERT_NE(Var(Object()), Var(Array()));
}

TEST(vars_Var, accessStringValue)
{
    Var var("abc");
    ASSERT_EQ(Var("abc"), var.string());
    ASSERT_EQ(Var(std::string("abc")), var.string());
    ASSERT_EQ(Var(), var.get(0));
    ASSERT_EQ(Var(), var.get("a"));
}
TEST(vars_Var, accessArrayItems)
{
    Var var(Array().add("a").add("b"));
    ASSERT_EQ(Var("a"), var.get(0));
    ASSERT_EQ(Var("b"), var.get(1));
    ASSERT_EQ(Var(), var.get(2));
    ASSERT_EQ(Var(), var.get("a"));
    ASSERT_EQ("", var.string());
}

TEST(vars_Var, accessObjectFields)
{
    Var var(Object().set("a", "1").set("b", "2"));
    ASSERT_EQ(Var("1"), var.get("a"));
    ASSERT_EQ(Var("2"), var.get("b"));
    ASSERT_EQ(Var(), var.get("c"));
    ASSERT_EQ(Var(), var.get(0));
    ASSERT_EQ("", var.string());
}

} // namespace tests
} // namespace vars
} // namespace ctemplator
