#include <stdio.h>
#include <stdlib.h>
#include "ler_pessoa.h"
#include "../util/util.h"

void ler_nome(char *nome, size_t tamanho) {
    do {
        printf("///            Nome: ");
        fgets(nome, tamanho, stdin);
        remove_newline(nome);
        if (!validarNome(nome)) {
            printf("///            Nome inválido! Deve ter pelo menos 3 caracteres.\n");
        }
    } while (!validarNome(nome));
}

// Função para ler idade
void ler_idade(char *idade, size_t tamanho) {
    do {
        printf("///            Idade: ");
        fgets(idade, tamanho, stdin);
        remove_newline(idade);
        if (!validar_idade(idade)) {
            printf("///            Idade inválida! Deve estar entre 0 e 120.\n");
        }
    } while (!validar_idade(idade));
}

// Função para ler email
void ler_email(char *email, size_t tamanho) {
    do {
        printf("///            E-mail: ");
        fgets(email, tamanho, stdin);
        remove_newline(email);
        if (!validar_email(email)) {
            printf("///            E-mail inválido! Deve conter '@' e '.'.\n");
        }
    } while (!validar_email(email));
}

// Função para ler telefone
void ler_telefone(char *tel, size_t tamanho) {
    do {
        printf("///            Telefone: ");
        fgets(tel, tamanho, stdin);
        remove_newline(tel);
        if (!validar_telefone(tel)) {
            printf("///            Telefone inválido! Deve conter pelo menos 10 dígitos.\n");
        }
    } while (!validar_telefone(tel));
}

// Função para ler CPF
void ler_cpf(char *cpf, size_t tamanho) {
    do {
        printf("///            CPF: ");
        fgets(cpf, tamanho, stdin);
        remove_newline(cpf);
        if (!validar_cpf(cpf)) {
            printf("///            CPF inválido! Deve conter exatamente 11 dígitos.\n");
        }
    } while (!validar_cpf(cpf));
}



