include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"


void menu_relatorios(void){
     int escolha;
     do{
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Relatórios = = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Relatórios de Pessoas                                     ///\n");
        printf("///            2. Relatórios de Orcamentos                                  ///\n");
        printf("///            0. Retornar ao menu principal                                ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &escolha);
        getchar();
        switch (escolha)
        {
        case 1:
            relatorios_pessoa();
            break;
        case 2:
            relatorios_orcamento();
            break;
        case 0:
        
            break;
        default:
            printf("\t\t\t>Opção inválida! Tente novamente.\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            break;
        }
        
    } while (escolha != 0);
}