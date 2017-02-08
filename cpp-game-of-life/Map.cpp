#include "Map.hpp"
#include "Game.hpp" // Having this include here fixes some strange error

std::vector<Cell>* Map::GetCells () { return &cells; }

Map::Map (int amountOfCells)
{

    GenerateMap (amountOfCells);

}

void Map::GenerateMap (int amountOfCells)
{

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
        RemapOutOfBoundsCells (&positions);

        for (auto& position : positions)
        {
            
            if (ValidateCellPosition (position))
            {


                /*
                 * There's a problem with the way our Map is built.
                 * I'm storing the cells of the Map in a single vector<Cell>.
                 * This means that in memory the map is nothing more than a long
                 * row of cells, and not a grid at all.
                 * Because of this the first cell on the second row would be the neighbour of the last cell of the first row.
                 * The following if-else-if block solves this problem.
                 * It makes sure that cells ignore their neighbours on previous
                 * and next rows.
                 *
                 * Next up to ensure that the left-edge and right-edge cells are neighbours, we have to apply some additional maths
                 */
                if ((position + 1) % Game::CELLS_PER_ROW == 0)
                {

                    // We're at the right edge, so we will add the cells on the opposite side as neighbours
                    std::vector<int> neighboursRightEdge;

                    neighboursRightEdge.push_back (position - ((Game::CELLS_PER_ROW * 2) - 1));
                    neighboursRightEdge.push_back (position - (Game::CELLS_PER_ROW - 1));
                    neighboursRightEdge.push_back (position + 1); // This is just + 1 since the next cell 
                                                                  // is on the next row obviously it jumps down one row as well.
                    

                    for (int& potentialNeighbour : neighboursRightEdge)
                    {

                        // Check for out-of-bounds positions and remove them, otherwise, forget about them.
                        if (potentialNeighbour > 0 && potentialNeighbour < Game::MAP_SIZE)
                        {

                            // If in-bounds
                            cell.AssignNeighbour (&cells.at (potentialNeighbour));

                        }

                    }

                    // We skip adding the actual 'auto& position' position, since we've been adding positions manually.
                    continue;

                } 
                else if (position % Game::CELLS_PER_ROW == 0)
                {

                    // At this point we're on the left side.
                    std::vector<int> neighboursLeftEdge;

                    neighboursLeftEdge.push_back (position - 1); // This is just - 1 since the next cell
                                                                 // is on the previous row, obviously it jumps up one row as well.
                    neighboursLeftEdge.push_back (position + ((Game::CELLS_PER_ROW * 2) - 1));
                    neighboursLeftEdge.push_back (position + (Game::CELLS_PER_ROW - 1));

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

void Map::RemapOutOfBoundsCells (std::vector<int>* positions)
{

    for (auto& positionPtr : *positions)
    {

        if (positionPtr < 0)
        {

            // positionPtr at this point has a NEGATIVE value
            positionPtr = Game::MAP_SIZE + positionPtr;

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

