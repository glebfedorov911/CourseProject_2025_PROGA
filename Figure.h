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
    COLORREF bgColor;

    virtual void printFigure();
public:
    Figure(LONG x, LONG y, COLORREF bgColor);
    Figure();
    virtual ~Figure();

    void show();
    void hide();
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
