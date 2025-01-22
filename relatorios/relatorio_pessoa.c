#include "relatorio_pessoa.h"
#include "../pessoa/pessoa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

<<<<<<< Updated upstream
#define ARQUIVO "pessoas.dat"

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

void inicializarArquivoPessoas() {
    FILE *arquivo = fopen(ARQUIVO, "ab");
=======
<<<<<<< Updated upstream
#define PESSOAS_ARQUIVO "pessoas.dat"

void inicializarArquivoPessoas() {
    FILE *arquivo = fopen(PESSOAS_ARQUIVO, "ab");
=======
#define ARQUIVO "pessoas.dat"

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

void inicializarArquivoPessoas() {
    FILE *arquivo = fopen(ARQUIVO, "ab");
>>>>>>> Stashed changes
>>>>>>> Stashed changes
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo de pessoas");
        exit(EXIT_FAILURE);
    }
    fclose(arquivo);
}

<<<<<<< Updated upstream
void relatorio_pessoa(void) {
    int opcao;
    char criterio[100];
=======
<<<<<<< Updated upstream
void gerarRelatorioPessoas() {
    FILE *arquivo = fopen(PESSOAS_ARQUIVO, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de pessoas para leitura");
        exit(EXIT_FAILURE);
    }
>>>>>>> Stashed changes

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


<<<<<<< Updated upstream
=======
    fclose(arquivo);
}
=======
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

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
}
=======
}

>>>>>>> Stashed changes
>>>>>>> Stashed changes
