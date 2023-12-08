#include "club.h"

Club::Club(const unsigned clubCapacity) : clubCapacity(clubCapacity)
{
	avaiable = clubCapacity;
	students = new Student[clubCapacity];
	numberOfStudents = 0;
}

Club::~Club()
{
	delete[] students;
	students = nullptr;
}

bool Club::add(const Group& group, const unsigned currentTime, std::ostream& output)
{
	unsigned numberOfEntering = group.size();

	if (numberOfEntering > avaiable)
		return false;

	for (size_t i = 0; i < numberOfEntering; ++i)
	{
		output << currentTime << " " << group[i].getFN() << " enter" << std::endl;
		students[numberOfStudents] = group[i];
		students[numberOfStudents].setExitTime(currentTime);
		++numberOfStudents;
		--avaiable;
	}
	return true;
}

void Club::exit(const unsigned currentTime, std::ostream& output)
{
	for (int i = 0; i < numberOfStudents; ++i)
	{
		if (students[i].eixtTime() == currentTime)
		{
			output << currentTime << " " << students[i].getFN() << " exit" << std::endl;
			for (size_t j = i+1; j < numberOfStudents; j++)
			{
				students[j - 1] = students[j];
			}
			--numberOfStudents;
			--i;
			++this->avaiable;
		}
	}
}

bool Club::empty() const
{
	return (numberOfStudents == 0);
}
