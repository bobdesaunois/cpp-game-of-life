#include "Cell.hpp"

Cell::Cell (bool alive)
{

    isAlive = alive;

}

bool Cell::IsMarkedForDeath ()  { return isMarkedForDeath; }
bool Cell::IsAlive ()           { return isAlive; }

void Cell::Die ()
{

    isAlive = false;
    graphic = ' ';

}

void Cell::BeBorn ()
{

    isAlive = true;
    graphic = 'O';

}

void Cell::MarkForDeath ()
{

    isMarkedForDeath = true;

}


