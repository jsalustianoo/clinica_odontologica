#include <stdio.h>
#include <stdlib.h>
#include "dentistas.h"

void menu_dentista(void) {
    int opcao_dentista;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("-----                          Menu dos Dentistas                           -----\n");
        printf("=================================================================================\n");
        printf("------      (1) - Cadastrar novo dentista                                  ------\n");
        printf("------      (2) - Visualizar dados de um dentista                          ------\n");
        printf("------      (3) - Editar dados de um dentista                              ------\n");
        printf("------      (4) - Excluir dentista                                         ------\n");
        printf("------      (0) - Retornar ao Menu Principal                               ------\n");
        printf("=================================================================================\n");
        scanf("%d", &opcao_dentista);
        getchar();
        switch (opcao_dentista) {
            case 0:
                break;
            case 1:
                cadastro_dentista();
                break;
            case 2:
                exibir_dados_dentista();
                break;
            case 3:
                editar_dentista();
                break;
            case 4:
                excluir_dentista();
                break;
            default:
                printf("Numero digitado nao condiz com nenhuma opcao do sistema");
            break;
        }
    } while (opcao_dentista != 0);

}

void cadastro_dentista (void) {
    char nome[100], cpf[13], telefone[13], especialidade[30], cro[12];
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Cadastro de Dentista                        ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome): ");
    scanf("%s", nome);
    getchar();
    printf("------      (CPF): ");
    scanf("%s", cpf);
    getchar();
    printf("------      (Telefone): ");
    scanf("%s", telefone);
    getchar();
    printf("------      (Especialidade): ");
    scanf("%s", especialidade);
    getchar(); 
    printf("------      (Numero do CRO): ");
    scanf("%s", cro);
    getchar(); 
    printf("=================================================================================\n");
    printf("-----                  Dentista cadastrado(a) com sucesso!                  -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_dados_dentista (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                        Dados de um Dentista                         ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (CPF):                                                         ------\n");
    printf("------      (Telefone):                                                    ------\n"); 
    printf("------      (Especialidade):                                               ------\n"); 
    printf("------      (Numero do CRO):                                               ------\n"); 
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
}

void editar_dentista (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                      Editar dados de um Dentista                    ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                          ------");
    printf("------      (CPF):                                                           ------");
    printf("------      (Telefone):                                                      ------"); 
    printf("------      (Especialidade):                                                 ------"); 
    printf("------      (Numero do CRO):                                                 ------"); 
    printf("=================================================================================\n");
    printf("-----               Dados do(a) Dentista editados com sucesso!              -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void excluir_dentista (void) {
    char confirmacao; 

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                           Excluir Dentista                          ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                          ------");
    printf("------      (CPF):                                                           ------");
    printf("------      (Telefone):                                                      ------"); 
    printf("------      (Especialidade):                                                 ------"); 
    printf("------      (Numero do CRO):                                                 ------"); 
    printf("------                                                                     ------\n"); 
    printf("------     Tem certeza que deseja excluir esse paciente? (S)IM | (N)AO     ------\n");

    scanf(" %c", confirmacao);
    if (confirmacao == 'S' || confirmacao == 's'){
        printf("------                   Paciente excluído com sucesso!                    ------\n");
    } else if (confirmacao == 'N' || confirmacao == 'n'){
        printf("------                        Operacao cancelada!                          ------\n");
    } else{
        printf("------      Numero digitado nao condiz com nenhuma opcao do sistema        ------\n");
    }                     
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}