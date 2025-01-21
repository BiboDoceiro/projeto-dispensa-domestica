#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ler_produtos.h"
#include "../util/util.h"

void ler_id_codigo(int *id_codigo) {
    do {
        printf("Informe o código do produto (número inteiro): ");
        if (scanf("%d", id_codigo) != 1 || *id_codigo <= 0) {
            printf("Código inválido! Por favor, insira um número positivo.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    } while (1);
    getchar();
}

void ler_nome_produto(char *nome, size_t tamanho) {
    do {
        printf("///            Nome: ");
        fgets(nome, tamanho, stdin);
        remove_newline(nome); 
        if (!validarNome(nome)) {
            printf("///            Nome do produto é inválido! Deve ter pelo menos 3 caracteres.\n");
        }
    } while (!validarNome(nome));
}


void ler_marca(char *marca, size_t tamanho) {
    do {
        printf("///            marca: ");
        fgets(marca, tamanho, stdin);
        remove_newline(marca);
        if (!validarNome(marca)) {
            printf("///            Marca invalida! Deve ter pelo menos 3 caracteres.\n");
        }
    } while (!validarNome(marca));
}

void ler_quantidade(int *quantidade) {
    char buffer[10];
    int valor_valido = 0;
    do {
        printf("///            Quantidade em estoque (número inteiro): ");
        fgets(buffer, sizeof(buffer), stdin);
        remove_newline(buffer);

        if (sscanf(buffer, "%d", quantidade) != 1 || *quantidade < 0) {
            printf("///            Quantidade inválida! Por favor, insira um número não negativo.\n");
        } else {
            valor_valido = 1;
        }
    } while (!valor_valido);
}

void ler_valor_produto(char *valor, size_t tamanho) {
    double val;
    do {
        printf("///            Valor do produto (ex: 123.45): R$ ");
        fgets(valor, tamanho, stdin);
        remove_newline(valor);

        // Tentar interpretar o valor
        if (sscanf(valor, "%lf", &val) != 1) {
            printf("///            Formato inválido! Certifique-se de inserir um valor numérico válido.");
            continue;
        }

        // Verificar se o valor é positivo
        if (val < 0) {
            printf("///            Valor inválido! O valor deve ser maior ou igual a zero.");
            continue;
        }

        // Tudo está válido
        break;
    } while (1);
}