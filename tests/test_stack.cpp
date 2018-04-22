#include <map>

#include <gtest/gtest.h>

#include "../src/stack.hpp"

TEST(Stack, stack_of_strings)
{
    Stack<std::string> s;
    s.push("a");
    s.push("b");
    s.push("c");

    EXPECT_EQ(s.to_string(), "c b a ");

    EXPECT_EQ(s.peek(), "c");
    EXPECT_EQ(s.pop(), "c");
    EXPECT_EQ(s.pop(), "b");
    EXPECT_EQ(s.pop(), "a");
}

TEST(Stack, stack_of_ints)
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    EXPECT_EQ(s.to_string(), "3 2 1 ");

    EXPECT_EQ(s.peek(), 3);
    EXPECT_EQ(s.pop(), 3);
    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
}

TEST(Stack, get_vector)
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    const std::vector<int> v = s.get_vector();

    ASSERT_EQ(v, std::vector<int>({3, 2, 1}));
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
