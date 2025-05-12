#include <windows.h>
#include <iostream>
#include "Rhomb.h"
#include "MyRectangle.h"
#include "ComplexFigure.h"
#include "FigureContainer.h"

using namespace std;

const int NotUsed = system("color F0");

int main() {
    system("chcp 65001");
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try {
        Rhomb *rhomb = new Rhomb(120, 180, 80, 80);
//        rhomb->show();
//        Sleep(1000);
//        rhomb->hide();
//        Sleep(1000);
//        rhomb->move(250, 250);
//        Sleep(1000);
//        rhomb->hide();
//        Sleep(1000);

        MyRectangle *myRect = new MyRectangle(120, 180, 40);
//        myRect->show();
//        Sleep(1000);
//        myRect->hide();
//        Sleep(1000);
//        myRect->move(250, 250);
//        Sleep(1000);
//        myRect->hide();
//        Sleep(1000);

        Rhomb *rhomb2 = new Rhomb(280, 280, 80, 80);
        MyRectangle *myRect2 = new MyRectangle(280, 280, 40);
        ComplexFigure *cf = new ComplexFigure(myRect2, rhomb2);
//        cf->show();
//        Sleep(2000);
//        cf->hide();
//        Sleep(2000);
//        cf->move(180, 360);
        FigureContainer *cont = new FigureContainer();
        cont->addToContainer(rhomb);
        cont->addToContainer(myRect);
        cont->addToContainer(cf);
        cont->showFromContainer();
        cont->deleteFromContainer(myRect);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    } catch (const char* err) {
        std::cerr << "Ошибка: " << err << std::endl;
    }
    Sleep(500000);
}