#include "relatorio_pessoa.h"
#include "../pessoa/pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQUIVO "pessoas.dat"

void inicializarArquivoPessoas() {
    FILE *arquivo = fopen(ARQUIVO, "ab");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo de pessoas");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

void listarRelatoriosPessoas() {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    // Contar quantas pessoas existem no arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    int quantidadePessoas = tamanhoArquivo / sizeof(Pessoa);
    if (quantidadePessoas == 0) {
        printf("Nenhuma pessoa encontrada no arquivo.\n");
        fclose(arquivo);
        return;
    }

    // Alocar memória para as pessoas
    Pessoa *pessoas = malloc(quantidadePessoas * sizeof(Pessoa));
    if (!pessoas) {
        perror("Erro ao alocar memória");
        fclose(arquivo);
        return;
    }

    // Ler as pessoas do arquivo
    fread(pessoas, sizeof(Pessoa), quantidadePessoas, arquivo);
    fclose(arquivo);

    // Função de comparação para ordenar as pessoas por nome
    int compararPorNome(const void *a, const void *b) {
        Pessoa *pessoaA = (Pessoa *)a;
        Pessoa *pessoaB = (Pessoa *)b;
        return strcmp(pessoaA->nome, pessoaB->nome);
    }

    // Ordenar as pessoas
    qsort(pessoas, quantidadePessoas, sizeof(Pessoa), compararPorNome);

    // Exibir as pessoas ordenadas
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Relatório de Pessoas em Ordem Alfabética = = = = = ///\n");
    printf("///                                                                         ///\n");

    for (int i = 0; i < quantidadePessoas; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %s\n", pessoas[i].idade);
        printf("Email: %s\n", pessoas[i].email);
        printf("Telefone: %s\n", pessoas[i].telefone);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("-------------------------\n");
    }

    printf("///////////////////////////////////////////////////////////////////////////////\n");

    // Liberar memória alocada
    free(pessoas);
}

void filtrarPorNome(const char *nomeFiltro) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Pessoa entrada;
    int encontrado = 0;

    printf("Relatório de Pessoas (Filtrado por Nome: %s):\n", nomeFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Pessoa), 1, arquivo)) {
        if (strstr(entrada.nome, nomeFiltro)) {
            encontrado = 1;
            printf("Nome: %s\n", entrada.nome);
            printf("Idade: %s\n", entrada.idade);
            printf("Email: %s\n", entrada.email);
            printf("Telefone: %s\n", entrada.telefone);
            printf("CPF: %s\n", entrada.cpf);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhuma pessoa encontrada com o nome: %s\n", nomeFiltro);
    }

    fclose(arquivo);
}

void filtrarPorIdade(const char *idadeFiltro) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Pessoa entrada;
    int encontrado = 0;

    printf("Relatório de Pessoas (Filtrado por Idade: %s):\n", idadeFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Pessoa), 1, arquivo)) {
        if (strcmp(entrada.idade, idadeFiltro) == 0) {
            encontrado = 1;
            printf("Nome: %s\n", entrada.nome);
            printf("Idade: %s\n", entrada.idade);
            printf("Email: %s\n", entrada.email);
            printf("Telefone: %s\n", entrada.telefone);
            printf("CPF: %s\n", entrada.cpf);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhuma pessoa encontrada com a idade: %s\n", idadeFiltro);
    }

    fclose(arquivo);
}

void filtrarPorEmail(const char *emailFiltro) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Pessoa entrada;
    int encontrado = 0;

    printf("Relatório de Pessoas (Filtrado por Email: %s):\n", emailFiltro);
    printf("-------------------------\n");

    while (fread(&entrada, sizeof(Pessoa), 1, arquivo)) {
        if (strcmp(entrada.email, emailFiltro) == 0) {
            encontrado = 1;
            printf("Nome: %s\n", entrada.nome);
            printf("Idade: %s\n", entrada.idade);
            printf("Email: %s\n", entrada.email);
            printf("Telefone: %s\n", entrada.telefone);
            printf("CPF: %s\n", entrada.cpf);
            printf("-------------------------\n");
        }
    }

    if (!encontrado) {
        printf("Nenhuma pessoa encontrada com o email: %s\n", emailFiltro);
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
        printf("///            1. Exibir Todas as Pessoas                                  ///\n");
        printf("///            2. Filtrar por Nome                                         ///\n");
        printf("///            3. Filtrar por Idade                                        ///\n");
        printf("///            4. Filtrar por Email                                        ///\n");
        printf("///            0. Voltar ao Menu Anterior                                  ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                listarRelatoriosPessoas();
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 2:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Nome para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorNome(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 3:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe a Idade para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorIdade(criterio);
                printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;

            case 4:
                printf("\n///////////////////////////////////////////////////////////////////////////////\n");
                printf("///            Informe o Email para Filtragem: ");
                fgets(criterio, sizeof(criterio), stdin);
                criterio[strcspn(criterio, "\n")] = '\0'; // Remove o '\n'
                filtrarPorEmail(criterio);
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
