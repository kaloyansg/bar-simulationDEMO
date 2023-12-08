#pragma once
#include "student.h"

class Group
{
	Speciality speciality;
	Student* students;
	unsigned groupCapacity;
	unsigned numberOfStudents;

public:
	Group();
	Group(const Student&, const unsigned);
	Group(const Group&);
	Group& operator=(const Group&);
	~Group();

	bool add(const Student&);
	unsigned size()const;
	const Student operator[](size_t index) const;
	Student& operator[](size_t index);
	void setExitTime(const unsigned);
};