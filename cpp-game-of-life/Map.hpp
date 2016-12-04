#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include "Cell.hpp"

class Map
{

    std::vector<Cell> cells;

public:

    Map::Map (int amountOfCells);
    std::vector<Cell> Map::GetCells ();
    bool ValidateCellPosition (int position);

};

#endif