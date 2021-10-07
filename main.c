#include "index.h"

int main()
{
    setup();
    printMenu();

    int opcaoAtual = 1;

    while (1)
    {
        printCursorMenu(opcaoAtual);

        switch (toupper(getch()))
        {
        case 'W':
            if (opcaoAtual > 1)
            {
                deleteCursorMenu(opcaoAtual);
                opcaoAtual--;
            }
            break;
        case 'S':
            if (opcaoAtual < 5)
            {
                deleteCursorMenu(opcaoAtual);
                opcaoAtual++;
            }
            break;
        case 'D':
            if (opcaoAtual != 5)
            {
                system("cls");
                switch (opcaoAtual)
                {
                case 1:
                    jogar();
                    break;
                case 2:
                    historia();
                    break;
                case 3:
                    ranking();
                    break;
                case 4:
                    creditos();
                    break;
                }

                printMenu();
            }
            else
                return 0;
            break;
        default:
            break;
        }
    }
}