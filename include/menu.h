#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_ITENS 10
#define MAX_TEXTO 50

// Estrutura para representar um item do menu
typedef struct
{
    char texto[MAX_TEXTO];
    int selecionado;
} MenuItem;

// Estrutura para o menu principal
typedef struct
{
    MenuItem itens[MAX_ITENS];
    int numItens;
    int itemAtual;
} Menu;

// Funções do menu
Menu *criarMenu();
void destruirMenu(Menu *menu);
void desenharMenu(Menu *menu);
void moverSelecao(Menu *menu, int direcao);
int processarInputMenu(Menu *menu);

#endif // MENU_H