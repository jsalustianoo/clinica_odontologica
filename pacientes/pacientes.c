#include <stdio.h>
#include <stdlib.h>
#include "pacientes.h"

void menu_paciente(void) {
    int opcao_paciente;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("------                         Menu dos Pacientes                          ------\n");
        printf("=================================================================================\n");
        printf("------        (1) - Cadastrar novo paciente                                ------\n");
        printf("------        (2) - Visualizar dados de um paciente                        ------\n");
        printf("------        (3) - Editar dados de um paciente                            ------\n");
        printf("------        (4) - Excluir paciente                                       ------\n");
        printf("------        (0) - Retornar ao Menu Principal                             ------\n");
        printf("=================================================================================\n");
        printf("    - (Opcao desejada): ");
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
                printf("Numero digitado nao condiz com nenhuma opcao do sistema");
            break;
        }
    }while(opcao_paciente != 0);
}
void cadastro_paciente (void) {
    char nome[100], data_nascimento[13], cpf[13], telefone[13], doencas[200], contraindicacao[200];
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Cadastro de Paciente                        ------\n");
    printf("=================================================================================\n");
    printf("\n        - (Nome): ");
    scanf("%s", nome);
    getchar();
    printf("\n        - (Data de nascimento): ");
    scanf("%s", data_nascimento);
    getchar();
    printf("\n        - (CPF): ");
    scanf("%s", cpf);
    getchar();
    printf("\n        - (Telefone): "); 
    scanf("%s", telefone);
    getchar();
    printf("\n        - (Doencas preexistentes): ");
    scanf("%s", doencas);
    getchar();
    printf("\n        - (Contra indicacao de remedios): ");
    scanf("%s", contraindicacao);
    getchar();
    printf("=================================================================================\n");
    printf("------                    Paciente cadastrado com sucesso                   -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...\n");
    getchar();
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
    printf("------      (Contra indicacao de remedios):                                  ------");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void editar_paciente (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                          Editar de Paciente                         ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (Data de nascimento):                                          ------\n");
    printf("------      (CPF):                                                         ------\n");
    printf("------      (Telefone):                                                    ------\n"); 
    printf("------      (Doencas preexistentes):                                       ------\n");
    printf("------      (Contra indicacao de remedios):                                ------\n");
    printf("=================================================================================\n");
    printf("------              Dados do(a) Paciente editados com sucesso!             ------\n");
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
    printf("------      (Doencas preexistentes):                                       ------\n");
    printf("------      (Contra indicacao de remedios):                                ------\n");
    printf("------                                                                     ------\n"); 
    printf("------     Tem certeza que deseja excluir esse paciente? (S)IM | (N)AO     ------\n");

    scanf(" %c", &confirmacao);
    if (confirmacao == 'S' || confirmacao == 's'){
        printf("------                   Paciente excluído com sucesso!                    ------\n");
    } else if (confirmacao == 'N' || confirmacao == 'n'){
        printf("------                        Operacao cancelada!                          ------\n");
    } else{
        printf("------      Numero digitado nao condiz com nenhuma opcao do sistema        ------\n");
    }                     
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}
