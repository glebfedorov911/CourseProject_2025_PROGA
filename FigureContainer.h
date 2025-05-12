#include <set>
#include <iostream>
#include "Figure.h"
#include "MyRectangle.h"
#include "Rhomb.h"

#ifndef COURSEPROJECT_FIGURECONTAINER_H
#define COURSEPROJECT_FIGURECONTAINER_H


class FigureContainer {
private:
    std::set<Figure*> figuresSet;
public:
    FigureContainer() {};
    ~FigureContainer();
    void addToContainer(Figure* figure);
    void deleteFromContainer(Figure* figure);
    void showFromContainer();
};


#endif //COURSEPROJECT_FIGURECONTAINER_H
