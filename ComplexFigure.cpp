#include "ComplexFigure.h"
#include <iostream>

using namespace std;

ComplexFigure::ComplexFigure(MyRectangle* rect, Rhomb* rhomb) {
    this->rect = rect;
    this->rhomb = rhomb;

    POINT rectPoints = this->rect->getCoords();
    POINT rhombPoints = this->rhomb->getCoords();

    LONG coordX = (&rectPoints)[0].x;
    LONG coordY = (&rectPoints)[0].y;

    LONG coordX1 = (&rhombPoints)[2].x;
    LONG coordY1 = (&rhombPoints)[2].y;
    LONG coordX2 = (&rhombPoints)[1].x;
    LONG coordY2 = (&rhombPoints)[1].y;

    cout << "-=-=-=" << endl;
    cout << (&rhombPoints)[0].x << " " << (&rhombPoints)[0].y << endl;
    cout << (&rhombPoints)[1].x << " " << (&rhombPoints)[1].y << endl;
    cout << (&rhombPoints)[2].x << " " << (&rhombPoints)[2].y << endl;
    cout << (&rhombPoints)[3].x << " " << (&rhombPoints)[3].y << endl;
//    cout << (&rectPoints)[0].x << " " << (&rectPoints)[0].y << endl;
    cout << "-=-=-=" << endl;

    bool isCollinear = (coordY - coordY1) * (coordX2 - coordX1) == (coordX - coordX1) * (coordY2 - coordY1);
//    cout << coordX << " " << coordX1 << " " << coordX2 << endl;
//    cout << coordY << " " << coordY1 << " " << coordY2 << endl;
//    cout << (coordY - coordY1) * (coordX2 - coordX1) << " " << (coordX - coordX1) * (coordY2 - coordY1) << endl;
    bool isWithinBounds = (coordX >= min(coordX1, coordX2)) &&
                          (coordX <= max(coordX1, coordX2)) &&
                          (coordY >= min(coordY1, coordY2)) &&
                          (coordY <= max(coordY1, coordY2));
    bool isOnSegment = isCollinear && isWithinBounds;
    cout << isOnSegment << endl;
}

ComplexFigure::~ComplexFigure() {
    Figure::~Figure();
    delete rect;
    delete rhomb;
}

void ComplexFigure::show() {
    rhomb->show();
    rect->show();
}

void ComplexFigure::hide() {
    rhomb->hide();
    rect->hide();
}

void ComplexFigure::move(LONG newX, LONG newY) {
    rhomb->move(newX, newY);
    rect->move(newX, newY);
}