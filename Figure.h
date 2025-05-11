#include <windows.h>

#ifndef COURSEPROJECT_FIGURE_H
#define COURSEPROJECT_FIGURE_H

class Figure {
protected:
    LONG x, y;
    HWND hwnd;
    HDC hdc;
    POINT points[4];

    virtual void printFigure(COLORREF bgColor);
    virtual POINT& getCoords();
public:
    Figure(LONG x, LONG y);
    Figure();
    virtual ~Figure();

    virtual void show() {};
    virtual void hide() {};
    virtual void move(LONG newX, LONG newY);
};


#endif //COURSEPROJECT_FIGURE_H
