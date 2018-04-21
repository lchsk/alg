#ifndef BAG_HPP
#define BAG_HPP

#include <memory>


template <typename T>
class Bag
{
	struct Node
	{
		T item;
		std::unique_ptr<Node> next;
	};


public:
	Bag() : first(nullptr), n(0) {};

	bool is_empty() const { return first == nullptr; }
	int size() const { return n; }

	void add(const T& item) {
		std::unique_ptr<Node> old_first = std::move(first);

		first = std::make_unique<Node>();
		first->item = item;
		first->next = std::move(old_first);

		n++;
	}

private:
	std::unique_ptr<Node> first;
	int n;
};

#endif
