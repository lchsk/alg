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

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
