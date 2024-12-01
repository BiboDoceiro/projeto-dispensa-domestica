#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"
#include "ler_produtos.h"

typedef struct {
    int id_codigo;
    char nome[50];
    char marca[50];
    int quantidade_estoque;
    char data_validade[11];
} Produto;


void menu_produto(){
    int escolha;
    do{   
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Produtos = = = = = = = = =             ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar um Produto                                      ///\n");
        printf("///            2. Pesquisar os Produtos                                      ///\n");
        printf("///            3. Atualizar Produtos                                         ///\n");
        printf("///            4. Excluir um produto                                        ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &escolha);
        getchar();
        switch (escolha)
        {
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
        
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            printf("\t\t\t>Opção inválida! Tente novamente.\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            break;
        }
    } while (escolha != 0);
}

void cadastrar_produto(void) {
    Produto produto;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo Produto = = = = = = = = = =         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados do produto:                                            ///\n");

    ler_nome_produto(produto.nome, sizeof(produto.nome));
    ler_marca(produto.marca, sizeof(produto.marca));
    ler_quantidade(&produto.quantidade_estoque);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Produto cadastrado com sucesso!                             ///\n");
    printf("///            Código: %d\n", produto.id_codigo);
    printf("///            Nome: %s\n", produto.nome);
    printf("///            Marca: %s\n", produto.marca);
    printf("///            Estoque: %d\n", produto.quantidade_estoque);
    printf("///            Validade: %s\n", produto.data_validade);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisar_produto(void) {
    int id_codigo;
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Produto = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o Código do produto para pesquisa: ");
    ler_id_codigo(&id_codigo);

    // adicionar metodo de consulta por arquivo

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizar_produto(void) {
    int id_codigo;
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Produto = = = = = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o Código do produto que deseja atualizar: ");
    ler_id_codigo(&id_codigo);

        // adicionar metodo de consulta por arquivo

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_produto(void) {
    int id_codigo;
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Produto = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o Código do produto que deseja excluir: ");
    ler_id_codigo(&id_codigo);

      // adicionar metodo de consulta por arquivo

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}