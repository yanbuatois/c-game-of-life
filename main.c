#include <stdio.h>
#include <curses.h>

int main() {
    initscr();
    printw("Hello, World!\n");
    refresh();
    getch();
    endwin();
    return 0;
}
