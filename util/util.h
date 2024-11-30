#ifndef UTIL_H
#define UTIL_H

//////
////// Assinaturas das funções Módulo Utilitário
//////

void delay(int);
void limpa_tela(void);
int eh_digito(char);
int ehLetra(char c);

int validarNome(char* nome);
int validar_idade(const char *idade);
int validar_email(const char *email);
int validar_telefone(const char *tel);
int validar_cpf(const char *cpf);
void remove_newline(char *str);

#endif