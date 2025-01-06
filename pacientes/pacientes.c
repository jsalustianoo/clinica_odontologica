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
        printf("------        (1) - Cadastrar Novo Paciente                                ------\n");
        printf("------        (2) - Visualizar Dados de um Paciente                        ------\n");
        printf("------        (3) - Editar Dados de um Paciente                            ------\n");
        printf("------        (4) - Excluir Paciente                                       ------\n");
        printf("------        (0) - Retornar ao Menu Principal                             ------\n");
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
    Paciente paciente;

    // ler_nomes_arquivo("pacientes.txt");

    // Aloca memória para o nome do paciente
    paciente.nome_paciente = (char*)malloc(100 * sizeof(char));
    if (paciente.nome_paciente == NULL) {
        printf("Erro ao alocar memória para o nome do paciente.\n");
        exit(1);
    }

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Cadastro de Paciente                        ------\n");
    printf("=================================================================================\n");

    salvar_nome_do_paciente(paciente.nome_paciente); // Nome do paciente é um ponteiro
    
    getchar();  // Aguardar pressionar Enter

    salvar_data_nascimento(&paciente.dia, &paciente.mes, &paciente.ano);
    getchar();
    salvar_cpf_paciente(paciente.cpf_paciente);
    getchar();
    salvar_telefone_paciente(paciente.telefone_paciente);
    getchar();
    salvar_doencas_preexistentes(paciente.doencas_preexistentes);
    getchar();
    salvar_contraindacacao(paciente.contraindicacao);
    getchar();

    printf("=================================================================================\n");
    printf("------                    Paciente Cadastrado com Sucesso                   -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...\n");
    getchar();

    // Libera a memória alocada
    free(paciente.nome_paciente);
}

void exibir_dados_paciente (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Dados de um Paciente                        ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                          ------");
    printf("------      (Data de nascimento):                                            ------");
    printf("------      (CPF):                                                           ------");
    printf("------      (Telefone):                                                      ------"); 
    printf("------      (Doencas preexistentes):                                         ------");
    printf("------      (Contra indicação de remédio(s)):                                ------");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void editar_paciente (void) {
    Paciente paciente;
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                          Editar de Paciente                         ------\n");
    printf("=================================================================================\n");
    salvar_nome_paciente(paciente.nome_paciente);
    getchar();
    salvar_data_nascimento(&paciente.dia, &paciente.mes, &paciente.ano);
    getchar();
    salvar_cpf_paciente(paciente.cpf_paciente);
    getchar();
    salvar_telefone_paciente(paciente.telefone_paciente);
    getchar();
    salvar_doencas_preexistentes(paciente.doencas_preexistentes);
    getchar();
    salvar_contraindacacao(paciente.contraindicacao);
    getchar();
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

// NOME PACIENTE
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

        // Agora salva o nome no arquivo
        salvar_nome_arquivo(nome_paciente, "pacientes.txt");
    }

    void salvar_nome_arquivo(const char* nome_paciente, const char* arquivo) {
        FILE* fp = fopen(arquivo, "a"); // Abre o arquivo em modo de adição (append)
        if (fp == NULL) {
            perror("Erro ao abrir o arquivo");
            exit(1);
        }

        fprintf(fp, "%s\n", nome_paciente); // Escreve o nome no arquivo, seguido de nova linha
        fclose(fp); // Fecha o arquivo
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

void salvar_cpf_paciente(char *cpf_paciente){
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

