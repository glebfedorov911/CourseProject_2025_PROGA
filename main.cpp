#include <windows.h>
#include <iostream>
#include "Rhomb.h"
#include "MyRectangle.h"

using namespace std;

const int NotUsed = system("color F0");

int main() {
//    Rhomb *rhomb = new Rhomb(100, 100, 40, 40);
//    cout << "Console Window" << endl;
//
//    rhomb->show();
//    Sleep(1000);
//    rhomb->hide();
//    Sleep(1000);
//    rhomb->move(250, 250);
//    Sleep(1000);
//    rhomb->hide();
//    Sleep(1000);

    MyRectangle *myRect = new MyRectangle(100, 100, 100);
    cout << "Console Window" << endl;

    myRect->show();
    Sleep(1000);
    myRect->hide();
    Sleep(1000);
    myRect->move(250, 250);
    Sleep(1000);
    myRect->hide();
    Sleep(1000);
}
