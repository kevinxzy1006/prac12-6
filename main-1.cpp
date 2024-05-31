#include <iostream>
#include "GridUnit.h"
#include "Modifier.h"
#include "Helper.h"

int main() {
    auto coords1 = Helper::generateRandomCoordinates(10, 10);
    auto coords2 = Helper::generateRandomCoordinates(10, 10);

    std::cout << "Coordinates 1: (" << std::get<0>(coords1) << ", " << std::get<1>(coords1) << ")\n";
    std::cout << "Coordinates 2: (" << std::get<0>(coords2) << ", " << std::get<1>(coords2) << ")\n";

    double distance = Helper::calculateDistance(coords1, coords2);
    std::cout << "Distance between coords1 and coords2: " << distance << "\n";

    return 0;
}
