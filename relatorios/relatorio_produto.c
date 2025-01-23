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

void listarRelatoriosProdutos() {
    FILE *arquivo = fopen(PRODUTOS_ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo de produtos para leitura");
        return;
    }

    // Contar quantos produtos existem no arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    int quantidadeProdutos = tamanhoArquivo / sizeof(Produto);
    if (quantidadeProdutos == 0) {
        printf("Nenhum produto encontrado no arquivo.\n");
        fclose(arquivo);
        return;
    }

    // Alocar memória para os produtos
    Produto *produtos = malloc(quantidadeProdutos * sizeof(Produto));
    if (!produtos) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return;
    }

    // Ler os produtos do arquivo
    fread(produtos, sizeof(Produto), quantidadeProdutos, arquivo);
    fclose(arquivo);

    // Função de comparação para ordenar os produtos por nome
    int compararPorNome(const void *a, const void *b) {
        Produto *produtoA = (Produto *)a;
        Produto *produtoB = (Produto *)b;
        return strcmp(produtoA->nome, produtoB->nome);
    }

    // Ordenar os produtos
    qsort(produtos, quantidadeProdutos, sizeof(Produto), compararPorNome);

    // Exibir os produtos ordenados
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Produtos em Ordem Alfabética = = = = = ///\n");
    printf("///                                                                         ///\n");

    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("ID Código: %d\n", produtos[i].id_codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Marca: %s\n", produtos[i].marca);
        printf("Quantidade em Estoque: %d\n", produtos[i].quantidade_estoque);
        printf("Valor: %s\n", produtos[i].valor);
        printf("-------------------------\n");
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");

    // Liberar memória alocada
    free(produtos);
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
        printf("///            1. Exibir Todos os Produtos                                 ///\n");
        printf("///            2. Filtrar por Nome                                         ///\n");
        printf("///            3. Filtrar por Marca                                        ///\n");
        printf("///            4. Filtrar por Valor                                        ///\n");
        printf("///            0. Voltar ao Menu Anterior                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                listarRelatoriosProdutos();
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 2:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Nome para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorNomeProduto(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 3:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe a Marca para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorMarca(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 4:
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