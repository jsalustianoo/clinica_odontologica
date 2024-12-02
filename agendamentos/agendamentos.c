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
        printf("-----      (2) Visualizar Agendamento                                       -----\n");
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
    char id[10]; 
    char nome[45]; 
    char cpf[14]; 
    char dentista[45]; 
    char horario[6];
    char pagamento[9]; 
    char situacao[20];
    int dia, mes, ano;

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Realizar Agendamento                        ------\n");
    printf("=================================================================================\n");
    printf("------      (ID): ");
    scanf("%s", id);
    getchar();
    salvar_nome_paciente(nome);
    getchar();
    salvar_cpf(cpf);
    getchar();
    salvar_dentista(dentista);
    getchar();
    salvar_data(&dia, &mes, &ano);
    salvar_horario(horario);
    getchar();
    salvar_pagamento(pagamento);
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
    char id[10]; 
    char nome[45]; 
    char cpf[14]; 
    char dentista[45]; 
    char horario[6];
    char pagamento[9]; 
    char situacao[20];
    int dia, mes, ano;

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
    scanf("%s", &dia, &mes, &ano);
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
    printf("------               Dados do Agendamento Editados com Sucesso!            ------\n");
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
    printf("------   Tem certeza que deseja Excluir esse Agendamento? (S)IM | (N)AO    ------\n");

    scanf(" %c", &confirmacao);
    if (confirmacao == 'S' || confirmacao == 's'){
        printf("------                  Agendamento excluído com sucesso!                  ------\n");
    } else if (confirmacao == 'N' || confirmacao == 'n'){
        printf("------                        Operacao cancelada!                          ------\n");
    } else{
        printf("------      Número digitado não condiz com nenhuma opção do sistema        ------\n");
    }                     
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

// O chatGPT fez uma dessas funções de validação e fui alterando o necessário para as outras

void salvar_nome_paciente(char *nome) {
    int valido = 0; // Não válido
    while (!valido) {
        printf("------      (Nome do Paciente): ");
        scanf(" %[^\n]", nome);
        
        if (validarNome(nome) == 1) { 
            valido = 1; // Válido
        } else {
            printf("\n             Tente Novamente! (Não coloque acentos) Tecle <ENTER> para continuar...\n\n");
            while (getchar() != '\n'); 
        }
    }
}

void salvar_cpf(char *cpf){
    int valido = 0;
    while (!valido){
        printf("------      (CPF): ");
        scanf("%s", cpf);
        if(validar_cpf(cpf)){
            valido = 1;
        } else{
            printf("CPF inválido");
        }
    }
}

void salvar_dentista(char *nome) {
    int valido = 0; // Não válido
    while (!valido) {
        printf("------      (Dentista): ");
        scanf(" %[^\n]", nome);
        
        if (validarNome(nome) == 1) { 
            valido = 1; // Válido
        } else {
            printf("\n            (Tente Novamente! (Não coloque acentos) Tecle <ENTER> para continuar...\n\n");
            while (getchar() != '\n'); 
        }
    }
}

void salvar_data(int *dia, int *mes, int *ano) {
    char data[11]; // Suporte para "MMDDYYYY" ou "MM/DD/YYYY"
    int data_valida = 0;

    while (!data_valida) {
        printf("------      (Data, no formato MM/DD/AAAA ou MMDDAAAA): ");
        scanf("%10s", data); // Lê até 10 caracteres

        // Remover barras, se existirem
        char data_limpa[9];
        int j = 0;
        for (int i = 0; data[i] != '\0'; i++) {
            if (data[i] != '/') {
                data_limpa[j++] = data[i];
            }
        }
        data_limpa[j] = '\0';

        // Verificar se a data tem exatamente 8 caracteres após limpeza
        if (strlen(data_limpa) == 8) {
            *mes = atoi(strndup(data_limpa, 2));     // Extrai MM
            *dia = atoi(strndup(data_limpa + 2, 2)); // Extrai DD
            *ano = atoi(data_limpa + 4);            // Extrai YYYY

            if (validar_data(*dia, *mes, *ano)) {
                data_valida = 1;
            } else {
                printf("\n             Data inválida, Tente Novamente!\n\n");
            }
        } else {
            printf("\n             Formato incorreto. Tente novamente.\n\n");
        }
    }
}

void salvar_horario(char *horario) {
    int horario_valido = 0;

    while (!horario_valido) {
        printf("Digite o horário no formato HH:MM: ");
        scanf("%5s", horario); // Lê no máximo 5 caracteres para "HH:MM"

        if (validar_horario(horario)) {
            horario_valido = 1;
            printf("Horário válido!\n");
        } else {
            printf("Horário inválido. Certifique-se de usar o formato HH:MM.\n");
        }
    }
}

void salvar_pagamento(char *pagamento){
    int pagamento_valido = 0;
    while(!pagamento_valido){
        printf("------      (Forma de Pagamento): ");
        scanf("%s", pagamento);

        if(strcmp(pagamento, "Pix") == 0 || strcmp(pagamento, "pix") == 0 || strcmp(pagamento, "PIX") == 0){
            pagamento_valido = 1;
        }else if(strcmp(pagamento, "Dinheiro") == 0 || strcmp(pagamento, "dinheiro") == 0 || strcmp(pagamento, "DINHEIRO") == 0){
            pagamento_valido = 1;
        }else if(strcmp(pagamento, "Cartão") == 0 || strcmp(pagamento, "cartão") == 0 || strcmp(pagamento, "CARTÃO") == 0){
            pagamento_valido = 1;
        }else{
            printf("\n             Forma de Pagamento Inválida!\n");
        }
    }    
    
}