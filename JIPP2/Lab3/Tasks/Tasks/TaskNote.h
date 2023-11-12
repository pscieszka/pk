#pragma once
#include "Task.h"
class TaskNote : public Task
{
private:
	bool status;
public:
	TaskNote(int id, std::string name, bool status) : Task(id, name), status(status) {};
	void display() const override;
	void changeStatus();
	void changeName(std::string name) override;
	
};

