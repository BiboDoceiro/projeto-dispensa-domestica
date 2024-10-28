#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"


// isso tudo estava no main e ira ser modificado na modularizacao de produtos, esta como base apenas
//void produtos(void) {
//    int escolha;
//    char id_codigo[20];      
//    char nome[100];           
//    char marca[50];           
//    int quant_estoque;        
//    char data_validade[11];   
//    char id_compra[20]; 

//    printf("/////////////////////////////////////////////////////////////////////\n");
 //   printf("///           = = = = = = = =   Produtos   = = = = = = =             ///\n");
   // printf("/////////////////////////////////////////////////////////////////////\n");

//    printf("#### Selecione uma das opções: \n");
 //   scanf("%d", &escolha);
   // getchar();  

   // switch (escolha) {
     //   case 1:
       //     printf("Digite o ID-código-de-barra: ");
         //   fgets(id_codigo, 20, stdin);
           // id_codigo[strcspn(id_codigo, "\n")] = '\0';  

//            printf("Digite o Nome: ");
  //          fgets(nome, 100, stdin);
    //        nome[strcspn(nome, "\n")] = '\0';  

//            printf("Digite a Marca: ");
  //          fgets(marca, 50, stdin);
    //        marca[strcspn(marca, "\n")] = '\0';  

      //      printf("Digite a Quantidade em estoque: ");
        //    scanf("%d", &quant_estoque);
          //  getchar();  

          //  printf("Digite a Data de validade (dd/mm/aaaa): ");
         //   fgets(data_validade, 11, stdin);
           // data_validade[strcspn(data_validade, "\n")] = '\0';  

           // printf("Digite o ID da compra: ");
            //fgets(id_compra, 20, stdin);
            //id_compra[strcspn(id_compra, "\n")] = '\0';  

            //printf("\nCadastro de produto realizado com sucesso!\n");
            //printf("ID-código-de-barra: %s\n", id_codigo);
            //printf("Nome: %s\n", nome);
            //printf("Marca: %s\n", marca);
            //printf("Quantidade em estoque: %d\n", quant_estoque);
            //printf("Data de validade: %s\n", data_validade);
            //printf("ID da compra: %s\n", id_compra);
            //break;

        //case 2:
          //  printf("Saindo do cadastro.\n");
           // break;

        //default:
          //  printf("Opção inválida! Por favor, tente novamente.\n");
            //break;
    




void menu_produto(){
    int opcao;
    do{   
        system("clear||cls");
        printf("\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///            = = = = = = = = = Menu Tarefas = = = = = = = = =             ///\n");
        printf("///                                                                         ///\n");
        printf("///            1. Cadastrar um Produto                                      ///\n");
        printf("///            2. Pesquisar os Produtos                                      ///\n");
        printf("///            3. Atualizar Produtos                                         ///\n");
        printf("///            4. Excluir um produto                                        ///\n");
        printf("///            0. Voltar ao menu anterior                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///            Escolha a opção desejada: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao)
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
    } while (opcao != 0);
}

void cadastrar_produto(){
}

void pesquisar_produto(){

}

void atualizar_produto(){

}

void excluir_produto(){

}