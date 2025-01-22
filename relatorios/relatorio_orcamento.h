#ifndef RELATORIO_ORCAMENTO_H
#define RELATORIO_ORCAMENTO_H

#include <stdio.h>
#include <stdlib.h>

void inicializarArquivoOrcamentos();
double listarRelatoriosOrcamentos();
void menu_relatorio_orcamento(void);
double calcularTotal();
void filtrar_orcamento_por_descricao(const char *descricaoFiltro);
void filtrar_orcamento_por_valor(const char *valorFiltro);


#endif
