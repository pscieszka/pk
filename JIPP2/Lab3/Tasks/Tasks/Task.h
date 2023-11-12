#pragma once
#include <iostream>
class Task
{
protected:
	int taskID;
	std::string taskName;

public:
	Task(int id, std::string name) : taskID(id), taskName(name) {};

	virtual void display() const = 0;
	virtual void changeName(std::string name) = 0;
	virtual ~Task() = default;
	

};

