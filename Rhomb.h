#include "Figure.h"

#ifndef COURSEPROJECT_RHOMB_H
#define COURSEPROJECT_RHOMB_H


class Rhomb : public Figure {
protected:
    LONG firstHalfDiagonal, secondHalfDiagonal;
    void printFigure() override;
public:
    Rhomb(LONG x, LONG y, LONG firstHalfDiagonal, LONG secondHalfDiagonal, COLORREF bgColor);
    ~Rhomb() override = default;

    void show();
    void hide();
    void move(LONG newX, LONG newY) override;
    POINT* getCoords() override;
    LONG getX() override;
    LONG getY() override;
    class RhombException : public FigureException
    {
    public:
        RhombException(ErrorType type, LONG x, LONG y, LONG firstHalfDiagonal, LONG secondHalfDiagonal);
    };
};


#endif //COURSEPROJECT_RHOMB_H
