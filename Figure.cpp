#include <windows.h>
#include "Figure.h"

Figure::Figure() : x(0), y(0)
{
    hwnd = GetConsoleWindow();
    hdc = GetDC(hwnd);
    GetClientRect(hwnd, &rt);
}

Figure::Figure(LONG x, LONG y, COLORREF bgColor) : Figure()
{
    this->x = x;
    this->y = y;
    this->bgColor = bgColor;
    if (x < 0 || y < 0) {
        this->hide();
        throw FigureException(FigureException::NEGATIVE_INPUT, x, y);
    }
}

Figure::~Figure()
{
    hide();
    ReleaseDC(hwnd, hdc);
}

POINT* Figure::getCoords() {
    return points;
}

void Figure::printFigure() {
    POINT* points = getCoords();
    HPEN hPen = CreatePen(PS_SOLID, 2, bgColor);
    HBRUSH hBrush = CreateSolidBrush(bgColor);
    SelectObject(hdc, hPen);
    SelectObject(hdc, hBrush);
    Polygon(hdc, points, 4);
    DeleteObject(hPen);
    DeleteObject(hBrush);
}

void Figure::show() {
    printFigure();
}

void Figure::hide() {
    COLORREF bgColorTemp = bgColor;
    bgColor = RGB(255, 255, 255);
    show();
    bgColor = bgColorTemp;
}

void Figure::move(LONG newX, LONG newY) {
    hide();
    if (newX < 0 || newY < 0) {
        this->hide();
        throw FigureException(FigureException::NEGATIVE_INPUT, x, y);
    }
    this->x = newX;
    this->y = newY;
    show();
}

LONG Figure::getX() {
    return this->x;
}

LONG Figure::getY() {
    return this->y;
}

Figure::FigureException::FigureException(ErrorType type, LONG x, LONG y) {
    if (type == NEGATIVE_INPUT) {
        message = "Некорректный ввод параметров: " + std::to_string(x) + ", " + std::to_string(y);
    } else if (type == OUT_OF_BOUNDS) {
        message = "Выход за границы: " + std::to_string(x) + ", " + std::to_string(y);
    } else {
        message = "Недоступный метод";
    }
}

const char* Figure::FigureException::what() const noexcept
{
    return message.c_str();
}