#include "index.h"

void setPositionCursor(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), c);
}


int main()
{
    
    setPositionCursor(20, 5);
    printf("Teste");

    setPositionCursor(23, 5);
    printf("<");
    getchar();
/*     printf("Coloque um nome 3 caracteres");
    for (size_t i = 0; i < 3; i++)
        scanf("%c", &pontuacao[10].nome[i]);
    
    fflush(stdin);
    printf("Insira a pontuação");
    scanf("%d", &pontuacao[10].valor);
    printf("Nome: %s\nPontos: %d\n\n\n\n", pontuacao[10].nome, pontuacao[10].valor); */



    return 0;
}



