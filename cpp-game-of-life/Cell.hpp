#ifndef CELL_HPP
#define CELL_HPP

#include <vector>

using namespace std;

class Map;

class Cell
{
    
    bool isMarkedForDeath;
    bool isAlive = false;

    std::vector<Cell> neighbours;

public:

    Cell (bool alive = false);

    bool IsMarkedForDeath ();
    bool IsAlive ();
    char GetGraphic ();

    void Die ();
    void MarkForDeath ();
    void Revive ();
    void AssignNeighbour (Cell neighbour);

};

#endif