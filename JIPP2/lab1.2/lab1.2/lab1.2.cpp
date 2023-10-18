
#include <iostream>
#include "Student.h"
int main()
{

    Student s("Jan", { 5,3.5,4,4.5 });
    s.printData();
    s.addGrade(3);
    s.printData();
    s.changeName("Asia");
    s.printData(); 

    Student s2("Maciek");
    s2.printData();
    s2.addGrade(5);
    s2.printData();
}

