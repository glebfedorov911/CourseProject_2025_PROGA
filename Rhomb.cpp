#include "Rhomb.h"
#include <iostream>
#include <windows.h>
#include <iostream>

using namespace std;

Rhomb::Rhomb(LONG x, LONG y, LONG firstDiagonal, LONG secondDiagonal) : Figure(x, y) {
    this->firstDiagonal = firstDiagonal;
    this->secondDiagonal = secondDiagonal;

    if (this->firstDiagonal <= 0 || this->secondDiagonal <= 0) {
        throw std::invalid_argument("Размеры диагоналей ромба не могут быть отрицательными");
    }
}

void Rhomb::printFigure(COLORREF bgColor) {
//    POINT& points = getCoords();
//    HPEN hPen = CreatePen(PS_SOLID, 2, bgColor);
//    HBRUSH hBrush = CreateSolidBrush(bgColor);
//    SelectObject(hdc, hPen);
//    SelectObject(hdc, hBrush);
//    Polygon(hdc, &points, 4);
//    DeleteObject(hPen);
//    DeleteObject(hBrush);
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, x, y, x+50, y+50);
    DeleteObject(hPen);
}

POINT& Rhomb::getCoords() {
    points[0] = { this->x, this->y - this->secondDiagonal};
    points[1] = { this->x + this->firstDiagonal, this->y };
    points[2] = { this->x , this->y + this->secondDiagonal };
    points[3] = { this->x - this->firstDiagonal, this->y };
    return *points;
}

void Rhomb::show() {
    this->printFigure(RGB(0, 0, 0));
    Sleep(2000);
    UpdateWindow(hwnd);
    Sleep(2000);
}

void Rhomb::hide() {
    this->printFigure(RGB(0, 0, 0));
}

void Rhomb::move(LONG newX, LONG newY) {
    hide();
    this->x = newX;
    this->y = newY;
    show();
}
