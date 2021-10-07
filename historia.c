#include "index.h"


void historia()
{
    char historia[] = "Não temos história ainda :)";
    printf("História \n");
    for (size_t i = 0; i < sizeof(historia); i++)
    {
        printf("%c", historia[i]);
        Sleep(5);
    }

    while (kbhit())
        getch();

    getch();
}
