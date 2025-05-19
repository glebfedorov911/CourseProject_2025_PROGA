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
        hide();
        throw MyRectangleException(FigureException::NEGATIVE_INPUT, x, y, halfDiagonal);
    }
}

POINT* MyRectangle::getCoords() {
    points[0] = { this->x + this->halfDiagonal, this->y + this->halfDiagonal };
    points[1] = { this->x + this->halfDiagonal, this->y - this->halfDiagonal};
    points[2] = { this->x - this->halfDiagonal, this->y - this->halfDiagonal};
    points[3] = { this->x - this->halfDiagonal, this->y + this->halfDiagonal };
    if (
        points[0].y <= rt.top ||
        points[2].y >= rt.bottom ||
        points[1].x <= rt.left ||
        points[3].x >= rt.right
    ) {
        throw MyRectangleException(FigureException::OUT_OF_BOUNDS, x, y, halfDiagonal);
    }
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

LONG MyRectangle::getX() {
    return Figure::getX();
}

LONG MyRectangle::getY() {
    return Figure::getY();
}

MyRectangle::MyRectangleException::MyRectangleException(ErrorType type, LONG x, LONG y, LONG halfDiagonal) :
        MyRectangle::MyRectangleException::FigureException(type, x, y) {
    message += ", " + std::to_string(halfDiagonal);
}

