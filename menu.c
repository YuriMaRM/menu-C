#include "index.h"

// Configurações iniciais
void setup()
{
    FILE *scoresFile = fopen("scores.bin", "ab");
    fclose(scoresFile);
    setCursorVisibility(0);
    system("chcp 65001");
}

// Apaga o cursor do menu
void deleteCursor(int opcaoAtual)
{
    setCursorPosition(11, opcaoAtual);
    printf(" ");
}

// Coloca o cursor do menu
void printCursor(int opcaoAtual)
{
    setCursorPosition(11, opcaoAtual);
    printf("\033[96m<\x1b[0m");
    setCursorPosition(1, 20);
}

void printMenu()
{
    system("cls");
    printf("\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557");
    printf("\n\u2551 \x1b[32mJogar\x1b[0m    \x1b[36m \x1b[0m\u2551");
    printf("\n\u2551 Historia \x1b[36m \x1b[0m\u2551");
    printf("\n\u2551 Ranking  \x1b[36m \x1b[0m\u2551");
    printf("\n\u2551 Creditos \x1b[36m \x1b[0m\u2551");
    printf("\n\u2551 \x1b[31mSair\x1b[0m     \x1b[36m \x1b[0m\u2551");
    printf("\n\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
}
