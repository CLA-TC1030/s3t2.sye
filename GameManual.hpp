#pragma once

#include "Game.hpp"

class GameManual:public Game {
protected:
    std::string getInput() override;   
public:
    GameManual(std::string);
};
