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

// Functions
void deleteCursorMenu(int opcaoAtual);
void printCursorMenu(int opcaoAtual);

void printMenu();

void creditos();
void historia();
void jogar();
void ranking();
void setup();

#endif