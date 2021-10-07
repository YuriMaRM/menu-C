#include "index.h"

// Valida se o arquivo foi aberto corretamente
void fileHandler(FILE *arquivo)
{
    if (arquivo == NULL)
    {
        printf("\x1b[31mError ao abrir o arquivo!\x1b[0m");
        exit(1);
    }
}

// Seta a posição do cursor
void setCursorPosition(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Recebe 1 ou 0 para mostrar ou não o cursor
void setCursorVisibility(size_t visibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;

    GetConsoleCursorInfo(handle, &cursor);
    cursor.bVisible = visibility ? TRUE : FALSE;
    SetConsoleCursorInfo(handle, &cursor);
}