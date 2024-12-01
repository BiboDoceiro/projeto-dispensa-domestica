#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ler_orcamento.h"
#include "../util/util.h"

void ler_id(int *id) {
    do {
        printf("Informe o id do orçamento (número inteiro): ");
        if (scanf("%d", id) != 1 || *id <= 0) {
            printf("ID inválido! Por favor, insira um número positivo.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        } else {
            break;
        }
    } while (1);
    getchar();
}

void ler_descricao(char *descricao, size_t tamanho) {
    do {
        printf("///            Nome: ");
        fgets(descricao, tamanho, stdin);
        remove_newline(descricao);
        if (!validarNome(descricao)) {
            printf("///            A descrição do orçamento é inválida! Deve ter pelo menos 3 caracteres.\n");
        }
    } while (!validarNome(descricao));
}

int validar_valor(const char *valor) {
    int i = 0;
    int ponto = 0;
    
    while (valor[i] != '\0') {
        if (valor[i] == '.') {
            ponto++;
        } else if (!eh_digito(valor[i])) {
            return 0;
        }
        i++;
    }
    
    return ponto <= 1; 
}

void ler_valor(char *valor, size_t tamanho) {
    do {
        printf("///            Valor: ");
        fgets(valor, tamanho, stdin);
        remove_newline(valor);  

        if (!validar_valor(valor)) {
            printf("///            Valor inválido! Deve ser numérico e positivo, com no máximo um ponto decimal.\n");
        }
    } while (!validar_valor(valor)); 
}

