#include "ComplexFigure.h"
#include <iostream>

using namespace std;

ComplexFigure::ComplexFigure(MyRectangle* rect, Rhomb* rhomb) {
    this->rect = rect;
    this->rhomb = rhomb;

    POINT* rectPoints = this->rect->getCoords();
    POINT* rhombPoints = this->rhomb->getCoords();

    bool isOnSegment1 = isOnSegment(
            rectPoints[0].y, rhombPoints[2].y, rhombPoints[1].y,
            rectPoints[0].x, rhombPoints[2].x, rhombPoints[1].x
    );
    bool isOnSegment2 = isOnSegment(
            rectPoints[1].y, rhombPoints[1].y, rhombPoints[0].y,
            rectPoints[1].x, rhombPoints[1].x, rhombPoints[0].x
    );
    bool isOnSegment3 = isOnSegment(
            rectPoints[2].y, rhombPoints[0].y, rhombPoints[3].y,
            rectPoints[2].x, rhombPoints[0].x, rhombPoints[3].x
    );
    bool isOnSegment4 = isOnSegment(
            rectPoints[3].y, rhombPoints[3].y, rhombPoints[2].y,
            rectPoints[3].x, rhombPoints[3].x, rhombPoints[2].x
    );

    if (!(isOnSegment1 && isOnSegment2 && isOnSegment3 && isOnSegment4)) {
        throw std::invalid_argument("Углы прямоугольника лежат не на сторонах ромба");
    }
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

bool ComplexFigure::isOnSegment(LONG coordY, LONG coordY1, LONG coordY2,
                 LONG coordX, LONG coordX1, LONG coordX2) {
    bool isCollinear = (coordY - coordY1) * (coordX2 - coordX1) == (coordX - coordX1) * (coordY2 - coordY1);
    bool isWithinBounds = (coordX >= min(coordX1, coordX2)) &&
                          (coordX <= max(coordX1, coordX2)) &&
                          (coordY >= min(coordY1, coordY2)) &&
                          (coordY <= max(coordY1, coordY2));
    bool isOnSegment = isCollinear && isWithinBounds;
    return isOnSegment;
}