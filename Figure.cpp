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