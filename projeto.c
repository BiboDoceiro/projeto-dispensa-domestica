

                                ///////////////////////////////////////////////////////////////////////////////
                                ///             Universidade Federal do Rio Grande do Norte                 ///
                                ///                 Centro de Ensino Superior do Seridó                     ///
                                ///               Departamento de Computação e Tecnologia                   ///
                                ///                  Disciplina DCT1106 -- Programação                      ///
                                ///             Projeto Sistema de Gestão Para Despensa Domestica           ///
                                ///                Developed by @cailucas_lm & @lelebiglove                 ///
                                ///////////////////////////////////////////////////////////////////////////////
                                ///                                Semana 2                                 ///
                                ///////////////////////////////////////////////////////////////////////////////






#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main(void) 
{
    void InicioLogin();
    void exibirMenu(); 
    void cadastro_Pessoa();
    void produtos();
    void controle_estoque();
    void orcamento();
    void equipe();
        
    setlocale(LC_ALL, "Portuguese");
    printf("Bem vindo ao seu controle de despesas\n");
    
    exibir_menu();

    return 0;
}

void inicio_login(void)
{
    printf("=========================================\n");
    printf("|               BEM VINDO!              |\n");
    printf("=========================================\n");
    printf("|---------------------------------------|\n");
    printf("|                  LOGIN                |\n");
    printf("|---------------------------------------|\n");
    printf("#### 1 - Login                          |\n");
    printf("#### 2 - Não Possuo Cadastro            |\n");
    printf("----------------------------------------|\n");
    printf("#### Selecione uma das opcoes: \n");
    printf("\n");
    getchar();
}

void exibir_menu(void)
{
    int escolha;
    printf("//////////////////////////////////////////////////////////////////////////////\n");
    printf("///   Escolha um módulo:                                                   ///\n");
    printf("///   1. Cadastro Pessoal                                                  ///\n");
    printf("///   2. Produtos                                                          ///\n");
    printf("///   3. Orçamento                                                         ///\n");
    printf("///   4. controle_estoque                                                  ///\n");
    printf("///   5. Equipe                                                            ///\n");
    printf("///   0. Sair                                                              ///\n");
    printf("//////////////////////////////////////////////////////////////////////////////\n");
    printf("#### Selecione uma das opcoes: \n");
    scanf("%d", &escolha);
    printf("\n");
    getchar();
}


void cadastro_pessoa(void) 
{
    int escolha;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = Cadastro Pessoal  = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID:                                                          ///\n");
    printf("///            Nome completo:                                               ///\n");
    printf("///            CPF:                                                         ///\n");
    printf("///            Data de Nascimento (dd/mm/aaaa):                             ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("#### Selecione uma das opcoes: \n");
    scanf("%d", &escolha);
    printf("\n");
    getchar();
}

void produtos(void)
{

    int escolha;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///           = = = = = = = =      Produtos   = = = = = = = = =             ///\n");
    printf("///           = = = = = = = = = = = = = = = = = = = = = = = = =             ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID-codigo-de-barra:                                          ///\n");
    printf("///            Nome:                                                        ///\n");
    printf("///            Marca:                                                       ///\n");
    printf("///            Quant_estoque:                                               ///\n");
    printf("///            Data_validade:                                               ///\n");
    printf("///            ID-compra:                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("#### Selecione uma das opcoes: \n");
    scanf("%d", &escolha);
    printf("\n");
    getchar();
}

void estoque(void)
{
    int escolha;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///          = = = = = =       Controle_estoque    = = = = = =              ///\n");
    printf("///          = = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID-codigo-de-barra:                                          ///\n");
    printf("///            ID-compra:                                                   ///\n"); /* sera relacionado ao id codigo de barra */ 
    printf("///            Data:                                                        ///\n");
    printf("///            Nome:                                                        ///\n");
    printf("///            Quantidade:                                                  ///\n");
    printf("///            preco:                                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("#### Selecione uma das opcoes: \n");
    scanf("%d", &escolha);
    printf("\n");
    getchar();
}

void orcamento(void)
{
    int escolha;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = =   Orçamento   = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            ID-codigo-de-barra:                                          ///\n");
    printf("///            Data:                                                        ///\n");
    printf("///            Hora:                                                        ///\n");
    printf("///            Quantidade:                                                  ///\n");
    printf("///            Valor gasto:                                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("#### Selecione uma das opcoes: \n");
    scanf("%d", &escolha);
    getchar();
}

void equipe(void)
{
   
    int escolha;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///                  Projeto Sistema de Despensa Domestica                  ///\n");
    printf("///          Developed by @caiolucas_lm   and @lelebiglove                  ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            Este projeto  foi desenvolvido por:                          ///\n");
    printf("///                                                                         ///\n");
    printf("///            Caio Lucas Lopes Medeiros                                    ///\n");
    printf("///            E-mail: caio.lopes.078@ufrn.edu.br                           ///\n");
    printf("///            Redes sociais: @caiolucas_lm                                 ///\n");
    printf("///            Git: https://github.com/BiboDoceiro                          ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            Leandro Isaac correia de Brito                               ///\n");
    printf("///            E-mail:                                                      ///\n");
    printf("///            Redes sociais:                                               ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("#### Selecione uma das opcoes: \n");
    scanf("%d", &escolha);
    getchar();



}



