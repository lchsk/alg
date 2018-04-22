#ifndef DEPTH_FIRST_PATHS_HPP
#define DEPTH_FIRST_PATHS_HPP

#include <memory>
#include <vector>
#include <sstream>

#include "graph.hpp"
#include "stack.hpp"

class DepthFirstPaths
{
public:
	DepthFirstPaths(Graph& g, const int source):
		source(source),
		marked(g.get_V()),
		edge_to(g.get_V()) {
		dfs(g, source);
	}

	bool has_path_to(const int v) const {
		return marked[v];
	}

	std::unique_ptr<Stack<int>> path_to(const int v) {
		std::unique_ptr<Stack<int>> path = std::make_unique<Stack<int>>();

		if (!has_path_to(v)) return path;

		for (int x = v; x != source; x = edge_to[x])
			path->push(x);

		path->push(source);

		return path;
	}

private:
	void dfs(Graph& g, const int v) {
		marked[v] = true;

		auto ws = g.get_adj(v)->get_vector();

		for (const int w : ws) {
			if (!marked[w]) {
				edge_to[w] = v;
				dfs(g, w);
			}
		}
	}

	const int source; // source vertex
	std::vector<bool> marked; // is there and s-v path
	std::vector<int> edge_to; // last edge on s-v path
};

#endif
