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

void filtrarPorNomeProduto(const char *nomeFiltro) {
    FILE *arquivo = fopen(PRODUTOS_ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de produtos para leitura");
        return;
    }

    Produto entrada;
    int encontrado = 0;

    printf("Relatório de Produtos (Filtrado por Nome: %s):\n", nomeFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (strstr(entrada.nome, nomeFiltro)) {
            encontrado = 1;
            printf("ID Código: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nome);
            printf("Marca: %s\n", entrada.marca);
            printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
            printf("Valor: %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o nome: %s\n", nomeFiltro);
    }

    fclose(arquivo);
}

void filtrarPorMarca(const char *marcaFiltro) {
    FILE *arquivo = fopen(PRODUTOS_ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de produtos para leitura");
        return;
    }

    Produto entrada;
    int encontrado = 0;

    printf("Relatório de Produtos (Filtrado por Marca: %s):\n", marcaFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (strcmp(entrada.marca, marcaFiltro) == 0) {
            encontrado = 1;
            printf("ID Código: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nome);
            printf("Marca: %s\n", entrada.marca);
            printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
            printf("Valor: %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com a marca: %s\n", marcaFiltro);
    }

    fclose(arquivo);
}

void filtrarPorValor(const char *valorFiltro) {
    FILE *arquivo = fopen(PRODUTOS_ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de produtos para leitura");
        return;
    }

    Produto entrada;
    int encontrado = 0;

    printf("Relatório de Produtos (Filtrado por Valor: %s):\n", valorFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Produto), 1, arquivo)) {
        if (strcmp(entrada.valor, valorFiltro) == 0) {
            encontrado = 1;
            printf("ID Código: %d\n", entrada.id_codigo);
            printf("Nome: %s\n", entrada.nome);
            printf("Marca: %s\n", entrada.marca);
            printf("Quantidade em Estoque: %d\n", entrada.quantidade_estoque);
            printf("Valor: %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum produto encontrado com o valor: %s\n", valorFiltro);
    }

    fclose(arquivo);
}

void relatorio_produto(void) {
    int opcao;
    char criterio[100];

    do {
        system("clear||cls");
        printf("\n///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = Relatório de Produtos = = = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Filtrar por Nome                                          ///\n");
        printf("///            2. Filtrar por Marca                                         ///\n");
        printf("///            3. Filtrar por Valor                                         ///\n");
        printf("///            0. Voltar ao Menu Anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Nome para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorNomeProduto(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 2:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe a Marca para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorMarca(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 3:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Valor para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorValor(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 0:
                printf("\nRetornando ao Menu Anterior...\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
        }
    } while (opcao != 0);
}