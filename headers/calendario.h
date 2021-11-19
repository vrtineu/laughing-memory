#pragma once

/* Menu de opção para o calendario */
void menu_calendario()
{
    system("cls");
    int escolha_calendario;
    int ano = 2024;

    do
    {
        system("cls");
        cabecalho();
        gotoxy(30, 12);
        printf("* MENU CALENDARIO *");
        gotoxy(30, 14);
        printf("[1] LISTAR DATAS DOS JOGOS\n");
        gotoxy(30, 15);
        printf("[2] EDITAR DATA\n");
        gotoxy(30, 16);
        printf("[3] EXCLUIR DATA\n");
        gotoxy(30, 17);
        printf("[4] CADASTRAR NOVA DATA\n");
        gotoxy(30, 18);
        printf("[5] VOLTAR PARA O MENU PRINCIPAL");
        gotoxy(30, 20);
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf("%d", &escolha_calendario);

        if (escolha_calendario >= 1 && escolha_calendario <= 4)
        {
            /* Se a opção for entre 1 e 4 */
            switch (escolha_calendario)
            {
            case 1:
                listar_todas_datas(1);
                break;

            case 2:
                editar_data_jogo();
                break;

            case 3:
                excluir_data();
                break;

            case 4:
                cadastrar_data_jogo();
                break;

            case 5:
                menu_principal();
                break;
            }
        }
        else
        { /* Se a opção for inválida */
            system("cls");
            gotoxy(30, 21);
            printf("Opção inválida, tente novamente\n");
        }
    } while (escolha_calendario != 5);
}

/*Quantidade de Linhas no Arquivo*/
int qtd_total_linhas_arquivo()
{

    int qtd_linhas_do_arquivo = 0;
    int dia, mes, ano;
    char esporte[MAX];
    FILE *arquivo;

    arquivo = fopen(".//banco-de-dados//calendario.txt", "r");

    /* Ocorrendo erro na leitura do arquivo */
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    if (fscanf(arquivo, "%d/%d/%d", &dia, &mes, &ano) == 3)
    {
        rewind(arquivo);
        /* Lendo todos os dados do arquivo de uma vez */
        while (!feof(arquivo))
        {
            fscanf(arquivo, "%d/%d/%d %[^\n]s", &dia, &mes, &ano, esporte); /*Lê uma linha formatada do arquivo*/
            qtd_linhas_do_arquivo++;
        }
        fclose(arquivo);
    }
    else
    {
        qtd_linhas_do_arquivo = 0;
    }
    return qtd_linhas_do_arquivo;
}

/* Retorna 1 se a data for válida e zero caso contrário */
int data_valida(int dia, int mes)
{
    int mes_valido = 0;

    if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12))
    {
        if ((dia > 0) && (dia <= 31))
        {
            mes_valido = 1;
        }
    }
    else if (mes == 2)
    {
        if ((dia > 0) && (dia < 30))
        {
            mes_valido = 1;
        }
    }
    else if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
    {
        if ((dia > 0) && (dia < 31))
        {
            mes_valido = 1;
        }
    }

    return mes_valido;
}

/* Listar todas as datas dos jogos */
int listar_todas_datas(int code)
{
    system("cls");
    cabecalho();

    int qtd_linhas_arquivo;
    int dia, mes, ano;
    int contador;
    int controle_de_linha = 17;
    char esporte[MAX];
    int i = 0;
    FILE *arquivo;

    qtd_linhas_arquivo = qtd_total_linhas_arquivo();

    if (qtd_linhas_arquivo > 0)
    {
        gotoxy(30, 14);
        printf("Datas Cadastradas : ");
        gotoxy(30, 16);
        arquivo = fopen(".//banco-de-dados//calendario.txt", "r");

        /* Ocorrendo erro na leitura do arquivo */
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }

        /* Lendo todos os dados do arquivo de uma vez */
        contador = 1;
        while (contador < qtd_linhas_arquivo)
        {
            fscanf(arquivo, "%d/%d/%d %[^\n]", &dia, &mes, &ano, esporte); /*Lê uma linha formatada do arquivo*/
            printf("%d - %d/%d/%d %s", ++i, dia, mes, ano, esporte);       /*Imprime a linha formatada na tela*/
            gotoxy(30, controle_de_linha++);
            contador++;
        }
        fclose(arquivo);
        if (i == 0)
        {
            printf("Não há datas cadastradas\n");
        }

        controle_de_linha += 2;
        if (code == 1)
        {
            gotoxy(23, controle_de_linha);
            system("pause");
        }
        else
        {
            gotoxy(30, controle_de_linha);
        }
    }
    else
    {
        if (code == 1)
        {
            gotoxy(30, 14);
            printf("Não há datas cadastradas.");
            gotoxy(30, 15);
            system("pause");
        }
    }
    return controle_de_linha;
}

/* Editar uma data específica dos jogos */

void editar_data_jogo()
{
    int qtd_linhas_arquivo;
    int linha_controle;
    int cod_linha;
    int contador;
    int novo_dia, novo_mes;
    int diacmp, mescmp;
    char esportecmp[MAX];
    int ano = 2024;
    FILE *arquivo, *fp;

    qtd_linhas_arquivo = qtd_total_linhas_arquivo();
    linha_controle = listar_todas_datas(0);
    if (qtd_linhas_arquivo > 0)
    {
        gotoxy(30, linha_controle++);
        printf("Informe o código da data que deseja alterar : ");
        gotoxy(30, linha_controle++);
        scanf("%d", &cod_linha);
        gotoxy(30, linha_controle++);
        printf("Informe o dia para a nova data : ");
        gotoxy(30, linha_controle++);
        scanf("%d", &novo_dia);
        gotoxy(30, linha_controle++);
        printf("Informe o mês para a nova data : ");
        gotoxy(30, linha_controle++);
        scanf("%d", &novo_mes);
        gotoxy(30, linha_controle++);

        if ((data_valida(novo_dia, novo_mes)) && (cod_linha > 0) && (cod_linha <= qtd_linhas_arquivo))
        {

            /* Abrindo o arquivo para leitura*/
            arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
            fp = fopen(".//banco-de-dados//calendarioAuxiliar.txt", "a");

            /* Verificando erro na abertura do arquivo */
            if ((arquivo == NULL) || (fp == NULL))
            {
                printf("Erro ao abrir o arquivo\n");
                exit(1);
            }

            /* Lendo o arquivo até o final ou até encontrar a linha que deseja alterar */
            contador = 1;
            while (contador < qtd_linhas_arquivo)
            {
                fscanf(arquivo, "%d/%d/%d %[^\n]", &diacmp, &mescmp, &ano, esportecmp);
                if (contador == cod_linha)
                {
                    fprintf(fp, "%d/%d/%d %s\n", novo_dia, novo_mes, ano, esportecmp);
                }
                else
                {
                    fprintf(fp, "%d/%d/%d %s\n", diacmp, mescmp, ano, esportecmp);
                }
                contador++;
            }
            fclose(arquivo);
            fclose(fp);
            remove(".//banco-de-dados//calendario.txt");
            rename(".//banco-de-dados//calendarioAuxiliar.txt", ".//banco-de-dados//calendario.txt");
            gotoxy(30, linha_controle++);
            printf("Data Editada com sucesso.");
        }
        else
        {
            gotoxy(30, linha_controle++);
            printf("Código ou data informados são inválidos. ");
        }
    }
    else
    {
        gotoxy(30, linha_controle++);
        printf("Não há datas para editar.");
    }
    gotoxy(30, linha_controle++);
    system("pause");
}

/*Excluir uma data*/
void excluir_data()
{

    int qtd_linhas_arquivo;
    int linha_controle;
    int cod_linha;
    int contador;
    int diacmp, mescmp;
    char esportecmp[MAX];
    int ano = 2024;
    FILE *arquivo, *fp;

    qtd_linhas_arquivo = qtd_total_linhas_arquivo();
    linha_controle = listar_todas_datas(0);
    /* Recebendo os novos dados */
    if (qtd_linhas_arquivo > 0)
    {
        gotoxy(30, linha_controle++);
        printf("Informe o código da data que deseja excluir : ");
        gotoxy(30, linha_controle++);
        scanf("%d", &cod_linha);
        gotoxy(30, linha_controle++);

        /* Verificando os novos dados */
        if ((cod_linha > 0) && (cod_linha <= qtd_linhas_arquivo))
        {

            /* Abrindo o arquivo para leitura*/
            arquivo = fopen(".//banco-de-dados//calendario.txt", "r");
            fp = fopen(".//banco-de-dados//calendarioAuxiliar.txt", "a");

            /* Verificando erro na abertura do arquivo */
            if ((arquivo == NULL) || (fp == NULL))
            {
                printf("Erro ao abrir o arquivo\n");
                exit(1);
            }

            /* Lendo o arquivo até o final */
            contador = 1;
            while (contador < qtd_linhas_arquivo)
            {
                fscanf(arquivo, "%d/%d/%d %[^\n]", &diacmp, &mescmp, &ano, esportecmp);
                if (contador != cod_linha)
                {
                    fprintf(fp, "%d/%d/%d %s\n", diacmp, mescmp, ano, esportecmp);
                }
                contador++;
            }
            fclose(arquivo);
            fclose(fp);
            remove(".//banco-de-dados//calendario.txt");
            rename(".//banco-de-dados//calendarioAuxiliar.txt", ".//banco-de-dados//calendario.txt");
            gotoxy(30, linha_controle++);
            printf("Data Excluída com sucesso.");
        }
        else
        {
            /* Dados informados são inválidos */
            gotoxy(30, linha_controle++);
            printf("Código informado é inválido. Data não excluída!");
        }
    }
    else
    {
        gotoxy(30, linha_controle++);
        printf("Não há datas para excluir.");
    }
    gotoxy(30, linha_controle++);
    system("pause");
}

/* Cadastrar nova data das olimpiadas */
void cadastrar_data_jogo()
{
    system("cls");
    int ano = 2024;
    int dia, mes;
    char esporte[MAX];
    int escolha_cadastrar;
    FILE *arquivo;

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
    scanf("%[^\n]", esporte);
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

    if ((escolha_cadastrar == 1) && (data_valida(dia, mes)))
    {
        /* Abrindo o arquivo para leitura*/
        arquivo = fopen(".//banco-de-dados//calendario.txt", "a");

        /* Verificando erro na abertura do arquivo */
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }
        fprintf(arquivo, "%d/%d/%d %s\n", dia, mes, ano, esporte);
        fclose(arquivo);

        gotoxy(30, 23);
        printf("Data cadastrada com sucesso.");
    }
    else
    {
        gotoxy(30, 23);
        printf("Dia ou Mês informados inválidos. Data não cadastrada.");
    }
    gotoxy(30, 25);
    system("pause");
}
