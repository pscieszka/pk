#include <iostream>
#include <bitset>
#include "Variable.h"
using namespace std;
int main() {

    Variable var;
    var.setInt(12);

    cout << var.getInt() << " " << bitset<64>(var.getInt()) << endl;
    var.setDouble(5555.0);
    cout << var.getChar() << " " << bitset<64>(var.getChar()) << endl;
    cout << var.getUnsigned() << " " << bitset<64>(var.getUnsigned()) << endl;
    cout << var.getShort() << " " << bitset<64>(var.getShort()) << endl;
    cout << var.getDouble() << " " << bitset<64>(var.getDouble()) << endl;
    //bru hbruh



    return 0;
}