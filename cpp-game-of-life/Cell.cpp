#include "Cell.hpp"

bool               Cell::IsMarkedForDeath ()    { return isMarkedForDeath; }
bool               Cell::IsAlive ()             { return isAlive; }
char               Cell::GetGraphic ()          { return isAlive ? 'O' : ' '; }
std::vector<Cell*> Cell::GetNeighbours ()       { return neighbours; }

Cell::Cell (bool alive)
{

    isAlive = alive;

}

void Cell::Die ()
{

    isAlive = false;

}

void Cell::Revive ()
{

    isAlive = true;

}

void Cell::MarkForDeath ()
{

    isMarkedForDeath = true;

}

void Cell::AssignNeighbour (Cell* neighbour)
{

    // The order in which neighbours are added doesn't matter,
    // the rules of the Game of Life don't care about that.
    // Therefore it's safe to just use push_back ().
    neighbours.push_back (neighbour);

}