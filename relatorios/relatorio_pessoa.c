#include "relatorio_pessoa.h"
#include "../pessoa/pessoa.h"
#include "../pessoa/pessoa_arquivo.h"
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

void relatorio_pessoa(void) {
    int opcao;
    char criterio[100];

    do {
        system("clear||cls");
        printf("\n///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = Relatório de Pessoas = = = = = = = = = =           ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Filtrar por Nome                                          ///\n");
        printf("///            2. Filtrar por Idade                                         ///\n");
        printf("///            3. Filtrar por Email                                         ///\n");
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
                filtrarPorNome(criterio); // Chama a função de filtragem por nome
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 2:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe a Idade para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorIdade(criterio); // Chama a função de filtragem por idade
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 3:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Email para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorEmail(criterio); // Chama a função de filtragem por e-mail
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