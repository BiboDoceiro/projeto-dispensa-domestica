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

///
/// Retorna 1 se o caractere recebido for um caractere alfabético 
/// (letra entre 'A' e 'Z' ou entre 'a' e 'z') ou retorna 0 caso contrário
///
int ehLetra(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}


///
/// Retorna 1 se string recebido for exclusivamente alfabético ou
/// retorna 0 caso contrário
///
int validarNome(char* nome) {
    for (int i=0; nome[i]!='\0'; i++) {
        if (!ehLetra(nome[i])) {
            return 0;
        }
    }
    return 1;
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para validar idade
int validar_idade(const char *idade) {
    for (int i = 0; idade[i] != '\0'; i++) {
        if (!eh_digito(idade[i])) {
            return 0;
        }
    }
    int idade_int = atoi(idade);
    return idade_int > 0 && idade_int <= 120;
}

// Função para validar email
int validar_email(const char *email) {
    return strchr(email, '@') && strchr(email, '.');
}

// Função para validar telefone
int validar_telefone(const char *tel) {
    int count = 0;
    for (int i = 0; tel[i] != '\0'; i++) {
        if (eh_digito(tel[i])) {
            count++;
        }
    }
    return count >= 10;
}

// Função para validar CPF
int validar_cpf(const char *cpf) {
    int count = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (eh_digito(cpf[i])) {
            count++;
        }
    }
    return count == 11;
}