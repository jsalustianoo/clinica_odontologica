#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendamentos.h"

typedef struct agendamentos Agendamento;

void menu_agendamento (void) {
    int opcao_agendamento;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("-----                           Menu Agendamentos                           -----\n");
        printf("=================================================================================\n");
        printf("-----                          |1| - Cadastrar                              -----\n");
        printf("-----                          |2| - Visualizar                             -----\n");
        printf("-----                          |3| - Editar                                 -----\n");
        printf("-----                          |4| - Excluir                                -----\n");
        printf("-----                          |0| - Voltar                                 -----\n");
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
    Agendamento* criar;
    Agendamento* ultimo;

    criar = (Agendamento*)malloc(sizeof(Agendamento));

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Realizar Agendamento                        ------\n");
    printf("=================================================================================\n");
    printf("------      (ID): ");
    scanf("%s", criar->id);
    getchar();
    salvar_nome_paciente(criar->nome);
    getchar();
    salvar_cpf(criar->cpf);
    getchar();
    salvar_dentista(criar->dentista);
    getchar();
    salvar_data(&criar->dia, &criar->mes, &criar->ano);
    salvar_horario(criar->horario);
    getchar();
    salvar_pagamento(criar->pagamento);
    getchar();
    salvar_situacao(criar->situacao);
    getchar();

    ultimo = criar;
    salvar_agendamento_em_arquivo_txt(criar->id, criar->nome, criar->cpf, criar->dentista, criar->dia, criar->mes, criar->ano, criar->horario, criar->pagamento, criar->situacao, "agendamentos.txt", ultimo);

    printf("=================================================================================\n");
    printf("------                 Agendamento Realizado com Sucesso!                  ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_dados_agendamento (void) {
    system("clear||cls");
    printf("\n");

    char id_busca[10];
    char id[10], nome[45], cpf[14], dentista[45], data[11], horario[6], pagamento[2], situacao[2];
    int encontrado = 0;

    printf("\n=================================================================================\n");
    printf("------                        Visualizar Agendamentos                       ------\n");
    printf("=================================================================================\n");
    printf("------      Informe o ID do agendamento: ");
    scanf("%s", id_busca);
    getchar();

    FILE* arquivo_agendamentos = fopen("agendamentos.txt", "r");
    if (arquivo_agendamentos == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos.\n");
        return;
    }

    while (fgets(id, sizeof(id), arquivo_agendamentos) != NULL) {
        fgets(nome, sizeof(nome), arquivo_agendamentos);
        fgets(cpf, sizeof(cpf), arquivo_agendamentos);
        fgets(dentista, sizeof(dentista), arquivo_agendamentos);
        fgets(data, sizeof(data), arquivo_agendamentos);
        fgets(horario, sizeof(horario), arquivo_agendamentos);
        fgets(pagamento, sizeof(pagamento), arquivo_agendamentos);
        fgets(situacao, sizeof(situacao), arquivo_agendamentos);


        id[strcspn(id, "\n")] = '\0';
        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        dentista[strcspn(dentista, "\n")] = '\0';
        data[strcspn(data, "\n")] = '\0';
        horario[strcspn(horario, "\n")] = '\0';
        pagamento[strcspn(pagamento, "\n")] = '\0';
        situacao[strcspn(situacao, "\n")] = '\0';

        if (strcmp(id, id_busca) == 0) {
            encontrado = 1;
            printf("=================================================================================\n");
            printf("------      Nome:                %s\n", nome);
            printf("------      CPF:                 %s\n", cpf);
            printf("------      Dentista:            %s\n", dentista);
            printf("------      Data do agendamento: %s\n", data);
            printf("------      Horário:             %s\n", horario);
            printf("------      Pagamento:            %s\n", pagamento);
            printf("------      Situação:             %s\n", situacao);
            printf("=================================================================================\n");
            break;
        }
    }

    fclose(arquivo_agendamentos);

    if (!encontrado) {
        printf("Agendamento com ID %s não encontrado.\n", id_busca);
    }

    printf("Tecle <ENTER> para continuar...");
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

void salvar_nome_paciente(char *nome) {
    int valido = 0; // Não válido
    while (!valido) {
        printf("------      (Nome do Paciente): ");
        scanf(" %[^\n]", nome);
        
        if (validarNome(nome) == 1) { 
            valido = 1; // Válido
        } else {
            printf("\n=========== Nome Inválido! Tente Novamente! ===========\n\n");
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
            printf("\n=========== CPF Inválido! Tente Novamente! ===========\n\n");
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
            printf("\n=========== Nome Inválido! Tente Novamente! ===========\n\n");
            while (getchar() != '\n'); 
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

void salvar_agendamento_em_arquivo_txt(char* id, char* nome, char* cpf, char* dentista, int dia, int mes, int ano, char* horario, char* pagamento, char* situacao, char* nome_arquivo, Agendamento* ultimo){
    FILE* arquivo_agendamentos = fopen(nome_arquivo, "a");
    if (arquivo_agendamentos == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    Agendamento* auxiliar = ultimo;
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->id);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->nome);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->cpf);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->dentista);
    fprintf(arquivo_agendamentos, "%02d/%02d/%04d\n", dia, mes, ano);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->horario);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->pagamento);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->situacao);
    
    fclose(arquivo_agendamentos);
}