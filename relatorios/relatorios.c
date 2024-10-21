#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void relatorios(void) {
    int opcao_relatorios;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("------                         Area de Relatorios                          ------\n");
        printf("=================================================================================\n");
        printf("------      (1) - Todos os agendamentos                                    ------\n");
        printf("------      (2) - Todos os pacientes                                       ------\n");
        printf("------      (3) - Todos os dentistas                                       ------\n");
        printf("------      (4) - Todos os agendamentos por dentista                       ------\n");
        printf("------      (0) - Retornar ao Menu Principal                               ------\n");
        printf("=================================================================================\n");
        printf("      - (Opcao desejada): ");
        scanf("%d", &opcao_relatorios);
        getchar();
    } while (opcao_relatorios != 0);
    
}
