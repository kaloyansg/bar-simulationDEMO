#pragma once
#include "group.h"

class Queue
{
	struct Node
	{
		Group group;
		Node* next;

		Node(const Group& group)
		{
			this->group = group;
			next = nullptr;
		}
	};

	Node* first;
	Node* last;
	unsigned numberOfGroups;

public:
	Queue();
	Queue(const Queue&) = delete;
	Queue& operator=(const Queue&) = delete;
	~Queue();

	void add(const Group&);
	Group& operator[](unsigned);
	const Group operator[](unsigned)const;
	void remove(unsigned);
	unsigned size() const;
	bool empty() const;
};