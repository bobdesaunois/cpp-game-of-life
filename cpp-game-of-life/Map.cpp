#include "Map.hpp"

Map::Map (int amountOfCells)
{

    // Fill cells vector with specified amount of cells
    for (int i = 0; i < amountOfCells; i++)
        cells.push_back (*new Cell (true));

    for (auto &cell : cells)
    {

        

    }

}

std::vector<Cell> Map::GetCells ()
{
    
    return cells;

}
