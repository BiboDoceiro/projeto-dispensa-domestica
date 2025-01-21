#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produtos.h"
#include "ler_produtos.h"
#include "produto_arquivo.h"

#define ARQUIVO "produtos.dat"

void salvar_produto_arquivo(const Produto *produto) {
    FILE *arquivo = fopen(ARQUIVO, "ab");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }
    fwrite(produto, sizeof(Produto), 1, arquivo); 
    fclose(arquivo);
}


void carregar_produtos_arquivo(Produto **produtos, int *qtd_produtos) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (!arquivo) {
        *produtos = NULL;
        *qtd_produtos = 0;
        return;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanho = ftell(arquivo);
    rewind(arquivo);

    *qtd_produtos = tamanho / sizeof(Produto);
    *produtos = malloc(tamanho);

    if (*produtos) {
        fread(*produtos, sizeof(Produto), *qtd_produtos, arquivo);
    }

    fclose(arquivo);
}

void atualizar_produto_arquivo(int id_codigo) {
    Produto *produtos;
    int qtd_produtos;

    carregar_produtos_arquivo(&produtos, &qtd_produtos); 

    if (!produtos) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    int encontrado = 0;
    for (int i = 0; i < qtd_produtos; i++) {
        if (produtos[i].id_codigo == id_codigo) {
            encontrado = 1;
            printf("Informe os novos dados para o produto:\n");
            ler_nome_produto(produtos[i].nome, sizeof(produtos[i].nome));
            ler_marca(produtos[i].marca, sizeof(produtos[i].marca));
            ler_quantidade(&produtos[i].quantidade_estoque);
            ler_valor_produto(produtos[i].valor, sizeof(produtos[i].valor));
            break;
        }
    }

    if (encontrado) {

        FILE *arquivo = fopen(ARQUIVO, "wb");
        if (!arquivo) {
            perror("Erro ao abrir o arquivo para atualização");
            free(produtos);
            return;
        }


        fwrite(produtos, sizeof(Produto), qtd_produtos, arquivo);
        fclose(arquivo);

        printf("Produto atualizado com sucesso!\n");
    } else {
        printf("Produto não encontrado.\n");
    }

    free(produtos); 
}

void excluir_produto_arquivo(int id_codigo) {
    Produto *produtos;
    int qtd_produtos;

    carregar_produtos_arquivo(&produtos, &qtd_produtos); 

    if (!produtos) {
        printf("Nenhum produto cadastrado!\n");
        return;
    }

    FILE *arquivo = fopen(ARQUIVO, "wb"); 
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para exclusão");
        free(produtos);
        return;
    }

    for (int i = 0; i < qtd_produtos; i++) {
        if (produtos[i].id_codigo != id_codigo) {
            fwrite(&produtos[i], sizeof(Produto), 1, arquivo); 
        }
    }

    fclose(arquivo);
    printf("Produto excluído com sucesso!\n");

    free(produtos);
}

int obter_proximo_id_produto(void) {
    Produto *produtos;
    int qtd_produtos;
    carregar_produtos_arquivo(&produtos, &qtd_produtos); 

    int proximo_id = 1;

    if (produtos != NULL && qtd_produtos > 0) {

        int maior_id = 0;
        for (int i = 0; i < qtd_produtos; i++) {
            if (produtos[i].id_codigo > maior_id) {
                maior_id = produtos[i].id_codigo;
            }
        }
        proximo_id = maior_id + 1; 
    }

    free(produtos);
    return proximo_id;
}

Produto* buscar_produto_arquivo(int id_codigo) {
    Produto *produtos;
    int qtd_produtos;

    carregar_produtos_arquivo(&produtos, &qtd_produtos);

    if (!produtos) {
        printf("Nenhum produto cadastrado!\n");
        return NULL;
    }


    for (int i = 0; i < qtd_produtos; i++) {
        if (produtos[i].id_codigo == id_codigo) {
            Produto *produto_encontrado = &produtos[i];
            free(produtos);
            return produto_encontrado;
        }
    }


    free(produtos);
    return NULL;
}

