#pragma once

#include "Game.hpp"

class GameAutomatic:public Game {
public:
    GameAutomatic(std::string, bool, bool);
    std::string getInput() override;
};
