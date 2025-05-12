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
    void printFigure(COLORREF bgColor) override {
        throw std::runtime_error("Method printFigure(COLORREF bgColor) not supported for ComplexFigure");
    };
    static bool isOnSegment(LONG coordY, LONG coordY1, LONG coordY2,
                     LONG coordX, LONG coordX1, LONG coordX2);
public:
    ComplexFigure(MyRectangle* rect, Rhomb* rhomb);
    ~ComplexFigure() override;

    void show() override;
    void hide() override;
    void move(LONG newX, LONG newY) override;
    POINT* getCoords() override {
        throw std::runtime_error("Method getCoords() not supported for ComplexFigure");
    }

    LONG getX() override {
        throw std::runtime_error("Method getX() not supported for ComplexFigure");
    }

    LONG getY() override {
        throw std::runtime_error("Method getY() not supported for ComplexFigure");
    }
};


#endif //COURSEPROJECT_COMPLEXFIGURE_H
