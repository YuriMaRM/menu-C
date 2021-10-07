#include "index.h"

int main()
{
    start();
    int opcaoAtual = 1;
    while (1) // enqaunto o menu for true o menu continua
    {
        selecaoMenu(opcaoAtual);
        switch (getch()) // getch espera um valor e verifica o valor no switch
        {
        case '1': // caso ele queria que a opção do menu suba
            if (opcaoAtual > 1)
            {
                apagarSelecaoMenu(opcaoAtual);
                opcaoAtual--;
            }
            break;
        case '3': // caso ele queria que a opção do menu desça
            if (opcaoAtual < 5)
            {
                apagarSelecaoMenu(opcaoAtual);
                opcaoAtual++;
            } // aumenta a opcaoAtual em 1
            break;
        case '2':                // caso ele escolha uma opção
            if (opcaoAtual != 5) // verifica se o usuario não escolheu apenas por sair
            {
                system("cls");
                switch (opcaoAtual) // verifica qual opção foi escolhida
                {
                case 1:
                    jogar();
                    break;
                case 2:
                    historia(); // executa a opção historia
                    break;
                case 3:
                    ranking(); // executa a opção ranking
                    break;
                case 4:
                    creditos(); // executa a opção creditos
                    break;
                }
                opcaoAtual = 1; // seta a opcaoAatual em 1 para voltar a primeira posição

                getch(); // pausa o sistema
                cabessarioMenu();
            }
            else
                return 0; // finaliza o menu
            break;
        default:
            break; // volta ao inicio do menu
        }
    }
}