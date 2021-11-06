#pragma once

/* Configurações do terminal */
void configurar_console() {
    system("mode 90, 35"); /* Configura o tamanho do console */
    system("chcp 65001");  /* Configura o console para utf-8 */
    system("cls");         /* Limpa o console */
    system("title Olympics"); /* Configura o titulo do console */
}

/* Função para posicionar o cursor na tela */
void gotoxy(short x, short y) {
    COORD pos = {
        x,
        y
    };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/* Exibe cabeçalho no centro da tela com a palavra "olympics". */
void cabecalho() {
    gotoxy(23, 1);
    printf("       _                       _          \n");
    gotoxy(23, 2);
    printf("      | |                     (_)         \n");
    gotoxy(23, 3);
    printf("  ___ | |_   _ _ __ ___  _ __  _  ___ ___ \n");
    gotoxy(23, 4);
    printf(" / _ \\| | | | | '_ ` _ \\| '_ \\| |/ __/ __|\n");
    gotoxy(23, 5);
    printf("| (_) | | |_| | | | | | | |_) | | (__\\__ \\\n");
    gotoxy(23, 6);
    printf(" \\___/|_|\\__, |_| |_| |_| .__/|_|\\___|___/\n");
    gotoxy(23, 7);
    printf("          __/ |         | |               \n");
    gotoxy(23, 8);
    printf("         |___/          |_|               \n");
}