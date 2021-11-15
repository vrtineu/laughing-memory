#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include ".//headers//console.h"
#include ".//headers//structures.h"
#include ".//headers//principal.h"
#include ".//headers//login.h"
#include ".//headers//atletas.h"
#include ".//headers//ranking.h"
#include ".//headers//calendario.h"

/* Função principal do programa. */
int main() {
    configurar_console();

    cabecalho_login();
    Sleep(1000);
    menu_login();
    login_valido ? menu_principal() : cabecalho_login();
    
    return 0; /* Encerra a aplicação */
}
