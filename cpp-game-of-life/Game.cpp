#include "Game.hpp"

Game::Game ()
    : map (Game::MAP_SIZE)
{

    Game::Initialize ();

}

void Game::Initialize ()
{

    while (true)
    {

        Game::Logic ();
        Game::Render ();

        Sleep (Game::GAME_SPEED_MILLISECONDS);

    }

    // This is here for debugging purposes
    int i;
    std::cin >> i;

}

void Game::Logic ()
{

    std::vector<Cell>* mapPtr = map.GetCells ();
    for (auto& cell : *mapPtr)
    {
     
        cell.Live ();

    }

}

void Game::Render ()
{

    system ("cls");

    std::vector<Cell>* cells = map.GetCells ();

    int cellCountInRow = 0;

    for (auto cell : *cells)
    {

        std::cout 
            << cell.GetGraphic ();

        cellCountInRow++;

        if (cellCountInRow >= Game::CELLS_PER_ROW)
        {

            cellCountInRow = 0;
            std::cout 
                << std::endl;

        }

    }


}