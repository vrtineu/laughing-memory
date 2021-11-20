#pragma once

void menu_login() {
    system("cls");
    cabecalho_login();

    int escolha_login;

    while(1){
        gotoxy(37, 14);
        printf("* LOGIN *");
        gotoxy(37, 16);
        printf("[1] Login");
        gotoxy(37, 17);
        printf("[2] Cadastrar");
        gotoxy(37, 18);
        printf("[0] Sair");
        gotoxy(37, 20);
        printf("Escolha uma opção: ");
        scanf("%d", &escolha_login);

        if(escolha_login >= 0 && escolha_login <= 2) {
            break;
        }
        else {
            gotoxy(37, 22);
            printf("Opção inválida!");
            Sleep(1000);
        }
    }

    switch(escolha_login) {
        case 0:
            exit(0);
            break;
        case 1:
            login();
            break;
        case 2:
            cadastro();
            break;
    } 
}


void cadastro() {
    system("cls");
    cabecalho_login();

    FILE *arquivo;
    char usuarioLogin[16], senhaLogin[16], email[MAX], nome[MAX];
    int existe = 0;

    gotoxy(37, 14);
    printf("* CADASTRO *");
    gotoxy(37, 16);
    printf("Nome: ");
    fflush(stdin);
    scanf("%s", &nome);
    gotoxy(37, 17);
    printf("Email: ");
    fflush(stdin);
    scanf("%s", &email);
    gotoxy(37, 18);
    printf("Usuário: ");
    fflush(stdin);
    scanf("%s", &usuarioLogin);
    gotoxy(37, 19);
    printf("Senha: ");
    fflush(stdin);
    scanf("%s", &senhaLogin);

    arquivo = fopen(".//banco-de-dados//usuarios.txt", "r");

    while(!feof(arquivo)) {
        fscanf(arquivo, "%s %s %s %s\n", usr.nome, usr.email, usr.usuario, usr.senha);
        if(strcmp(usuarioLogin, usr.usuario) == 0) {
            existe = 1;
            break;
        }
    }
    fclose(arquivo);

    if(existe == 0) {
        arquivo = fopen(".//banco-de-dados//usuarios.txt", "a");
        fprintf(arquivo, "%s %s %s %s\n", nome, email, usuarioLogin, senhaLogin);
        fclose(arquivo);
        gotoxy(37, 22);
        printf("Cadastro realizado com sucesso!");
        Sleep(3700);
        menu_login();
    }
    else {
        gotoxy(37, 22);
        printf("Usuário já existe!");
        Sleep(3000);
        menu_login();
    }
}

int login() {
    system("cls");
    cabecalho_login();

    FILE *arquivo;
    char usuarioLogin[16], senhaLogin[16], email[MAX], nome[MAX];
    int login = 0;

    gotoxy(37, 14);
    printf("* LOGIN *");
    gotoxy(37, 16);
    printf("Usuário: ");
    fflush(stdin);
    scanf("%s", &usr.usuario);
    gotoxy(37, 17);
    printf("Senha: ");
    fflush(stdin);
    scanf("%s", &usr.senha);

    arquivo = fopen(".//banco-de-dados//usuarios.txt", "r");

    while(!feof(arquivo)) {
        fscanf(arquivo, "%s %s %s %s\n", nome, email, usuarioLogin, senhaLogin);
        if(strcmp(usr.usuario, usuarioLogin) == 0 && strcmp(usr.senha, senhaLogin) == 0) {
            login = 1;
            break;
        }
    }
    fclose(arquivo);

    if(login) {
        return login_valido = 1;
    } else {
        gotoxy(37, 22);
        printf("Usuário ou senha incorretos!");
        Sleep(3000);
        menu_login();
    }
}
