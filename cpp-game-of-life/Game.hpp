#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <windows.h>

#include "Map.hpp"

class Game
{

    static const int GAME_SPEED_MILLISECONDS    = 1000;
    static const int MAP_SIZE                   = 800;
    static const int MAX_CELLS_PER_ROW          = 40;

    Map map;

    void Game::Initialize ();
    void Game::Logic ();
    void Game::Render ();

public:

    Game::Game ();
    Game::~Game ();

};

#endif