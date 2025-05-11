#include <windows.h>
#include <iostream>
#include "Rhomb.h"

using namespace std;

//const int NotUsed = system("color F0");

int main() {
    Rhomb *rhomb = new Rhomb(100, 100, 40, 40);
    cout << "Console Window" << endl;

    rhomb->show();
    Sleep(5000);
    rhomb->move(250, 250);
    Sleep(5000);
}
