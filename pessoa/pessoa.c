#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "ler_pessoa.h"

typedef struct {
    char nome[50];
    char idade[5];
    char email[50];
    char telefone[17];
    char cpf[13];
} Pessoa;

void menu_cadastro_pessoal(void){
    int escolha;
    do{
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
            break; //Termina o bloco case. Isso impede que os outros casos sejam executados depois de executar este.
        case 2:
            pesquisar_pessoa();
            break;
        case 3:
            editar_pessoa();
            break;
        case 4:
            excluir_pessoa();
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
    } while (escolha != 0);
}

void cadastrar_pessoa(void) {
    Pessoa pessoa;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Nova Pessoa = = = = = = = = = = = = =    ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados da pessoa:                                             ///\n");

    ler_nome(pessoa.nome, sizeof(pessoa.nome));
    ler_idade(pessoa.idade, sizeof(pessoa.idade));
    ler_email(pessoa.email, sizeof(pessoa.email));
    ler_telefone(pessoa.telefone, sizeof(pessoa.telefone));
    ler_cpf(pessoa.cpf, sizeof(pessoa.cpf));

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Pessoa cadastrada com sucesso!                              ///\n");
    printf("///            Nome: %s\n", pessoa.nome);
    printf("///            Idade: %s\n", pessoa.idade);
    printf("///            E-mail: %s\n", pessoa.email);
    printf("///            Tel: %s\n", pessoa.telefone);
    printf("///            CPF: %s\n", pessoa.cpf);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar(); // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}

void pesquisar_pessoa(void){
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Pessoa = = = = = = = = = = = = =         ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o CPF da pessoa para pesquisa: ");
    ler_cpf(cpf, sizeof(cpf));
    // Código para pesquisar a pessoa
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}

void editar_pessoa(void){
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Editar Pessoa = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o CPF da pessoa que deseja atualizar: ");
    ler_cpf(cpf, sizeof(cpf));
    // Código para editar a pessoa
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}

void excluir_pessoa(void){
    char cpf[13];
    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Pessoa = = = = = = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o CPF da pessoa que deseja excluir: ");
    ler_cpf(cpf, sizeof(cpf));
    // Código para excluir a pessoa 
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();  // Aguarda o usuário pressionar ENTER antes de voltar ao menu
}
