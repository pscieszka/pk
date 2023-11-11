
#include <iostream>

#include "Task.h"
#include "TaskNote.h"
#include "TaskList.h"
#include "TaskContainer.h"

int main()
{

    TaskContainer tab(50);
 

   tab[2]= new TaskNote(2,"dwa",false);//2
   tab.add(new TaskList(0, "zero", "abc"));//0
   tab.add(new TaskList(1, "jeden", "abc"));//1
   tab.add(new TaskList(2, "dwav2", "abc"));//2


   tab.deleteId(0); // teraz jedyna opcja aby dodac obiekt w tym miejscu to uzycie przeciazenia operatora [] ???
   tab.displayAll();


        

    

   


    
    
}

