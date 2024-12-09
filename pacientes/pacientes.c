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
void cadastro_paciente (void) {
    char nome_paciente[45];
    char cpf_paciente[14];
    char telefone_paciente[15];
    char doencas[200]; 
    char contraindicacao[200];
    int dia, mes, ano;

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Cadastro de Paciente                        ------\n");
    printf("=================================================================================\n");
    salvar_nome_paciente(nome_paciente);
    getchar();
    printf("\n        - (Data de nascimento): ");
    getchar();
    printf("\n        - (CPF): ");
    scanf("%s", cpf_paciente);
    getchar();
    printf("\n        - (Telefone): "); 
    scanf("%s", telefone_paciente);
    getchar();
    printf("\n        - (Doenças preexistentes): ");
    scanf("%s", doencas);
    getchar();
    printf("\n        - (Contra indição de remédio(s)): ");
    scanf("%s", contraindicacao);
    getchar();
    printf("=================================================================================\n");
    printf("------                    Paciente Cadastrado com Sucesso                   -----\n");
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
    printf("------      (Contra indicação de remédio(s)):                                  ------");
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
    printf("------      (Contra indicação de remédio(s)):                                ------\n");
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
