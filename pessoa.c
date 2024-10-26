#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"


void menu_cadastro_pessoal(void){
    int escolha;
    do{
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            ===================================================          ///\n");
        printf("///            = = = =              SigFinance             = = = =          ///\n");
        printf("///            ===================================================          ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            = = = = = = = = = Menu Pessoa = = = = = = = = =              ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar uma nova pessoa                                 ///\n");
        printf("///            2. Pesquisar pessoas                                         ///\n");
        printf("///            3. Editar o cadastro de uma pessoa                           ///\n");
        printf("///            4. Excluir uma pessoa                                        ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &escolha);
        getchar();
        switch (escolha)
        {
        case 1:
            cadastrar_pessoa();
            break; /*Termina o bloco case. Isso impede que os outros casos sejam executados depois de executar este.*/
        case 2:
            pesquisar_morador();
            break;
        case 3:
            atualizar_morador();
            break;
        case 4:
            excluir_morador();
            break;
        case 0:
        
            break;
        default: // Se nenhum dos valores anteriores (1, 2, 3, 4 ou 0) for selecionado, este bloco é executado.
            printf("\t\t\t>Opção inválida! Tente novamente.\n");
            printf("///                                                                         ///\n");
            printf("///////////////////////////////////////////////////////////////////////////////\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
        }
    } while (opcao != 0);
}

void cadastrar_pessoa(void){
    char nome[50];
    char idade[5];
    char email[50];
    char tel[17];
    char cpf[13];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Nova Pessoa = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados da pessoa:                                             ///\n");
    printf("///            Nome: ");
    fgets(nome, sizeof(nome), stdin);
    printf("///            Idade: ");
    fgets(idade, sizeof(idade), stdin);
    printf("///            E-mail: ");
    fgets(email, sizeof(email), stdin);
    printf("///            Telefone: ");
    fgets(tel, sizeof(tel), stdin);
    printf("///            CPF: ");
    fgets(cpf, sizeof(cpf), stdin);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Pessoa cadastrado com sucesso!                               ///\n");
    printf("///            Nome: %s", nome);
    printf("///            Idade: %s", idade);
    printf("///            E-mail: %s", email);
    printf("///            Tel: %s", tel);
    printf("///            CPF: %s", cpf);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}
