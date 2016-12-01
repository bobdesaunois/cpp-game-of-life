#include "Game.hpp"

Game::Game ()
{

    Game::Initialize ();

}

void Game::Initialize ()
{

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

    for (int k = 0; k < 100; k++)
        std::cout << std::endl;

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