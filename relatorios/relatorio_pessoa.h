#ifndef RELATORIO_PESSOA_H
#define RELATORIO_PESSOA_H

#include "../pessoa/pessoa.h"

void filtrarPorNome(const char *nomeFiltro);
void filtrarPorEmail(const char *emailFiltro);
void filtrarPorIdade(const char *idadeFiltro);
void inicializarArquivoPessoas();
void relatorio_pessoa();

#endif
