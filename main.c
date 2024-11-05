#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes/validacoes.h"

void menu_principal (void);

void informacoes (void); 

int main() {
    int opcao_principal;
    do{
	    menu_principal();
        scanf("%d", &opcao_principal);
        getchar();
        switch (opcao_principal){
            case 0:
                printf("Desligando sistema...");
                exit(0);
            case 1:
                menu_agendamento();
                break;
            case 2:
                menu_paciente();
                break;
            case 3:
                menu_dentista();
                break;
            case 4:
                relatorios();
                break;
            case 5:
                informacoes();
                break;
            default:
                printf("Número digitado não condiz com nenhuma opção do sistema");
            break;
        }
    } while(opcao_principal != 0);

    return 0;
}

void menu_principal (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("-----                  SIG-Dentistry: Clínica Odontológica                  -----\n");
    printf("=================================================================================\n");
    printf("-----                     (1) - Módulo dos Agendamentos                     -----\n");
    printf("-----                     (2) - Módulo dos Pacientes                        -----\n");
    printf("-----                     (3) - Módulo dos Dentistas                        -----\n"); 
    printf("-----                     (4) - Módulo dos Relatorios                       -----\n");
    printf("-----                     (5) - Módulo das Informacoes                      -----\n");
    printf("-----                     (0) - Desligar sistema                            -----\n");
    printf("=================================================================================\n");
    printf("      - (Opcao desejada): ");
}

void informacoes (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Área de Informações                         ------\n");
    printf("=================================================================================\n");
    printf("------                       Projeto SIG-Dentistry:                        ------\n");                   
    printf("------           Sistema de Agendamento para Clínicas Dentárias            ------\n");                   
    printf("------           Desenvolvido por: José Salustiano e Raul Araujo           ------\n");
    printf("=================================================================================\n");
    getchar();
    printf("Tecle <ENTER> para continuar...");
}