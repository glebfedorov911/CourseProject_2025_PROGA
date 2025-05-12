#include <windows.h>
#include <iostream>
#include "Rhomb.h"
#include "MyRectangle.h"
#include "ComplexFigure.h"

using namespace std;

const int NotUsed = system("color F0");

int main() {
    Rhomb *rhomb = new Rhomb(120, 180, 80, 80);
    rhomb->show();
    Sleep(1000);
    rhomb->hide();
    Sleep(1000);
    rhomb->move(250, 250);
    Sleep(1000);
    rhomb->hide();
    Sleep(1000);

    MyRectangle *myRect = new MyRectangle(120, 180, 40);
    myRect->show();
    Sleep(1000);
    myRect->hide();
    Sleep(1000);
    myRect->move(250, 250);
    Sleep(1000);
    myRect->hide();
    Sleep(1000);

    ComplexFigure *cf = new ComplexFigure(myRect, rhomb);
    cf->show();
    Sleep(2000);
    cf->hide();
    Sleep(2000);
    cf->move(180, 360);
    Sleep(500000);
}
