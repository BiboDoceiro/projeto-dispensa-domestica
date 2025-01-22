#ifndef PESSOA_ARQUIVO_H
#define PESSOA_ARQUIVO_H
#include "pessoa.h"


void salvar_pessoa_arquivo(const Pessoa *pessoa);
void carregar_pessoas_arquivo(Pessoa **pessoas, int *qtd_pessoas);
void atualizar_pessoa(const char *cpf);
void excluir_pessoa_arquivo(const char *cpf);
void buscar_pessoa_por_cpf(const char *cpf);
void filtrarPorNome(const char *nomeFiltro);
void filtrarPorEmail(const char *emailFiltro);
void filtrarPorIdade(const char *idadeFiltro);

#endif 
