#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendamentos.h"

#define MAX_NOME 100
#define MAX_CPF 12

// Estruturas (adaptar conforme o seu modelo de dados)
typedef struct {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
} Paciente;

typedef struct {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
} Dentista;

typedef struct agendamentos {
    char cpf_paci[MAX_CPF];
    char nome_paci[MAX_NOME];
    char cpf_dent[MAX_CPF];
    char nome_dent[MAX_NOME];
    int dia, mes, ano;
    char horario[6];
    char pagamento[2];
    char situacao[2];
} Agendamento;

void menu_agendamento (void) {
    int opcao_agendamento;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("------                          Menu Agendamentos                          ------\n");
        printf("=================================================================================\n");
        printf("------                                                                     ------\n");
        printf("------                          |1| Cadastrar                              ------\n");
        printf("------                          |2| Visualizar                             ------\n");
        printf("------                          |3| Editar                                 ------\n");
        printf("------                          |4| Excluir                                ------\n");
        printf("------                          |0| Voltar                                 ------\n");
        printf("------                                                                     ------\n");
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

void agendar(void) {
    Agendamento* criar;
    Agendamento* ultimo;

    criar = (Agendamento*)malloc(sizeof(Agendamento));

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Realizar Agendamento                        ------\n");
    printf("=================================================================================\n");

    salvar_cpf_paci(criar->cpf_paci);
    buscar_nome_paciente(criar->cpf_paci, criar->nome_paci); // Buscar nome do paciente
    getchar();

    salvar_cpf_dent(criar->cpf_dent);
    buscar_nome_dentista(criar->cpf_dent, criar->nome_dent); // Buscar nome do dentista
    getchar();

    salvar_data(&criar->dia, &criar->mes, &criar->ano);
    salvar_horario(criar->horario);
    getchar();
    salvar_pagamento(criar->pagamento);
    getchar();
    salvar_situacao(criar->situacao);
    getchar();

    ultimo = criar;
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

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                          Editar Agendamento                         ------\n");
    printf("=================================================================================\n");
    
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

void salvar_cpf_paci(char *cpf_paci){
    int valido = 0;
    while (!valido){
        printf("------      (CPF do Paciente): ");
        scanf("%s", cpf_paci);
        if(validar_cpf(cpf_paci)){
            valido = 1;
        } else{
            printf("\n=========== CPF Inválido! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_cpf_dent(char *cpf_dent){
    int valido = 0;
    while (!valido){
        printf("------      (CPF do Dentista): ");
        scanf("%s", cpf_dent);
        if(validar_cpf(cpf_dent)){
            valido = 1;
        } else{
            printf("\n=========== CPF Inválido! Tente Novamente! ===========\n\n");
        }
    }
}

// Usei chatGPT
void salvar_data(int *dia, int *mes, int *ano) {
    char data[11]; // Suporte para "MMDDYYYY" ou "MM/DD/YYYY"
    int data_valida = 0;

    while (!data_valida) {
        printf("------      (Data, MM/DD/AAAA ou MMDDAAAA): ");
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
                printf("\n=========== Data Inválida! Tente Novamente! ===========\n\n");
            }
        } else {
            printf("\n=========== Formato Incorreto! Tente Novamente! ===========\n\n");

        }
    }
}

// Usei chatGPT
void salvar_horario(char *horario) {
    int horario_valido = 0;

    while (!horario_valido) {
        printf("------      (Horário, HH:MM): ");
        scanf("%5s", horario); // Lê no máximo 5 caracteres para "HH:MM"

        if (validar_horario(horario)) {
            horario_valido = 1;
        } else {
            printf("\n=========== Horário Inválido! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_pagamento(char *pagamento){
    int pagamento_valido = 0;
    while(!pagamento_valido){
        printf("\nEscolha dentre as opções: \n");
        printf("\n      1 - Pix");
        printf("\n      2 - Dinheiro");
        printf("\n      3 - Cartão");
        printf("\n\n------      (Forma de Pagamento): ");
        scanf("%s", pagamento);

        if(strcmp(pagamento, "1") == 0){
            pagamento_valido = 1;
        }else if(strcmp(pagamento, "2") == 0){
            pagamento_valido = 1;
        }else if(strcmp(pagamento, "3") == 0){
            pagamento_valido = 1;
        }else{
            printf("\n=========== Forma de Pagamento Inválida! Tente Novamente! ===========\n\n");
        }
    }    
    
}

void salvar_situacao(char *situacao){
    int situacao_valida = 0;
    while(!situacao_valida){
        printf("\nEscolha dentre as opções: \n");
        printf("\n      1 - Agendado");
        printf("\n      2 - Finalizado");
        printf("\n      3 - Cancelado");
        printf("\n\n------      (Situação): ");
        scanf("%s", situacao);

        if(strcmp(situacao, "1") == 0){
            situacao_valida = 1;
        }else if(strcmp(situacao, "2") == 0){
            situacao_valida = 1;
        }else if(strcmp(situacao, "3") == 0){
            situacao_valida = 1;
        }else{
            printf("\n=========== Situação Inválida! Tente Novamente! ===========\n\n");
        }
    }
}

void buscar_nome_paciente(const char *cpf, char *nome_paci) {
    FILE *arq = fopen("pacientes.txt", "r");
    Paciente paciente;
    int encontrado = 0;

    if (arq) {
        while (fscanf(arq, "%s %s", paciente.nome, paciente.cpf) != EOF) {
            // Adicionar depuração para imprimir o que está sendo lido
            printf("Nome: %s, CPF: %s\n", paciente.nome, paciente.cpf);

            if (strcmp(paciente.cpf, cpf) == 0) {
                strcpy(nome_paci, paciente.nome);
                encontrado = 1;
                break;
            }
        }
        fclose(arq);
    } else {
        printf("Erro ao abrir o arquivo pacientes.txt!\n");
    }

    if (!encontrado) {
        printf("Paciente com CPF %s não encontrado!\n", cpf);
        strcpy(nome_paci, "Não encontrado");
    }
}

void buscar_nome_dentista(const char *cpf, char *nome_dent) {
    FILE *arq = fopen("dentistas.txt", "r");
    Dentista dentista;
    int encontrado = 0;

    if (arq) {
        while (fscanf(arq, "%s %s", dentista.nome, dentista.cpf) != EOF) {
            // Adicionar depuração para imprimir o que está sendo lido
            printf("Nome: %s, CPF: %s\n", dentista.nome, dentista.cpf);

            if (strcmp(dentista.cpf, cpf) == 0) {
                strcpy(nome_dent, dentista.nome);
                encontrado = 1;
                break;
            }
        }
        fclose(arq);
    } else {
        printf("Erro ao abrir o arquivo dentista.txt!\n");
    }

    if (!encontrado) {
        printf("Dentista com CPF %s não encontrado!\n", cpf);
        strcpy(nome_dent, "Não encontrado");
    }
}
