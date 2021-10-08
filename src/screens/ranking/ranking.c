#include "../../lib/index.h"

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

// Printa o ranking
void printRanking(SCORE *scores)
{
    printf("\033[1mRANKING\n\n");

    printf("  NOME \t\t PONTOS\033[0m\n");
    for (size_t i = 0; i < 10; i++)
        printf("%2d - %s \t %d\n", i + 1, scores[i].name, scores[i].value);
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

void ranking()
{
    SCORE score[10];

    getScores(score);
    printRanking(score);

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
            if (charASCII > 65)
                charASCII--;
            else
                (charASCII = 90);

            newScore.name[posicao] = (char)charASCII;
            break;
        case 'S':
            if (charASCII < 90)
                charASCII++;
            else
                (charASCII = 65);

            newScore.name[posicao] = (char)charASCII;
            break;
        case 'D':
            if (((int)newScore.name[posicao + 1] <= 90) && ((int)newScore.name[posicao + 1] >= 65) && (posicao < 3))
                charASCII = (int)newScore.name[posicao + 1];
            else
            {
                newScore.name[posicao] = (char)charASCII;
                charASCII = 65;
            }

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
