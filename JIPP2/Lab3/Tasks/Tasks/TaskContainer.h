#pragma once
#include "Task.h"
#include "TaskNote.h"
#include "set"
class TaskContainer
{
private:
	Task** tab = NULL;
	int size = 0;
	int actualSize = 0;


public:
	TaskContainer(int size);
	//To do: konstruktor kopiujacy
	void add(Task* task);
	void displayAll();

	//TaskId (pole klasy Task)!= id
	void displayId(int id);
	void deleteId(int id);
	~TaskContainer();

	Task*& operator[](int index); // aby dalo sie wypelnic obiekty usuniete przez id

	


};

