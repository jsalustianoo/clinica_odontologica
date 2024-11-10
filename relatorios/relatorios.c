#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void relatorios(void) {
    int opcao_relatorios;
    do{
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
    } while (opcao_relatorios != 0);
    
}
