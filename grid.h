// Used to create functions for grid.c file

#define MaxGrid 50
#include <stdio.h>
extern char grid[MaxGrid][MaxGrid];
extern int tempGrid[MaxGrid][MaxGrid];
extern int gridsize;
extern char file[40];
#include <SDL2/SDL.h>
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern SDL_Color grid_background; // Barely Black
extern SDL_Color grid_line_color; // Dark grey

// Reads a game from the text file
int readGame();

// Writes a game to the text file
int writeGame();

// Updates the grid after each iteration of the game
void updateGrid();
void displayGrid();
void initialiseTemp();
void render_frame();