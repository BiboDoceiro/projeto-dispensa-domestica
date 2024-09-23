#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void exibirMenu();
void cadastroPessoa();
void produtos();
void orcamento();
void equipe();
int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Bem vindo ao seu controle de despesas\n");
    
    exibirMenu();

    return 0;
}

void exibirMenu()
{
    int escolha;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///   Controle de despesas:                                           ///\n");
    printf("/// Escolha um módulo:                                                     ///\n");
    printf("///   1. Cadastro Pessoal                                                  ///\n");
    printf("///   2. Produtos                                                          ///\n");
    printf("///   3. Orçamento                                                         ///\n");
    printf("///   4. Equipe                                                            ///\n");
    printf("///   0. Sair                                                              ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%d", &escolha);
}

void cadastroPessoa()
{
    char nome[50];
    char cpf[15];
    char email[50];
    char dataNascimento[11];

    printf("Qual o seu nome? ");
      scanf("%s", nome);

    printf("Digite seu CPF: ");
      scanf("%s", cpf);

    printf("Qual o seu email? ");
    
       scanf("%s", email);
    printf("Qual a sua data de nascimento? (dd/mm/aaaa) ");
    
     scanf("%s", dataNascimento);

    printf("Cadastro realizado com sucesso!\n");
    printf("Nome: %s\nCPF: %s\nEmail: %s\nData de Nascimento: %s\n", nome, cpf, email, dataNascimento);
}

void produtos()
{ 
    char marca [50];
    float  preco;
    char data [10];
    
    printf("Digite a marca do produto: ");;
    scanf("%s", marca);
    printf("Digite o preço do produto: ");;
    scanf("%f", &preco);
    printf("Digite a data de fabricação");
    scanf("%s", data);

    printf("Produto cadastrado com sucesso!\n");
    printf("Marca: %s\nPreço: %.2f\nData de Fabricação: %s\n", marca, preco, data);
}
  
void orcamento()
 {
    float orcamentoMensal;
    float orcamentoDia;
    float orcamentoSemana;
    printf("Digite o orçamento mensal: ");
    scanf("%f", &orcamentoMensal);  
    printf("Digite o orçamento diário: ");
    scanf("%f", &orcamentoDia); 
     printf("Digite o orçammento Semanal");
     scanf("%f", &orcamentoSemana);
 }    
void equipe()
{ 
    printf("Desenvolvedores Caio Lucas e Leandro Isaac");
    printf("Instagram: caiolucas_lm e lelebiglove");
    
}