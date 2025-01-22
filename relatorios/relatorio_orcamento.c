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
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    double total = 0;
    Orcamento entrada;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório Detalhado de Orçamentos = = = = =        ///\n");
    printf("///                                                                         ///\n");

    while (fread(&entrada, sizeof(Orcamento), 1, arquivo) > 0) {
        printf("ID: %d\n", entrada.id);
        printf("Descrição: %s\n", entrada.descricao);
        printf("Valor: R$ %s\n", entrada.valor);

        total += atof(entrada.valor); // Soma o valor total
        printf("-------------------------\n");
    }

    printf("///                                                                         ///\n");
    printf("///            Valor Total dos Orçamentos: R$ %.2f                          ///\n", total);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    fclose(arquivo);
    return total;
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
