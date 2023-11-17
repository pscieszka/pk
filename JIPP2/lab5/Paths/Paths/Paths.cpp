#include <iostream>
#include "Path.h"
int main()
{
    Path p("/abc/ddd");
    Path p2("/abc/ddd");
    p2 = p + "/ccc/"; // do poprawenia chyba

    std::cout << p.getPath()<<std::endl;
    std::cout << p2.getPath() << std::endl;



}

