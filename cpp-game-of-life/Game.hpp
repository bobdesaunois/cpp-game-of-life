#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <windows.h>

#include "Map.hpp"

class Game
{

public:
    static const int GAME_SPEED_MILLISECONDS    = 1000;
    static const int MAP_SIZE                   = 800;
    static const int CELLS_PER_ROW          = 40;

private:

    Map map;

    void Game::Initialize ();
    void Game::Logic ();
    void Game::Render ();

public:

    Game::Game ();
    Game::~Game ();

};

#endif