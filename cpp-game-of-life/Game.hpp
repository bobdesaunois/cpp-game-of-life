#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <windows.h>

#include "Map.hpp"

class Game
{

public:

    static const int GAME_SPEED_MILLISECONDS    = 500;      // Time the game waits before continuing to the next generation.
    static const int MAP_SIZE                   = 800;      // Make sure it's a number dividable by two.
    static const int MAP_CELL_DENSITY           = 40;       // Increase this value to decrease density.
    static const int CELLS_PER_ROW              = 40;       // The width of the map.
    
private:

    Map map;
    void Game::Initialize ();
    void Game::Logic ();
    void Game::Render ();

public:

    Game::Game ();

};

#endif