#ifndef RELATORIO_PESSOA_H
#define RELATORIO_PESSOA_H

#include <stdio.h>
#include <stdlib.h>

void inicializarArquivoPessoas();
void gerarRelatorioPessoa(void);
void filtrarPorNome(const char *nomeFiltro);
void filtrarPorEmail(const char *emailFiltro);
void filtrarPorIdade(const char *idadeFiltro);


#endif