#pragma once

/* Exibir menu de ranking */
void menu_ranking() {
    system("cls");

    int escolha_ranking;

    while (escolha_ranking != 3) {
        cabecalho();
        gotoxy(30, 12);
        printf("* MENU RANKING *");
        gotoxy(30, 14);
        printf("[1] RANKING DE PAISES\n");
        gotoxy(30, 15);
        printf("[2] ATRIBUIÇÃO DE MEDALHAS\n");
        gotoxy(30, 16);
        printf("[3] VOLTAR PARA O MENU PRINCIPAL\n");
        gotoxy(30, 18);
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &escolha_ranking);

        if (escolha_ranking >= 1 && escolha_ranking <= 3) { /* Se a opção for entre 1 e 2 */
            switch (escolha_ranking) {                      /* Escolha a opção */
                case 1:                                     /* Ranking de paises */
                    system("cls");
                    ranking_paises();
                    break;

                case 2: /* Atribuição de medalhas */
                    system("cls");
                    atribuicao_medalhas();
                    break;

                case 3: /* Voltar ao menu principal */
                    system("cls");
                    main();
                    break;
            }
        } else { /* Se a opção for inválida */
            system("cls");
            gotoxy(30, 21);
            printf("Opção inválida, tente novamente\n");
        }
    }
}


/* Função para edição de medalhas de paises */
void atribuicao_medalhas() {
    system("cls");

    FILE* banco_paises;
    FILE* temp;
    temp = fopen("replace.tmp", "a"); /* Cria arquivo temporario */
    /* Declaração de variáveis */
    int id_edicao = 0;
    int escolha_edicao;
    char* coluna[100];
    char linha[100];

    cabecalho();

    gotoxy(30, 12);
    printf("* ATRIBUIÇÃO DE MEDALHAS *");
    gotoxy(30, 14);
    printf("Digite o ID do país: ");
    fflush(stdin);
    scanf("%d", &id_edicao);

    system("cls");
    cabecalho();
    gotoxy(30, 12);
    printf("* ATRIBUIÇÃO DE MEDALHAS *");
    gotoxy(30, 14);
    printf("QUAL MEDALHA QUE DESEJA ALTERAR?");
    gotoxy(30, 16);
    printf("[1] Ouro\n");
    gotoxy(30, 17);
    printf("[2] Prata\n");
    gotoxy(30, 18);
    printf("[3] Bronze\n");
    gotoxy(30, 20);
    printf("Escolha uma opção: ");
    fflush(stdin);
    scanf("%d", &escolha_edicao);

    system("cls");
    cabecalho();
    gotoxy(30, 12);
    printf("* ATRIBUIÇÃO DE MEDALHAS *");

    /* Abre o arquivo de paises */
    banco_paises = fopen(".//banco-de-dados//paises.txt", "r+");

    /* Verifica se o arquivo foi aberto */
    if (banco_paises == NULL) {
        gotoxy(30, 14);
        printf("Erro ao abrir o arquivo\n");
        gotoxy(30, 15);
        printf("Tente novamente\n");
        gotoxy(30, 16);
        system("pause");
        system("cls");
        menu_ranking();
    }

    while (!feof(banco_paises)) {         /* Enquanto não for o fim do arquivo */
        fgets(linha, 100, banco_paises);  /* Lê a linha do arquivo */
        char* token = strtok(linha, ";"); /* Quebra a linha em tokens */
        int i = 0;

        while (token != NULL) {        /* Enquanto não for o fim do token */
            coluna[i] = token;         /* Coloca o token na posição correta */
            token = strtok(NULL, ";"); /* Quebra o token */
            i++;
        }

        if (atoi(coluna[0]) == id_edicao) { /* Se o id for igual ao id digitado */
            sprintf(coluna[escolha_edicao + 1], "%d", atoi(coluna[escolha_edicao + 1]) + 1); /* Atribui a medalha */
        }
        fprintf(temp, "%s;%s;%s;%s;%s;%s;%s", coluna[0], coluna[1], coluna[2], coluna[3], coluna[4], coluna[5], coluna[6]); /* Escreve no arquivo */
    }
    fclose(banco_paises); /* Fecha os arquivos */
    fclose(temp);
    remove(".//banco-de-dados//paises.txt");
    rename("replace.tmp", ".//banco-de-dados//paises.txt");
}


/* Exibe o ranking de paises pela pontuação */
void ranking_paises() {
    FILE* paises;

    cabecalho();
    gotoxy(30, 19);

    paises = fopen(".//banco-de-dados//paises.txt", "r"); /* Abre o arquivo de paises */

    if (paises == NULL) {  // Se o arquivo não existir, cria-o
        system("cls");
        cabecalho();
        gotoxy(27, 14);
        printf("Erro ao abrir o banco de dados.\n");
        gotoxy(27, 15);
        printf("Novo arquivo criado, tente novamente.\n");
        paises = fopen(".//banco-de-dados//paises.txt", "w"); /* Cria o arquivo */
        fclose(paises);
        gotoxy(20, 17);
        system("pause");
        menu_atletas();
    }
    fclose(paises); /* Fecha o arquivo */
}
