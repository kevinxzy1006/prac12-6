#include <iostream>
#include "GameSession.h"

int main() {
    GameSession game;
    game.initGameSession(2, 3, 10, 10);

    std::cout << "Initial game state:\n";
    for (const auto& entity : game.getGrid()) {
        std::cout << entity->getEntity() << " at (" << std::get<0>(entity->getCoordinates()) << ", " << std::get<1>(entity->getCoordinates()) << ")\n";
    }

    game.gameCycle(10, 1.0);

    std::cout << "Final game state:\n";
    for (const auto& entity : game.getGrid()) {
        std::cout << entity->getEntity() << " at (" << std::get<0>(entity->getCoordinates()) << ", " << std::get<1>(entity->getCoordinates()) << ")\n";
    }

    return 0;
}
