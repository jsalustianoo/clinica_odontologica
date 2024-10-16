#include <stdio.h>
#include <stdlib.h>

void menu_principal (void); 

// Módulo Agendamento
void menu_agendamento (void);
void agendar (void);
void exibir_dados_agendamento (void);
void editar_agendamento (void);
void excluir_agendamento (void);

// Módulo Pacientes
void menu_paciente (void);
void cadastro_paciente (void);
void exibir_dados_paciente (void);
void editar_paciente (void);
void excluir_paciente (void);

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
    printf("-----                      1 - Modulo dos Agendamentos                      -----\n");
    printf("-----                      2 - Modulo dos Pacientes                         -----\n");
    printf("-----                      3 - Modulo dos Dentistas                         -----\n"); 
    printf("-----                      4 - Modulo dos Relatorios                        -----\n");
    printf("-----                      5 - Modulo das Informacoes                       -----\n");
    printf("-----                      0 - Fechar sistema                               -----\n");
    printf("=================================================================================\n");
    printf("     - Opcao desejada: ");
}

void menu_agendamento (void) {
    int opcao_agendamento;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("-----                           Menu Agendamentos                           -----\n");
        printf("=================================================================================\n");
        printf("-----      (1) Realizar agendamento                                         -----\n");
        printf("-----      (2) Visualizar agendamentos                                      -----\n");
        printf("-----      (3) Editar agendamento                                           -----\n");
        printf("-----      (4) Excluir agendamento                                          -----\n");
        printf("-----      (0) Retornar ao menu anterior                                    -----\n");
        printf("=================================================================================\n");

        scanf("%d", &opcao_agendamento);
        getchar();
        switch (opcao_agendamento) {
            case 0:
                break;
            case 1:
                agendar();
                break;
            case 2:
                exibir_dados_agendamento();
                break;
            case 3:
                editar_agendamento();
                break;
            case 4:
                excluir_agendamento();
                break;
            default:
                printf("Numero digitado nao condiz com nenhuma opcao do sistema");
            break;
        }
    }while(opcao_agendamento != 0);

}

void agendar (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Realizar Agendamento                        ------\n");
    printf("=================================================================================\n");
    printf("------      (ID):                                                          ------\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (CPF):                                                         ------\n"); 
    printf("------      (Data):                                                        ------\n");
    printf("------      (Horario):                                                     ------\n");
    printf("------      (Situacao):                                                    ------\n");
    printf("------      (Pagamento):                                                   ------\n");
    printf("=================================================================================\n");
    printf("------                 Agendamento realizado com sucesso!                  ------\n");
    printf("=================================================================================\n");
    getchar();
}

void exibir_dados_agendamento (void) {
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                       Dados de um Agendamento                       ------\n");
    printf("=================================================================================\n");
    printf("------      (ID do Agendamento):                                           ------\n");
    printf("------                                                                     ------\n");
    printf("------      (Nome):                                                        ------\n");
    printf("------      (CPF):                                                         ------\n"); 
    printf("------      (Data):                                                        ------\n");
    printf("------      (Horario):                                                     ------\n");
    printf("------      (Situacao):                                                    ------\n");
    printf("------      (Pagamento):                                                   ------\n");
    printf("=================================================================================\n");
    getchar();
}
void editar_agendamento (void) {
    printf("\n=================================================================\n");
    printf("------                  Editar Agendamento                 ------\n");
    printf("=================================================================\n");
    printf("     - ID: \n");
    printf("     - Nome: \n");
    printf("     - CPF: \n"); 
    printf("     - Data: \n");
    printf("     - Horario: \n");
    printf("     - Situacao: \n");
    printf("     - Pagamento: \n");
    printf("\n-----      Dados do Agendamento editados com sucesso!     -----\n");
    printf("=================================================================\n");
}

void excluir_agendamento (void) {
	printf("\n=================================================================\n");
    printf("-----                  Excluir Agendamento                  -----\n");
    printf("=================================================================\n");
    printf("     - ID: \n");
    printf("     - Nome: \n");
    printf("     - CPF: \n"); 
    printf("     - Data: \n");
    printf("     - Horario: \n");
    printf("     - Situacao: \n");
    printf("     - Pagamento: \n");                      
    printf("=================================================================\n");
}

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
    printf("        - (Nome): ");
    scanf("%s", nome);
    getchar();
    printf("        - (Data de nascimento): ");
    scanf("%s", data_nascimento);
    getchar();
    printf("        - (CPF): ");
    scanf("%s", cpf);
    getchar();
    printf("        - (Telefone): "); 
    scanf("%s", telefone);
    getchar();
    printf("        - (Doencas preexistentes): ");
    scanf("%s", doencas);
    getchar();
    printf("        - (Contra indicacao de remedios): ");
    scanf("%s", contraindicacao);
    getchar();
    printf("=================================================================================\n");
    printf("------                    Paciente cadastrado com sucesso                   -----\n");
    printf("=================================================================================\n");
    printf("Tecle <ENTER> para continuar...\n");
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
    getchar();
}

void editar_paciente (void) {
    printf("\n=================================================================\n");
    printf("------                  Editar de Paciente                 ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    printf("     - Data de nascimento: ");
    printf("     - CPF: ");
    printf("     - Telefone: "); 
    printf("     - Doencas preexistentes: ");
    printf("     - Contra indicacao de remedios: ");
    printf("\n-----      Dados do(a) Paciente editados com sucesso!     -----\n");
    printf("=================================================================\n");
}

void excluir_paciente (void) {
    int confirmacao;

    printf("\n=================================================================\n");
    printf("------                   Excluir Paciente                  ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    printf("     - Data de nascimento: ");
    printf("     - CPF: ");
    printf("     - Telefone: "); 
    printf("     - Doencas preexistentes: ");
    printf("     - Contra indicacao de remedios: ");
    printf("Tem certeza que deseja excluir esse paciente?");
    scanf("%d", &confirmacao);
    if (confirmacao != 0 || confirmacao != 1){
        printf("n\n-----     O numero digitado nao corresponde a nenhuma funcao!    -----\n");
    } else if (confirmacao == 0){
        printf("n\n-----     Operacao cancelada!    -----\n");
    } else{
        printf("n\n-----     Paciente excluido com sucesso!    -----\n");
    }
    printf("=================================================================\n");
}

void menu_dentista(void) {
    int opcao_dentista;
    do{
        system("clear||cls");
        printf("\n=================================================================\n");
        printf("-----                  Menu dos Dentistas                   -----\n");
        printf("=================================================================\n");
        printf("----- 1 - Cadastrar novo dentista                           -----\n");
        printf("----- 2 - Visualizar dados de um dentista                   -----\n");
        printf("----- 3 - Editar dados de um dentista                       -----\n");
        printf("----- 4 - Excluir dentista                                  -----\n");
        printf("----- 0 - Retornar ao Menu Principal                        -----\n");
        printf("=================================================================\n");
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
    printf("\n=================================================================\n");
    printf("------                 Cadastro de Dentista                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    printf("     - CPF: ");
    printf("     - Telefone: "); 
    printf("     - Especialidade: "); 
    printf("     - Numero do CRO: "); 
    printf("\n-----            Dentista cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
    getchar();
}

void exibir_dados_dentista (void) {
    printf("\n=================================================================\n");
    printf("------                 Dados de um Dentista                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    printf("     - CPF: ");
    printf("     - Telefone: "); 
    printf("     - Especialidade: "); 
    printf("     - Numero do CRO: "); 
    printf("=================================================================\n");
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
    getchar();
}

void excluir_dentista (void) {
    int confirmacao; //variaveis

    printf("\n=================================================================\n");
    printf("------                   Excluir Dentista                  ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    printf("     - CPF: ");
    printf("     - Telefone: "); 
    printf("     - Especialidade: "); 
    printf("     - Numero do CRO: "); 
    printf("Tem certeza que deseja excluir esse dentista?");
    scanf("%d", &confirmacao);
    if (confirmacao != 0 || confirmacao != 1){
        printf("n\n-----     O numero digitado nao corresponde a nenhuma funcao!    -----\n");
    } else if (confirmacao == 0){
        printf("n\n-----     Operacao cancelada!    -----\n");
    } else{
        printf("n\n-----     Dentista excluido com sucesso!    -----\n");
    }
    printf("=================================================================\n");
}

void relatorios(void) {
    int opcao_relatorios;
    do{
        system("clear||cls");
        printf("\n=================================================================\n");
        printf("-----                  Area de Relatorios                   -----\n");
        printf("=================================================================\n");
        printf("----- 1 - Todos os agendamentos                             -----\n");
        printf("----- 2 - Todos os pacientes                                -----\n");
        printf("----- 3 - Todos os dentistas                                -----\n");
        printf("----- 4 - Todos os agendamentos por dentista                -----\n");
        printf("----- 0 - Retornar ao Menu Principal                        -----\n");
        printf("=================================================================\n");
        printf("Opcao desejada: ");
        scanf("%d", &opcao_relatorios);
        getchar();
    } while (opcao_relatorios != 0);
    
}

void informacoes (void) {
    system("clear||cls");
    printf("\n=================================================================\n");
    printf("-----                  Area de Informacoes                  -----\n");
    printf("=================================================================\n");
    printf("-----                   Projeto SIG-Dentistry:                   \n");                   
    printf("-----       Sistema de Agendamento para Clinicas Dentarias       \n");                   
    printf("-----    Desenvolvido por: Jose Salustiano e Raul Araujo    -----\n");
    printf("=================================================================\n");
    getchar();
    printf("Tecle <ENTER> para continuar...");
}