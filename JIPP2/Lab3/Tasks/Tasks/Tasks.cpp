
#include <iostream>

#include "Task.h"
#include "TaskNote.h"

int main()
{



    Task* task = new TaskNote(6,"zadanie2","cos",false);
 
    TaskNote* task2 = new TaskNote(5, "zadanie1", "Napisz klase", false);
    task2->setTest(34);

    Task* taskTest = task2;
    taskTest->display();
    taskTest = task;
    taskTest->display();



    
    
}

