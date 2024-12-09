#ifndef ORCAMENTO_H
#define ORCAMENTO_H

typedef struct {
    int id;
    char descricao[100];
    char valor[20];
} Orcamento;

void menu_cadastro_orcamento(void);
void cadastrar_orcamento(void);
void pesquisar_orcamento(void);
void atualizar_orcamento(void);
void excluir_orcamento(void);

#endif