#include "Map.hpp"
#include "Game.hpp" // Having this include here fixes some strange error

std::vector<Cell>* Map::GetCells () { return &cells; }

Map::Map (int amountOfCells)
{

    GenerateMap (amountOfCells);

}

void Map::GenerateMap (int amountOfCells)
{

    //srand (Game::RANDOM_SEED);

    // Fill cells vector with specified amount of cells
    for (int i = 0; i < amountOfCells; i++)
    {

        int randomNumber = (rand () % Game::MAP_CELL_DENSITY);
        bool deadOrAlive = randomNumber < 10 ? true : false;
        cells.push_back (*new Cell (deadOrAlive));

    }

    // TODO give this block of code it's own method or class (NeighbourFinder)
    int cellIndex = 0;
    for (auto& cell : cells)
    {

        // Let's find some indexes of potential neighbours 
        std::vector<int> positions;

        // Top-Left
        positions.push_back ((cellIndex - 1) - Game::CELLS_PER_ROW);

        // Top
        positions.push_back (cellIndex - Game::CELLS_PER_ROW);

        // Top-Right
        positions.push_back ((cellIndex + 1) - Game::CELLS_PER_ROW);

        // Left
        positions.push_back (cellIndex - 1);

        // Right
        positions.push_back (cellIndex + 1);

        // Bottom-Left
        positions.push_back ((cellIndex - 1) + Game::CELLS_PER_ROW);

        // Bottom
        positions.push_back (cellIndex + Game::CELLS_PER_ROW);

        // Bottom-Right
        positions.push_back ((cellIndex + 1) + Game::CELLS_PER_ROW);

        // Reroute out-of-bounds positions
        RerouteOutOfBoundsCells (&positions);

        for (auto& position : positions)
        {
            
            if (ValidateCellPosition (position))
            {


                /*
                 * There's a problem with the way our Map is built.
                 * I'm storing the cells of the Map in a single Vector.
                 * This means that in memory the map is nothing more than a long
                 * row of cells, and not a grid at all.
                 * The following if-else-if block solves this problem.
                 * It makes sure that cells ignore their neighbours on previous
                 * and next rows.
                 *
                 */
                if ((position + 1) % Game::CELLS_PER_ROW == 0)
                {

                    // Ignore neighbours on the next row
                    continue;

                } 
                else if (position % Game::CELLS_PER_ROW == 0)
                {

                    // Ignore neighbours on the previous row
                    continue;

                }

                // Save a pointer to neighbouring cell
                Cell* cellPtr = &cells.at (position);
                cell.AssignNeighbour (cellPtr);

            }
            
        }

        cellIndex++;

    }

}

void Map::RerouteOutOfBoundsCells (std::vector<int>* positions)
{

    for (auto& positionPtr : *positions)
    {

        if (positionPtr < 0)
        {

            positionPtr = Game::MAP_SIZE + positionPtr; // Note that positionPtr has a negative value

        }
        else if (positionPtr > Game::MAP_SIZE)
        {

            positionPtr = positionPtr - Game::MAP_SIZE;

        }

    }

}

bool Map::ValidateCellPosition (int position)
{

    if (position > 0 && position < Game::MAP_SIZE)
    {
        
        // If the cell to be validated is not out-of-bounds
        return true;

    }

    return false;

}

