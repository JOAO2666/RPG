#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"

int main()
{
    // Criar menu
    Menu *menu = criarMenu();
    if (!menu)
    {
        printf("Erro ao criar menu\n");
        return 1;
    }

    // Loop principal
    int executando = 1;

    while (executando)
    {
        // Desenhar menu
        desenharMenu(menu);

        // Processar input
        int resultado = processarInputMenu(menu);
        if (resultado > 0)
        {
            switch (resultado)
            {
            case 1: // Novo Jogo
                printf("\n    Iniciando novo jogo...\n");
                system("pause");
                break;
            case 2: // Carregar Jogo
                printf("\n    Carregando jogo...\n");
                system("pause");
                break;
            case 3: // Opções
                printf("\n    Abrindo opções...\n");
                system("pause");
                break;
            case 4: // Sair
                executando = 0;
                break;
            }
        }
    }

    // Limpar recursos
    destruirMenu(menu);

    return 0;
}