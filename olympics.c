#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include ".//headers//console.h"
#include ".//headers//structures.h"
#include ".//headers//atletas.h"
#include ".//headers//ranking.h"


/* Função principal do programa. */
int main() {
    configurar_console();

    int escolha;

    while (1) { /* Enquanto o usuário não escolher a opção de sair */
        cabecalho();
        gotoxy(30, 12);
        printf("* MENU PRINCIPAL *");
        gotoxy(30, 14);
        printf("[1] ATLETAS\n");
        gotoxy(30, 15);
        printf("[2] RANKING\n");
        gotoxy(30, 16);
        printf("[3] CALENDÁRIO DOS JOGOS\n");
        gotoxy(30, 17);
        printf("[4] DADOS DO USUÁRIO\n");
        gotoxy(30, 18);
        printf("[0] SAIR DA APLICAÇÃO\n");
        gotoxy(30, 20);
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &escolha); /* Lê a opção */

        if (escolha >= 0 && escolha <= 4) { /* Se a opção for entre 0 e 4 */
            switch (escolha) {              /* Escolha a opção */
                case 0:                     /* Sair da aplicação */
                    gotoxy(30, 22);
                    printf("Encerrando aplicaçao\n");
                    gotoxy(30, 23);
                    exit(0); /* Encerra a aplicação */
                    break;

                case 1: /* Atletas */
                    system("cls");
                    menu_atletas();
                    break;

                case 2: /* Ranking */
                    system("cls");
                    gotoxy(30, 22);
                    menu_ranking();
                    break;

                case 3: /* Calendário */
                    system("cls");
                    gotoxy(30, 22);
                    printf("calendario (WIP)");
                    // menu_calendario ();
                    break;

                case 4: /* Dados do usuário */
                    system("cls");
                    gotoxy(30, 22);
                    printf("user (WIP)");
                    // mostrar_dados_usuario ();
                    break;
            }
        } else { /* Se a opção for inválida */
            system("cls");
            gotoxy(30, 22);
            printf("Opção inválida, tente novamente.\n");
        }
    }
    return 0; /* Encerra a aplicação */
}
