#include "../include/menu.h"

Menu *criarMenu()
{
    Menu *menu = (Menu *)malloc(sizeof(Menu));
    if (!menu)
        return NULL;

    menu->numItens = 4;
    menu->itemAtual = 0;

    // Configurar itens do menu
    const char *textos[] = {
        "Novo Jogo",
        "Carregar Jogo",
        "Opcoes",
        "Sair"};

    for (int i = 0; i < menu->numItens; i++)
    {
        strncpy(menu->itens[i].texto, textos[i], MAX_TEXTO - 1);
        menu->itens[i].texto[MAX_TEXTO - 1] = '\0';
        menu->itens[i].selecionado = (i == 0);
    }

    return menu;
}

void destruirMenu(Menu *menu)
{
    if (menu)
    {
        free(menu);
    }
}

void desenharMenu(Menu *menu)
{
    system("cls"); // Limpa a tela (Windows)
    printf("\n\n");
    printf("    ====================================\n");
    printf("    |          RPG DE LUTA            |\n");
    printf("    ====================================\n\n");

    for (int i = 0; i < menu->numItens; i++)
    {
        if (menu->itens[i].selecionado)
        {
            printf("    > %s <\n", menu->itens[i].texto);
        }
        else
        {
            printf("      %s\n", menu->itens[i].texto);
        }
    }
    printf("\n    Use as setas para navegar e ENTER para selecionar\n");
}

void moverSelecao(Menu *menu, int direcao)
{
    if (!menu)
        return;

    menu->itens[menu->itemAtual].selecionado = 0;

    menu->itemAtual += direcao;
    if (menu->itemAtual < 0)
        menu->itemAtual = menu->numItens - 1;
    if (menu->itemAtual >= menu->numItens)
        menu->itemAtual = 0;

    menu->itens[menu->itemAtual].selecionado = 1;
}

int processarInputMenu(Menu *menu)
{
    if (!menu)
        return 0;

    int tecla = getch();

    if (tecla == 224)
    { // Tecla especial (setas)
        tecla = getch();
        switch (tecla)
        {
        case 72: // Seta para cima
            moverSelecao(menu, -1);
            return 0;
        case 80: // Seta para baixo
            moverSelecao(menu, 1);
            return 0;
        }
    }
    else if (tecla == 13)
    { // Enter
        return menu->itemAtual + 1;
    }

    return 0;
}