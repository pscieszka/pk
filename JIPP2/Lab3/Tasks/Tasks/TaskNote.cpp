#include "TaskNote.h"

void TaskNote::display() const
{
	std::cout << "ID: " << taskID << std::endl;
	std::cout << "Task name: " << taskName << std::endl;
	std::cout << "Status: "<< status << std::endl;
}

void TaskNote::changeStatus()
{
	status = !status;
}

void TaskNote::changeName(std::string name)
{
	taskName = name;
}
