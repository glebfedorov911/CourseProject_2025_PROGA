#include "Figure.h"

#ifndef COURSEPROJECT_RECTANGLE_H
#define COURSEPROJECT_RECTANGLE_H


class MyRectangle : public Figure {
protected:
    LONG halfDiagonal;
    void printFigure() override;
public:
    MyRectangle(LONG x, LONG y, LONG halfDiagonal, COLORREF bgColor);
    ~MyRectangle() override = default;

    void show();
    void hide();
    void move(LONG newX, LONG newY) override;
    POINT* getCoords() override;
    LONG getX() override;
    LONG getY() override;
    class MyRectangleException : public FigureException
    {
    public:
        MyRectangleException(ErrorType type, LONG x, LONG y, LONG halfDiagonal);
    };
};


#endif //COURSEPROJECT_RECTANGLE_H
