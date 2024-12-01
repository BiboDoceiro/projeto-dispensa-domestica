#ifndef LER_ORCAMENTO_H
#define LER_ORCAMENTO_H

void ler_id(int *id);

void ler_descricao(char *descricao, size_t tamanho);

int validar_valor(const char *valor);

void ler_valor(char *valor, size_t tamanho);

#endif