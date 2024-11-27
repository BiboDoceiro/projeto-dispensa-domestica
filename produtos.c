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
}

void pesquisar_produto(){

}

void atualizar_produto(){

}

void excluir_produto(){

}