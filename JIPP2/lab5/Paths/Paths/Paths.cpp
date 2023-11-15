#include <iostream>
#include "Path.h"
int main()
{
    Path p("/abc/ddd");
    p = p + "/ccc/abc/"; // do poprawenia chyba
    p += "/3333/"; // chyba tez
    std::cout << p.getPath()<<std::endl;
    bool res = p <= "/abc/ccc/abc/3333";
    std::cout << res<<std::endl;
    --p;
    std::cout << p;

}

