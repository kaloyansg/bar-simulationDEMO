#include "bar-simulator.h"

///
/// @brief Simulate the student bar problem
///
/// @param input
///   The stream, which contains the simulation commands
/// @param output
///   The stream, where the steps of simulation have to be printed.
///

void simulate_bar(std::istream& input, std::ostream& output)
{
		unsigned clubCapacity;
		unsigned groupCapacity;
		unsigned numberOfStudents;
		Student* students = nullptr;
		Queue queue;
	try
	{
		input >> clubCapacity;
		Club club(clubCapacity);
		input >> groupCapacity;
		input >> numberOfStudents;

		if (clubCapacity == 0 && groupCapacity == 0 && numberOfStudents == 0)
			return;
		if (clubCapacity == 0)
			throw std::runtime_error("No space in bar");

		students = new Student[numberOfStudents];
		for (size_t i = 0; i < numberOfStudents; i++)
		{
			students[i] = Student(input);
			if (i > 0 && students[i].arrivalTime() < students[i - 1].arrivalTime())
				throw incorrect_simulation("Not monotonous time");
		}

		unsigned time = 0;
		Student currentStudent;
		unsigned unqueuedStudents = numberOfStudents;
		bool grouped = false;

		while (unqueuedStudents > 0 || !queue.empty() || !club.empty())
		{
			if (unqueuedStudents > 0)
				for (size_t i = 0; i < numberOfStudents; ++i)
				{
					currentStudent = students[i];
					if (students[i].specialty() != Speciality::Default && students[i].arrivalTime() == time)
					{
						for (size_t g = 0; g < queue.size(); ++g)
						{
							if (queue[g].add(currentStudent))
							{
								grouped = true;
								if (queue[g].size() > clubCapacity)
									throw std::runtime_error("Group bigger than the club capacity");
								break;
							}
						}
						if (!grouped)
						{
							queue.add(Group(currentStudent, groupCapacity));
						}
						grouped = false;
						students[i].queued();
						--unqueuedStudents;
					}
				}

			if (!club.empty())
				club.exit(time, output);

			if (!queue.empty())
				for (int i = 0; i < queue.size(); ++i)
				{
					if (club.add(queue[i], time, output))
					{
						queue.remove(i);
						--i;
					}
				}
			++time;
		}

		delete[] students;
	}
	catch (const char* error)
	{
		if (students != nullptr)
			delete[] students;
		throw incorrect_simulation(error);
	}
	catch (const std::runtime_error& error)
	{
		if (students != nullptr)
			delete[] students;
		throw error;
	}
	catch (...)
	{
		if (students != nullptr)
			delete[] students;
		throw std::runtime_error("Error");
	}
}
