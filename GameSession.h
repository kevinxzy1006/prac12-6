#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <iostream>
#include <vector>
#include "GridUnit.h"
#include "Avatar.h"
#include "Obstacle.h"
#include "Helper.h"

class GameSession {
public:
    GameSession() = default;

    std::vector<GridUnit*>& getGrid() { return grid; }

    void initGameSession(int numAvatars, int numObstacles, int gridWidth, int gridHeight) {
        for (int i = 0; i < numAvatars; ++i) {
            auto pos = Helper::generateRandomCoordinates(gridWidth, gridHeight);
            grid.push_back(new Avatar(std::get<0>(pos), std::get<1>(pos)));
        }
        for (int i = 0; i < numObstacles; ++i) {
            auto pos = Helper::generateRandomCoordinates(gridWidth, gridHeight);
            grid.push_back(new Obstacle(std::get<0>(pos), std::get<1>(pos)));
        }
    }

    void gameCycle(int maxCycles, double obstacleActivationDistance) {
        for (int cycle = 0; cycle < maxCycles; ++cycle) {
            for (auto entity : grid) {
                if (entity->getEntity() == 'A') {
                    static_cast<Avatar*>(entity)->shift(1, 0);

                    if (std::get<0>(entity->getCoordinates()) < 0 || std::get<0>(entity->getCoordinates()) >= 10 ||
                        std::get<1>(entity->getCoordinates()) < 0 || std::get<1>(entity->getCoordinates()) >= 10) {
                        std::cout << "Avatar has won the game!\n";
                        return;
                    }
                }
            }

            for (auto entity : grid) {
                if (entity->getEntity() == 'O' && static_cast<Obstacle*>(entity)->isActive()) {
                    for (auto other : grid) {
                        if (other->getEntity() == 'A') {
                            if (Helper::calculateDistance(entity->getCoordinates(), other->getCoordinates()) <= obstacleActivationDistance) {
                                static_cast<Obstacle*>(entity)->apply(*other);
                            }
                        }
                    }
                }
            }
        }

        std::cout << "Maximum number of cycles reached. Game over.\n";
    }

    ~GameSession() {
        for (auto entity : grid) {
            delete entity;
        }
    }

private:
    std::vector<GridUnit*> grid;
};

#endif // GAMESESSION_H
