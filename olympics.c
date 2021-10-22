#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#define MAX 50

void gotoxy (short x, short y) {
    COORD pos = {
      x,
      y
    };
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos);
}

/* Exibe cabeçalho no centro da tela com a palavra "olympics". */
void cabecalho () {
    gotoxy (15, 2);
    printf ("       _                       _          \n");
    gotoxy (15, 3);
    printf ("      | |                     (_)         \n");
    gotoxy (15, 4);
    printf ("  ___ | |_   _ _ __ ___  _ __  _  ___ ___ \n");
    gotoxy (15, 5);
    printf (" / _ \\| | | | | '_ ` _ \\| '_ \\| |/ __/ __|\n");
    gotoxy (15, 6);
    printf ("| (_) | | |_| | | | | | | |_) | | (__\\__ \\\n");
    gotoxy (15, 7);
    printf (" \\___/|_|\\__, |_| |_| |_| .__/|_|\\___|___/\n");
    gotoxy (15, 8);
    printf ("          __/ |         | |               \n");
    gotoxy (15, 9);
    printf ("         |___/          |_|               \n");
}

/* Estrutura para paises */
typedef struct paises {
    int id_pais;
    char nome_pais[MAX];
};
struct paises pai;

/* Estrutura para esportes */
typedef struct esportes {
    int id_esporte;
    char nome_modalidades[MAX];
};
struct esportes esp;

/* Estrutura para atletas */
typedef struct atletas {
    int id_atleta;
    char nome[MAX];
    char pais[MAX];
    char modalidade[MAX];
};
struct atletas atl;

void menu_atletas () {
    system ("cls");

    int escolha_atletas;

    while (escolha_atletas != 4) {
        cabecalho ();
        gotoxy (25, 12);
        printf ("* MENU ATLETAS *");
        gotoxy (25, 14);
        printf ("[1] LISTAR ATLETAS\n");
        gotoxy (25, 15);
        printf ("[2] CONSULTAR ATLETAS POR ID\n");
        gotoxy (25, 16);
        printf ("[3] CADASTRAR NOVO ATLETA\n");
        gotoxy (25, 17);
        printf ("[4] VOLTAR PARA O MENU PRINCIPAL");
        gotoxy (25, 18);
        printf ("Escolha uma opcao: ");
        fflush (stdin);
        scanf ("%d", &escolha_atletas);
        
        if (escolha_atletas >= 1 && escolha_atletas <= 4) {
            switch (escolha_atletas) {
                case 1: 
                    // listar_atletas ();
                    break;

                case 2:
                    // buscar_atleta ();
                    break;

                case 3:
                    // cadastrar_atleta ();
                    break;
                
                case 4:
                    main();
                    break;
            }
        } else {
            system ("cls");
            gotoxy (25, 21);
            printf ("Opcao invalida, tente novamente\n");
        }
    }
}

void menu_ranking () {

}

void menu_calendario () {

}

void mostrar_dados_usuario () {

}

/* Função principal do programa. */
int main () {
    system ("mode 80, 25"); // setar tamanho do prompt.
    setlocale (LC_ALL, ".UTF8"); // setar padrão UTF-8.

    int escolha;

    while (1) {
        cabecalho ();
        gotoxy (25, 12);
        printf ("* MENU PRINCIPAL *");
        gotoxy (25, 14);
        printf ("[1] ATLETAS\n");
        gotoxy (25, 15);
        printf ("[2] RANKING\n");
        gotoxy (25, 16);
        printf ("[3] CALENDARIO DOS JOGOS\n");
        gotoxy (25, 17);
        printf ("[4] DADOS DO USUARIO\n");
        gotoxy (25, 18);
        printf ("[0] SAIR DA APLICACAO\n");
        gotoxy (25, 19);
        printf ("Escolha uma opcao: ");
        fflush (stdin);
        scanf ("%d", &escolha);

        if (escolha >= 0 && escolha <= 4) {
            switch (escolha) {
                case 0:
                    gotoxy (25, 21);
                    printf ("Encerrando aplicacao\n");
                    gotoxy (25, 23);
                    system ("pause");
                    exit (0);
                    break;

                case 1:
                    system ("cls");
                    menu_atletas ();
                    break;

                case 2:
                    system ("cls");
                    gotoxy (25, 21);
                    printf ("ranking");
                    // menu_ranking ();
                    break;

                case 3:
                    system ("cls");
                    gotoxy (25, 21);
                    printf ("calendario");
                    // menu_calendario ();
                    break;

                case 4:
                    system ("cls");
                    gotoxy (25, 21);
                    printf ("user");
                    // mostrar_dados_usuario ();
                    break;
            }
        } else {
            system ("cls");
            gotoxy (25, 21);
            printf ("Opcao invalida, tente novamente.\n");
        }
    }
    return 0;
}