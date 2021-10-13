// Main function used to link all the other header files and c files together
#include "stdio.h"
#include "checker.h"
#include "grid.h"
#include "logic.h"
#include <SDL2/SDL.h>
#include<time.h>
#define MaxTimeStep 100

// *************************************************************************
// Place for declaring variables

char next[40];
FILE *p;
char file[40];
SDL_Window *window;
SDL_Renderer *renderer;


// End of declaring variables
// *************************************************************************


// menu for displaying prompts to the user
void menu(){
printf("Welcome to the Game of Life please choose one of the following options:\n");
printf("1) Load game\n");
printf("2) Quit\n");
}

// returns -1 if response is invalid, else returns a positive integer
int inputChecker(char response[40]){
    char *temp;
    int checker = strtol(response,&temp,10);
    if (checker == 0){
        return 0;
    }else if (checker == 1){
        return 1;
    }else if (checker == 2){
        return 2;
    }else if (checker == 3){
        return 3;
    }
}

int  main (int argc, char* argv[]) {

    static const int32_t field_size = 30; // the amount of cells in both dimensions
    static const int32_t pixels_per_cell = 18; // size of a displayed cell in pixels

    int window_size = (field_size * pixels_per_cell); // width of whole window

    if (SDL_Init(SDL_INIT_VIDEO) < 0) { // initialises SDL video (Returns 0 on success)
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s",
                     SDL_GetError()); // Retrieves a message about the last error
        return EXIT_FAILURE;
    } // Checks that the window is open

    if (SDL_CreateWindowAndRenderer(window_size, window_size, 0, &window,
                                    &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Create window and renderer: %s", SDL_GetError());
        return EXIT_FAILURE;
    } // Creates a window and default renderer (Returns 0 if successfully created)

    SDL_SetWindowTitle(window, "Game of Life"); // Sets the title of the grid
    // Draw grid background.
    SDL_SetRenderDrawColor(renderer, grid_background.r, grid_background.g,
                           grid_background.b, grid_background.a);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    int menuChecker = 1;

    while (menuChecker) {

        menu();
        scanf(" %[^\n]%*c", next);
         if (inputChecker(next) == 1) { // load game from pathfile
            //printf("Please enter the file path you want to load (e.g.) ../test.txt\n");
            //scanf (" %[^\n]%*c", file);
            //printf("%s\n",file);
            if (readGame() == -1){
                printf("Can't find text file\n");
            }else{
                render_frame();
                int done = 1;
                int counter = 0;

                while (done && counter < 100) { // loops while the user is currently in the game

                    printf("Current time step: %d\n",counter);
                    printf("Would you like to go to the next time state (y/n)\n");
                    scanf(" %[^\n]%*c", next);

                    if (strcmp(next, "y") == 0) {
                        initialiseTemp();
                        checkAlive();
                        updateGrid();
                        render_frame();
                    } else {
                        done = 0;
                        printf("Do you want to save the game state to the output.txt file? (y/n)");
                        scanf(" %[^\n]%*c", next);
                        if (strcmp(next, "y") == 0) {
                            writeGame();
                        }
                    }
                    counter+=1;
                    if (counter  == 100){
                        printf("Game has reached max time steps (%d)\n",counter);
                        printf("Game state written to ../output.txt\n");
                        writeGame();
                        done = 0;
                    }
                }
            }


        } else if (inputChecker(next) == 2) {
            menuChecker = 0;
        } else if (inputChecker(next) == 0) {
            printf("Please select a valid option\n");
        }
        SDL_Event event; // event handling in SDL (reads events from event queue and place events on event queue)
        while (SDL_PollEvent(&event)) { // removes the next event from the event queue. If there are no events on the queue
            // it returns 0, else it returns 1
            switch (event.type) {
                case SDL_QUIT:
                    menuChecker = 0;
                    break;
            }

        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;


}

