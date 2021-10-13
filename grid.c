// Contains the functions to manipulate the grid to be used in main.c
// This can potentially be used in checker.c to make the GUI by getting existing
// board
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

char grid[MaxGrid][MaxGrid];
tempGrid[MaxGrid][MaxGrid];
char filename[40];
int gridsize = 0;
FILE *p;
SDL_Renderer *renderer;
SDL_Color grid_background = {22, 22, 22, 255};
SDL_Color grid_line_color = {44, 44, 44, 255};

// Reads a game from the text file
// returns -1 if the gamesize > MaxGrid
// returns -2 if the text file can't be found

/*
 TEXT FILE FORMAT:
 1ST line has dimensions of the game
 2nd-nth line has state of the game, 0 = cell dead, 1 = cell alive
 */
int readGame(){
    //filename = (char*)malloc((sizeof(char) * 40));
    //printf("hi %s", file);
    //printf("filename = %s",file);
    printf("Please enter the name of the game you want to load (e.g. ../test.txt)\n");
    scanf(" %[^\n]%*c", filename);
    p = fopen(filename,"r");
    // formats the filename to be readable by the program

    if (p == NULL) {
        return -1;
    }else{
        //printf("hi in loop \n");
        char input[200];
        int line = 0;
        int posCounter = 0;
        while (fgets(input,200,p)){
            //printf("Line number = %i\n",line);
            char *token = strtok(input," ");
            posCounter = 0;
            while (token != NULL){
                // create a separate counter here
                //printf("Poscounter = %i\n",posCounter);
                //printf( "%s\n", token );

                if (line == 0){ // gets the dimensions of the game
                    sscanf(token,"%d",&gridsize);
                    //printf("gridsize = %i",gridsize);
                }else{
                    if (posCounter < gridsize){
                        //grid[line][posCounter] = token;
                        strcpy(&grid[line-1][posCounter],token);
                        //sscanf(token,"%c",&grid[line][i]);
                    }
                    posCounter+=1;
                }
                token = strtok(NULL, " ");

            }
            line ++;
            //printf("******************\n");
        }
        printf("Game loaded!\n");
        return 1;
    }
    fclose(p);

}


// Writes a game to the text file
// returns -1 if the text file can't be found/written to
int writeGame(){
    p = fopen("../output.txt", "w");
    if (p == NULL) {
        printf("Unable to write to file loans.txt\n");
        return -1;
    } else {
        char t_gsize[5];
        sprintf(t_gsize, "%d", gridsize);
        strcat(t_gsize,"\n");
        fprintf(p, "%s", t_gsize);
        for (int i = 0; i < gridsize; i++){
            for (int j = 0; j < gridsize; j++){
                fprintf(p, "%c", grid[i][j]);
                fprintf(p, "%s", " ");

            }
            fprintf(p, "%s", "\n");
        }
        fclose(p);
        return 1;
    }

}


// Updates the grid after each iteration of the game
void updateGrid(){

    for (int i = 0; i < gridsize; i++){
        for (int j = 0; j < gridsize; j++){
            if (tempGrid[i][j] == 1){
                grid[i][j] = '1';
            }else{
                grid[i][j] = '0';
            }
        }
    }
}

// initialises tempGrid
// needs to be intialised after every iteration of the time state
void initialiseTemp(){
    for (int i = 0; i < gridsize; i++){

        for (int j = 0; j < gridsize; j++){

            tempGrid[i][j] = 0;
        }
    }
}

void displayGrid(){
    for (int i = 0; i < gridsize; i++){

        for (int j = 0; j < gridsize; j++){
            if (grid[i][j] == '1'){
                printf("%c ",grid[i][j]);
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }

}

void render_frame()
{
    SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
                           grid_background.b, grid_background.a);
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, grid_line_color.a);

    // draw a white rectangle for each living cell
    for(int32_t x = 0; x < gridsize; x++)
    {
        for(int32_t y = 0; y < gridsize; y++)
        {
            if (grid[x][y] == '1')
            {
                SDL_Rect rect = {
                        .x = x * 18,
                        .y = y * 18,
                        .w = 18,
                        .h = 18
                };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    SDL_RenderPresent(renderer);
}

