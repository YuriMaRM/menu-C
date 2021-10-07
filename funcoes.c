#include "index.h"

void setPositionCursor(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void fileHandler(FILE *arquivo)
{
    if (arquivo == NULL)
    {
        printf("Error ao abrir o arquivo");
        exit(1);
    }
}

void apagarCursor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;

    GetConsoleCursorInfo(handle, &cursor);
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &cursor);
}

void apagarSelecaoMenu(int opcaoAtual)
{
    setPositionCursor(11, opcaoAtual);
    printf(" \u2551");
}

void viewRanking(Pontuacao *pontuacao)
{
    printf("PONTUACAO\n");
    for (size_t i = 0; i < 10; i++)
        printf("%2d) Nome: %s   || Pontos: %d\n", (int)i + 1, pontuacao[i].nome, pontuacao[i].valor);
}

void selectRanking(Pontuacao *pontuacao)
{
    size_t i = 0;
    FILE *ranking = fopen("pontuacao.bin", "rb");
    fileHandler(ranking);
    Pontuacao aux;
    for (i = 0; fread(&aux, sizeof(Pontuacao), 1, ranking); i++)
        pontuacao[i] = aux;
    fclose(ranking);
    if (i != 10)
    {
        for (; i < 10; i++)
        {
            strcpy(pontuacao[i].nome, "***");
            pontuacao[i].valor = 0;
        }
    }
}

void orderRanking(Pontuacao *pontuacao)
{
    for (int j, i = 1; i < 11; i++)
    {
        Pontuacao aux = pontuacao[i];
        for (j = i - 1; j >= 0 && pontuacao[j].valor < aux.valor; j--)
            pontuacao[j + 1] = pontuacao[j];
        pontuacao[j + 1] = aux;
    }
}

void insertPontuacao(Pontuacao *pontuacao)
{
    FILE *ranking = fopen("pontuacao.bin", "wb");
    fileHandler(ranking);
    for (size_t i = 0; i < 10; i++)
        fwrite(&pontuacao[i], sizeof(Pontuacao), 1, ranking);
    fclose(ranking);
}

// Globais

// Primeira
void start()
{
    FILE *arquivo = fopen("pontuacao.bin", "ab");
    fclose(arquivo);
    apagarCursor();
    system("chcp 65001"); // definindo o terminal como UTF-8
    cabessarioMenu();
}

// Opcoes do menu
void jogar()
{
    Pontuacao pontuacao[11];
    printf("Nome: A**");
    selectRanking(pontuacao);
    int charASCII = 65;
    int posicao = 0;
    while (posicao < 3)
    {
        switch (getch())
        {
        case '1':
            if (charASCII < 90)
            {
                charASCII++;
            }
            break;
        case '2':
            pontuacao[10].nome[posicao] = charASCII;
            posicao++;
            charASCII = 65;
            break;
        case '3':
            if (charASCII > 65)
            {
                charASCII--;
            }
            break;
        default:
            break;
        }

        setPositionCursor(6 + posicao, 0);
        printf("%c", charASCII);
        setPositionCursor(20, 0);
    }
    printf("Insira a pontuação");
    scanf("%d", &pontuacao[10].valor);
    printf("Nome: %s\nPontos: %d\n\n\n\n", pontuacao[10].nome, pontuacao[10].valor);

    orderRanking(pontuacao);
    viewRanking(pontuacao);
    insertPontuacao(pontuacao);
}

void historia()
{
    char historia[] = "Um adorável ratinho que, após se deparar\ncom a grandiosa Lua, imagina que ela é\nfeita de queijo. O ratinho então reúne \nseus esforços para chegar através de \nsaltos entre meteoros em seu tão sonhado\nobjetivo. Em seu trajeto ele irá se\nmeter em altas confusões. Conseguirá o \npobre ratinho comer Lua?";
    printf("História \n");
    for (size_t i = 0; i < sizeof(historia); i++)
    {
        printf("%c", historia[i]); // printa uma lentra da historia do jogo
        Sleep(5);                  // delay
    }
    while (kbhit()) // Repete enquanto tiver algo que foi digitado enquanto passava a historia
        getch();    // consome um digito
}

void ranking()
{
    Pontuacao pontuacao[10];

    selectRanking(pontuacao);
    viewRanking(pontuacao);
}

void creditos()
{
    printf("Quatro ++\n");
    getch(); // paradinha pra fazer
    printf("\nEmilly\nGuilherme\nLuiz\nMaria\nYuri\n");
}

// Outras
void cabessarioMenu()
{
    system("cls");
    printf("\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557"); // barra de cima do menu
    printf("\n\u2551 \x1b[32mJogar\x1b[0m    \x1b[36m \x1b[0m\u2551");                        // opção jogar
    printf("\n\u2551 Historia \x1b[36m \x1b[0m\u2551");                                       // opção historia
    printf("\n\u2551 Ranking  \x1b[36m \x1b[0m\u2551");                                       // opção ranking
    printf("\n\u2551 Creditos \x1b[36m \x1b[0m\u2551");                                       // opção creditos
    printf("\n\u2551 \x1b[31mSair\x1b[0m     \x1b[36m \x1b[0m\u2551");                        // opção sair
    printf("\n\u255A\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D\n");
}

void selecaoMenu(int opcaoAtual)
{
    setPositionCursor(11, opcaoAtual);
    printf("<\u2563");
    setPositionCursor(1, 20);
}
