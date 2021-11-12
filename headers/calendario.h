#pragma once

/* Menu de opção para o calendario */
void menu_calendario()
{
    system("cls");
    int escolha_calendario;
    int ano = 2024;

    do
    {

        cabecalho();
        gotoxy(30, 12);
        printf("* MENU CALENDARIO *");
        gotoxy(30, 14);
        printf("[1] LISTAR DATAS DOS JOGOS\n");
        gotoxy(30, 15);
        printf("[2] EDITAR DATA\n");
        gotoxy(30, 16);
        printf("[3] CADASTRAR NOVA DATA\n");
        gotoxy(30, 17);
        printf("[4] VOLTAR PARA O MENU PRINCIPAL");
        gotoxy(30, 19);
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &escolha_calendario);

        if (escolha_calendario >= 1 && escolha_calendario <= 4)
        { /* Se a opção for entre 1 e 4 */
            switch (escolha_calendario)
            {
            case 1: /* Lista todas as datas dos jogos */
                system("cls");
                listar_todas_datas(ano);
                break;

            case 2: /* Consultar Dia */
                system("cls");
                menu_editar(ano);
                break;

            case 3: /* Cadastrar nova data */
                system("cls");
                cadastrar_data_jogo();
                break;

            case 4: /* Voltar ao menu principal */
                main();
                break;
            }
        }
        else
        { /* Se a opção for inválida */
            system("cls");
            gotoxy(30, 21);
            printf("Opção inválida, tente novamente\n");
        }
    } while (escolha_calendario != 4);
}

/* Cadastrar nova data das olimpiadas */
void cadastrar_data_jogo()
{
    system("cls");
    int ano = 2024;
    int dia, mes;
    char esporte[MAX];
    int escolha_cadastrar;

    // cadastro de nova data
    cabecalho();
    gotoxy(30, 12);
    printf("* CADASTRAR NOVA DATA *");
    gotoxy(30, 14);
    printf("Digite o dia: ");
    scanf("%d", &dia);
    gotoxy(30, 15);
    printf("Digite o mês: ");
    scanf("%d", &mes);
    gotoxy(30, 16);
    printf("Digite o esporte: ");
    fflush(stdin);
    gets(esporte);
    gotoxy(30, 17);
    printf("Deseja cadastrar a data?\n");
    gotoxy(30, 18);
    printf("[1] SIM\n");
    gotoxy(30, 19);
    printf("[2] NAO\n");
    gotoxy(30, 20);
    printf("Escolha uma opção: ");
    fflush(stdin);
    scanf("%d", &escolha_cadastrar);

    if (escolha_cadastrar == 1)
    {
        salvar_data(dia, mes, esporte, ano);
    }
    else
    {
        menu_calendario();
    }
}

void salvar_data(int dia, int mes, char esporte[MAX], int ano)
{

    FILE *arquivo;
    arquivo = fopen(".//banco-de-dados//calendario.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    fprintf(arquivo, "%d/%d/%d %s\n", dia, mes, ano, esporte);
    fclose(arquivo);
    menu_calendario();
}

/* Listar todas as datas dos jogos */
void listar_todas_datas(int ano)
{
    system("cls");
    int dia, mes;
    char esporte[MAX];
    int i = 0;
    FILE *arquivo;
    arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d/%d/%d %s\n", &dia, &mes, &ano, esporte);
        if (ano == ano)
        {
            printf("%d/%d/%d %s\n", dia, mes, ano, esporte);
            i++;
            system("pause");
        }
    }
    fclose(arquivo);
    if (i == 0)
    {
        printf("Não há datas cadastradas\n");
    }
    menu_calendario();
}

/* Excluir ou Editar data */
void menu_editar(int ano)
{
    system("cls");
    int dia, mes;
    char esporte[MAX];
    int i = 0;
    FILE *arquivo;
    arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    while (!feof(arquivo)) // enquanto não for o fim do arquivo
    {
        fscanf(arquivo, "%d/%d/%d %s\n", &dia, &mes, &ano, esporte);
        if (ano == ano)
        {
            printf("%d/%d/%d %s\n", dia, mes, ano, esporte);
            i++;
        }
    }
    fclose(arquivo);
    if (i == 0)
    {
        printf("Não há datas cadastradas\n");
    }
    else
    {
        int escolha_editar;
        int dia_editar, mes_editar;
        char esporte_editar[MAX];
        int escolha_excluir;
        int dia_excluir, mes_excluir;
        char esporte_excluir[MAX];
        int escolha_voltar;

        do
        {
            cabecalho();
            gotoxy(30, 12);
            printf("* EDITAR DATA *");
            gotoxy(30, 14);
            printf("[1] EDITAR DATA\n");
            gotoxy(30, 15);
            printf("[2] EXCLUIR DATA\n");
            gotoxy(30, 16);
            printf("[3] VOLTAR\n");
            gotoxy(30, 17);
            printf("Escolha uma opção: ");
            fflush(stdin);
            scanf("%d", &escolha_editar);

            switch (escolha_editar)
            {
            case 1: /* Editar data */
                system("cls");
                cabecalho();
                gotoxy(30, 12);
                printf("* EDITAR DATA *");
                gotoxy(30, 14);
                printf("Digite o dia: ");
                scanf("%d", &dia_editar);
                gotoxy(30, 15);
                printf("Digite o mês: ");
                scanf("%d", &mes_editar);
                gotoxy(30, 16);
                printf("Digite o esporte: ");
                fflush(stdin);
                gets(esporte_editar);
                gotoxy(30, 17);
                printf("Deseja editar a data?\n");
                gotoxy(30, 18);
                printf("[1] SIM\n");
                gotoxy(30, 19);
                printf("[2] NAO\n");
                gotoxy(30, 20);
                printf("Escolha uma opção: ");
                fflush(stdin);
                scanf("%d", &escolha_editar);

                if (escolha_editar == 1)
                {
                    editar_data_jogo(dia_editar, mes_editar, esporte_editar);
                }
                else
                {
                    menu_calendario();
                }
                break;

            case 2: /* Excluir data */
                system("cls");
                cabecalho();
                gotoxy(30, 12);
                printf("* EXCLUIR DATA *");
                gotoxy(30, 14);
                printf("Digite o dia: ");
                scanf("%d", &dia_excluir);
                gotoxy(30, 15);
                printf("Digite o mês: ");
                scanf("%d", &mes_excluir);
                gotoxy(30, 16);
                printf("Digite o esporte: ");
                fflush(stdin);
                gets(esporte_excluir);
                gotoxy(30, 17);
                printf("Deseja excluir a data?\n");
                gotoxy(30, 18);
                printf("[1] SIM\n");
                gotoxy(30, 19);
                printf("[2] NAO\n");
                gotoxy(30, 20);
                printf("Escolha uma opção: ");
                fflush(stdin);
                scanf("%d", &escolha_excluir);

                if (escolha_excluir == 1)
                {
                    excluir_data_jogo(dia_excluir, mes_excluir, esporte_excluir);
                }
                else
                {
                    menu_calendario();
                }
                break;

            case 3: /* Voltar */
                menu_calendario();
                break;

            default:
                printf("Opção inválida\n");
                // editar_data(ano);
                break;
            }
        } while (escolha_editar != 3);
    }
}

/* Editar data */
void editar_data_jogo(int dia, int mes, char esporte[MAX])
{
    int diacmp, mescmp, anocmp;
    char esportecmp[MAX];
    int ano = 2024;

    system("cls");
    FILE *arquivo;
    arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d/%d/%d %s\n", &diacmp, &mescmp, esportecmp);
        if (dia == diacmp && mes == mescmp && strcmp(esporte, esportecmp) == 0) // Se encontrar a data
        {
            fclose(arquivo);
            arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
            if (arquivo == NULL)
            {
                printf("Erro ao abrir o arquivo\n");
                exit(1);
            }
            FILE *arquivo_temp;
            arquivo_temp = fopen(".//banco-de-dados//calendario_temp.txt", "w");
            if (arquivo_temp == NULL)
            {
                printf("Erro ao abrir o arquivo\n");
                exit(1);
            }
            while (!feof(arquivo))
            {
                fscanf(arquivo, "%d/%d/%d %s\n", &diacmp, &mescmp, &anocmp, esportecmp);
                if (dia == diacmp && mes == mescmp && strcmp(esporte, esportecmp) == 0)
                {
                    fprintf(arquivo_temp, "%d/%d/%d %s\n", dia, mes, ano, esporte);
                }
                else
                {
                    fprintf(arquivo_temp, "%d/%d/%d %s\n", diacmp, mescmp, anocmp, esportecmp);
                }
            }
            fclose(arquivo);
            fclose(arquivo_temp);
            remove(".//banco-de-dados//calendario.txt");
            rename("calendario_temp.txt", ".//banco-de-dados//calendario.txt");
        }
        fclose(arquivo);
    }
}

/* Excluir data */
void excluir_data_jogo(int dia, int mes, char esporte[MAX])
{
    int diacmp, mescmp, anocmp;
    char esportecmp[MAX];
    int ano = 2024;

    system("cls");
    FILE *arquivo;
    arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%d/%d/%d %s\n", &diacmp, &mescmp, esportecmp);
        if (dia == diacmp && mes == mescmp && strcmp(esporte, esportecmp) == 0) // Se encontrar a data
        {
            fclose(arquivo);
            arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
            if (arquivo == NULL)
            {
                printf("Erro ao abrir o arquivo\n");
                exit(1);
            }
            FILE *arquivo_temp;
            arquivo_temp = fopen(".//banco-de-dados//calendario_temp.txt", "w");
            if (arquivo_temp == NULL)
            {
                printf("Erro ao abrir o arquivo\n");
                exit(1);
            }
            while (!feof(arquivo))
            {
                fscanf(arquivo, "%d/%d/%d %s\n", &diacmp, &mescmp, &anocmp, esportecmp);
                if (dia != diacmp || mes != mescmp || strcmp(esporte, esportecmp) != 0)
                {
                    fprintf(arquivo_temp, "%d/%d/%d %s\n", diacmp, mescmp, anocmp, esportecmp);
                }
            }
            fclose(arquivo);
            fclose(arquivo_temp);
            remove(".//banco-de-dados//calendario.txt");
            rename("calendario_temp.txt", ".//banco-de-dados//calendario.txt");
        }
    }
    fclose(arquivo);
}
