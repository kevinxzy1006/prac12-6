#ifndef HELPER_H
#define HELPER_H

#include <tuple>
#include <cstdlib>
#include <cmath>

class Helper {
    public:
    static std::tuple<int, int> generateRandomCoordinates(int gridWidth, int gridHeight) {
        int x = rand() % gridWidth;
        int y = rand() % gridHeight;
        return std::make_tuple(x, y);
    }

    static double calculateDistance(std::tuple<int, int> coords1, std::tuple<int, int> coords2) {
        int x1 = std::get<0>(coords1);
        int y1 = std::get<1>(coords1);
        int x2 = std::get<0>(coords2);
        int y2 = std::get<1>(coords2);

        return std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
};
#endif //HELPER_H