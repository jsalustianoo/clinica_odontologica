#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorios.h"
#include "../dentistas/dentistas.h"

void relatorios(void) {
    int opcao_relatorios;

        system("clear||cls");
        printf("\n");
        printf("===================================================================================\n");
        printf("------                          Área de Relatórios                           ------\n");
        printf("===================================================================================\n");
        printf("------                                                                       ------\n");
        printf("------                   |1| - Agendamentos do Dia                           ------\n");
        printf("------                   |2| - Todos os Agendamentos                         ------\n");
        printf("------                   |3| - Agendamentos por Dentista                     ------\n");
        printf("------                                                                       ------\n");
        printf("------                   |4| - Todos os Pacientes                            ------\n");
        printf("------                   |5| - Pacientes por Ordem Alfabética                ------\n");
        printf("------                                                                       ------\n");
        printf("------                   |6| - Todos os Dentistas                            ------\n");
        printf("------                   |7| - Dentistas por Ordem Alfabética                ------\n");
        printf("------                   |0| - Retornar ao Menu Principal                    ------\n");
        printf("------                                                                       ------\n");
        printf("===================================================================================\n");
        printf("- (Opção desejada): ");
        scanf("%d", &opcao_relatorios);
        getchar();
}
