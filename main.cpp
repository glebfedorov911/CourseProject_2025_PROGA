#include <windows.h>
#include <iostream>
#include "Rhomb.h"
#include "MyRectangle.h"
#include "ComplexFigure.h"

using namespace std;

const int NotUsed = system("color F0");

int main() {
    Rhomb *rhomb = new Rhomb(120, 180, 80, 80);
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

//    MyRectangle *myRect = new MyRectangle(12, 5, 1);
    MyRectangle *myRect = new MyRectangle(120, 180, 40);
//    cout << "Console Window" << endl;
//
//    myRect->show();
//    Sleep(1000);
//    myRect->hide();
//    Sleep(1000);
//    myRect->move(250, 250);
//    Sleep(1000);
//    myRect->hide();
//    Sleep(1000);
    ComplexFigure *cf = new ComplexFigure(myRect, rhomb);
    cf->show();
    Sleep(500000);
}
