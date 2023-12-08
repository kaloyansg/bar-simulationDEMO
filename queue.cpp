#include "queue.h"

Queue::Queue()
{
	first = nullptr;
	last = nullptr;
	numberOfGroups = 0;
}

Queue::~Queue()
{
	Node* iterator = first;
	while (iterator)
	{
		iterator = first->next;
		delete first;
		first = iterator;
	}
}

void Queue::add(const Group& group)
{
	Node* element = new Node(group);
	if (first == nullptr)
	{
		first = last = element;
	}
	else
	{
		last->next = element;
		last = element;
	}
	++numberOfGroups;
}

Group& Queue::operator[](unsigned index)
{
	if (index >= numberOfGroups)
		throw "Invalid index";

	Node* element = first;
	for (size_t i = 0; i < index; ++i)
	{
		element = element->next;
	}
	return element->group;
}

inline const Group Queue::operator[](unsigned index) const
{
	if (index >= numberOfGroups)
		throw "Invalid index";

	Node* element = first;
	for (size_t i = 0; i < index; ++i)
	{
		element = element->next;
	}
	return element->group;
}

void Queue::remove(unsigned index)
{
	if (!first)
		throw "Queue is empty";
	if (index >= numberOfGroups)
		throw "Invalid index";

	Node* element = first;

	if (index == 0)
	{
		element = element->next;
		delete first;
		first = element;
	}
	else
	{
		for (size_t i = 1; i < index; i++)
		{
			element = element->next;
			Node* toDelete = element->next;
			element->next = toDelete->next;
			if (toDelete == last)
				last = element;
			delete toDelete;
		}
	}
	--numberOfGroups;
}

unsigned Queue::size() const
{
	return numberOfGroups;
}

bool Queue::empty() const
{
	return numberOfGroups == 0;
}
