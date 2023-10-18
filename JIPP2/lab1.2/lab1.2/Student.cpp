#include "Student.h"

void Student::calculateAvg()
{
	if (!gradesNum) {
		avg = 0;
	}
	else {
	double sum = 0;
	for (auto& grade : grades) {
		sum += grade;
	}
	avg = sum / gradesNum;
	}
}

Student::Student(std::string name)
{
	this->name = name;
}

Student::Student(std::string name, std::vector<double> grades)
{
	this->name = name;
	this->grades = grades;
	gradesNum = grades.size();
	gradesAval = true;
	calculateAvg();
}

void Student::addGrade(double grade)
{
	grades.push_back(grade);
	gradesNum++;
	gradesAval = true;
	calculateAvg();
}

void Student::printData()
{
	std::cout << "Name: " << name << std::endl;
	if(gradesAval)
	std::cout << "Average grade: " << avg << std::endl;

}

void Student::changeName(std::string name)
{
	this->name = name;
}
