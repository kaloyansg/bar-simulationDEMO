#pragma once
#include "group.h"
#include "student.h"

class Club
{
	unsigned avaiable;
	Student* students;
	const unsigned clubCapacity;
	unsigned numberOfStudents;
	
public:
	Club(const unsigned);
	Club(const Club&) = delete;
	Club& operator=(const Club&) = delete;
	~Club();

	bool add(const Group&, const unsigned, std::ostream&);
	void exit(const unsigned, std::ostream&);
	bool empty() const;
};