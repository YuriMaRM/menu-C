#include "./lib/index.h"

int main()
{
    // Configurações iniciais
    FILE *scoresFile = fopen("./arquivos/scores.bin", "ab");
    fclose(scoresFile);
    setCursorVisibility(0);
    system("chcp 65001");

    printMenu();
    size_t opcaoAtual = 1;

    while (1)
    {
        printCursor(opcaoAtual);

        switch (toupper(getch()))
        {
        case 'W':
            deleteCursor(opcaoAtual);
            opcaoAtual = opcaoAtual > 1 ? opcaoAtual - 1 : 5;
            break;
        case 'S':
            deleteCursor(opcaoAtual);
            opcaoAtual = opcaoAtual < 5 ? opcaoAtual + 1 : 1;
            break;
        case 'D':
            if (opcaoAtual == 5)
                return 0;

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
            break;
        default:
            break;
        }
    }
}