#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <memory>
#include <vector>
#include <sstream>

#include "bag.hpp"

class Graph
{
public:
	Graph(const int V) : V(V), E(0), adj(V) {
		if (V < 0) throw std::exception();

		for (int v = 0; v < V; v++) {
			adj[v] = std::make_unique<Bag<int>>();
		}
	};

	const int get_V() const { return V; }
	const int get_E() const { return E; }

	void validate_vertex(const int v) const {
		if (v < 0 || v >= V)
			throw std::exception();
	}

	void add_edge(const int v, const int w) {
		validate_vertex(v);
		validate_vertex(w);
		E++;
		adj[v]->add(w);
		adj[w]->add(v);
	}

	const Bag<int>* get_adj(const int v) {
		validate_vertex(v);

		return adj[v].get();
	}

	const int degree(const int v) const {
		validate_vertex(v);

		return adj[v]->size();
	}

	const std::string to_string() const {
		std::stringstream ss;

		ss << V << " vertices, "
		   << E << " edges"
		   << "\n";

		for (int v = 0; v < V; v++) {
			ss << v << ": ";

			auto w = adj[v]->get_head();

			while (w != nullptr) {
				ss << w->item << " ";
				w = w->next.get();
			}

			ss << "\n";
		}

		return ss.str();
	}

private:
	const int V;
	int E;
	std::vector<std::unique_ptr<Bag<int>>> adj;
};

#endif
