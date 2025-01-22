#ifndef RELATORIO_PRODUTO_H
#define RELATORIO_PRODUTO_H

#include <stdio.h>
#include <stdlib.h>

void inicializarArquivoProdutos(void);
int calcularTotalEstoque(void);
void filtrarPorNomeProduto(const char *nomeFiltro);
void filtrarPorMarca(const char *marcaFiltro);
void filtrarPorValor(const char *valorFiltro);
void relatorio_produto(void);

#endif