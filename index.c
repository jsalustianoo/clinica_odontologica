#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_principal (void);

// Módulo Dentistas
void menu_dentista (void);
void cadastro_dentista (void);
void exibir_dados_dentista (void);
void editar_dentista (void);
void excluir_dentista (void);

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

void menu_dentista(void) {
    int opcao_dentista;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("-----                          Menu dos Dentistas                           -----\n");
        printf("=================================================================================\n");
        printf("------      (1) - Cadastrar novo dentista                                  ------\n");
        printf("------      (2) - Visualizar dados de um dentista                          ------\n");
        printf("------      (3) - Editar dados de um dentista                              ------\n");
        printf("------      (4) - Excluir dentista                                         ------\n");
        printf("------      (0) - Retornar ao Menu Principal                               ------\n");
        printf("=================================================================================\n");
        scanf("%d", &opcao_dentista);
        getchar();
        switch (opcao_dentista) {
            case 0:
                break;
            case 1:
                cadastro_dentista();
                break;
            case 2:
                exibir_dados_dentista();
                break;
            case 3:
                editar_dentista();
                break;
            case 4:
                excluir_dentista();
                break;
            default:
                printf("Numero digitado nao condiz com nenhuma opcao do sistema");
            break;
        }
    } while (opcao_dentista != 0);

}

void cadastro_dentista (void) {
    char nome[100], cpf[13], telefone[13], especialidade[30], cro[12];
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Cadastro de Dentista                        ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome): ");
    scanf("%s", nome);
    getchar();
    printf("------      (CPF): ");
    scanf("%s", cpf);
    getchar();
    printf("------      (Telefone): ");
    scanf("%s", telefone);
    getchar();
    printf("------      (Especialidade): ");
    scanf("%s", especialidade);
    getchar(); 
    printf("------      (Numero do CRO): ");
    scanf("%s", cro);
    getchar(); 
    printf("=================================================================================\n");
    printf("-----                  Dentista cadastrado(a) com sucesso!                  -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_dados_dentista (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                        Dados de um Dentista                         ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (CPF):                                                         ------\n");
    printf("------      (Telefone):                                                    ------\n"); 
    printf("------      (Especialidade):                                               ------\n"); 
    printf("------      (Numero do CRO):                                               ------\n"); 
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
}

void editar_dentista (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                      Editar dados de um Dentista                    ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                          ------");
    printf("------      (CPF):                                                           ------");
    printf("------      (Telefone):                                                      ------"); 
    printf("------      (Especialidade):                                                 ------"); 
    printf("------      (Numero do CRO):                                                 ------"); 
    printf("=================================================================================\n");
    printf("-----               Dados do(a) Dentista editados com sucesso!              -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void excluir_dentista (void) {
    char confirmacao; 

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                           Excluir Dentista                          ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                          ------");
    printf("------      (CPF):                                                           ------");
    printf("------      (Telefone):                                                      ------"); 
    printf("------      (Especialidade):                                                 ------"); 
    printf("------      (Numero do CRO):                                                 ------"); 
    printf("------                                                                     ------\n"); 
    printf("------     Tem certeza que deseja excluir esse paciente? (S)IM | (N)AO     ------\n");

    scanf(" %c", confirmacao);
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