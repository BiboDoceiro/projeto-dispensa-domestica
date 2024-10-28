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

void cadastrar_orcamento()
{
    char descricao[200];
    char valor[10];
    char data[12];
    char id[5];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo orçamento = = = =                   ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados do orçamento:                                          ///\n");
    printf("///            Descrição: ");
    fgets(descricao, sizeof(descricao), stdin);
    printf("///            Valor: ");
    fgets(valor, sizeof(valor), stdin);
    printf("///            Data (dd/mm/aaaa): ");
    fgets(data, sizeof(data), stdin);
    printf("///            id: ");
    fgets(id, sizeof(id), stdin);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Orçamento cadastrado com sucesso!                            ///\n");
    printf("///            Descrição: %s", descricao);
    printf("///            Valor: %s", valor);
    printf("///            Data: %s", data);
    printf("///            Data: %s", id);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}

void pesquisar_orçamento()
{
    char id[5];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Orçamento = = = =                        ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id do orçamento:                                              ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}

void atualizar_orçamento() {
    char id[5];
    char descricao[200];
    char valor[10];
    char data[12];

    printf("\n/////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Orçamento = = = =                        ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id do orçamento:                                              ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();  // Aguarda o usuário pressionar Enter
    printf("/// Informe a descrição do orçamento:                                       ///\n");
    fgets(descricao, sizeof(descricao), stdin);
    printf("/// Informe o valor do orçamento:                                           ///\n");
    fgets(valor, sizeof(valor), stdin);
    printf("/// Informe a data do orçamento (DD/MM/AAAA):                               ///\n");
    fgets(data, sizeof(data), stdin);
    //  adicionar o código para atualizar o orçamento com os dados recebidos.
}

void excluir_orçamento()
{
    char id[5];
    
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Orçamento = = = =                          ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o id do orçamento:                                              ///\n");
    fgets(id, sizeof(id), stdin);
    getchar();   // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}