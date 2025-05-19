#include <windows.h>
#include <iostream>

#ifndef COURSEPROJECT_FIGURE_H
#define COURSEPROJECT_FIGURE_H

class Figure {
protected:
    LONG x, y;
    HWND hwnd;
    HDC hdc;
    POINT points[4];
    RECT rt;

    virtual void printFigure(COLORREF bgColor);
public:
    Figure(LONG x, LONG y);
    Figure();
    virtual ~Figure();

    virtual void show() {};
    virtual void hide() {};
    virtual void move(LONG newX, LONG newY);
    virtual POINT* getCoords();
    virtual LONG getX();
    virtual LONG getY();

    class FigureException : public std::exception
        {
            protected:
                std::string message;
            public:
                enum ErrorType{NEGATIVE_INPUT, OUT_OF_BOUNDS, NO_ACCESS};
                FigureException(ErrorType type, LONG x, LONG y);
                FigureException(std::string msg) : message(msg) {}
                const char* what() const noexcept override;
        };
};


#endif //COURSEPROJECT_FIGURE_H
