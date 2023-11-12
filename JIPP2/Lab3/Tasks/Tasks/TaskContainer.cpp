#include "TaskContainer.h"
#include "TaskNote.h"

TaskContainer::TaskContainer(int size) : size(size) {

	if (size > 0) {
		tab = new Task * [size];
		for (int i = 0; i < size; i++) {
			//  ??? 
			tab[i] = NULL;
		}
	}
	else {
		tab = NULL;
	}
}

void TaskContainer::add(Task* task)
{
	if (tab != NULL && actualSize<size) {
		tab[actualSize] = task;
		actualSize++;
	}
}

void TaskContainer::displayAll()
{
	if (actualSize == 0) {
		std::cout << "Tablica jest pusta" << std::endl;
		return;
	}


	if (tab != NULL) {
		for (int i = 0; i < size; i++) {

			if (tab[i] != NULL) {
				std::cout << "id w tablicy = " << i << std::endl;
				tab[i]->display();
			}
			
		}
	}
	else {
		std::cout << "Tablica nie istnieje" << std::endl;
	}
}

void TaskContainer::displayId(int id)
{
	if (tab != NULL) {
		if (id >= 0 && id<size) {
			if (tab[id] != NULL) {
				tab[id]->display();
			}
			else {
				std::cout << "Obiekt nie istnieje" << std::endl;
			}
			
		}
	}
	else {
		std::cout << "Tablica nie istnieje" << std::endl;
	}

}

void TaskContainer::deleteId(int id)
{
	if (tab != NULL) {
		if (id >= 0 && id<size) {
			if (tab[id] != NULL) {
				tab[id] = NULL;
			}
		}
	}
	
	
}

TaskContainer::~TaskContainer()
{
	if (tab != NULL) {
		for (int i = 0; i < size; i++) {
			delete tab[i];
		}
		delete[] tab;
	}
}

Task*& TaskContainer::operator[](int id)
{
	if (id >= 0 && id < size && tab!=NULL) {
		return tab[id];
	}
}


