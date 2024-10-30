#include <time.h>
#include <stdlib.h>
#include <string.h>

// BY : @flgorgonio

//////
////// Funções do Módulo Utilitário
//////



///
/// Faz uma pausa por n segundos, com n sendo passado como parâmetro
///
void delay(int segundos) {
    int tempo = 1000 * segundos;
    clock_t inicio = clock();
    while (clock() < inicio + tempo) {
        // não faz nada, apenas gasta tempo
    }
}

///
/// Limpa a tela; funciona em Linux / MacOS / Windows
///
void limpa_tela(void) {
    if (system("clear") || system("cls")) {
        // limpa a tela, Linux, Mac e Windows
    }
}

///
/// Retorna 1 se o caractere recebido for um dígito (entre 0 e 9)
/// retorna 0 caso contrário
///
int eh_digito(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    } else {
        return 0;
    }
}