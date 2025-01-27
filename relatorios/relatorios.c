#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "../dentistas/dentistas.h"

void relatorios(void) {
    int opcao_relatorios;
    do {
        system("clear||cls");
        printf("\n");
        printf("===================================================================================\n");
        printf("------                          Área de Relatórios                           ------\n");
        printf("===================================================================================\n");
        printf("------                                                                       ------\n");
        printf("------                   |1| - Todos os Agendamentos                         ------\n");
        printf("------                                                                       ------\n");
        printf("------                   |2| - Todos os Pacientes                            ------\n");
        printf("------                   |3| - Pacientes por Ordem Alfabética                ------\n");
        printf("------                                                                       ------\n");
        printf("------                   |4| - Todos os Dentistas                            ------\n");
        printf("------                   |5| - Dentistas por Ordem Alfabética                ------\n");
        printf("------                   |0| - Retornar ao Menu Principal                    ------\n");
        printf("------                                                                       ------\n");
        printf("===================================================================================\n");
        printf("- (Opção desejada): ");
        scanf("%d", &opcao_relatorios);
        getchar();
        switch (opcao_relatorios) {
            case 0:
                break;
            case 1:
                todos_os_agendamentos();
                break;
            case 2:
                exibir_todos_pacientes();
                break;
            case 3:
                exibir_pacientes_por_ordem_alfabetica();
                break;
            case 4:
                exibir_todos_dentistas();
                break;
            case 5:
                exibir_dentistas_por_ordem_alfabetica();
                break;
            default:
                printf("Número digitado não condiz com nenhuma opção do sistema!");
                break;
        }
    } while (opcao_relatorios != 0);
}


void todos_os_agendamentos(void) {
    char id[10], cpf_paci[12], nome_paci[50], cpf_dent[12], nome_dent[50], data_agendamento[11], horario[6], pagamento[20], situacao[20];
    int contador = 0;

    system("clear||cls");
    printf("\n");
    printf("===================================================================================\n");
    printf("------                          Todos os Agendamentos                        ------\n");
    printf("===================================================================================\n");

    FILE *arquivo = fopen("agendamentos.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    // Lê o arquivo linha por linha e exibe os dados de cada agendamento
    while (fscanf(arquivo, "%s\n%s\n%[^\n]\n%s\n%[^\n]\n%s\n%s\n%s\n%s\n", 
                  id, 
                  cpf_paci, 
                  nome_paci, 
                  cpf_dent, 
                  nome_dent, 
                  data_agendamento, 
                  horario, 
                  pagamento, 
                  situacao) != EOF) {

        contador++;
        
        printf("    - ID do Agendamento: %s\n", id);
        printf("    - CPF Paciente: %s\n", cpf_paci);
        printf("    - Nome Paciente: %s\n", nome_paci);
        printf("    - CPF Dentista: %s\n", cpf_dent);
        printf("    - Nome Dentista: %s\n", nome_dent);
        printf("    - Data do Agendamento: %s\n", data_agendamento);
        printf("    - Horário: %s\n", horario);
        printf("    - Pagamento: %s\n", pagamento);
        printf("    - Situação: %s\n", situacao);
        printf("-----------------------------------------------------------------------------------\n");
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("\nNenhum agendamento encontrado.\n");
    }

    printf("===================================================================================\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}


void agendamentos_por_dentista(void){
    system("clear||cls");
    printf("\n");
    printf("===================================================================================\n");
    printf("------                        < Em desenvolvimento >                         ------\n");
    printf("===================================================================================\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_todos_pacientes(void) {
    char nome[100], cpf[15], telefone[20], doencas_preexistentes[100], contraindicacao[20];
    int contador = 0;

    system("clear||cls");
    printf("\n");
    printf("===================================================================================\n");
    printf("------                          Todos os Pacientes                           ------\n");
    printf("===================================================================================\n");

    FILE *arquivo = fopen("pacientes.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    // Lê o arquivo linha por linha e exibe os dados de cada dentista
    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(doencas_preexistentes, sizeof(doencas_preexistentes), arquivo);
        fgets(doencas_preexistentes, sizeof(doencas_preexistentes), arquivo);
        fgets(contraindicacao, sizeof(contraindicacao), arquivo);

        // Remove possíveis quebras de linha dos dados lidos
        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        telefone[strcspn(telefone, "\n")] = '\0';
        doencas_preexistentes[strcspn(doencas_preexistentes, "\n")] = '\0';
        contraindicacao[strcspn(contraindicacao, "\n")] = '\0';

        contador++;
        printf("    - Nome: %s\n", nome);
        printf("    - CPF: %s\n", cpf);
        printf("    - Telefone: %s\n", telefone);
        printf("    - Doença(s) preexistentes(s): %s\n", doencas_preexistentes);
        printf("    - Contraindicacao: %s\n", contraindicacao);
        printf("-----------------------------------------------------------------------------------\n");
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("\nNenhum paciente cadastrado.\n");
    }

    printf("===================================================================================\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_pacientes_por_ordem_alfabetica(void) {
    char nome[100], cpf[15], telefone[20], doencas_preexistentes[100], contraindicacao[20];
    char pacientes[100][100]; 
    int contador = 0;

    system("clear||cls");
    printf("\n");
    printf("===================================================================================\n");
    printf("------                Todos os Pacientes por Ordem Alfabética                ------\n");
    printf("===================================================================================\n");

    FILE *arquivo = fopen("pacientes.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(doencas_preexistentes, sizeof(doencas_preexistentes), arquivo);
        fgets(doencas_preexistentes, sizeof(doencas_preexistentes), arquivo);
        fgets(contraindicacao, sizeof(contraindicacao), arquivo);

        nome[strcspn(nome, "\n")] = '\0';
        strcpy(pacientes[contador], nome);
        contador++;
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("\nNenhum paciente cadastrado.\n");
    } else {
        for (int i = 0; i < contador - 1; i++) {
            for (int j = i + 1; j < contador; j++) {
                if (strcmp(pacientes[i], pacientes[j]) > 0) {
                    char temp[100];
                    strcpy(temp, pacientes[i]);
                    strcpy(pacientes[i], pacientes[j]);
                    strcpy(pacientes[j], temp);
                }
            }
        }

        for (int i = 0; i < contador; i++) {
            printf("    - Nome: %s\n", pacientes[i]);
        }
    }

    printf("===================================================================================\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}


void exibir_todos_dentistas(void) {
    char nome[100], cpf[15], telefone[20], especialidades[100], cro[20];
    int contador = 0;

    system("clear||cls");
    printf("\n");
    printf("===================================================================================\n");
    printf("------                          Todos os Dentistas                           ------\n");
    printf("===================================================================================\n");

    FILE *arquivo = fopen("dentistas.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(especialidades, sizeof(especialidades), arquivo);
        fgets(cro, sizeof(cro), arquivo);

        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        telefone[strcspn(telefone, "\n")] = '\0';
        especialidades[strcspn(especialidades, "\n")] = '\0';
        cro[strcspn(cro, "\n")] = '\0';

        contador++;
        printf("    - Nome: %s\n", nome);
        printf("    - CPF: %s\n", cpf);
        printf("    - Telefone: %s\n", telefone);
        printf("    - Especialidade(s): %s\n", especialidades);
        printf("    - Número do CRO: %s\n", cro);
        printf("-----------------------------------------------------------------------------------\n");
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("\nNenhum dentista cadastrado.\n");
    }

    printf("===================================================================================\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}


void exibir_dentistas_por_ordem_alfabetica(void) {
    char nome[100], cpf[15], telefone[20], especialidades[100], cro[20];
    char dentistas[100][100];
    char dados_dentistas[100][5][100];  // Armazenar os dados dos dentistas (nome, cpf, telefone, especialidades, cro)
    int contador = 0;

    system("clear||cls");
    printf("\n");
    printf("===================================================================================\n");
    printf("------                Todos os Dentistas por Ordem Alfabética                ------\n");
    printf("===================================================================================\n");

    FILE *arquivo = fopen("dentistas.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    // Lê todos os dentistas do arquivo e armazena as informações
    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(especialidades, sizeof(especialidades), arquivo);
        fgets(cro, sizeof(cro), arquivo);

        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        telefone[strcspn(telefone, "\n")] = '\0';
        especialidades[strcspn(especialidades, "\n")] = '\0';
        cro[strcspn(cro, "\n")] = '\0';

        // Armazena os dados do dentista
        strcpy(dentistas[contador], nome);
        strcpy(dados_dentistas[contador][0], nome);
        strcpy(dados_dentistas[contador][1], cpf);
        strcpy(dados_dentistas[contador][2], telefone);
        strcpy(dados_dentistas[contador][3], especialidades);
        strcpy(dados_dentistas[contador][4], cro);
        
        contador++;
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("\nNenhum dentista cadastrado.\n");
    } else {
        // Ordena os dentistas por nome (ordem alfabética)
        for (int i = 0; i < contador - 1; i++) {
            for (int j = i + 1; j < contador; j++) {
                if (strcmp(dentistas[i], dentistas[j]) > 0) {
                    // Troca os nomes
                    char temp_nome[100];
                    strcpy(temp_nome, dentistas[i]);
                    strcpy(dentistas[i], dentistas[j]);
                    strcpy(dentistas[j], temp_nome);

                    // Troca os dados relacionados ao dentista
                    char temp_dados[5][100];
                    for (int k = 0; k < 5; k++) {
                        strcpy(temp_dados[k], dados_dentistas[i][k]);
                        strcpy(dados_dentistas[i][k], dados_dentistas[j][k]);
                        strcpy(dados_dentistas[j][k], temp_dados[k]);
                    }
                }
            }
        }

        // Exibe os dentistas ordenados
        for (int i = 0; i < contador; i++) {
            printf("    - Nome: %s\n", dados_dentistas[i][0]);
            printf("    - CPF: %s\n", dados_dentistas[i][1]);
            printf("    - Telefone: %s\n", dados_dentistas[i][2]);
            printf("    - Especialidade(s): %s\n", dados_dentistas[i][3]);
            printf("    - Número do CRO: %s\n", dados_dentistas[i][4]);
            printf("-----------------------------------------------------------------------------------\n");
        }
    }

    printf("===================================================================================\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

