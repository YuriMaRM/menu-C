#ifndef INDEX
#define INDEX

// Includes
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct score
{
    char name[3];
    size_t value;
} SCORE;

// Helpers
void fileHandler(FILE *arquivo);
void setCursorVisibility(size_t visibility);
void setCursorPosition(int x, int y);


// Screens
void creditos();
void historia();
void jogar();
void ranking();

// Menu
void deleteCursor(int opcaoAtual);
void printCursor(int opcaoAtual);
void printMenu();
void setup();

#endif