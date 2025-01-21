#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
    int id_codigo;
    char nome[50];
    char marca[50];
    int quantidade_estoque;
    char valor[10];
} Produto;

void menu_produto(void);
void cadastrar_produto(void);
void pesquisar_produto(void);
void atualizar_produto(void);
void excluir_produto(void);

#endif