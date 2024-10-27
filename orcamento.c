#include <stdio.h>
#include <stdlib.h>
#include "orçamento.h"

void menu_cadastro_orcamento(void) {
    int escolha;
    do {
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            ===================================================          ///\n");
        printf("///            = = = =           Despensa domestica        = = = =          ///\n");
        printf("///            ===================================================          ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            = = = = = = = = = Menu Orçamento = = = = = = = = =           ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar um novo orçamento                               ///\n");
        printf("///            2. Pesquisar orçamentos                                      ///\n");
        printf("///            3. Editar um orçamento                                       ///\n");
        printf("///            4. Excluir um orçamento                                      ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &escolha);
        getchar();
        
        switch (escolha) {
            case 1:
                cadastrar_orcamento();
                break;
            case 2:
                pesquisar_orcamento();
                break;
            case 3:
                editar_orcamento();
                break;
            case 4:
                excluir_orcamento();
                break;
            case 0:
                break;
            default:
                printf("\t\t\t>Opção inválida! Tente novamente.\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
        }
    } while (escolha != 0);
}

void cadastrar_orcamento(void) {
    char descricao[100];
    char valor[20];
    char data[11];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo Orçamento = = = = = = = = = = = =   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados do orçamento:                                          ///\n");
    printf("///            Descrição: ");
    fgets(descricao, sizeof(descricao), stdin);
    printf("///            Valor: ");
    fgets(valor, sizeof(valor), stdin);
    printf("///            Data (dd/mm/yyyy): ");
    fgets(data, sizeof(data), stdin);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Orçamento cadastrado com sucesso!                            ///\n");
    printf("///            Descrição: %s", descricao);
    printf("///            Valor: %s", valor);
    printf("///            Data: %s", data);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisar_orcamento(void) {
    char descricao[100];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Orçamento = = = = = = = = = = = = =      ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe a descrição do orçamento para pesquisa: ");
    fgets(descricao, sizeof(descricao), stdin);
    // Código para pesquisar o orçamento
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void editar_orcamento(void) {
    char descricao[100];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Editar Orçamento = = = = = = = = = = = = =         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe a descrição do orçamento que deseja atualizar: ");
    fgets(descricao, sizeof(descricao), stdin);
    // Código para editar o orçamento
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_orcamento(void) {
    char descricao[100];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Orçamento = = = = = = = = = = = = =        ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe a descrição do orçamento que deseja excluir: ");
    fgets(descricao, sizeof(descricao), stdin);
    // Código para excluir o orçamento
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}