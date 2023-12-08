#include "student.h"

Student::Student()
{
	fn = 0;
	arrival = 0;
	speciality = Speciality::Default;
	stayingDuration = 0;
}

Student::Student(std::istream& input)
{
	input >> fn;
	if (fn / 1000000000 > 0)
		throw "Invalid FN";

	input >> arrival;

	std::string specialty;
	input >> specialty;

	if (specialty == "Fraud")
		speciality = Speciality::Fraud;
	else if (specialty == "International")
	{
		speciality = Speciality::InternationalSchemes;
		input >> specialty;
	}
	else if (specialty == "Creative")
	{
		speciality = Speciality::CreativeNihilism;
		input >> specialty;
	}
	else if (specialty == "Subjective")
	{
		speciality = Speciality::SubjectiveResearches;
		input >> specialty;
	}
	else if (specialty == "File")
	{
		speciality = Speciality::FileAnalizis;
		input >> specialty;
	}
	else if (specialty == "Micromanagement")
		speciality = Speciality::Micromanagement;
	else if (specialty == "Applied")
	{
		speciality = Speciality::AppliedMaterialization;
		input >> specialty;
	}
	else if (specialty == "Subjectivistics")
		speciality = Speciality::Subjectivistics;
	else if (specialty == "Magnetism")
	{
		speciality = Speciality::MagnetismAndClearing;
		input >> specialty;
		input >> specialty;
	}
	else
	{
		throw "Invalid Speciality";
	}

	input >> stayingDuration;
}

Speciality Student::specialty() const
{
	return this->speciality;
}

void Student::queued()
{
	this->speciality = Speciality::Default;
}

unsigned Student::getFN() const
{
	return fn;
}

unsigned Student::eixtTime() const
{
	return this->stayingDuration;
}

unsigned Student::arrivalTime() const
{
	return arrival;
}

bool Student::operator==(const Student& other) const
{
	return (this->speciality == other.speciality);
}

void Student::setExitTime(const unsigned currentTime)
{
	this->stayingDuration += currentTime;
}