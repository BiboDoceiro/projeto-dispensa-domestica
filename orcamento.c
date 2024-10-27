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