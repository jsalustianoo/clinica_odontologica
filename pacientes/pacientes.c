#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

typedef struct pacientes Paciente;

void menu_paciente(void) {
    int opcao_paciente;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("------                         Menu dos Pacientes                          ------\n");
        printf("=================================================================================\n");
        printf("------                         |1| - Cadastrar                             ------\n");
        printf("------                         |2| - Visualizar                            ------\n");
        printf("------                         |3| - Editar                                ------\n");
        printf("------                         |4| - Excluir                               ------\n");
        printf("------                         |0| - Voltar                                ------\n");
        printf("=================================================================================\n");
        printf("    - (Opção desejada): ");
        scanf("%d", &opcao_paciente);
        getchar();
        switch (opcao_paciente) {
            case 0:
                break;
            case 1:
                cadastro_paciente();
                break;
            case 2:
                exibir_dados_paciente();
                break;
            case 3:
                editar_paciente();
                break;
            case 4:
                excluir_paciente();
                break;
            default:
                printf("Número digitado não condiz com nenhuma opção do sistema");
            break;
        }
    }while(opcao_paciente != 0);
}
void cadastro_paciente(void) {
    Paciente* criar;
    Paciente* ultimo;

    criar = (Paciente*)malloc(sizeof(Paciente));

    criar->nome_paciente = (char*)malloc(100 * sizeof(char)); 
    if (criar->nome_paciente == NULL) {
        printf("Erro ao alocar memória para o nome do paciente.\n");
        exit(1);
    }

    criar->cpf_paciente = (char*)malloc(100 * sizeof(char)); 
    if (criar->cpf_paciente == NULL) {
        printf("Erro ao alocar memória para o CPF do paciente.\n");
        exit(1);
    }

    criar->telefone_paciente = (char*)malloc(100 * sizeof(char)); 
    if (criar->telefone_paciente == NULL) {
        printf("Erro ao alocar memória para o nome do paciente.\n");
        exit(1);
    }

    criar->doencas_preexistentes = (char*)malloc(100 * sizeof(char)); 
    if (criar->doencas_preexistentes == NULL) {
        printf("Erro ao alocar memória para o CPF do paciente.\n");
        exit(1);
    }

    criar->contraindicacao = (char*)malloc(100 * sizeof(char)); 
    if (criar->contraindicacao == NULL) {
        printf("Erro ao alocar memória para o CPF do paciente.\n");
        exit(1);
    }

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Cadastro de Paciente                        ------\n");
    printf("=================================================================================\n");

    salvar_nome_do_paciente(criar->nome_paciente);
    getchar(); 
    salvar_cpf_paciente(criar->cpf_paciente);
    getchar();
    salvar_data_nascimento(&criar->dia, &criar->mes, &criar->ano);
    getchar();
    salvar_telefone_paciente(criar->telefone_paciente);
    getchar();
    salvar_doencas_preexistentes(criar->doencas_preexistentes);
    getchar();
    salvar_contraindacacao(criar->contraindicacao);
    getchar();

    ultimo = criar;
    salvar_pacientes_em_arquivo_txt(criar->nome_paciente, criar->cpf_paciente, criar->telefone_paciente, criar->doencas_preexistentes, criar->contraindicacao, criar->dia, criar->mes, criar->ano, "pacientes.txt", ultimo);

    printf("=================================================================================\n");
    printf("------                    Paciente Cadastrado com Sucesso                   -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...\n");
    getchar();

    // Liberando Memória Alocada para Variáveis
    free(criar->nome_paciente);
    free(criar->cpf_paciente);
    free(criar->telefone_paciente);
    free(criar->doencas_preexistentes);
    free(criar->contraindicacao);
}

void exibir_dados_paciente (void) {
    system("clear||cls");
    printf("\n");

    char cpf_busca[100];
    char nome[100], cpf[100], telefone[100], doencas[100], contraindicacao[100];
    int dia, mes, ano;
    int encontrado = 0;

    system("clear||cls");
    printf("\n=================================================================================\n");
    printf("------                         Consulta de Paciente                        ------\n");
    printf("=================================================================================\n");
    printf("------      Informe o CPF do paciente: ");
    scanf("%s", cpf_busca);
    getchar();

    FILE* arquivo_pacientes = fopen("pacientes.txt", "r");
    if (arquivo_pacientes == NULL) {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        return;
    }

    while (fscanf(arquivo_pacientes, " %[^\n] %[^\n] %[^\n] %d/%d/%d %[^\n] %[^\n]", 
                  nome, cpf, telefone, &dia, &mes, &ano, doencas, contraindicacao) != EOF) {
        if (strcmp(cpf, cpf_busca) == 0) {
            encontrado = 1;
            printf("=================================================================================\n");
            printf("------      Nome:                %s\n", nome);
            printf("------      CPF:                 %s\n", cpf);
            printf("------      Telefone:            %s\n", telefone);
            printf("------      Data de nascimento:  %02d/%02d/%04d\n", dia, mes, ano);
            printf("------      Doenças preexistentes: %s\n", doencas);
            printf("------      Contraindicação:     %s\n", contraindicacao);
            printf("=================================================================================\n");
            break;
        }
    }

    fclose(arquivo_pacientes);

    if (!encontrado) {
        printf("Paciente com CPF %s não encontrado.\n", cpf_busca);
    }

    printf("Tecle <ENTER> para continuar...");
    getchar();
}


void editar_paciente (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                          Editar de Paciente                         ------\n");
    printf("=================================================================================\n");
    
    printf("=================================================================================\n");
    printf("------              Dados do(a) Paciente Editados com Sucesso!             ------\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void excluir_paciente (void) {
    char confirmacao;

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                           Excluir Paciente                          ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (Data de nascimento):                                          ------\n");
    printf("------      (CPF):                                                         ------\n");
    printf("------      (Telefone):                                                    ------\n"); 
    printf("------      (Doenças preexistentes):                                       ------\n");
    printf("------      (Contra indicacao de remedios):                                ------\n");
    printf("------                                                                     ------\n"); 
    printf("------     Tem certeza que deseja Excluir esse Paciente? (S)IM | (N)AO     ------\n");

    scanf(" %c", &confirmacao);
    if (confirmacao == 'S' || confirmacao == 's'){
        printf("------                   Paciente excluído com sucesso!                    ------\n");
    } else if (confirmacao == 'N' || confirmacao == 'n'){
        printf("------                        Operação Cancelada!                          ------\n");
    } else{
        printf("------      Némero digitado não condiz com nenhuma opção do sistema        ------\n");
    }                     
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}


// NOME 
    void salvar_nome_do_paciente(char* nome_paciente) {
        int nome_valido = 0;

        while (!nome_valido) {
            printf("------      (Nome do Paciente): ");
            fgets(nome_paciente, 100, stdin); // Usa o ponteiro alocado
            nome_paciente[strcspn(nome_paciente, "\n")] = '\0'; // Remove o '\n'

            nome_valido = validarNome(nome_paciente);

            if (!nome_valido) {
                printf("\n=========== Nome Inválido! Tente Novamente! ===========\n\n");
            }
        }
    }

// CPF 
    void salvar_cpf_paciente(char* cpf_paciente){
        int cpf_paciente_valido = 0;
        while(!cpf_paciente_valido){
            printf("------      (CPF): ");
            scanf("%s", cpf_paciente);

            if(validar_cpf(cpf_paciente)){
                cpf_paciente_valido = 1;
            } else{
                printf("\n=========== CPF Inválido! Tente Novamente! ===========\n\n");
            }
        }
    }

void salvar_data_nascimento(int *dia, int *mes, int *ano){
    char data[11]; // Suporte para "MMDDYYYY" ou "MM/DD/YYYY"
    int data_valida = 0;

    while (!data_valida) {
            printf("------      (Data de Nascimento, MM/DD/AAAA ou MMDDAAAA): ");
            scanf("%10s", data); // Limita a entrada para evitar overflow

            data_valida = validar_data_nascimento(data, dia, mes, ano);
            if (!data_valida) {
                printf("\n=========== Data de Nascimento Inválida! Tente Novamente! ===========\n\n");
            }
        }
}

void salvar_telefone_paciente(char *telefone_paciente){
    int telefone_paciente_valido = 0;
    while(!telefone_paciente_valido){
        printf("------      (Telefone): "); 
        scanf("%s", telefone_paciente);

        telefone_paciente_valido = validar_telefone(telefone_paciente);

        if (!telefone_paciente) {
            printf("\n=========== Telefone Inválido! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_doencas_preexistentes(char *doencas_preexistentes){
    int doencas_preexistentes_validas = 0;
    while(!doencas_preexistentes_validas){
        printf("------      (Doenças Preexistentes): ");
        scanf(" %[^\n]", doencas_preexistentes); 

        doencas_preexistentes_validas = validar_doencas_preexistentes(doencas_preexistentes);

        if (!doencas_preexistentes_validas) {
            printf("\n=========== Especialidade Inválida! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_contraindacacao(char *contraindicacao){
    int contraindacacao_valida = 0;
    while(!contraindacacao_valida){
        printf("------      (Contraindicação de Medicamento(s)): ");
        scanf(" %[^\n]", contraindicacao);

        contraindacacao_valida = validar_contraindicacao(contraindicacao);

        if (!contraindacacao_valida) {
            printf("\n=========== Contraindicação Inválida! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_pacientes_em_arquivo_txt(char* nome_paciente, char* cpf_paciente, char* telefone_paciente, char* doencas_preexistentes, char* contraincacao, int dia, int mes, int ano, char *nome_arquivo, Paciente* ultimo){
    FILE* arquivo_pacientes = fopen(nome_arquivo, "a");
    if (arquivo_pacientes == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return;
    }

    Paciente* auxiliar = ultimo;
    fprintf(arquivo_pacientes, "%s\n", auxiliar->nome_paciente);
    fprintf(arquivo_pacientes, "%s\n", auxiliar->cpf_paciente);
    fprintf(arquivo_pacientes, "%s\n", auxiliar->telefone_paciente);
    fprintf(arquivo_pacientes, "%02d/%02d/%04d\n", dia, mes, ano);
    fprintf(arquivo_pacientes, "%s\n", auxiliar->doencas_preexistentes);
    fprintf(arquivo_pacientes, "%s\n", auxiliar->contraindicacao);
    
    fclose(arquivo_pacientes);
}