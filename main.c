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


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./pessoa/pessoa.h"  
#include "./orcamento/orcamento.h"
#include "./relatorios/relatorio.h"
#include "./produtos/produtos.h"


//////
////// Assinaturas das funções
//////

char exibir_menu(void);
void tela_sobre(void);
void tela_equipe(void);

//////
////// Programa principal
//////

int main(void) {
    char escolha;

    do {
        escolha = exibir_menu();
        switch(escolha) {
            case '1':   menu_cadastro_pessoal();
                        break;
            case '2':   menu_produto();
                        break;
            case '3':   menu_cadastro_orcamento();
                        break;  
            case '4':   menu_relatorios();
                        break;
            case '5':   tela_sobre();
                        tela_equipe();
                        break;
        } 	
    } while (escolha != '0');

    return 0;
}

//////
////// Funções do Módulo Principal
//////


char exibir_menu(void) {
    char escolha;



         system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///   Escolha um módulo:                                                    ///\n");
        printf("///   1. Cadastro Pessoal                                                   ///\n");
        printf("///   2. Produtos                                                           ///\n");
        printf("///   3. Orçamento                                                          ///\n");
        printf("///   4. Relatorios                                                         ///\n");
        printf("///   5. Equipe                                                             ///\n");
        printf("///   0. Sair                                                               ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("#### Selecione uma das opções: \n");
        scanf("%c", &escolha);    
        getchar();
        printf("///                                                                         ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t\t<<< ... Aguarde ... >>>\n");
        sleep(1);
        return escolha;
    }
    


