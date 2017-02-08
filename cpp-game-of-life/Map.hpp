#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
//#include <time.h>
#include "Cell.hpp"

class Map
{

    std::vector<Cell> cells;
    void Map::GenerateMap (int amountOfCells);

public:

    Map::Map (int amountOfCells);
    std::vector<Cell>* Map::GetCells ();
    bool Map::ValidateCellPosition (int position);
    void Map::RemapOutOfBoundsCells (std::vector<int>* position);

};

#endif