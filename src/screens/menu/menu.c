#include "../../lib/index.h"

// Retorna o nome da opção atual
void getOpcaoAtualName(size_t opcaoAtual, char name[24])
{
    switch (opcaoAtual)
    {
    case 1:
        strcpy(name, "\x1b[32mJogar\x1b[0m    ");
        break;
    case 2:
        strcpy(name, "História ");
        break;
    case 3:
        strcpy(name, "Ranking  ");
        break;
    case 4:
        strcpy(name, "Créditos ");
        break;
    case 5:
        strcpy(name, "\x1b[31mSair\x1b[0m     ");
        break;
    default:
        break;
    }
}

// Apaga o cursor do menu e tira o bold do texto
void deleteCursor(size_t opcaoAtual)
{
    char name[24] = "";
    getOpcaoAtualName(opcaoAtual, name);

    setCursorPosition(2, opcaoAtual);
    printf("%s", name);

    setCursorPosition(11, opcaoAtual);
    printf(" ");

    setCursorPosition(1, 20);
}

// Printa o cursor do menu e coloca o bold no texto
void printCursor(size_t opcaoAtual)
{
    char name[24] = "";
    getOpcaoAtualName(opcaoAtual, name);

    setCursorPosition(2, opcaoAtual);
    printf("\033[1m%s\x1b[0m", name);

    setCursorPosition(11, opcaoAtual);
    printf("\033[96m<\x1b[0m");

    setCursorPosition(1, 20);
}

// É... Printa o menu
void printMenu()
{
    system("cls");

    printf("\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557");
    for (size_t i = 1; i <= 5; i++)
    {
        char name[24] = "";
        getOpcaoAtualName(i, name);
        setCursorPosition(0, i - 1);
        printf("\n\u2551 %s\x1b[36m \x1b[0m\u2551", name);
    }
    printf("\n\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
}
