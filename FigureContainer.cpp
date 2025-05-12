#include "FigureContainer.h"


FigureContainer::~FigureContainer() {
    for (auto figure: this->figuresSet) {
        delete figure;
    }
    this->figuresSet.clear();
}

void FigureContainer::addToContainer(Figure* figure) {
    this->figuresSet.insert(figure);
}

void FigureContainer::deleteFromContainer(Figure* figure) {
    auto it = this->figuresSet.find(figure);
    if (it != this->figuresSet.end()) {
        (*it)->hide();
        delete *it;
        this->figuresSet.erase(it);
        Sleep(2000);
    }
}

void FigureContainer::showFromContainer() {
    for (auto figure: this->figuresSet) {
        figure->show();
        Sleep(2000);
    }
}