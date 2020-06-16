#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H

#include <stdlib.h>

#define DEAD 0
#define ALIVE 1

char** GAME_OF_LIFE;
unsigned int GOL_WIDTH = 4096;
unsigned int GOL_HEIGHT = 4096;

char** initGameOfLife(unsigned int width, unsigned int height);
char** playGameOfLifeTurn();
void freeGameOfLife();

#endif //GAMEOFLIFE_GAMEOFLIFE_H
