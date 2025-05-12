#include "Figure.h"

#ifndef COURSEPROJECT_RECTANGLE_H
#define COURSEPROJECT_RECTANGLE_H


class MyRectangle : public Figure {
protected:
    LONG halfDiagonal;
    void printFigure(COLORREF bgColor) override;
public:
    MyRectangle(LONG x, LONG y, LONG halfDiagonal);
    ~MyRectangle() override = default;

    void show() override;
    void hide() override;
    void move(LONG newX, LONG newY) override;
    POINT* getCoords() override;
    LONG getX() override;
    LONG getY() override;
};


#endif //COURSEPROJECT_RECTANGLE_H
