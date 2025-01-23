#include "relatorio_orcamento.h"
#include "../orcamento/orcamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORCAMENTO_ARQUIVO "orcamento.dat"

void inicializarArquivoOrcamentos() {
    FILE *arquivo = fopen(ORCAMENTO_ARQUIVO, "ab");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

double listarRelatoriosOrcamentos() {
    FILE *arquivo = fopen(ORCAMENTO_ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return 0.0;
    }

    // Contar quantos orçamentos existem no arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    int quantidadeOrcamentos = tamanhoArquivo / sizeof(Orcamento);
    if (quantidadeOrcamentos == 0) {
        printf("Nenhum orçamento encontrado no arquivo.\n");
        fclose(arquivo);
        return 0.0;
    }

    // Alocar memória para os orçamentos
    Orcamento *orcamentos = malloc(quantidadeOrcamentos * sizeof(Orcamento));
    if (!orcamentos) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return 0.0;
    }

    // Ler os orçamentos do arquivo
    fread(orcamentos, sizeof(Orcamento), quantidadeOrcamentos, arquivo);
    fclose(arquivo);

    // Função de comparação para ordenar os orçamentos por descrição
    int compararPorDescricao(const void *a, const void *b) {
        Orcamento *orcamentoA = (Orcamento *)a;
        Orcamento *orcamentoB = (Orcamento *)b;
        return strcmp(orcamentoA->descricao, orcamentoB->descricao);
    }

    // Ordenar os orçamentos
    qsort(orcamentos, quantidadeOrcamentos, sizeof(Orcamento), compararPorDescricao);

    // Exibir os orçamentos ordenados
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Orçamentos em Ordem Alfabética = = = = =          ///\n");
    printf("///                                                                         ///\n");

    for (int i = 0; i < quantidadeOrcamentos; i++) {
        printf("ID: %d\n", orcamentos[i].id);
        printf("Descrição: %s\n", orcamentos[i].descricao);
        printf("Valor: R$ %s\n", orcamentos[i].valor);
        printf("-------------------------\n");
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");

    // Liberar memória alocada
    free(orcamentos);
    return 0.0;
}

void menu_relatorio_orcamento(void) {
    int opcao;
    char criterio[100];

    do {
        system("clear||cls");
        printf("\n///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = Relatório de Orçamentos = = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Exibir Todos os Orçamentos                               ///\n");
        printf("///            2. Filtrar por Descrição                                    ///\n");
        printf("///            3. Filtrar por Valor                                        ///\n");
        printf("///            0. Voltar ao Menu Anterior                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                listarRelatoriosOrcamentos(); 
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 2:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe a Descrição para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; 
                filtrar_orcamento_por_descricao(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 3:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Valor para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0';
                filtrar_orcamento_por_valor(criterio); 
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

void filtrar_orcamento_por_descricao(const char *descricaoFiltro) {
    FILE *arquivo = fopen(ORCAMENTO_ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Orcamento entrada;
    int encontrado = 0;

    printf("Orçamentos (Filtrado por Descrição: %s):\n", descricaoFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Orcamento), 1, arquivo)) {
        if (strstr(entrada.descricao, descricaoFiltro)) {
            encontrado = 1;
            printf("ID: %d\n", entrada.id);
            printf("Descrição: %s\n", entrada.descricao);
            printf("Valor: %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum orçamento encontrado com a descrição: %s\n", descricaoFiltro);
    }

    fclose(arquivo);
}

void filtrar_orcamento_por_valor(const char *valorFiltro) {
    FILE *arquivo = fopen(ORCAMENTO_ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Orcamento entrada;
    int encontrado = 0;

    printf("Orçamentos (Filtrado por Valor: %s):\n", valorFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Orcamento), 1, arquivo)) {
        if (strcmp(entrada.valor, valorFiltro) == 0) { // Filtra por valor exato
            encontrado = 1;
            printf("ID: %d\n", entrada.id);
            printf("Descrição: %s\n", entrada.descricao);
            printf("Valor: %s\n", entrada.valor);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhum orçamento encontrado com o valor: %s\n", valorFiltro);
    }

    fclose(arquivo);
}
