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
            while (getchar() != '\n'); // Limpa o buffer de entrada
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

void ler_validade(char *data, size_t tamanho) {
    int dia, mes, ano;
    do {
        printf("///            Data de validade (DD/MM/AAAA): ");
        fgets(data, tamanho, stdin);
        remove_newline(data);

        // Tentar interpretar a data
        if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
            printf("///            Formato inválido! Certifique-se de usar o formato DD/MM/AAAA.\n");
            continue;
        }

        // Verificar limites básicos
        if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 2023) {
            printf("///            Data inválida! Certifique-se de inserir uma data futura válida.\n");
            continue;
        }

        // Validar o dia em relação ao mês
        if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
            printf("///            O mês informado tem no máximo 30 dias.\n");
            continue;
        }

        // Validar fevereiro e anos bissextos
        if (mes == 2) {
            int is_leap_year = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
            if (dia > 29 || (dia == 29 && !is_leap_year)) {
                printf("///            Fevereiro tem no máximo %d dias nesse ano.\n", is_leap_year ? 29 : 28);
                continue;
            }
        }

        // Tudo está válido
        break;
    } while (1);
}