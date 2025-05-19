#include "Rhomb.h"
#include <iostream>
#include <windows.h>

using namespace std;

Rhomb::Rhomb(LONG x, LONG y, LONG firstHalfDiagonal, LONG secondHalfDiagonal) : Figure(x, y) {
    this->firstHalfDiagonal = firstHalfDiagonal;
    this->secondHalfDiagonal = secondHalfDiagonal;

    if (this->firstHalfDiagonal <= 0 || this->secondHalfDiagonal <= 0) {
        hide();
        throw RhombException(FigureException::NEGATIVE_INPUT, x, y, firstHalfDiagonal, secondHalfDiagonal);
    }
}

void Rhomb::printFigure(COLORREF bgColor) {
    Figure::printFigure(bgColor);
}

POINT* Rhomb::getCoords() {
    points[0] = { this->x, this->y - this->secondHalfDiagonal};
    points[1] = { this->x + this->firstHalfDiagonal, this->y };
    points[2] = { this->x , this->y + this->secondHalfDiagonal };
    points[3] = { this->x - this->firstHalfDiagonal, this->y };
    if (
        points[0].y >= rt.bottom ||
        points[2].y <= rt.top ||
        points[1].x >= rt.right ||
        points[3].x <= rt.left
    ) {
        throw RhombException(FigureException::OUT_OF_BOUNDS, x, y, firstHalfDiagonal, secondHalfDiagonal);
    }
    return Figure::getCoords();
}

void Rhomb::show() {
    this->printFigure(RGB(0, 255, 0));
}

void Rhomb::hide() {
    this->printFigure(RGB(255, 255, 255));
}

void Rhomb::move(LONG newX, LONG newY) {
    Figure::move(newX, newY);
}

LONG Rhomb::getX() {
    return Figure::getX();
}

LONG Rhomb::getY() {
    return Figure::getY();
}

Rhomb::RhombException::RhombException(ErrorType type, LONG x, LONG y, LONG firstHalfDiagonal, LONG secondHalfDiagonal) :
        Rhomb::RhombException::FigureException(type, x, y) {
    message += ", " + std::to_string(firstHalfDiagonal) + ", " + std::to_string(secondHalfDiagonal);
}
