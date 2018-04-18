#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <sstream>


template <typename T>
class Stack
{
	struct Node
	{
		T item;
		std::unique_ptr<Node> next;
	};


public:
	Stack() : first(nullptr), n(0) {};

	bool is_empty() const { return first == nullptr; }
	int size() const { return n; }

	void push(const T& item) {
		std::unique_ptr<Node> old_first = std::move(first);

		first = std::make_unique<Node>();
		first->item = item;
		first->next = std::move(old_first);

		n++;
	}

	const T pop() {
		if (is_empty())
			throw std::exception();

		const T item = first->item;
		first = std::move(first->next);

		n--;

		return item;
	}

	const T& peek() {
		if (is_empty())
			throw std::exception();

		return first->item;
	}

	const std::string to_string() const {
		std::stringstream s;

		Node* element = first.get();

		while (element != nullptr) {
			s << element->item;
			s << " ";

			element = element->next.get();
		}

		return s.str();
	}


private:
	std::unique_ptr<Node> first;
	int n;
};

#endif
