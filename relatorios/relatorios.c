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
        printf("=================================================================================\n");
        printf("------                         Área de Relatórios                          ------\n");
        printf("=================================================================================\n");
        printf("------      (1) - Todos os Agendamentos                                    ------\n");
        printf("------      (2) - Todos os Pacientes                                       ------\n");
        printf("------      (3) - Todos os Dentistas                                       ------\n");
        printf("------      (4) - Todos os Agendamentos por Dentista                       ------\n");
        printf("------      (0) - Retornar ao Menu Principal                               ------\n");
        printf("=================================================================================\n");
        printf("      - (Opção desejada): ");
        scanf("%d", &opcao_relatorios);
        getchar();
        switch (opcao_relatorios) {
            case 0:
                break;
            case 3:
                exibir_todos_dentistas();
                break;
            default:
                printf("Número digitado não condiz com nenhuma opção do sistema!");
                break;
        }
    } while (opcao_relatorios != 0);
}

void exibir_todos_dentistas(void) {
    char nome[100], cpf[15], telefone[20], especialidades[100], cro[20];
    int contador = 0;

    system("clear||cls");
    printf("\n=================================================================================\n");
    printf("------                     Lista de Todos os Dentistas                        ------\n");
    printf("=================================================================================\n");

    FILE *arquivo = fopen("dentistas.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    // Lê o arquivo linha por linha e exibe os dados de cada dentista
    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(especialidades, sizeof(especialidades), arquivo);
        fgets(cro, sizeof(cro), arquivo);

        // Remove possíveis quebras de linha dos dados lidos
        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        telefone[strcspn(telefone, "\n")] = '\0';
        especialidades[strcspn(especialidades, "\n")] = '\0';
        cro[strcspn(cro, "\n")] = '\0';

        contador++;
        printf("Dentista #%d\n", contador);
        printf("Nome: %s\n", nome);
        printf("CPF: %s\n", cpf);
        printf("Telefone: %s\n", telefone);
        printf("Especialidade(s): %s\n", especialidades);
        printf("Número do CRO: %s\n", cro);
        printf("---------------------------------------------------------------------------------\n");
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("\nNenhum dentista cadastrado.\n");
    }

    printf("\n=================================================================================\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}
