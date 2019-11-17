#include <stdbool.h>
#include<time.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Board Color Indicies
#define GREEN 0
#define ORANGE 1
#define YELLOW 2

#define HUMAN 3
#define RANDOM 4
#define WIN 5

void printBoard(int board[3]);
int *choose(int board[3]);
int *randomCPU(int board[3]);
int *winCPU(int board[3]);
void move(int board[3], int move[2]);
int main(int argc, char *argv[]);