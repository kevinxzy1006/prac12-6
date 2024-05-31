#ifndef AVATAR_H
#define AVATAR_H

#include "GridUnit.h"

class Avatar : public GridUnit {
    public:
    Avatar(int x, int y) : GridUnit(x, y, 'A') {}

    void shift(int dx, int dy){
        auto [x, y] = getCoordinates();
        coordinates = std::make_tuple(x + dx, y + dy);
    }
};
#endif //AVATAR_H