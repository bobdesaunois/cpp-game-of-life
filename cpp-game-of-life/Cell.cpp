#include "Cell.hpp"

bool               Cell::IsAlive ()             { return isAlive; }
char               Cell::GetGraphic ()          { return isAlive ? 'O' : ' '; }
std::vector<Cell*> Cell::GetNeighbours ()       { return neighbours; }

int Cell::getAmountOfLiveNeighbours () 
{

    int amountOfLiveNeighbours = 0;
    for (auto& neighbour : neighbours)
    {

        if (neighbour->IsAlive ())
        {

            amountOfLiveNeighbours++;

        }

    }

    return amountOfLiveNeighbours;

}

Cell::Cell (bool alive)
{

    isAlive = alive;

}

void Cell::Live ()
{

    int amountOfLiveNeighbours = this->getAmountOfLiveNeighbours ();

    if (this->IsAlive ())
    {

        if (amountOfLiveNeighbours < 2)
        {

            // Die by under-population
            this->Die ();

        }
        else if (amountOfLiveNeighbours == 2 || amountOfLiveNeighbours == 3)
        {

            // We live!

        }
        else if (amountOfLiveNeighbours > 3)
        {


            // Die by over-population
            this->Die ();

        }

    }
    else if (amountOfLiveNeighbours == 3)
    {

        // Revived by reproduction
        this->Revive ();

    }

}

void Cell::Die ()
{

    isAlive = false;

}

void Cell::Revive ()
{

    isAlive = true;

}

void Cell::AssignNeighbour (Cell* neighbour)
{

    // The order in which neighbours are added doesn't matter,
    // the rules of the Game of Life don't care about that.
    // Therefore it's safe to just use push_back ().
    neighbours.push_back (neighbour);

}