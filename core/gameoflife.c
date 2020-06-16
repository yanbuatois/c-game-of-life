#include "gameoflife.h"

void freeGrid(char** grid) {
    for (unsigned int i = 0; i < GOL_HEIGHT; ++i) {
        free(grid[i]);
    }

    free(grid);
}

char** createGrid() {
    char** grid = calloc(GOL_HEIGHT, sizeof(char*));

    for (unsigned int i = 0; i < GOL_HEIGHT; ++i) {
        grid[i] = calloc(GOL_WIDTH, sizeof(char));
        for (unsigned int j = 0; j < GOL_WIDTH; ++j) {
            grid[i][j] = DEAD;
        }
    }

    return grid;
}

char** copyGrid(char*** grid_ptr) {
    const char** grid = *grid_ptr;
    char** copy = createGrid();
    for (unsigned int i = 0; i < GOL_HEIGHT; ++i) {
        for (unsigned int j = 0; j < GOL_WIDTH; ++j) {
            copy[i][j] = grid[i][j];
        }
    }

    return copy;
}

char** initGameOfLife(unsigned int width, unsigned int height) {
    GOL_HEIGHT = height;
    GOL_WIDTH = width;
    GAME_OF_LIFE = createGrid();

    return GAME_OF_LIFE;
}

char** playGameOfLifeTurn() {
    char** oldState = copyGrid(&GAME_OF_LIFE);

    for (unsigned int i = 0; i < GOL_HEIGHT; ++i) {
        for (unsigned int j = 0; j < GOL_WIDTH; ++j) {
            unsigned char aliveNeighbours = 0;
            unsigned char isAlive = oldState[i][j];
            unsigned int maxX = (j + 1) >= GOL_WIDTH ? (GOL_WIDTH - 1) : (j + 1);
            unsigned int maxY = (i + 1) >= GOL_HEIGHT ? (GOL_HEIGHT - 1) : (i + 1);
            for (unsigned int x = ((j - 1) < 0 ? 0 : (j - 1)); x < maxX; ++x) {
                for (unsigned int y = ((i - 1) < 0 ? 0 : (i - 1)); y < maxY; ++y) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    aliveNeighbours += oldState[y][x] ? 1 : 0;
                    if (aliveNeighbours > 3) {
                        goto endNeighboursVisit;
                    }
                }
            }

            endNeighboursVisit: if (isAlive && (aliveNeighbours < 2 || aliveNeighbours > 3)) {
                GAME_OF_LIFE[i][j] = DEAD;
            } else if (!isAlive && aliveNeighbours == 3) {
                GAME_OF_LIFE[i][j] = ALIVE;
            }
        }
    }

    freeGrid(oldState);
}

void freeGameOfLife() {
    freeGrid(GAME_OF_LIFE);
}