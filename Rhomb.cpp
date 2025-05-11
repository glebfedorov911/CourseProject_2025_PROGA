#include "Rhomb.h"
#include <iostream>
#include <windows.h>

using namespace std;

Rhomb::Rhomb(LONG x, LONG y, LONG firstHalfDiagonal, LONG secondHalfDiagonal) : Figure(x, y) {
    this->firstHalfDiagonal = firstHalfDiagonal;
    this->secondHalfDiagonal = secondHalfDiagonal;

    if (this->firstHalfDiagonal <= 0 || this->secondHalfDiagonal <= 0) {
        throw std::invalid_argument("Размеры диагоналей ромба не могут быть отрицательными");
    }
}

void Rhomb::printFigure(COLORREF bgColor) {
    Figure::printFigure(bgColor);
}

POINT& Rhomb::getCoords() {
    cout << this->x << " " << this->firstHalfDiagonal << " " << this->secondHalfDiagonal << " " << this->y << endl;
    points[0] = { this->x, this->y - this->secondHalfDiagonal};
    points[1] = { this->x + this->firstHalfDiagonal, this->y };
    points[2] = { this->x , this->y + this->secondHalfDiagonal };
    points[3] = { this->x - this->firstHalfDiagonal, this->y };
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