#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa_arquivo.h"
#include "pessoa.h"
#include "ler_pessoa.h"

#define ARQUIVO "pessoas.dat"

void salvar_pessoa_arquivo(const Pessoa *pessoa) {
    FILE *arquivo = fopen(ARQUIVO, "ab"); 
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    fwrite(pessoa, sizeof(Pessoa), 1, arquivo);
    fclose(arquivo);
}

void carregar_pessoas_arquivo(Pessoa **pessoas, int *qtd_pessoas) {
    FILE *arquivo = fopen(ARQUIVO, "rb"); 
    if (!arquivo) {
        *pessoas = NULL;
        *qtd_pessoas = 0;
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    *qtd_pessoas = tamanho / sizeof(Pessoa);
    *pessoas = malloc(tamanho);

    if (*pessoas) {
        fread(*pessoas, sizeof(Pessoa), *qtd_pessoas, arquivo);
    }

    fclose(arquivo);
}

void atualizar_pessoa(const char *cpf) {
    Pessoa *pessoas;
    int qtd_pessoas;

    carregar_pessoas_arquivo(&pessoas, &qtd_pessoas);
    if (!pessoas) {
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < qtd_pessoas; i++) {
        if (strcmp(pessoas[i].cpf, cpf) == 0) {
            encontrado = 1;
            printf("Informe os novos dados para a pessoa:\n");
            ler_nome(pessoas[i].nome, sizeof(pessoas[i].nome));
            ler_idade(pessoas[i].idade, sizeof(pessoas[i].idade));
            ler_email(pessoas[i].email, sizeof(pessoas[i].email));
            ler_telefone(pessoas[i].telefone, sizeof(pessoas[i].telefone));
            break;
        }
    }

    if (encontrado) {
        FILE *arquivo = fopen(ARQUIVO, "wb");
        fwrite(pessoas, sizeof(Pessoa), qtd_pessoas, arquivo);
        fclose(arquivo);
        printf("Cadastro atualizado com sucesso!\n");
    } else {
        printf("Pessoa não encontrada.\n");
    }

    free(pessoas);
}

void excluir_pessoa_arquivo(const char *cpf) {
    Pessoa *pessoas;
    int qtd_pessoas;

    carregar_pessoas_arquivo(&pessoas, &qtd_pessoas);
    if (!pessoas) {
        printf("Nenhuma pessoa cadastrada!\n");
        return;
    }

    FILE *arquivo = fopen(ARQUIVO, "wb"); 
    for (int i = 0; i < qtd_pessoas; i++) {
        if (strcmp(pessoas[i].cpf, cpf) != 0) {
            fwrite(&pessoas[i], sizeof(Pessoa), 1, arquivo);
        }
    }
    fclose(arquivo);

    printf("Cadastro excluído com sucesso!\n");
    free(pessoas);
}

void buscar_pessoa_por_cpf(const char *cpf) {
    FILE *arquivo = fopen(ARQUIVO, "rb"); 
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    Pessoa pessoa;
    int encontrado = 0;

    while (fread(&pessoa, sizeof(Pessoa), 1, arquivo)) {
        if (strcmp(pessoa.cpf, cpf) == 0) {

            printf("\n///////////////////////////////////////////////////////////////////////////////\n");
            printf("///            = = = = = Pessoa Encontrada = = = = =                        ///\n");
            printf("///                                                                         ///\n");
            printf("///            Nome: %s\n", pessoa.nome);
            printf("///            Idade: %s\n", pessoa.idade);
            printf("///            E-mail: %s\n", pessoa.email);
            printf("///            Tel: %s\n", pessoa.telefone);
            printf("///            CPF: %s\n", pessoa.cpf);
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado) {
        printf("\nNenhuma pessoa encontrada com o CPF: %s\n", cpf);
    }

    fclose(arquivo);
}