#pragma once
#include "Task.h"
class TaskList : public Task
{
private:
	std::string taskContents;
public:
	TaskList(int id, std::string name, std::string taskContents) : Task(id, name), taskContents(taskContents) {};
	void display() const;
	void addToContents(std::string name);
	void changeName(std::string name);
};

