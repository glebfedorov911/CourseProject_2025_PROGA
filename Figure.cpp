#include <windows.h>
#include "Figure.h"

Figure::Figure() : x(0), y(0)
{
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);
}

Figure::Figure(LONG x, LONG y) : Figure()
{
    this->x = x;
    this->y = y;
}

Figure::~Figure()
{
    hide();
    ReleaseDC(hwnd, hdc);
}

POINT& Figure::getCoords() {
    return *points;
}

void Figure::printFigure(COLORREF bgColor) {
    POINT& points = getCoords();
    HPEN hPen = CreatePen(PS_SOLID, 2, bgColor);
    HBRUSH hBrush = CreateSolidBrush(bgColor);
    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);
    Polygon(hdc, &points, 4);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}

void Figure::move(LONG newX, LONG newY) {
    hide();
    this->x = newX;
    this->y = newY;
    show();
}