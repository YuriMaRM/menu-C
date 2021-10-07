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

// Apaga o cursor do menu
void deleteCursorMenu(int opcaoAtual)
{
    setCursorPosition(11, opcaoAtual);
    printf(" ");
}

// Insere um score no arquivo
void insertScore(SCORE *newScores)
{
    FILE *scoresFile = fopen("scores.bin", "wb");
    fileHandler(scoresFile);

    for (size_t i = 0; i < 10; i++)
        fwrite(&newScores[i], sizeof(SCORE), 1, scoresFile);
    fclose(scoresFile);
}

// Coloca o cursor do menu
void printCursorMenu(int opcaoAtual)
{
    setCursorPosition(11, opcaoAtual);
    printf("\033[96m<\x1b[0m");
    setCursorPosition(1, 20);
}

// Configurações iniciais
void setup()
{
    FILE *scoresFile = fopen("scores.bin", "ab");
    fclose(scoresFile);
    setCursorVisibility(0);
    system("chcp 65001");
}

// Printa o ranking
void printRanking(SCORE *scores)
{
    printf("\033[1mRANKING\n\n");

    printf("  NOME \t\t PONTOS\033[0m\n");
    for (size_t i = 0; i < 10; i++)
        printf("%2d - %s \t %d\n", i + 1, scores[i].name, scores[i].value);
}

// Seta um ponteiro com os scores armazenados
void getScores(SCORE *scores)
{
    size_t i = 0;
    FILE *scoresFile = fopen("scores.bin", "rb");
    fileHandler(scoresFile);
    SCORE aux;

    for (i = 0; fread(&aux, sizeof(SCORE), 1, scoresFile); i++)
        scores[i] = aux;

    fclose(scoresFile);
    for (; i < 10; i++)
    {
        strcpy(scores[i].name, "***");
        scores[i].value = 0;
    }
}

// Recebe scores e newScore e insere o newScore na posição apropriada
void orderRanking(SCORE *scores, SCORE newScore)
{
    int i;
    SCORE copyNewScore = newScore;
    for (i = 9; i >= 0 && scores[i].value < copyNewScore.value; i--)
        scores[i + 1] = scores[i];
    scores[i + 1] = copyNewScore;
}

void creditos()
{
    printf("Empresa Séria\n\n");

    printf("Luiz\nYuri\n");

    getch();
}

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

void jogar()
{
    setCursorVisibility(1);
    SCORE scores[10], newScore;
    getScores(scores);

    printf("Nome: A**");
    int charASCII = 65;
    size_t posicao = 0;

    setCursorPosition(21, 0);
    printf("Pontos: ");
    setCursorPosition(6, 0);

    while (posicao < 3)
    {
        switch (toupper(getch()))
        {
        case 'W':
            (charASCII > 65) ? charASCII-- : (charASCII = 90);
            newScore.name[posicao] = (char)charASCII;
            break;
        case 'S':
            (charASCII < 90) ? charASCII++ : (charASCII = 65);
            newScore.name[posicao] = (char)charASCII;
            break;
        case 'D':
            charASCII = 65;

            if (((int)newScore.name[posicao] <= 90) && ((int)newScore.name[posicao] >= 65))
                charASCII = (int)newScore.name[posicao];
            else
                newScore.name[posicao] = (char)charASCII;

            posicao++;
            break;
        case 'A':
            if (posicao > 0)
            {
                posicao--;
                charASCII = (int)newScore.name[posicao];
            }
            break;
        default:
            break;
        }

        setCursorPosition(6 + posicao, 0);
        if (posicao < 3)
            printf("%c", charASCII);
        setCursorPosition(6 + posicao, 0);
    }

    setCursorPosition(29, 0);
    scanf("%d", &newScore.value);

    orderRanking(scores, newScore);
    insertScore(scores);
    setCursorVisibility(0);
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

void ranking()
{
    SCORE score[10];

    getScores(score);
    printRanking(score);

    getch();
}
