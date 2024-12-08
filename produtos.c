#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"


void menu_produto() {
    int escolha;

    do {   
        system("clear||cls"); 
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Produtos = = = = = = = = =             ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar um Produto                                      ///\n");
        printf("///            2. Pesquisar os Produtos                                     ///\n");
        printf("///            3. Atualizar Produtos                                        ///\n");
        printf("///            4. Excluir um Produto                                        ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &escolha);
        getchar(); 

        switch (escolha) {
            case 1:
                cadastrar_produto();
                break;
            case 2:
                pesquisar_produto();
                break;
            case 3:
                atualizar_produto();
                break;
            case 4:
                excluir_produto();
                break;
            case 0:
                printf("\nVoltando ao menu anterior...\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                printf("Pressione <ENTER> para continuar...\n");
                getchar(); 
                break;
        }
    } while (escolha != 0);
}

void cadastrar_produto(){
  char id_codigo[20];
    char nome[100];
    char marca[50];
    int quant_estoque;
    char data_validade[11];
    char id_compra[20];

    printf("\n==== Cadastrar Produto ====\n");

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

    printf("\nPressione <ENTER> para continuar...\n");
    getchar();
}

void pesquisar_produto(){
char id_codigo[20];
    system("clear||cls"); 
    printf("\n/////////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Produto = = = =                          ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID do produto:                                                 ///\n");
    fgets(id_codigo, sizeof(id_codigo), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void atualizar_produto(){
    char id_codigo[20];
    char nova_data_validade[11];
    char nova_quant;
    system("clear||cls"); 
    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Produtos = = = =                         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID do produto que deseja atualizar:                           ///\n");
    fgets(id_codigo, sizeof(id_codigo), stdin);
    printf("/// Nova quantidades de produtos:                                           ///\n");
    fgets(nova_quant, sizeof(nova_quant), stdin);
    printf("/// Nova data de validade (dd/mm/aaaa):                                     ///\n");
    fgets(nova_data_validade, sizeof(nova_data_validade), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
}

void excluir_produto(){
    char id_codigo[20];
    system("clear||cls"); 
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Produto  = = = = =                           ///\n");
    printf("///                                                                           ///\n");
    printf("/// Informe o ID do produto que deseja excluir:                                ///\n");
    fgets(id_codigo, sizeof(id_codigo), stdin);
    getchar();  // Aguarda o usuário pressionar Enter

}