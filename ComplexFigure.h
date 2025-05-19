#include "Figure.h"
#include "MyRectangle.h"
#include "Rhomb.h"
#include <iostream>

#ifndef COURSEPROJECT_COMPLEXFIGURE_H
#define COURSEPROJECT_COMPLEXFIGURE_H


class ComplexFigure : public Figure {
protected:
    Rhomb* rhomb;
    MyRectangle* rect;
    void printFigure() override {
        throw ComplexFigureException::FigureException("Метод printFigure(COLORREF bgColor) не поддерживается для ComplexFigure");
    };
    static bool isOnSegment(LONG coordY, LONG coordY1, LONG coordY2,
                     LONG coordX, LONG coordX1, LONG coordX2);
public:
    ComplexFigure(MyRectangle* rect, Rhomb* rhomb);
    ~ComplexFigure() override;

    void show();
    void hide();
    void move(LONG newX, LONG newY) override;
    POINT* getCoords() override {
        throw ComplexFigureException::FigureException("Метод getCoords() не поддерживается для ComplexFigure");
    }

    LONG getX() override {
        throw ComplexFigureException::FigureException("Метод getX() не поддерживается для ComplexFigure");
    }

    LONG getY() override {
        throw ComplexFigureException::FigureException("Метод getY() не поддерживается для ComplexFigure");
    }
    class ComplexFigureException : public FigureException {};
};

#endif //COURSEPROJECT_COMPLEXFIGURE_H
