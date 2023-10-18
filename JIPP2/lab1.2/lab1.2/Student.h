#pragma once
#include <iostream>
#include <vector>
class Student
{
	std::vector<double> grades;
	int gradesNum = 0;
	double avg=0;
	void calculateAvg();
	bool gradesAval = false;

public:
	std::string name="";
	Student(std::string name);
	Student(std::string name,std::vector<double> grades);
	void addGrade(double grade);
	void printData();
	void changeName(std::string name);
	
};

