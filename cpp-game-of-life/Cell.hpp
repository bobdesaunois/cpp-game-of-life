#ifndef CELL_HPP
#define CELL_HPP

#include <vector>
#include <memory>

class Map;

class Cell
{
    
    bool isMarkedForDeath;
    bool isAlive = false;

    std::vector<std::shared_ptr<Cell>> neighbours;

public:

    Cell (bool alive = false);

    bool IsMarkedForDeath ();
    bool IsAlive ();
    char GetGraphic ();
    std::vector<std::shared_ptr<Cell>> GetNeighbours ();

    void Die ();
    void MarkForDeath ();
    void Revive ();
    void AssignNeighbour (std::shared_ptr<Cell> neighbour);

};

#endif