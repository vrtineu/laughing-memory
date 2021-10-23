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
    gotoxy (19, 2);
    printf ("       _                       _          \n");
    gotoxy (19, 3);
    printf ("      | |                     (_)         \n");
    gotoxy (19, 4);
    printf ("  ___ | |_   _ _ __ ___  _ __  _  ___ ___ \n");
    gotoxy (19, 5);
    printf (" / _ \\| | | | | '_ ` _ \\| '_ \\| |/ __/ __|\n");
    gotoxy (19, 6);
    printf ("| (_) | | |_| | | | | | | |_) | | (__\\__ \\\n");
    gotoxy (19, 7);
    printf (" \\___/|_|\\__, |_| |_| |_| .__/|_|\\___|___/\n");
    gotoxy (19, 8);
    printf ("          __/ |         | |               \n");
    gotoxy (19, 9);
    printf ("         |___/          |_|               \n");
}

/* Estrutura para paises */
typedef struct paises {
    int id_pais;
    char nome_pais[MAX];
    int medalha_ouro;
    int medalha_prata;
    int medalha_bronze;
    int total_medalhas;
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
    char ultimo_nome[MAX];
    char pais[MAX];
    char modalidade[MAX];
};
struct atletas atl;

/* Cadastrar atleta */
void cadastrar_atleta () {
    FILE* banco_atletas;

    cabecalho ();

    int novo_id;
    int maior_id = 0;

    banco_atletas = fopen (".//banco-de-dados//atletas.txt", "r");
    if (banco_atletas == NULL) {
        printf ("Erro ao abrir arquivo\n");
        exit (1);
    }
    while (!feof (banco_atletas)) {
        fscanf (banco_atletas, "%d;%s;%s;%s\n", &atl.id_atleta, &atl.nome, &atl.pais, &atl.modalidade);
        if (atl.id_atleta > maior_id) {
            maior_id = atl.id_atleta;
        }
    }
    novo_id = maior_id + 1;
    fclose (banco_atletas);

    banco_atletas = fopen (".//banco-de-dados//atletas.txt", "a");
    if (banco_atletas == NULL) {
        printf ("Erro ao abrir arquivo\n");
        exit (1);
    }

    fflush (stdin);
    gotoxy (27, 14);
    printf ("Digite o nome do atleta: ");
    fgets (atl.nome, MAX, stdin);

    fflush (stdin);
    gotoxy (27, 15);
    printf ("Digite o ultimo nome do atleta: ");
    fgets (atl.ultimo_nome, MAX, stdin);

    fflush (stdin);
    gotoxy (27, 16);
    printf ("Digite o pais do atleta: ");
    fgets (atl.pais, MAX, stdin);

    fflush (stdin);
    gotoxy (27, 17);
    printf ("Digite a modalidade do atleta: ");
    fgets (atl.modalidade, MAX, stdin);

    atl.nome[strlen (atl.nome) - 1] = '\0';
    atl.ultimo_nome[strlen (atl.ultimo_nome) - 1] = '\0';
    atl.pais[strlen (atl.pais) - 1] = '\0';
    atl.modalidade[strlen (atl.modalidade) - 1] = '\0';

    fprintf (banco_atletas, "\n%d;%s;%s;%s;%s", novo_id, atl.nome, atl.ultimo_nome, atl.pais, atl.modalidade);
    fclose (banco_atletas);
    system ("cls");
    menu_atletas ();
}

/* Listar atletas */
void listar_atletas () {
    FILE* banco_atletas;

    char linha[MAX];
    char* coluna[MAX];

    cabecalho ();

    banco_atletas = fopen (".//banco-de-dados//atletas.txt", "r");
    if (banco_atletas == NULL) {
        printf ("Erro ao abrir arquivo\n");
        exit (1);
    }

    while (!feof (banco_atletas)) {
        fscanf (banco_atletas, "%d;%s;%s;%s\n", &atl.id_atleta, &linha);

        *coluna = strtok (linha, ";");
        gotoxy (30, 14);
        printf ("ID: %d\n", atl.id_atleta);
        gotoxy (30, 15);
        printf ("Nome: %s ", *coluna);
        *coluna = strtok (NULL, ";");
        printf ("%s\n", *coluna);

        *coluna = strtok (NULL, ";");
        gotoxy (30, 16);
        printf ("Pais: %s\n", *coluna);

        *coluna = strtok (NULL, ";");
        gotoxy (30, 17);
        printf ("Modalidade: %s\n", *coluna);

        gotoxy (30, 20);
        printf ("Deseja ver o proximo atleta?\n");
        gotoxy (30, 21);
        printf ("'S' para continuar\n");
        gotoxy (30, 22);
        printf ("'N' para voltar ao menu\n");
        gotoxy (30, 23);
        printf ("Digite a opcao: ");
        fflush (stdin);
        char escolha = getche ();
        if (escolha == 'N' || escolha == 'n') {
            fclose (banco_atletas);
            main ();
        } else {
            system ("cls");
            cabecalho ();
            continue;
        }
        fclose (banco_atletas);
        menu_atletas ();
    }
}

/* Procurar atletas pelo id. */
void buscar_atleta_id () {
    FILE* banco_atletas;

    char linha[MAX];
    char* coluna[MAX];
    int id_busca;

pesquisar:
    cabecalho ();

    gotoxy (30, 14);
    printf ("Digite o ID do atleta: ");
    fflush (stdin);
    scanf ("%d", &id_busca);
    system ("cls");
    
    cabecalho ();

    banco_atletas = fopen (".//banco-de-dados//atletas.txt", "r");
    if (banco_atletas == NULL) {
        printf ("Erro ao abrir arquivo\n");
        exit (1);
    }

    while (!feof (banco_atletas)) {
        fscanf (banco_atletas, "%d;%s;%s;%s\n", &atl.id_atleta, &linha);

        if (id_busca == atl.id_atleta) {
            *coluna = strtok (linha, ";");
            gotoxy (30, 14);
            printf ("ID: %d\n", atl.id_atleta);
            gotoxy (30, 15);
            printf ("Nome: %s ", *coluna);
            *coluna = strtok (NULL, ";");
            printf ("%s\n", *coluna);

            *coluna = strtok (NULL, ";");
            gotoxy (30, 16);
            printf ("Pais: %s\n", *coluna);

            *coluna = strtok (NULL, ";");
            gotoxy (30, 17);
            printf ("Modalidade: %s\n", *coluna);

            gotoxy (30, 20);
            printf ("Deseja buscar outro atleta?");
            gotoxy (30, 21);
            printf ("'S' para continuar\n");
            gotoxy (30, 22);
            printf ("'N' para voltar ao menu\n");
            gotoxy (30, 23);
            printf ("Digite a opcao: ");
            fflush (stdin);
            char escolha = getche ();
            if (escolha == 'N' || escolha == 'n') {
                fclose (banco_atletas);
                menu_atletas ();
            } else {
                system ("cls");
                goto pesquisar;
            }
        } else {
            continue;
        }
    }
    fclose (banco_atletas);
    system ("cls");
    cabecalho ();
    gotoxy (30, 14);
    printf ("Atleta nao encontrado\n");
    gotoxy (20, 17);
    system ("pause");
    system ("cls");
}

/* Menu de opção para atletas */
void menu_atletas () {
    system ("cls");

    int escolha_atletas;

    while (escolha_atletas != 4) {
        cabecalho ();
        gotoxy (30, 12);
        printf ("* MENU ATLETAS *");
        gotoxy (30, 14);
        printf ("[1] LISTAR ATLETAS\n");
        gotoxy (30, 15);
        printf ("[2] CONSULTAR ATLETAS POR ID\n");
        gotoxy (30, 16);
        printf ("[3] CADASTRAR NOVO ATLETA\n");
        gotoxy (30, 17);
        printf ("[4] VOLTAR PARA O MENU PRINCIPAL");
        gotoxy (30, 18);
        printf ("Escolha uma opcao: ");
        fflush (stdin);
        scanf ("%d", &escolha_atletas);

        if (escolha_atletas >= 1 && escolha_atletas <= 4) {
            switch (escolha_atletas) {
                case 1:
                    system ("cls");
                    listar_atletas ();
                    break;

                case 2:
                    system ("cls");
                    buscar_atleta_id ();
                    break;

                case 3:
                    system ("cls");
                    cadastrar_atleta ();
                    break;

                case 4:
                    main ();
                    break;
            }
        } else {
            system ("cls");
            gotoxy (30, 21);
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
        gotoxy (30, 12);
        printf ("* MENU PRINCIPAL *");
        gotoxy (30, 14);
        printf ("[1] ATLETAS\n");
        gotoxy (30, 15);
        printf ("[2] RANKING\n");
        gotoxy (30, 16);
        printf ("[3] CALENDARIO DOS JOGOS\n");
        gotoxy (30, 17);
        printf ("[4] DADOS DO USUARIO\n");
        gotoxy (30, 18);
        printf ("[0] SAIR DA APLICACAO\n");
        gotoxy (30, 19);
        printf ("Escolha uma opcao: ");
        fflush (stdin);
        scanf ("%d", &escolha);

        if (escolha >= 0 && escolha <= 4) {
            switch (escolha) {
                case 0:
                    gotoxy (30, 21);
                    printf ("Encerrando aplicacao\n");
                    gotoxy (30, 23);
                    exit (0);
                    break;

                case 1:
                    system ("cls");
                    menu_atletas ();
                    break;

                case 2:
                    system ("cls");
                    gotoxy (30, 21);
                    printf ("ranking");
                    // menu_ranking ();
                    break;

                case 3:
                    system ("cls");
                    gotoxy (30, 21);
                    printf ("calendario");
                    // menu_calendario ();
                    break;

                case 4:
                    system ("cls");
                    gotoxy (30, 21);
                    printf ("user");
                    // mostrar_dados_usuario ();
                    break;
            }
        } else {
            system ("cls");
            gotoxy (30, 21);
            printf ("Opcao invalida, tente novamente.\n");
        }
    }
    return 0;
}