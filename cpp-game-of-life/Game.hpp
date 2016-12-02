#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <windows.h>

#include "Map.hpp"

class Game
{

    Map map;

    void Game::Initialize ();
    void Game::Logic ();
    void Game::Render ();

public:

    Game::Game ();
    Game::~Game ();

};

#endif