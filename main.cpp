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
        Sleep(1000);
        Rhomb *rhomb2 = new Rhomb(600, 320, 80, 80, RGB(255, 0, 0));
        MyRectangle *myRect2 = new MyRectangle(600, 320, 40, RGB(0, 0, 255));
        ComplexFigure *cf = new ComplexFigure(myRect2, rhomb2);
        FigureContainer* cont = new FigureContainer();
        cont->addToContainer(rhomb2);
        cont->addToContainer(myRect2);
        cont->showFromContainer();
        Sleep(3000);
        cont->deleteFromContainer(rhomb2);
        cont->showFromContainer();

    } catch (const Figure::FigureException& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    Sleep(500000);
}