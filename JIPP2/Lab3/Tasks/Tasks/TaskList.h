#pragma once
#include "Task.h"
class TaskList : public Task
{
private:
	std::string taskContents;
public:
	TaskList(int id, std::string name, std::string taskContents) : Task(id, name), taskContents(taskContents) {};

	//Metody z klasy Task
	void display() const override;
	void changeName(std::string name) override;
	

	void addToContents(std::string name);

	
};

