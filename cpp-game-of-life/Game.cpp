#include "Game.hpp"

Game::Game ()
{

    Game::Initialize ();

}

void Game::Initialize ()
{

    map.GenerateMap (Game::MAP_SIZE);

    /*while (true)
    {*/

        //Game::Logic ();
        Game::Render ();

        //Sleep (Game::GAME_SPEED_MILLISECONDS);

    //}

    // This is here for debugging purposes
    int i;
    std::cin >> i;

}

void Game::Logic ()
{
}

void Game::Render ()
{

    system ("cls");

    int cellCountInRow = 0;
    for (auto &cell : map.GetCells ())
    {

        std::cout << cell.GetGraphic ();
        cellCountInRow++;

        if (cellCountInRow >= Game::CELLS_PER_ROW)
        {

            cellCountInRow = 0;
            std::cout << std::endl;

        }

    }


}