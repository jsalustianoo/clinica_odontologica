#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendamentos.h"
#include <time.h>

typedef struct agendamentos Agendamento;

void menu_agendamento (void) {
    int opcao_agendamento;
    do{
        system("clear||cls");
        printf("\n");
        printf("===================================================================================\n");
        printf("------                           Menu Agendamentos                           ------\n");
        printf("===================================================================================\n");
        printf("------                                                                       ------\n");
        printf("------                           |1| - Cadastrar                             ------\n");
        printf("------                           |2| - Visualizar                            ------\n");
        printf("------                           |3| - Editar                                ------\n");
        printf("------                           |4| - Excluir                               ------\n");
        printf("------                           |0| - Voltar                                ------\n");
        printf("------                                                                       ------\n");
        printf("===================================================================================\n");
        printf("- (Opção desejada): ");
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

    criar->id = (char*)malloc(sizeof(char));
    if (criar->id == NULL) {
        printf("Erro na alocação de memória do ID!");
    }

    criar->cpf_paci = (char*)malloc(100 * sizeof(char));
    if(criar->cpf_paci == NULL){
        printf("Erro na alocação de memória do CPF do Paciente!");
    }

    criar->cpf_dent = (char*)malloc(100 * sizeof(char));
    if(criar->cpf_dent == NULL){
        printf("Erro na alocação de memória do CPF do Dentista!");
    }

    criar->data_agendamento = (char*)malloc(100 * sizeof(char));
    if(criar->data_agendamento == NULL){
        printf("Erro na alocação de memória da Data do Agendamento!");
    }

    criar->horario = (char*)malloc(100 * sizeof(char));
    if(criar->horario == NULL){
        printf("Erro na alocação de memória do Horário!");
    }

    criar->pagamento = (char*)malloc(100 * sizeof(char));
    if(criar->pagamento == NULL){
        printf("Erro na alocação de memória do Pagamento!");
    }

    criar->situacao = (char*)malloc(100 * sizeof(char));
    if(criar->situacao == NULL){
        printf("Erro na alocação de memória da Situação!");
    }

    criar->nome_paci = (char*)malloc(100 * sizeof(char));
    if(criar->nome_paci == NULL){
        printf("Erro na alocação de memória do Nome do Paciente!");
    }

    criar->nome_dent = (char*)malloc(100 * sizeof(char));
    if(criar->nome_dent == NULL){
        printf("Erro na alocação de memória do Nome do Dentista!");
    }

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Realizar Agendamento                        ------\n");
    printf("=================================================================================\n");

    printf("------      (ID): ");
    scanf("%s", criar->id);
    getchar();

    salvar_cpf_paci(criar->cpf_paci);
    verificar_cpf_paciente(criar->cpf_paci, criar->nome_paci);
    getchar();

    salvar_cpf_dent(criar->cpf_dent);
    verificar_cpf_dentista(criar->cpf_dent, criar->nome_dent);
    getchar();

    salvar_data_agendamento(criar->data_agendamento);
    getchar();
    salvar_horario(criar->horario);
    getchar();
    salvar_pagamento(criar->pagamento);
    getchar();
    salvar_situacao(criar->situacao);
    getchar();


    ultimo = criar;
    salvar_agendamento_em_arquivo_txt(criar->id, criar->cpf_paci, criar->nome_paci, criar->cpf_dent, criar->nome_dent, criar->data_agendamento, criar->horario, criar->pagamento, criar->situacao, "agendamentos.txt", ultimo);

    printf("=================================================================================\n");
    printf("------                 Agendamento Realizado com Sucesso!                  ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_dados_agendamento(void) {
    system("clear||cls");
    printf("\n");

    char id_procurado[100];
    char id[100], cpf_paci[15], nome_paci[100], cpf_dent[15], nome_dent[100];
    char data_agendamento[20], horario[20], pagamento[20], situacao[20];
    int encontrado = 0;

    // Solicita o ID do agendamento
    printf("=================================================================================\n");
    printf("------                        Visualizar Agendamento                       ------\n");
    printf("=================================================================================\n");
    printf("      - (ID do Agendamento): ");
    scanf("%s", id_procurado);
    getchar();  // Limpa buffer

    FILE *arquivo = fopen("agendamentos.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(id, sizeof(id), arquivo) != NULL) {
        fgets(cpf_paci, sizeof(cpf_paci), arquivo);
        fgets(nome_paci, sizeof(nome_paci), arquivo);
        fgets(cpf_dent, sizeof(cpf_dent), arquivo);
        fgets(nome_dent, sizeof(nome_dent), arquivo);
        fgets(data_agendamento, sizeof(data_agendamento), arquivo);
        fgets(horario, sizeof(horario), arquivo);
        fgets(pagamento, sizeof(pagamento), arquivo);
        fgets(situacao, sizeof(situacao), arquivo);

        // Remove o '\n' de cada linha lida
        id[strcspn(id, "\n")] = '\0';
        cpf_paci[strcspn(cpf_paci, "\n")] = '\0';
        nome_paci[strcspn(nome_paci, "\n")] = '\0';
        cpf_dent[strcspn(cpf_dent, "\n")] = '\0';
        nome_dent[strcspn(nome_dent, "\n")] = '\0';
        data_agendamento[strcspn(data_agendamento, "\n")] = '\0';
        horario[strcspn(horario, "\n")] = '\0';
        pagamento[strcspn(pagamento, "\n")] = '\0';
        situacao[strcspn(situacao, "\n")] = '\0';

        // Verifica se o ID do agendamento corresponde ao solicitado
        if (strcmp(id, id_procurado) == 0) {
            encontrado = 1;
            // Exibe os dados do agendamento
            printf("\n============================== Agendamento ==============================\n");
            printf("ID: %s\n", id);
            printf("CPF do Paciente: %s\n", cpf_paci);
            printf("Nome do Paciente: %s\n", nome_paci);
            printf("CPF do Dentista: %s\n", cpf_dent);
            printf("Nome do Dentista: %s\n", nome_dent);
            printf("Data do Agendamento: %s\n", data_agendamento);
            printf("Horário: %s\n", horario);
            printf("Forma de Pagamento: %s\n", pagamento);
            printf("Situação: %s\n", situacao);
            printf("==========================================================================\n");
            printf("-----                   Agendamento visualizado com sucesso!            -----\n");
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("\nAgendamento com ID %s não encontrado.\n", id_procurado);
    }

    printf("\nTecle <ENTER> para continuar...");
    getchar();
}

void editar_agendamento(void) {
    system("clear||cls");
    printf("\n");

    printf("=================================================================================\n");
    printf("------                         < Em desenvolvimento >                      ------\n");
    printf("=================================================================================\n");

    printf("\nTecle <ENTER> para continuar...");
    getchar();
}

void excluir_agendamento(void) {
    system("clear||cls");
    printf("\n");

    char id_procurado[100];
    char id[100], cpf_paci[15], nome_paci[100], cpf_dent[15], nome_dent[100];
    char data_agendamento[20], horario[20], pagamento[20], situacao[20];
    int encontrado = 0;
    int confirmacao;

    // Solicita o ID do agendamento
    printf("=================================================================================\n");
    printf("------                            Excluir Agendamento                        ------\n");
    printf("=================================================================================\n");
    printf("      - (ID do Agendamento): ");
    fgets(id_procurado, sizeof(id_procurado), stdin);
    id_procurado[strcspn(id_procurado, "\n")] = '\0'; 

    FILE *arquivo = fopen("agendamentos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(id, sizeof(id), arquivo) != NULL) {
        fgets(cpf_paci, sizeof(cpf_paci), arquivo);
        fgets(nome_paci, sizeof(nome_paci), arquivo);
        fgets(cpf_dent, sizeof(cpf_dent), arquivo);
        fgets(nome_dent, sizeof(nome_dent), arquivo);
        fgets(data_agendamento, sizeof(data_agendamento), arquivo);
        fgets(horario, sizeof(horario), arquivo);
        fgets(pagamento, sizeof(pagamento), arquivo);
        fgets(situacao, sizeof(situacao), arquivo);

        // Remove o '\n' de cada linha lida
        id[strcspn(id, "\n")] = '\0';
        cpf_paci[strcspn(cpf_paci, "\n")] = '\0';
        nome_paci[strcspn(nome_paci, "\n")] = '\0';
        cpf_dent[strcspn(cpf_dent, "\n")] = '\0';
        nome_dent[strcspn(nome_dent, "\n")] = '\0';
        data_agendamento[strcspn(data_agendamento, "\n")] = '\0';
        horario[strcspn(horario, "\n")] = '\0';
        pagamento[strcspn(pagamento, "\n")] = '\0';
        situacao[strcspn(situacao, "\n")] = '\0';

        if (strcmp(id, id_procurado) == 0) {
            printf("\n=================================================================================\n");
            printf("      - (ID): %s\n", id);
            printf("      - (CPF do Paciente): %s\n", cpf_paci);
            printf("      - (Nome do Paciente): %s\n", nome_paci);
            printf("      - (CPF do Dentista): %s\n", cpf_dent);
            printf("      - (Nome do Dentista): %s\n", nome_dent);
            printf("      - (Data do Agendamento): %s\n", data_agendamento);
            printf("      - (Horário): %s\n", horario);
            printf("      - (Forma de Pagamento): %s\n", pagamento);
            printf("      - (Situação): %s\n", situacao);
            printf("=================================================================================\n");

            printf("\nDeseja realmente excluir? (1 - Sim / 0 - Não): ");
            scanf("%d", &confirmacao);
            getchar();

            if (confirmacao == 1) {
                encontrado = 1;
                printf("===================================================================================\n");
                printf("-----                 Agendamento excluído com sucesso!                       -----\n");
                printf("===================================================================================\n");
                continue;  // Não escreve o agendamento no arquivo temporário
            } else {
                printf("\nExclusão cancelada.\n");
            }
        }

        // Escreve os dados no arquivo temporário, exceto o agendamento excluído
        fprintf(temp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", id, cpf_paci, nome_paci, cpf_dent, nome_dent, data_agendamento, horario, pagamento, situacao);
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("agendamentos.txt");
        rename("temp.txt", "agendamentos.txt");
    } else {
        remove("temp.txt");
        printf("\nAgendamento com ID %s não encontrado.\n", id_procurado);
    }

    printf("\nTecle <ENTER> para continuar...");
    getchar();
}


void salvar_cpf_paci(char* cpf_paci){
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

#define MAX_LINHA 200

int verificar_cpf_paciente(char* cpf_paci, char* nome_paci) {
    FILE* arquivo = fopen("pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo pacientes.txt\n");
        return 0;
    }

    char linha[MAX_LINHA];
    char nome[MAX_LINHA];
    char cpf_lido[MAX_LINHA];

    while (fgets(linha, sizeof(linha), arquivo)) {
        strcpy(nome, linha); 
        if (fgets(cpf_lido, sizeof(cpf_lido), arquivo)) {
            cpf_lido[strcspn(cpf_lido, "\n")] = '\0'; 

            if (strcmp(cpf_paci, cpf_lido) == 0) {
                nome[strcspn(nome, "\n")] = '\0'; 
                strcpy(nome_paci, nome);
                fclose(arquivo);
                return 1;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            fgets(linha, sizeof(linha), arquivo);
        }
    }

    fclose(arquivo);
    return 0;
}

void salvar_cpf_dent(char* cpf_dent){
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

#define MAX_LINHA 200

int verificar_cpf_dentista(char* cpf_dent, char* nome_dent) {
    FILE* arquivo = fopen("dentistas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo dentistas.txt\n");
        return 0;
    }

    char linha[MAX_LINHA];
    char nome[MAX_LINHA];
    char cpf_lido[MAX_LINHA];

    while (fgets(linha, sizeof(linha), arquivo)) {
        strcpy(nome, linha); 
        if (fgets(cpf_lido, sizeof(cpf_lido), arquivo)) {
            cpf_lido[strcspn(cpf_lido, "\n")] = '\0'; 

            if (strcmp(cpf_dent, cpf_lido) == 0) {
                nome[strcspn(nome, "\n")] = '\0'; 
                strcpy(nome_dent, nome);
                fclose(arquivo);
                return 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            fgets(linha, sizeof(linha), arquivo);
        }
    }

    fclose(arquivo);
    return 0;
}

void salvar_data_agendamento(char* data_agendamento) {
    int data_valida = 0;
    while (!data_valida) {
        printf("------      (Data, (MM/DD/AAAA)): ");
        scanf("%s", data_agendamento);
        
        // Validar a data
        if (validar_data_agendamento(data_agendamento)) {
            data_valida = 1;
        } else {
            printf("\n=========== Data Inválida! Tente Novamente! ===========\n\n");
        }
    }
}

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

void salvar_agendamento_em_arquivo_txt(char* id, char* cpf_paci, char* nome_paci, char* cpf_dent, char* nome_dent, char* horario, char* data_agendamento, char* pagamento, char* situacao, char* nome_arquivo, Agendamento* ultimo){
    FILE* arquivo_agendamentos = fopen(nome_arquivo, "a");
    if (arquivo_agendamentos == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    Agendamento* auxiliar = ultimo;
    
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->id);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->cpf_paci);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->nome_paci);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->cpf_dent);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->nome_dent);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->data_agendamento);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->horario);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->pagamento);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->situacao);
    fclose(arquivo_agendamentos);
}