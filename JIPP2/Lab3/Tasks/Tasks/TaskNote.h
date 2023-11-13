#pragma once
#include "Task.h"
class TaskNote : public Task
{
private:
	bool status;
public:
	TaskNote(int id, std::string name, bool status) : Task(id, name), status(status) {};

	//Metody z klasy Task
	void display() const override;
	void changeStatus();
	//Dodatkowa metoda
	void changeName(std::string name) override;
	
};

