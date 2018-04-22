#include <map>

#include <gtest/gtest.h>

#include "../src/bag.hpp"

TEST(Bag, bag_of_strings)
{
    Bag<std::string> b;
    b.add("a");
    b.add("b");
    b.add("c");
}

TEST(Bag, iteration)
{
    Bag<int> b;
    b.add(1);
    b.add(2);
    b.add(3);

    // TODO: order
    auto head = b.get_head();
    ASSERT_EQ(head->item, 3);

    head = head->next.get();
    ASSERT_EQ(head->item, 2);

    head = head->next.get();
    ASSERT_EQ(head->item, 1);

    head = head->next.get();

    if (head != nullptr)
        FAIL();
}

TEST(Bag, get_vector)
{
    Bag<int> b;
    b.add(1);
    b.add(2);
    b.add(3);

    const std::vector<int> v = b.get_vector();

    ASSERT_EQ(v, std::vector<int>({3, 2, 1}));
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
