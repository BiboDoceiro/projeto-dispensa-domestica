#include "relatorio_orcamento.h"
#include "../orcamento/orcamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORCAMENTO_ARQUIVO "orcamento.dat"

void inicializarArquivo() {
    FILE *arquivo = fopen(ORCAMENTO_ARQUIVO, "ab");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

void gerarRelatorio() {
    FILE *arquivo = fopen(ORCAMENTO_ARQUIVO, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    Orcamento entrada;
    printf("Relatório de Orçamento:\n");
    printf("-------------------------\n");
    
    while (fread(&entrada, sizeof(Orcamento), 1, arquivo) > 0) {
        printf("ID: %d\n", entrada.id);
        
        printf("Descrição: %s\n", entrada.descricao);
        
        double valor = atof(entrada.valor);
        printf("Valor: R$ %.2f\n", valor);
        printf("-------------------------\n");
    }

    fclose(arquivo);
}

double calcularTotal() {
    FILE *arquivo = fopen(ORCAMENTO_ARQUIVO, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    double total = 0;
    Orcamento entrada;

    while (fread(&entrada, sizeof(Orcamento), 1, arquivo) > 0) {
        total += atof(entrada.valor);
    }

    fclose(arquivo);
    return total;
}
