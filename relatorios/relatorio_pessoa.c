#include "relatorio_pessoa.h"
#include "../pessoa/pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PESSOAS_ARQUIVO "pessoas.dat"

void inicializarArquivoPessoas() {
    FILE *arquivo = fopen(PESSOAS_ARQUIVO, "ab");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo de pessoas");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

void gerarRelatorioPessoas() {
    FILE *arquivo = fopen(PESSOAS_ARQUIVO, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de pessoas para leitura");
        exit(EXIT_FAILURE);
    }

    Pessoa entrada;
    printf("Relatório de Pessoas:\n");
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Pessoa), 1, arquivo) > 0) {
        printf("Nome: %s\n", entrada.nome);
        printf("Idade: %s\n", entrada.idade);
        printf("Email: %s\n", entrada.email);
        printf("Telefone: %s\n", entrada.telefone);
        printf("CPF: %s\n", entrada.cpf);
        printf("-------------------------\n");
    }

    fclose(arquivo);
}