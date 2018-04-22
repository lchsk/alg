#include <map>

#include <gtest/gtest.h>

#include "../src/depth_first_paths.hpp"

TEST(DepthFirstPaths, test)
{
    // 0 - 1 - 2
        // | /
        // 3

    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    const int source = 0;

    DepthFirstPaths dfs(g, source);

    for (int v = 0; v < g.get_V(); v++) {
        if (dfs.has_path_to(v)) {
            std::cout << "\t" << source << " " << v << std::endl;

            auto path_to = dfs.path_to(v)->get_vector();

            for (int x : path_to) {
                if (x == source) {
                    std::cout << x << std::endl;
                } else {
                    std::cout << "-" << x << std::endl;
                }
            }
        } else {
            std::cout << "no edge " << source << " " << v << std::endl;
        }
    }
}

TEST(DepthFirstPaths, path_to)
{
        // 0
        // | \
        // 1 2
       // /   \
      // 3    5
       // \
        // 4

    Graph g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 5);
    g.add_edge(3, 4);

    DepthFirstPaths dfs(g, 0);

    ASSERT_EQ(dfs.path_to(4)->get_vector(), std::vector<int>({0, 1, 3, 4}));
    ASSERT_EQ(dfs.path_to(5)->get_vector(), std::vector<int>({0, 2, 5}));

    DepthFirstPaths dfs2(g, 1);

    ASSERT_EQ(dfs2.path_to(4)->get_vector(), std::vector<int>({1, 3, 4}));

    DepthFirstPaths dfs3(g, 5);

    ASSERT_EQ(dfs3.path_to(4)->get_vector(), std::vector<int>({5, 2, 0, 1, 3, 4}));
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
