#pragma once
#include <istream>
#include <string>

enum class Speciality
{
	Default,
	Fraud,
	InternationalSchemes,
	CreativeNihilism,
	SubjectiveResearches,
	FileAnalizis,
	Micromanagement,
	AppliedMaterialization,
	Subjectivistics,
	MagnetismAndClearing
};

class Student
{
	unsigned fn;
	unsigned arrival;
	Speciality speciality;
	unsigned stayingDuration;

public:
	Student();
	Student(std::istream&);
	
	void setExitTime(const unsigned);
	unsigned eixtTime() const;
	unsigned arrivalTime() const;
	bool operator==(const Student&) const;
	Speciality specialty()const;
	void queued();
	unsigned getFN() const;
};