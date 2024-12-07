#pragma once

#include "Game.hpp"

class GameAutomatic:public Game {
public:
    GameAutomatic(std::string);
    std::string getInput() override;   
};