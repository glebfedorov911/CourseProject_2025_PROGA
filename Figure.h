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
public:
    Figure(LONG x, LONG y);
    Figure();
    virtual ~Figure();

    virtual void show() {};
    virtual void hide() {};
    virtual void move(LONG newX, LONG newY);
    virtual POINT& getCoords();
    virtual LONG getX();
    virtual LONG getY();
};


#endif //COURSEPROJECT_FIGURE_H
