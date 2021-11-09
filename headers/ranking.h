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
        printf("[3] REMOVER MEDALHA");
        gotoxy(30, 17);
        printf("[4] VOLTAR PARA O MENU PRINCIPAL\n");
        gotoxy(30, 19);
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &escolha_ranking);

        if (escolha_ranking >= 1 && escolha_ranking <= 4) { /* Se a opção for entre 1 e 2 */
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
                    remover_medalha();
                    break;

                case 4: /* Voltar ao menu principal */
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
    printf("QUAL MEDALHA QUE DESEJA ATRIBUIR?");
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
            if (escolha_edicao == 1) {
                int score_ouro = 3;
                sprintf(coluna[6], "%d\n", atoi(coluna[6]) + score_ouro); /* Atribui a pontuação para ouro */
            } else if (escolha_edicao == 2) {
                int score_prata = 2;
                sprintf(coluna[6], "%d\n", atoi(coluna[6]) + score_prata); /* Atribui a pontuação para prata */
            } else if (escolha_edicao == 3) {
                int score_bronze = 1;
                sprintf(coluna[6], "%d\n", atoi(coluna[6]) + score_bronze); /* Atribui a pontuação para bronze */
            }
        }
        fprintf(temp, "%s;%s;%s;%s;%s;%s;%s", coluna[0], coluna[1], coluna[2], coluna[3], coluna[4], coluna[5], coluna[6]); /* Escreve no arquivo */
    }
    fclose(banco_paises); /* Fecha os arquivos */
    fclose(temp);
    remove(".//banco-de-dados//paises.txt");
    rename("replace.tmp", ".//banco-de-dados//paises.txt");
}

/* Função para remover medalhas de paises */
void remover_medalha() {
    system("cls");

    FILE* banco_paises;
    FILE* temp;
    temp = fopen("replace.tmp", "a"); /* Cria arquivo temporario */
    
    int id_edicao = 0;
    int escolha_edicao;
    char* coluna[100];
    char linha[100];

    cabecalho();

    gotoxy(30, 12);
    printf("* REMOVER MEDALHA *");
    gotoxy(30, 14);
    printf("Digite o ID do país: ");
    fflush(stdin);
    scanf("%d", &id_edicao);

    system("cls");
    cabecalho();
    gotoxy(30, 12);
    printf("* REMOVER MEDALHA *");
    gotoxy(30, 14);
    printf("QUAL MEDALHA QUE DESEJA REMOVER?");
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
    printf("* REMOVER MEDALHA *");

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
            sprintf(coluna[escolha_edicao + 1], "%d", atoi(coluna[escolha_edicao + 1]) - 1); /* Atribui a medalha */
            if (escolha_edicao == 1) {
                int score_ouro = 3;
                sprintf(coluna[6], "%d\n", atoi(coluna[6]) - score_ouro); /* Atribui a pontuação para ouro */
            } else if (escolha_edicao == 2) {
                int score_prata = 2;
                sprintf(coluna[6], "%d\n", atoi(coluna[6]) - score_prata); /* Atribui a pontuação para prata */
            } else if (escolha_edicao == 3) {
                int score_bronze = 1;
                sprintf(coluna[6], "%d\n", atoi(coluna[6]) - score_bronze); /* Atribui a pontuação para bronze */
            }
        }
        fprintf(temp, "%s;%s;%s;%s;%s;%s;%s", coluna[0], coluna[1], coluna[2], coluna[3], coluna[4], coluna[5], coluna[6]); /* Escreve no arquivo */
    }
    fclose(banco_paises); /* Fecha os arquivos */
    fclose(temp);
    remove(".//banco-de-dados//paises.txt");
    rename("replace.tmp", ".//banco-de-dados//paises.txt");
}


/* Função para construir ranking dos paises conforme a pontuação */
void ranking_paises() {
    system("cls");
    FILE* banco_paises;
    FILE* ranking;
    FILE* ranking_ordenado;

    /* Limpa o arquivo de ranking.txt */
    
    remove(".//banco-de-dados//ranking.txt"); /* Remove o arquivo de ranking */
    ranking = fopen(".//banco-de-dados//ranking.txt", "w"); /* Cria o arquivo de ranking */
    fclose(ranking);

    cabecalho();
    gotoxy(30, 12);
    printf("* RANKING PAÍSES *");

    /* Popula o arquivo de ranking.txt */
   
    banco_paises = fopen(".//banco-de-dados//paises.txt", "r");
    ranking = fopen(".//banco-de-dados//ranking.txt", "w");
    int count = 0;
    while (!feof(banco_paises)) {
        char* coluna[100];
        char linha[100];
        fgets(linha, 100, banco_paises);
        char* token = strtok(linha, ";");
        int i = 0;

        while (token != NULL) {
            coluna[i] = token;
            token = strtok(NULL, ";");
            i++;
        }

        int pontuacao = atoi(coluna[6]);
        if (pontuacao > 0) {
            if(count != 0) {
                fprintf(ranking, "\n");
            }
            fprintf(ranking, "%s;%d", coluna[1], pontuacao);
        }
        count++;
    }
    fclose(ranking);                             /* Fecha o arquivo */
    fclose(banco_paises);                        /* Fecha o arquivo */

    /* Ordena o arquivo de ranking.txt em ranking-ordenado.txt */
    
    char nome_pais[100];
    int maior_pontuacao_anterior = 0;
    for(int i = 0; i < sizeof(ranking); i++) {
        int maior_pontuacao = 0;
        ranking = fopen(".//banco-de-dados//ranking.txt", "r");
        ranking_ordenado = fopen(".//banco-de-dados//ranking-ordenado.txt", "a");

        while (!feof(ranking)) {
            char* coluna[100];
            char linha[100];
            fgets(linha, 100, ranking);
            char* token = strtok(linha, ";");
            
            int j = 0;
            while (token != NULL) {
                coluna[j] = token;
                token = strtok(NULL, ";");
                j++;
            }
            
            int pontuacao = atoi(coluna[1]);

            if(i == 0 && pontuacao > maior_pontuacao){
                maior_pontuacao = pontuacao;
                strcpy(nome_pais, coluna[0]);
            } else if (i != 0 && pontuacao < maior_pontuacao_anterior && pontuacao > maior_pontuacao) {
                maior_pontuacao = pontuacao;
                strcpy(nome_pais, coluna[0]);
            } else if (i != 0 && pontuacao == maior_pontuacao) {
                strcat(nome_pais, ";");
                strcat(nome_pais, coluna[0]);
            }
        }        
        maior_pontuacao_anterior = maior_pontuacao;
        printf("%s\n", nome_pais, maior_pontuacao);
        if (i != 0) {
            fputs(";", ranking_ordenado);
        }
        fputs(nome_pais, ranking_ordenado);
        fclose(ranking);
        fclose(ranking_ordenado);
    }        
    exibe_ranking();
    menu_ranking();
}

/* Função para exibir o ranking */
void exibe_ranking() {
    system("cls");
    cabecalho();
    gotoxy(30, 12);
    printf("* RANKING PAÍSES *");

    FILE* ranking_ordenado;
    ranking_ordenado = fopen(".//banco-de-dados//ranking-ordenado.txt", "r");


    char* coluna[100];
    char linha[100];
    
    fgets(linha, 100, ranking_ordenado);
    char* token = strtok(linha, ";");

    int i = 0;
    while (token != NULL) {
        coluna[i] = token;
        token = strtok(NULL, ";");
        i++;
    }
    
    for(int j = 0; j < i; j++) {
        for (int k = 0; k < strlen(coluna[j]); k++) { /* Replace de under score para space bar */
            if (coluna[j][k] == '_') {
                // printf("%s\n", coluna[j]);
                coluna[j][k] = ' ';
            }
            // system("pause");
        }
        gotoxy(30, 14 + j);
        printf("%s\n", coluna[j]);
    }

    fclose(ranking_ordenado);
    remove(".//banco-de-dados//ranking-ordenado.txt");
    ranking_ordenado = fopen(".//banco-de-dados//ranking-ordenado.txt", "w");
    fclose(ranking_ordenado);
    gotoxy(25, 33);
    system("pause");
}
