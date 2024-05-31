#ifndef GRIDUNIT_H
#define GRIDUNIT_H

#include <tuple>

class GridUnit {
protected:
    std::tuple<int, int> coordinates;
    char entity;

public:
    GridUnit(int x, int y, char entity) : coordinates(std::make_tuple(x,y)), entity(entity) {}

    std::tuple<int, int> getCoordinates() {
        return coordinates;
    }
    char getEntity() {
        return entity;
    }
    void setCoordinates(int x, int y) {

    }
    void setEntity(char entity) {
        this->entity = entity;
    }
};

#endif //GRIDUNIT_H

