#pragma once


/* Menu de opção para atletas */
void menu_atletas() {
    system("cls");

    int escolha_atletas;

    while (escolha_atletas != 4) {
        cabecalho();
        gotoxy(30, 12);
        printf("* MENU ATLETAS *");
        gotoxy(30, 14);
        printf("[1] LISTAR ATLETAS\n");
        gotoxy(30, 15);
        printf("[2] CONSULTAR ATLETAS POR ID\n");
        gotoxy(30, 16);
        printf("[3] CADASTRAR NOVO ATLETA\n");
        gotoxy(30, 17);
        printf("[4] VOLTAR PARA O MENU PRINCIPAL");
        gotoxy(30, 19);
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &escolha_atletas);

        if (escolha_atletas >= 1 && escolha_atletas <= 4) { /* Se a opção for entre 1 e 4 */
            switch (escolha_atletas) {                      /* Escolha a opção */
                case 1:                                     /* Listar atletas */
                    system("cls");
                    listar_atletas();
                    break;

                case 2: /* Buscar atleta por id */
                    system("cls");
                    buscar_atleta_id();
                    break;

                case 3: /* Cadastrar novo atleta */
                    system("cls");
                    cadastrar_atleta();
                    break;

                case 4: /* Voltar ao menu principal */
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


/* Cadastrar atleta */
void cadastrar_atleta() {
    FILE* banco_atletas; /* Arquivo para armazenar os atletas */

    cabecalho();

    int novo_id;
    int maior_id = 0;

    banco_atletas = fopen(".//banco-de-dados//atletas.txt", "r");  // Abre o arquivo para leitura
    if (banco_atletas == NULL) {                                   // Se o arquivo não existir, cria-o
        system("cls");
        cabecalho();
        gotoxy(27, 14);
        printf("Erro ao abrir o banco de dados.\n");
        gotoxy(27, 15);
        printf("Novo arquivo criado, tente novamente.\n");
        banco_atletas = fopen(".//banco-de-dados//atletas.txt", "w");
        fclose(banco_atletas);
        gotoxy(20, 17);
        system("pause");
        menu_atletas();
    }

    while (!feof(banco_atletas)) { /* Enquanto não chegar ao final do arquivo */
        fscanf(banco_atletas, "%d;%s;%s;%s\n", &atl.id_atleta, &atl.nome, &atl.pais, &atl.modalidade);
        if (atl.id_atleta > maior_id) { /* Verifica se o id é maior que o maior id */
            maior_id = atl.id_atleta;
        }
    }
    novo_id = maior_id + 1; /* Novo id é o maior id encontrado + 1 */
    fclose(banco_atletas);

    banco_atletas = fopen(".//banco-de-dados//atletas.txt", "a"); /* Abre o arquivo no modo append */
    if (banco_atletas == NULL) {                                  // Se o arquivo não existir, cria-o
        system("cls");
        cabecalho();
        gotoxy(27, 14);
        printf("Erro ao abrir o banco de dados.\n");
        gotoxy(27, 15);
        printf("Novo arquivo criado, tente novamente.\n");
        banco_atletas = fopen(".//banco-de-dados//atletas.txt", "w");  // Cria o arquivo utilizando o método write.
        fclose(banco_atletas);
        gotoxy(20, 17);
        system("pause");
        menu_atletas();
    }

    fflush(stdin); /* Limpa o buffer de entrada */
    gotoxy(27, 14);
    printf("Digite o nome do atleta: ");
    fgets(atl.nome, MAX, stdin); /* Lê a string até o \n */

    for (int i = 0; i < strlen(atl.nome); i++) { /* Replace de space bar para under score */
        if (atl.nome[i] == ' ') {
            atl.nome[i] = '_';
        }
    }

    fflush(stdin); /* Limpa o buffer de entrada */
    gotoxy(27, 15);
    printf("Digite o país do atleta: ");
    fgets(atl.pais, MAX, stdin); /* Lê a string até o \n */

    for (int i = 0; i < strlen(atl.pais); i++) { /* Replace de space bar para under score */
        if (atl.pais[i] == ' ') {
            atl.pais[i] = '_';
        }
    }

    fflush(stdin); /* Limpa o buffer de entrada */
    gotoxy(27, 16);
    printf("Digite a modalidade do atleta: ");
    fgets(atl.modalidade, MAX, stdin); /* Lê a string até o \n */

    for (int i = 0; i < strlen(atl.modalidade); i++) { /* Replace de space bar para under score */
        if (atl.modalidade[i] == ' ') {
            atl.modalidade[i] = '_';
        }
    }

    atl.nome[strlen(atl.nome) - 1] = '\0';             /* Remove o \n do final da string */
    atl.pais[strlen(atl.pais) - 1] = '\0';             /* Remove o \n do final da string */
    atl.modalidade[strlen(atl.modalidade) - 1] = '\0'; /* Remove o \n do final da string */

    fprintf(banco_atletas, "\n%d;%s;%s;%s", novo_id, atl.nome, atl.pais, atl.modalidade); /* Escreve no arquivo */
    fclose(banco_atletas);
    system("cls");
    menu_atletas();
}


/* Listar atletas */
void listar_atletas() {
    FILE* banco_atletas; /* Arquivo para armazenar os atletas */

    char linha[MAX];
    char* coluna[MAX];

    cabecalho();

    banco_atletas = fopen(".//banco-de-dados//atletas.txt", "r");
    if (banco_atletas == NULL) {  // Se o arquivo não existir, cria-o
        system("cls");
        cabecalho();
        gotoxy(27, 14);
        printf("Erro ao abrir o banco de dados.\n");
        gotoxy(27, 15);
        printf("Novo arquivo criado, tente novamente.\n");
        banco_atletas = fopen(".//banco-de-dados//atletas.txt", "w");
        fclose(banco_atletas);
        gotoxy(20, 17);
        system("pause");
        menu_atletas();
    }

    while (!feof(banco_atletas)) {                                      /* Enquanto não chegar ao final do arquivo */
        fscanf(banco_atletas, "%d;%s;%s;%s\n", &atl.id_atleta, &linha); /* Lê o id e o nome do atleta */

        *coluna = strtok(linha, ";"); /* Separa a string em colunas guardando o ID e o primeiro nome */
        gotoxy(30, 14);
        printf("ID: %d\n", atl.id_atleta); /* Imprime o id */

        for (int i = 0; i < strlen(coluna[0]); i++) { /* Replace de under score para space bar */
            if (coluna[0][i] == '_') {
                coluna[0][i] = ' ';
            }
        }
        gotoxy(30, 15);
        printf("Nome: %s ", *coluna); /* Imprime o nome */

        *coluna = strtok(NULL, ";");                  /* Separa a string em colunas guardando o pais */
        for (int i = 0; i < strlen(coluna[0]); i++) { /* Replace de under score para space bar */
            if (coluna[0][i] == '_') {
                coluna[0][i] = ' ';
            }
        }
        gotoxy(30, 16);
        printf("País: %s\n", *coluna); /* Imprime o pais */

        *coluna = strtok(NULL, ";");                  /* Separa a string em colunas guardando a modalidade */
        for (int i = 0; i < strlen(coluna[0]); i++) { /* Replace de under score para space bar */
            if (coluna[0][i] == '_') {
                coluna[0][i] = ' ';
            }
        }
        gotoxy(30, 17);
        printf("Modalidade: %s\n", *coluna); /* Imprime a modalidade */

        gotoxy(30, 20);
        printf("Deseja ver o próximo atleta?\n");
        gotoxy(30, 21);
        printf("'S' para continuar\n");
        gotoxy(30, 22);
        printf("'N' para voltar ao menu\n");
        gotoxy(30, 23);
        printf("Digite a opcao: ");
        fflush(stdin);                          /* Limpa o buffer de entrada */
        char escolha = getche();                /* Lê a opção */
        if (escolha == 'N' || escolha == 'n') { /* Se a opção for não, volta ao menu de atletas */
            fclose(banco_atletas);              /* Fecha o arquivo */
            menu_atletas();                     /* Chama o menu de atletas */
        } else {                                /* Se a opção for sim, continua a listagem */
            system("cls");
            cabecalho();
            continue; /* Continua a listagem */
        }
    }
}


/* Procurar atletas pelo id. */
void buscar_atleta_id() {
    FILE* banco_atletas; /* Arquivo para armazenar os atletas */

    char linha[MAX];
    char* coluna[MAX];
    int id_busca;

pesquisar:

    cabecalho();

    gotoxy(30, 14);
    printf("Digite o ID do atleta: ");
    fflush(stdin);          /* Limpa o buffer de entrada */
    scanf("%d", &id_busca); /* Lê o id */
    system("cls");

    cabecalho();

    banco_atletas = fopen(".//banco-de-dados//atletas.txt", "r"); /* Abre o arquivo */
    if (banco_atletas == NULL) {                                  // Se o arquivo não existir, cria-o
        system("cls");
        cabecalho();
        gotoxy(27, 14);
        printf("Erro ao abrir o banco de dados.\n");
        gotoxy(27, 15);
        printf("Novo arquivo criado, tente novamente.\n");
        banco_atletas = fopen(".//banco-de-dados//atletas.txt", "w"); /* Cria o arquivo */
        fclose(banco_atletas);
        gotoxy(20, 17);
        system("pause");
        menu_atletas();
    }

    while (!feof(banco_atletas)) {                                      /* Enquanto não chegar ao final do arquivo */
        fscanf(banco_atletas, "%d;%s;%s;%s\n", &atl.id_atleta, &linha); /* Lê o id e o nome do atleta */

        if (id_busca == atl.id_atleta) {
            *coluna = strtok(linha, ";"); /* Separa a string em colunas guardando o ID e o primeiro nome */
            gotoxy(30, 14);
            printf("ID: %d\n", atl.id_atleta); /* Imprime o id */

            for (int i = 0; i < strlen(coluna[0]); i++) { /* Replace de under score para space bar */
                if (coluna[0][i] == '_') {
                    coluna[0][i] = ' ';
                }
            }
            gotoxy(30, 15);
            printf("Nome: %s\n", *coluna); /* Imprime o nome */

            *coluna = strtok(NULL, ";"); /* Separa a string em colunas guardando o pais */
            for (int i = 0; i < strlen(coluna[0]); i++) { /* Replace de under score para space bar */
                if (coluna[0][i] == '_') {
                    coluna[0][i] = ' ';
                }
            }
            gotoxy(30, 16);
            printf("País: %s\n", *coluna); /* Imprime o pais */

            *coluna = strtok(NULL, ";"); /* Separa a string em colunas guardando a modalidade */
            for (int i = 0; i < strlen(coluna[0]); i++) { /* Replace de under score para space bar */
                if (coluna[0][i] == '_') {
                    coluna[0][i] = ' ';
                }
            }
            gotoxy(30, 17);
            printf("Modalidade: %s\n", *coluna); /* Imprime a modalidade */

            gotoxy(30, 20);
            printf("Deseja buscar outro atleta?");
            gotoxy(30, 21);
            printf("'S' para continuar\n");
            gotoxy(30, 22);
            printf("'N' para voltar ao menu\n");
            gotoxy(30, 23);
            printf("Digite a opção: ");
            fflush(stdin);
            char escolha = getche();                /* Lê a escolha */
            if (escolha == 'N' || escolha == 'n') { /* Se a escolha for não, volta ao menu de atletas */
                fclose(banco_atletas);
                menu_atletas();
            } else { /* Se a escolha for sim, busca outro atleta. */
                system("cls");
                goto pesquisar; /* Vai para a linha pesquisar */
            }
        } else {      /* Se o id não for encontrado, continua a listagem */
            continue; /* Continua a listagem */
        }
    }
    fclose(banco_atletas); /* Fecha o arquivo */
    system("cls");
    cabecalho();
    gotoxy(30, 14);
    printf("Atleta não encontrado\n"); /* Imprime que o atleta não foi encontrado */
    gotoxy(20, 17);
    system("pause");
    system("cls");
}
