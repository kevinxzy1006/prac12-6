#include <iostream>
#include "Obstacle.h"
#include "Avatar.h"

int main() {
    Avatar avatar(2, 2);
    Obstacle obstacle(5, 5);

    std::cout << "Initial Avatar: (" << std::get<0>(avatar.getCoordinates()) << ", " << std::get<1>(avatar.getCoordinates()) << "), Entity: " << avatar.getEntity() << "\n";
    std::cout << "Initial Obstacle: (" << std::get<0>(obstacle.getCoordinates()) << ", " << std::get<1>(obstacle.getCoordinates()) << "), Entity: " << obstacle.getEntity() << "\n";

    avatar.shift(3, 3);
    std::cout << "Avatar after shift: (" << std::get<0>(avatar.getCoordinates()) << ", " << std::get<1>(avatar.getCoordinates()) << "), Entity: " << avatar.getEntity() << "\n";

    obstacle.apply(avatar);
    std::cout << "Avatar after obstacle apply: (" << std::get<0>(avatar.getCoordinates()) << ", " << std::get<1>(avatar.getCoordinates()) << "), Entity: " << avatar.getEntity() << "\n";
    std::cout << "Obstacle active: " << obstacle.isActive() << "\n";

    return 0;
}
