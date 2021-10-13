#include "checker.h"
#include "grid.h"
//  checks the rules for the game

// *************************************************************************
// Place for declaring variables

int result = -1;
int count = 0;
char grid[MaxGrid][MaxGrid];
int gridsize;

// End of declaring variables
// *************************************************************************


//checks whether the cell above is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkAbove(int i, int j){
    result = -1;
    // check that it isn't the lower boundary
    if (i == 0){
        result = 0;
    }else{
        if (grid[i-1][j] == '1'){
            result = 1;
            //printf("hi , result = %i",result);

        }
    }
    return result;
}

// checks whether the cell below is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkBelow(int i, int j){
    result = -1;

    // check that it isn't the lower boundary
    if (i == gridsize-1){
       result = 0;
    }else{
        if (grid[i+1][j] == '1'){
            result = 1;
        }
    }
    if (result == 1){
        //printf("checkBelow result: %i\n",result);
    }

    return result;
}

// checks whether the cell to the right is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkRight(int i, int j){
    result = -1;
    // check that it isn't the lower boundary
    if (j == gridsize-1){
        result = 0;
    }else{
        if (grid[i][j+1] == '1'){
            result = 1;
        }
    }
    return result;
}

// checks whether the cell to the left is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkLeft(int i, int j){
    result = -1;
    // check that it isn't the lower boundary
    if (j == 0){
        result = 0;
    }else{
        if (grid[i][j-1] == '1'){
            result = 1;
        }
    }
    return result;
}

// checks whether the cell to the upperRight is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkUpperRight(int i, int j){
    result = -1;

    if (i == 0 || j == gridsize-1){
        result = 0;
    }else{
        if (grid[i-1][j+1] == '1'){
            result = 1;
        }
    }

    return result;
}

// checks whether the cell to the upperLeft is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkUpperLeft(int i, int j){
    result = -1;

    if (i == 0 || j == 0){
        result = 0;
    }else{
        if (grid[i-1][j-1] == '1'){
            result = 1;
        }
    }

    return result;
}

//checks whether the cell to the lowerRight is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkLowerRight(int i, int j){
    result = -1;

    if (i == gridsize-1 || j == gridsize-1){
        result = 0;
    }else{
        if (grid[i+1][j+1] == '1'){
            result = 1;
        }
    }

    return result;
}

//checks whether the cell to the lowerLeft is alive
// returns 1 if it alive
// returns -1 if it is out of bounds
int checkLowerLeft(int i, int j){
    result = -1;

    if (i == gridsize-1 || j == 0){
        result = 0;
    }else{
        if (grid[i+1][j-1] == '1'){
            result = 1;
        }
    }
    return result;
}

// Uses the methods defined above and returns the number of live neighbours to the cell
int checkCells(int i, int j){
    count = 0; // counter for checking number of live cells
    if(checkAbove(i,j) == 1){
        count+=1;
        //printf("count = %i - above\n",count);
    }

    if(checkBelow(i,j) == 1){
        count+=1;
        //printf("count = %i - below\n",count);

    }

    if(checkLeft(i,j) == 1){
        count+=1;
    }

    if(checkRight(i,j) == 1){
        count+=1;
    }

    if(checkUpperLeft(i,j) == 1){
        count+=1;
        //printf("count = %i - upper left\n",count);
    }

    if(checkUpperRight(i,j) == 1){
        count+=1;
        //printf("count = %i - upper right\n",count);

    }

    if(checkLowerLeft(i,j) == 1){
        count+=1;
        //printf("count = %i - lower left\n",count);

    }

    if(checkLowerRight(i,j) == 1){
        count+=1;
        //printf("count = %i - lower right\n",count);

    }
    return count;
}