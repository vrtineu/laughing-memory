#include <conio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include ".//headers//console.h"
#include ".//headers//structures.h"
#include ".//headers//principal.h"
#include ".//headers//atletas.h"
#include ".//headers//ranking.h"


/* Função principal do programa. */
int main() {
    configurar_console();
    
    menu_principal();

    return 0; /* Encerra a aplicação */
}
