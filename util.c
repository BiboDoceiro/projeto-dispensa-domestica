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

