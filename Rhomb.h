#include "Figure.h"

#ifndef COURSEPROJECT_RHOMB_H
#define COURSEPROJECT_RHOMB_H


class Rhomb : public Figure {
protected:
    LONG firstDiagonal, secondDiagonal;
    void printFigure(COLORREF bgColor) override;
    POINT& getCoords() override;
public:
    Rhomb(LONG x, LONG y, LONG firstDiagonal, LONG secondDiagonal);
    ~Rhomb() override = default;

    void show() override;
    void hide() override;
    void move(LONG newX, LONG newY) override;
};


#endif //COURSEPROJECT_RHOMB_H
