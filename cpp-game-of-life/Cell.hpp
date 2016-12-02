#ifndef CELL_HPP
#define CELL_HPP

class Cell
{
    
    int kaas = 2;
    Cell* kaass;
    bool isMarkedForDeath;
    bool isAlive = false;
    char graphic;

public:

    Cell (bool alive);

    bool IsMarkedForDeath ();
    bool IsAlive ();

    void Die ();
    void MarkForDeath ();
    void BeBorn ();

};

#endif