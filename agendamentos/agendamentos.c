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
        printf("-----      (1) Realizar Agendamento                                         -----\n");
        printf("-----      (2) Visualizar Agendamentos                                      -----\n");
        printf("-----      (3) Editar Agendamento                                           -----\n");
        printf("-----      (4) Excluir Agendamento                                          -----\n");
        printf("-----      (0) Retornar ao Menu Anterior                                    -----\n");
        printf("=================================================================================\n");
        printf("    - (Opção desejada): ");
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
                printf("Número digitado não condiz com nenhuma opção do sistema");
            break;
        }
    }while(opcao_agendamento != 0);

}

void agendar (void) {
    char id[10], nome[100], cpf[14], dentista[13], data[13], horario[9], pagamento[20], situacao[20];

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Realizar Agendamento                        ------\n");
    printf("=================================================================================\n");
    printf("------      (ID): ");
    scanf("%s", id);
    getchar();
    validar_nome(nome);
    getchar();
    validar_cpf(cpf);
    getchar();
    printf("------      (Dentista): "); 
    scanf("%s", dentista);
    getchar();
    printf("------      (Data): ");
    scanf("%s", data);
    getchar();
    printf("------      (Horário): ");
    scanf("%s", horario);
    getchar();
    printf("------      (Pagamento): ");
    scanf("%s", pagamento);
    getchar();
    printf("------      (Situação): ");
    scanf("%s", situacao);
    getchar();
    printf("=================================================================================\n");
    printf("------                 Agendamento Realizado com Sucesso!                  ------\n");
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
    printf("------      (Nome do Paciente):                                            ------\n");
    printf("------      (CPF):                                                         ------\n"); 
    printf("------      (Dentista):                                                    ------\n");
    printf("------      (Data):                                                        ------\n");
    printf("------      (Horário):                                                     ------\n");
    printf("------      (Forma de Pagamento):                                          ------\n");
    printf("------      (Situação):                                                    ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}
void editar_agendamento (void) {
    char id[10], nome[100], cpf[14], dentista[50], data[13], horario[9], pagamento[20], situacao[20];

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                          Editar Agendamento                         ------\n");
    printf("=================================================================================\n");
    printf("------      (ID): ");
    scanf("%s", id);
    getchar();
    printf("------      (Nome do Paciente): ");
    scanf("%s", nome);
    getchar();
    printf("------      (CPF): "); 
    scanf("%s", cpf);
    getchar();
    printf("------      (Dentista): "); 
    scanf("%s", dentista);
    getchar();
    printf("------      (Data): ");
    scanf("%s", data);
    getchar();
    printf("------      (Horário): ");
    scanf("%s", horario);
    getchar();
    printf("------      (Forma de Pagamento): ");
    scanf("%s", pagamento);
    getchar();
    printf("------      (Situação): ");
    scanf("%s", situacao);
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
    printf("------      (Nome do Paciente):                                            ------\n");
    printf("------      (CPF):                                                         ------\n"); 
    printf("------      (Dentista):                                                    ------\n"); 
    printf("------      (Data):                                                        ------\n");
    printf("------      (Horário):                                                     ------\n");
    printf("------      (Forma de Pagamento):                                          ------\n"); 
    printf("------      (Situação):                                                    ------\n");
    printf("------                                                                     ------\n"); 
    printf("------     Tem certeza que deseja Excluir esse Paciente? (S)IM | (N)AO     ------\n");

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

// (Autor: João Roberto)
void validar_nome(char *nome) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("------      (Nome do Paciente): ");
        scanf(" %[^\n]", nome);
        getchar();
        if (validarNome(nome)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("------      (Tente Novamente (Digite apenas Letras e Espaços, sem acentos)\n");
            printf("      Tecle <ENTER> para continuar...");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}

void validar_cpf(char *cpf){
    printf("------      (CPF): " );
    scanf("%s", cpf);
    getchar();
    return 0;
}