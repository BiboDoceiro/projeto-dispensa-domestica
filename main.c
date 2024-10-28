///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///             Projeto Sistema de Gestão Para Despensa Domestica           ///
///                Developed by @cailucas_lm & @lelebiglove                 ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 4                               ///
///////////////////////////////////////////////////////////////////////////////

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"  
#include "orcamento.h"
#include "relatorio.h"



void inicio_login(void);
void exibir_menu(void);
void produtos(void);
void controle_estoque(void);
void equipe(void);

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    printf("Bem vindo ao seu controle de despesas\n");
    inicio_login();   
    exibir_menu();    
    return 0;
}

void inicio_login(void) {
    int escolha; 
    printf("=========================================\n");
    printf("|               BEM VINDO!              |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|                  LOGIN                |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Login                          |\n");
    printf("#### 2 - Não Possuo Cadastro            |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opções: \n");
    scanf("%d", &escolha);
    getchar();  
    switch (escolha) {
        case 1:
            printf("Login selecionado.\n");
            break;
        case 2:
            printf("Opção de cadastro selecionada.\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

void exibir_menu(void) {
    int escolha;
    do {
        printf("/////////////////////////////////////////////////////////////////////\n");
        printf("///   Escolha um módulo:                                             ///\n");
        printf("///   1. Cadastro Pessoal                                            ///\n");
        printf("///   2. Produtos                                                    ///\n");
        printf("///   3. Orçamento                                                   ///\n");
        printf("///   4. Controle de Estoque                                         ///\n");
        printf("///   5. Equipe                                                      ///\n");
        printf("///   0. Sair                                                        ///\n");
        printf("/////////////////////////////////////////////////////////////////////\n");
        printf("#### Selecione uma das opções: \n");
        scanf("%d", &escolha);
        getchar();  
        
        switch (escolha) {
            case 1:
                cadastro_pessoa();
                break;
            case 2:
                produtos();
                break;
            case 3:
                menu_orcamento();
                break;
            case 4:
                controle_estoque();
                break;
            case 5:
                equipe();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 0);
}

void produtos(void) {
    int escolha;
    char id_codigo[20];      
    char nome[100];           
    char marca[50];           
    int quant_estoque;        
    char data_validade[11];   
    char id_compra[20]; 

    printf("/////////////////////////////////////////////////////////////////////\n");
    printf("///           = = = = = = = =   Produtos   = = = = = = =             ///\n");
    printf("/////////////////////////////////////////////////////////////////////\n");

    printf("#### Selecione uma das opções: \n");
    scanf("%d", &escolha);
    getchar();  

    switch (escolha) {
        case 1:
            printf("Digite o ID-código-de-barra: ");
            fgets(id_codigo, 20, stdin);
            id_codigo[strcspn(id_codigo, "\n")] = '\0';  

            printf("Digite o Nome: ");
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = '\0';  

            printf("Digite a Marca: ");
            fgets(marca, 50, stdin);
            marca[strcspn(marca, "\n")] = '\0';  

            printf("Digite a Quantidade em estoque: ");
            scanf("%d", &quant_estoque);
            getchar();  

            printf("Digite a Data de validade (dd/mm/aaaa): ");
            fgets(data_validade, 11, stdin);
            data_validade[strcspn(data_validade, "\n")] = '\0';  

            printf("Digite o ID da compra: ");
            fgets(id_compra, 20, stdin);
            id_compra[strcspn(id_compra, "\n")] = '\0';  

            printf("\nCadastro de produto realizado com sucesso!\n");
            printf("ID-código-de-barra: %s\n", id_codigo);
            printf("Nome: %s\n", nome);
            printf("Marca: %s\n", marca);
            printf("Quantidade em estoque: %d\n", quant_estoque);
            printf("Data de validade: %s\n", data_validade);
            printf("ID da compra: %s\n", id_compra);
            break;

        case 2:
            printf("Saindo do cadastro.\n");
            break;

        default:
            printf("Opção inválida! Por favor, tente novamente.\n");
            break;
    }
}

void controle_estoque(void) {
    int escolha;
    char id_codigo[20];      
    char id_compra[20];       
    char data[11];            
    char nome[100];           
    int quantidade;           
    float preco;              
  printf("/////////////////////////////////////////////////////////////////////"
         "//////////\n");
  printf("///                                                                  "
         "       ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = =       "
         "       ///\n");
  printf("///          = = = = = =       Controle_estoque    = = = = = =       "
         "       ///\n");
  printf("///          = = = = = = = = = = = = = = = = = = = = = = = = =       "
         "       ///\n");
  printf("///                                                                  "
         "       ///\n");
  printf("///            ID-codigo-de-barra:                                   "
         "       ///\n");
  printf("///            ID-compra:                                            "
         "       ///\n"); /* sera relacionado ao id codigo de barra */
  printf("///            Data:                                                 "
         "       ///\n");
  printf("///            Nome:                                                 "
         "       ///\n");
  printf("///            Quantidade:                                           "
         "       ///\n");
  printf("///            preco:                                                "
         "       ///\n");
  printf("///                                                                  "
         "       ///\n");
  printf("/////////////////////////////////////////////////////////////////////"
         "//////////\n");
  printf("#### Selecione uma das opcoes: \n");
  scanf("%d", &escolha);
  printf("\n");
  getchar();  

        switch (escolha) {
            case 1:
                printf("Digite o ID-código-de-barra: ");
                fgets(id_codigo, 20, stdin);
                id_codigo[strcspn(id_codigo, "\n")] = '\0';  

                printf("Digite o ID da compra: ");
                fgets(id_compra, 20, stdin);
                id_compra[strcspn(id_compra, "\n")] = '\0';  

                printf("Digite a Data (dd/mm/aaaa): ");
                fgets(data, 11, stdin);
                data[strcspn(data, "\n")] = '\0';  

                printf("Digite o Nome: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = '\0';  

                printf("Digite a Quantidade: ");
                scanf("%d", &quantidade);
                getchar();  

                printf("Digite o Preço: ");
                scanf("%f", &preco);
                getchar();  

                printf("\nCadastro de item no estoque realizado com sucesso!\n");
                printf("ID-código-de-barra: %s\n", id_codigo);
                printf("ID da compra: %s\n", id_compra);
                printf("Data: %s\n", data);
                printf("Nome: %s\n", nome);
                printf("Quantidade: %d\n", quantidade);
                printf("Preço: %.2f\n", preco);
                break;

            case 2:
                printf("Saindo do controle de estoque.\n");
                break;

            default:
                printf("Opção inválida! Por favor, tente novamente.\n");
                break;
        }
    }


void equipe(void) {
    int escolha;

    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////\n");
    printf("///             Universidade Federal do Rio Grande do Norte         ///\n");
    printf("///                 Centro de Ensino Superior do Seridó             ///\n");
    printf("///               Departamento de Computação e Tecnologia           ///\n");
    printf("///                  Disciplina DCT1106 -- Programação              ///\n");
    printf("///                  Projeto Sistema de Despensa Doméstica          ///\n");
    printf("///          Developed by @caiolucas_lm & @lelebiglove              ///\n");
    printf("/////////////////////////////////////////////////////////////////////\n");
    printf("///            Caio Lucas Lopes Medeiros                            ///\n");
    printf("///            Leandro Isaac Correia de Brito                       ///\n");
    printf("/////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("#### Selecione uma das opções: \n");
    printf("1. Voltar ao menu principal\n");
    printf("2. Sair\n");
    scanf("%d", &escolha);
    getchar();  

    switch (escolha) {
        case 1:
            printf("Voltando ao menu principal...\n");
            break;
        case 2:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida! Por favor, tente novamente.\n");
            break;
    }
}
