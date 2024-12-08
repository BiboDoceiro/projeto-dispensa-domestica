#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orcamento.h"
#include "ler_orcamento.h"
#include "orcamento_arquivo.h"

#define ARQUIVO "orcamento.dat"

void salvar_orcamento_arquivo(const Orcamento *orcamento) {
    FILE *arquivo = fopen(ARQUIVO, "ab");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    fwrite(orcamento, sizeof(Orcamento), 1, arquivo); 
    fclose(arquivo);
}


void carregar_orcamentos_arquivo(Orcamento **orcamentos, int *qtd_orcamentos) {
    FILE *arquivo = fopen(ARQUIVO_ORCAMENTO, "rb");
    if (!arquivo) {
        *orcamentos = NULL;
        *qtd_orcamentos = 0;
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    *qtd_orcamentos = tamanho / sizeof(Orcamento);
    *orcamentos = malloc(tamanho);

    if (*orcamentos) {
        fread(*orcamentos, sizeof(Orcamento), *qtd_orcamentos, arquivo);
    }

    fclose(arquivo);
}


void atualizar_orcamento_arquivo(int id_codigo) {
    Orcamento *orcamentos;
    int qtd_orcamentos;

    carregar_orcamentos_arquivo(&orcamentos, &qtd_orcamentos);

    if (!orcamentos) {
        printf("Nenhum orçamento cadastrado!\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < qtd_orcamentos; i++) {
        if (orcamentos[i].id_codigo == id_codigo) {
            encontrado = 1;
            printf("Informe os novos dados para o orçamento:\n");
            printf("Descrição: ");
            scanf(" %[^\n]", orcamentos[i].descricao);
            printf("Valor: ");
            scanf("%lf", &orcamentos[i].valor);
            printf("Status (Aberto/Fechado): ");
            scanf(" %[^\n]", orcamentos[i].status);
            break;
        }
    }

    if (encontrado) {
        FILE *arquivo = fopen(ARQUIVO_ORCAMENTO, "wb");
        if (!arquivo) {
            perror("Erro ao abrir o arquivo para atualização");
            free(orcamentos);
            return;
        }

        fwrite(orcamentos, sizeof(Orcamento), qtd_orcamentos, arquivo);
        fclose(arquivo);

        printf("Orçamento atualizado com sucesso!\n");
    } else {
        printf("Orçamento não encontrado.\n");
    }

    free(orcamentos);
}


void excluir_orcamento_arquivo(int id_codigo) {
    Orcamento *orcamentos;
    int qtd_orcamentos;

    carregar_orcamentos_arquivo(&orcamentos, &qtd_orcamentos);

    if (!orcamentos) {
        printf("Nenhum orçamento cadastrado!\n");
        return;
    }

    FILE *arquivo = fopen(ARQUIVO_ORCAMENTO, "wb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para exclusão");
        free(orcamentos);
        return;
    }

    for (int i = 0; i < qtd_orcamentos; i++) {
        if (orcamentos[i].id_codigo != id_codigo) {
            fwrite(&orcamentos[i], sizeof(Orcamento), 1, arquivo);
        }
    }

    fclose(arquivo);
    printf("Orçamento excluído com sucesso!\n");

    free(orcamentos);
}


int obter_proximo_id_orcamento(void) {
    Orcamento *orcamentos;
    int qtd_orcamentos;
    carregar_orcamentos_arquivo(&orcamentos, &qtd_orcamentos);

    int proximo_id = 1;

    if (orcamentos != NULL && qtd_orcamentos > 0) {
        int maior_id = 0;
        for (int i = 0; i < qtd_orcamentos; i++) {
            if (orcamentos[i].id_codigo > maior_id) {
                maior_id = orcamentos[i].id_codigo;
            }
        }
        proximo_id = maior_id + 1;
    }

    free(orcamentos);
    return proximo_id;
}



Orcamento* buscar_orcamento_arquivo(int id_codigo) {
    Orcamento *orcamentos;
    int qtd_orcamentos;

    carregar_orcamentos_arquivo(&orcamentos, &qtd_orcamentos);

    if (!orcamentos) {
        printf("Nenhum orçamento cadastrado!\n");
        return NULL;
    }

    for (int i = 0; i < qtd_orcamentos; i++) {
        if (orcamentos[i].id_codigo == id_codigo) {
            Orcamento *orcamento_encontrado = malloc(sizeof(Orcamento));
            *orcamento_encontrado = orcamentos[i];
            free(orcamentos);
            return orcamento_encontrado;
        }
    }

    free(orcamentos);
    return NULL;
}
