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

    criar->id = (int*)malloc(sizeof(int));
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

    salvar_cpf_paci(criar->cpf_paci);
    verificar_cpf_paciente(criar->cpf_paci, criar->nome_paci);
    getchar();

    salvar_cpf_dent(criar->cpf_dent);
    verificar_cpf_dentista(criar->cpf_dent, criar->nome_dent);
    printf("%s", criar->nome_dent);
    getchar();


    ultimo = criar;
    salvar_agendamento_em_arquivo_txt(criar->cpf_paci, criar->nome_paci, criar->cpf_dent, criar->nome_dent, "agendamentos.txt", ultimo);

    printf("=================================================================================\n");
    printf("------                 Agendamento Realizado com Sucesso!                  ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_dados_agendamento (void) {

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

void salvar_agendamento_em_arquivo_txt(char* cpf_paci, char* nome_paci, char* cpf_dent, char* nome_dent, char* nome_arquivo, Agendamento* ultimo){
    FILE* arquivo_agendamentos = fopen(nome_arquivo, "a");
    if (arquivo_agendamentos == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    Agendamento* auxiliar = ultimo;
    
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->cpf_paci);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->nome_paci);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->cpf_dent);
    fprintf(arquivo_agendamentos, "%s\n", auxiliar->nome_dent);
    fclose(arquivo_agendamentos);
}