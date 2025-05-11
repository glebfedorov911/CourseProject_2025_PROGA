#include "MyRectangle.h"
#include <iostream>
#include <windows.h>

using namespace std;

void MyRectangle::printFigure(COLORREF bgColor) {
    Figure::printFigure(bgColor);
}

MyRectangle::MyRectangle(LONG x, LONG y, LONG halfDiagonal) : Figure(x, y) {
    this->halfDiagonal = halfDiagonal;

    if (this->halfDiagonal <= 0) {
        throw std::invalid_argument("Размеры диагоналей прямоугольника не могут быть отрицательными");
    }
}

POINT& MyRectangle::getCoords() {
    points[0] = { this->x + this->halfDiagonal, this->y - this->halfDiagonal};
    points[1] = { this->x + this->halfDiagonal, this->y + this->halfDiagonal };
    points[2] = { this->x - this->halfDiagonal, this->y + this->halfDiagonal };
    points[3] = { this->x - this->halfDiagonal, this->y - this->halfDiagonal};
    return Figure::getCoords();
}

void MyRectangle::show() {
    this->printFigure(RGB(0, 0, 255));
}

void MyRectangle::hide() {
    this->printFigure(RGB(255, 255, 255));
}

void MyRectangle::move(LONG newX, LONG newY) {
    Figure::move(newX, newY);
}