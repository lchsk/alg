#include <map>

#include <gtest/gtest.h>

#include "../src/graph.hpp"

TEST(Graph, graph_ops)
{
    Graph g(3);
    ASSERT_EQ(g.get_V(), 3);
    ASSERT_EQ(g.get_E(), 0);

    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(0, 2);

    ASSERT_EQ(g.get_E(), 3);
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
