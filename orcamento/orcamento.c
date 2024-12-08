#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orcamento.h"
#include "ler_orcamento.h"

typedef struct {
    int id;
    char descricao[100];
    char valor[20];
} Orcamento;

void menu_cadastro_orcamento() {
    int escolha;
    do {
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Orçamentos = = = = = = = = =          ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar um Orçamento                                    ///\n");
        printf("///            2. Pesquisar Orçamentos                                      ///\n");
        printf("///            3. Atualizar Orçamentos                                      ///\n");
        printf("///            4. Excluir um Orçamento                                      ///\n");
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
                atualizar_orcamento();
                break;
            case 4:
                excluir_orcamento();
                break;
            case 0:
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                getchar();
                break;
        }
    } while (escolha != 0);
}

void cadastrar_orcamento(void) {
    Orcamento orcamento;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Cadastrar Novo Orçamento = = = = = = = =          ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe os dados do orçamento:                                          ///\n");

    ler_id(&orcamento.id);
    ler_descricao(orcamento.descricao, sizeof(orcamento.descricao));
    ler_valor(orcamento.valor, sizeof(orcamento.valor));

    orcamento.id = obter_proximo_id_orcamento();
    salvar_orcamento_arquivo(&orcamento);

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Orçamento cadastrado com sucesso!                            ///\n");
    printf("///            ID: %d\n", orcamento.id);
    printf("///            Descrição: %s\n", orcamento.descricao);
    printf("///            Valor: %s\n", orcamento.valor);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisar_orcamento(void) {
    int id;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Pesquisar Orçamento = = = = = = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID do orçamento para pesquisa: ");
    ler_id(&id);

    Orcamento *orcamento = buscar_orcamento_arquivo(id);

    // Adicione a lógica de busca em arquivos ou base de dados aqui

}

void atualizar_orcamento(void) {
    int id;
    char novo_valor[20];

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Atualizar Orçamento = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID do orçamento que deseja atualizar: ");
    ler_id(&id);

    ler_valor(novo_valor, sizeof(novo_valor));

    atualizar_orcamento_arquivo(id);

    // Adicione a lógica de atualização em arquivos ou base de dados aqui

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Orçamento atualizado com sucesso!                            ///\n");
    printf("///            ID: %d\n", id);
    printf("///            Novo Valor: %s\n", novo_valor);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void excluir_orcamento(void) {
    int id;

    printf("\n///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            = = = = = Excluir Orçamento = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("/// Informe o ID do orçamento que deseja excluir: ");
    ler_id(&id);

    excluir_orcamento_arquivo(id);

    // Adicione a lógica de exclusão em arquivos ou base de dados aqui

    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///            Orçamento excluído com sucesso!                              ///\n");
    printf("///            ID: %d\n", id);
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

