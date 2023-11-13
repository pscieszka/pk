
#include <iostream>

#include "Task.h"
#include "TaskNote.h"
#include "TaskList.h"
#include "TaskContainer.h"

int main()
{

    TaskContainer tab(50);
    /*
    * Tablica wskaznikow do klasy Task.
    * Klasa jest wirutalna, wiec dodaje.
    * do niej klasy dziedziczace
    * TaskNote i TaskList.
    */
 

   
   tab.add(new TaskList(1, "zero", "abc"));//0
   tab.add(new TaskList(2, "jeden", "abc"));//1
   tab.add(new TaskList(3, "dwav2", "abc"));//2
   tab[2] = new TaskNote(0, "dwa", false);//2


   tab.deleteId(0);
   /*
   * Teraz aby dostac sie do tego indeksu trzeba uzyc przeciazenia operatora []
   * albo dodac/zmienic metode add, zeby dalo sie dodac po indeksie.
   * Obecna metoda dziala podobnie jak push_back w wektorze.
   * 
   */

   tab.displayAll();


        

    

   


    
    
}

