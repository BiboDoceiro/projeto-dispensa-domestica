#ifndef ORCAMENTO_ARQUIVO_H
#define ORCAMENTO_ARQUIVO_H
#include "orcamento.h"

void salvar_orcamento_arquivo(const Orcamento *orcamento);
void carregar_orcamentos_arquivo(Orcamento **orcamentos, int *qtd_orcamentos);
void atualizar_orcamento_arquivo(int id);
void excluir_orcamento_arquivo(int id);
int obter_proximo_id_orcamento(void);
Orcamento* buscar_orcamento_arquivo(int id);
#endif 