#ifndef INDEX
    #define INDEX
    // Includes
    #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>
    #include <windows.h> 

    typedef struct pontuacao{
        int valor;
        char nome[3];
    } Pontuacao;

    // Functions
    void start();
    void historia();
    void ranking(); 
    void creditos(); 
    void selecaoMenu(int opcaoAtual);
    void jogar();
    void cabessarioMenu();
    void apagarSelecaoMenu(int opcaoAtual);
#endif