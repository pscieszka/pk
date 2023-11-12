#include "TaskList.h"

void TaskList::display() const
{
	std::cout << "ID: " << taskID << std::endl;
	std::cout << "Task name: " << taskName << std::endl;
	std::cout << "Task Contents: " << taskContents << std::endl;
}

void TaskList::addToContents(std::string add)
{
	taskContents += add;
}

void TaskList::changeName(std::string name)
{
	taskName = name;
}
