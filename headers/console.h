#pragma once

/* Cofigurações do terminal */
void configurar_console() {
    system("mode 80, 25"); /* Configura o tamanho do console */
    system("chcp 65001");  /* Configura o console para utf-8 */
    system("cls");         /* Limpa o console */
}

/* Função para posicionar o cursor na tela */
void gotoxy(short x, short y) {
    COORD pos = {
        x,
        y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/* Exibe cabeçalho no centro da tela com a palavra "olympics". */
void cabecalho() {
    gotoxy(19, 2);
    printf("       _                       _          \n");
    gotoxy(19, 3);
    printf("      | |                     (_)         \n");
    gotoxy(19, 4);
    printf("  ___ | |_   _ _ __ ___  _ __  _  ___ ___ \n");
    gotoxy(19, 5);
    printf(" / _ \\| | | | | '_ ` _ \\| '_ \\| |/ __/ __|\n");
    gotoxy(19, 6);
    printf("| (_) | | |_| | | | | | | |_) | | (__\\__ \\\n");
    gotoxy(19, 7);
    printf(" \\___/|_|\\__, |_| |_| |_| .__/|_|\\___|___/\n");
    gotoxy(19, 8);
    printf("          __/ |         | |               \n");
    gotoxy(19, 9);
    printf("         |___/          |_|               \n");
}