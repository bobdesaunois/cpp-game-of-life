#include "Map.hpp"
#include "Game.hpp"
#include <iostream>

Map::Map (int amountOfCells)
{

    // Fill cells vector with specified amount of cells
    for (int i = 0; i < amountOfCells; i++)
    {

        cells.push_back (*new Cell (true));

    }

    int cellIndex = 0;
    for (auto cell : cells)
    {

        // Let's find some indexes of potential neighbours 
        
        std::vector<int> positions;

        // Top-Left
        positions.push_back ((cellIndex - 1) - Game::CELLS_PER_ROW);
        
        // Top
        positions.push_back (cellIndex - Game::CELLS_PER_ROW);
        
        // Top-Right
        positions.push_back ((cellIndex + 1) - Game::CELLS_PER_ROW);

        // Left
        positions.push_back (cellIndex - 1);

        // Right
        positions.push_back (cellIndex + 1);

        // Bottom-Left
        positions.push_back ((cellIndex - 1) + Game::CELLS_PER_ROW);

        // Bottom
        positions.push_back (cellIndex + Game::CELLS_PER_ROW);

        // Bottom-Right
        positions.push_back ((cellIndex + 1) + Game::CELLS_PER_ROW);

        for (int position : positions)
        {

            if (ValidateCellPosition (position))
            {

                // Save a pointer to neighbouring cell
                cell.AssignNeighbour (cells.at (position));

            }

        }

        cellIndex++;

    }

}

bool Map::ValidateCellPosition (int position)
{

    if (position > 0 && position < Game::MAP_SIZE)
        return true;

    return false;

}

std::vector<Cell> Map::GetCells ()
{
    
    return cells;

}
