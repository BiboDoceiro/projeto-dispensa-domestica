// relatorio_produto.c
#include "relatorio_produto.h"
#include "../produtos/produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUTOS_ARQUIVO "produtos.dat"

void inicializarArquivoProdutos() {
    FILE *arquivo = fopen(PRODUTOS_ARQUIVO, "ab");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo de produtos");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

void gerarRelatorioProdutos() {
    FILE *arquivo = fopen(PRODUTOS_ARQUIVO, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de produtos para leitura");
        exit(EXIT_FAILURE);
    }

    Produto entrada;
    printf("Relatório de Produtos:\n");
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo) > 0) {
        printf("ID Código: %d\n", entrada.id_codigo);
        printf("Nome: %s\n", entrada.nome);
        printf("Marca: %s\n", entrada.marca);
        printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
        printf("Valor: %s\n", entrada.valor);
        printf("-------------------------\n");
    }

    fclose(arquivo);
}

int calcularTotalEstoque() {
    FILE *arquivo = fopen(PRODUTOS_ARQUIVO, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de produtos para leitura");
        exit(EXIT_FAILURE);
    }

    int totalEstoque = 0;
    Produto entrada;

    while (fread(&entrada, sizeof(Produto), 1, arquivo) > 0) {
        totalEstoque += entrada.quantidade_estoque;
    }

    fclose(arquivo);
    return totalEstoque;
}