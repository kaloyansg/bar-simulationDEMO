#include "group.h"

Group::Group()
{
	speciality = Speciality::Default;
	students = nullptr;
	groupCapacity = 0;
	numberOfStudents = 0;
}

Group::Group(const Student& student, const unsigned groupCapacity)
{
	speciality = student.specialty();
	students = new Student[groupCapacity];
	this->groupCapacity = groupCapacity;
	students[0] = student;
	numberOfStudents = 1;
}

Group::Group(const Group& other)
{
	speciality = other.speciality;
	students = new Student[groupCapacity];
	for (size_t i = 0; i < other.numberOfStudents; i++)
	{
		students[i] = other.students[i];
	}
	groupCapacity = other.groupCapacity;
	numberOfStudents = other.numberOfStudents;
}

Group& Group::operator=(const Group& other)
{
	if (this != &other)
	{
		Student* temp = new Student[other.groupCapacity];

		speciality = other.speciality;
		for (size_t i = 0; i < other.numberOfStudents; i++)
		{
			temp[i] = other.students[i];
		}
		groupCapacity = other.groupCapacity;
		numberOfStudents = other.numberOfStudents;
		delete[] students;
		students = temp;
	}
	return *this;
}

Group::~Group()
{
	delete[] students;
	students = nullptr;
}

bool Group::add(const Student& student)
{
	if (numberOfStudents == groupCapacity)
		return false;
	if (speciality != student.specialty())
		return false;

	students[numberOfStudents] = student;
	++numberOfStudents;
	return true;
}

unsigned Group::size() const
{
	return numberOfStudents;
}

const Student Group::operator[](size_t index) const
{
	if (index >= numberOfStudents)
		throw "Invalid index";

	return students[index];
}

Student& Group::operator[](size_t index)
{
	if (index >= numberOfStudents)
		throw "Invalid index";

	return students[index];
}

void Group::setExitTime(const unsigned time)
{
	for (size_t i = 0; i < numberOfStudents; i++)
	{
		students[i].setExitTime(time);
	}
}
