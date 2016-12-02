#include "Game.hpp"

Game::Game ()
{

    Game::Initialize ();

}

Game::~Game ()
{

    delete &map;

}

void Game::Initialize ()
{

    map = *new Map ();

    while (true)
    {

        Game::Logic ();
        Game::Render ();

        Sleep (1000);

    }

}

void Game::Logic ()
{



}

void Game::Render ()
{

    system ("cls");

    for
    (
        int i = 0;
        i < (sizeof (map.y)) / (sizeof (map.y[0]));
        i++
    )
    {

        std::cout << map.y[i];

        for
        (
            int j = 0;
            j < (sizeof (map.x)) / (sizeof (map.x[0]));
            j++
        )
        {

            std::cout << map.x[j];

        }

        std::cout << std::endl;

    }

}