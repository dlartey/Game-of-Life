#include "logic.h"
#include "checker.h"
#include "grid.h"
// Checks whether a cell will be alive or dead in the next time state
// and updates each cell in the grid accordingly

// *************************************************************************
// Place for declaring variables
// End of declaring variables
// *************************************************************************

// Returns 1 if a LIVE cell has exactly two or three live neighbours (the LIVE cell stays alive)
// else returns -1

// Returns 1 if a DEAD cell has exactly THREE live neighbours (the DEAD cells turns ALIVE)
int checkAlive(){

    for (int i = 0; i < gridsize; i++){
        for (int j = 0; j < gridsize; j++){

            if (grid[i][j] == '1'){
                int temp = checkCells(i,j);
                if (checkCells(i,j) == 2 || checkCells(i,j) == 3){
                    //printf("LIVE CELL: grid[%i][%i] = %i\n",i,j,temp);
                    tempGrid[i][j] = 1; // make a temporary array to change the values instead
                }
            }else{
                if (checkCells(i,j) == 3){
                    //printf("DEAL CELL: grid[%i][%i] = 3\n",i,j);
                    tempGrid[i][j] = 1; // make a temporary array to change the values instead (DONE)
                }
            }
        }
    }

}





