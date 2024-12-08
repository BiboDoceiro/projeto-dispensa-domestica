#ifndef PESSOA_H
#define PESSOA_H

typedef struct {
    char nome[50];
    char idade[5];
    char email[50];
    char telefone[17];
    char cpf[13];
} Pessoa;

void menu_cadastro_pessoal(void);
void cadastrar_pessoa(void);
void pesquisar_pessoa(void);
void editar_pessoa(void);
void excluir_pessoa(void);

#endif