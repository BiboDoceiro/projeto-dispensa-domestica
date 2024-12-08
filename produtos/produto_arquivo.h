#ifndef PRODUTO_ARQUIVO_H
#define PRODUTO_ARQUIVO_H

#include "produtos.h"

void salvar_produto_arquivo(const Produto *produto);
void carregar_produtos_arquivo(Produto **produtos, int *qtd_produtos);
void atualizar_produto_arquivo(int id_codigo);
void excluir_produto_arquivo(int id_codigo);
int obter_proximo_id_produto(void);
Produto* buscar_produto_arquivo(int id_codigo);

#endif 