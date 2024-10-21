#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_principal (void);

void informacoes (void); 
void relatorios (void); 

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
                printf("Numero digitado nao condiz com nenhuma opcao do sistema");
            break;
        }
    } while(opcao_principal != 0);

    return 0;
}

void menu_principal (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("-----                  SIG-Dentistry: Clinica Odontologica                  -----\n");
    printf("=================================================================================\n");
    printf("-----                     (1) - Modulo dos Agendamentos                     -----\n");
    printf("-----                     (2) - Modulo dos Pacientes                        -----\n");
    printf("-----                     (3) - Modulo dos Dentistas                        -----\n"); 
    printf("-----                     (4) - Modulo dos Relatorios                       -----\n");
    printf("-----                     (5) - Modulo das Informacoes                      -----\n");
    printf("-----                     (0) - Desligar sistema                            -----\n");
    printf("=================================================================================\n");
    printf("      - (Opcao desejada): ");
}



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

void informacoes (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Area de Informacoes                         ------\n");
    printf("=================================================================================\n");
    printf("------                       Projeto SIG-Dentistry:                        ------\n");                   
    printf("------           Sistema de Agendamento para Clinicas Dentarias            ------\n");                   
    printf("------           Desenvolvido por: Jose Salustiano e Raul Araujo           ------\n");
    printf("=================================================================================\n");
    getchar();
    printf("Tecle <ENTER> para continuar...");
}