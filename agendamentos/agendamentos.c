#include <stdio.h>
#include <stdlib.h>
#include "agendamentos.h"

void menu_agendamento (void) {
    int opcao_agendamento;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("-----                           Menu Agendamentos                           -----\n");
        printf("=================================================================================\n");
        printf("-----      (1) Realizar agendamento                                         -----\n");
        printf("-----      (2) Visualizar agendamentos                                      -----\n");
        printf("-----      (3) Editar agendamento                                           -----\n");
        printf("-----      (4) Excluir agendamento                                          -----\n");
        printf("-----      (0) Retornar ao menu anterior                                    -----\n");
        printf("=================================================================================\n");
        printf("      - (Opcao desejada): ");
        scanf("%d", &opcao_agendamento);
        getchar();
        switch (opcao_agendamento) {
            case 0:
                break;
            case 1:
                agendar();
                break;
            case 2:
                exibir_dados_agendamento();
                break;
            case 3:
                editar_agendamento();
                break;
            case 4:
                excluir_agendamento();
                break;
            default:
                printf("Numero digitado nao condiz com nenhuma opcao do sistema");
            break;
        }
    }while(opcao_agendamento != 0);

}

void agendar (void) {
    char id[10], nome[100], cpf[14], data[13], horario[9], situacao[200], pagamento[20];

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Realizar Agendamento                        ------\n");
    printf("=================================================================================\n");
    printf("------      (ID): ");
    scanf("%s", id);
    getchar();
    printf("------      (Nome): ");
    scanf("%s", nome);
    getchar();
    printf("------      (CPF): "); 
    scanf("%s", cpf);
    getchar();
    printf("------      (Data): ");
    scanf("%s", data);
    getchar();
    printf("------      (Horario): ");
    scanf("%s", horario);
    getchar();
    printf("------      (Situacao): ");
    scanf("%s", situacao);
    getchar();
    printf("------      (Pagamento): ");
    scanf("%s", pagamento);
    getchar();
    printf("=================================================================================\n");
    printf("------                 Agendamento realizado com sucesso!                  ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_dados_agendamento (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                       Dados de um Agendamento                       ------\n");
    printf("=================================================================================\n");
    printf("------      (ID do Agendamento):                                           ------\n");
    printf("------                                                                     ------\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (CPF):                                                         ------\n"); 
    printf("------      (Data):                                                        ------\n");
    printf("------      (Horario):                                                     ------\n");
    printf("------      (Situacao):                                                    ------\n");
    printf("------      (Pagamento):                                                   ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}
void editar_agendamento (void) {
    char id[10], nome[100], cpf[14], data[13], horario[9], situacao[200], pagamento[20];

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                          Editar Agendamento                         ------\n");
    printf("=================================================================================\n");
    printf("------      (ID): \n");
    scanf("%s", id);
    getchar();
    printf("------      (Nome): \n");
    scanf("%s", nome);
    getchar();
    printf("------      (CPF): \n"); 
    scanf("%s", cpf);
    getchar();
    printf("------      (Data): \n");
    scanf("%s", data);
    getchar();
    printf("------      (Horario): \n");
    scanf("%s", horario);
    getchar();
    printf("------      (Situacao): \n");
    scanf("%s", situacao);
    getchar();
    printf("------      (Pagamento): \n");
    scanf("%s", pagamento);
    printf("=================================================================================\n");
    printf("------               Dados do Agendamento editados com sucesso!            ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void excluir_agendamento (void) {
    char confirmacao;
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("-----                          Excluir Agendamento                          -----\n");
    printf("=================================================================================\n");
    printf("------      (ID):                                                          ------\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (CPF):                                                         ------\n"); 
    printf("------      (Data):                                                        ------\n");
    printf("------      (Horario):                                                     ------\n");
    printf("------      (Situacao):                                                    ------\n");
    printf("------      (Pagamento):                                                   ------\n"); 
    printf("------                                                                     ------\n"); 
    printf("------     Tem certeza que deseja excluir esse paciente? (S)IM | (N)AO     ------\n");

    scanf(" %c", &confirmacao);
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