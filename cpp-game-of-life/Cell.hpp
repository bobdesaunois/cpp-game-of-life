#ifndef CELL_HPP
#define CELL_HPP

#include <vector>
#include <memory>

class Map;

class Cell
{
    
    bool isAlive = false;
    std::vector<Cell*> neighbours;

public:

    Cell (bool alive = false);

    bool IsAlive ();
    char GetGraphic ();
    std::vector<Cell*> GetNeighbours ();
    int getAmountOfLiveNeighbours ();

    void Live ();
    void Die ();
    void Revive ();
    void AssignNeighbour (Cell* neighbour);

};

#endif