#include <stdio.h>
#include <stdlib.h>

void menu_principal (void); // Menu Principal

// Módulo Agendamento
void menu_agendamento (void);
void agendar (void);

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

void informacoes (void); // Módulo Informações
void relatorios (void); // Módulo Relatórios

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
    printf("\n=================================================================\n");
    printf("------                Clinica Odontologica                 ------\n");
    printf("=================================================================\n");
    printf("-----                1 - Area de Agendamentos               -----\n");
    printf("-----                2 - Area dos Pacientes                 -----\n");
    printf("-----                3 - Area dos Dentistas                 -----\n"); 
    printf("-----                4 - Area de Relatorios                 -----\n");
    printf("-----                5 - Area de Informacoes                -----\n");
    printf("-----                0 - Desligar Sistema                   -----\n");
    printf("=================================================================\n");
    printf("     - Opcao desejada: ");
}

void menu_agendamento (void) {
    printf("\n=================================================================\n");
    printf("-----                 Menu Agendamentos                 -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Realizar agendamento                              -----\n");
    printf("----- 2 - Visualizar agendamentos                           -----\n");
    printf("----- 3 - Editar agendamento                                -----\n");
    printf("----- 4 - Excluir agendamento                               -----\n");
    printf("----- 0 - Retornar ao menu anterior                         -----\n");
    printf("=================================================================\n");
}

void agendar (void) {
    printf("\n=================================================================\n");
    printf("------                 Realizar Agendamento                ------\n");
    printf("=================================================================\n");
    printf("     - ID: \n");
    printf("     - Nome: \n");
    printf("     - CPF: \n"); 
    printf("     - Data: \n");
    printf("     - Horario: \n");
    printf("     - Situacao: \n");
    printf("     - Pagamento: \n");
    printf("\n-----           Agendamento realizado com sucesso           -----\n");
    printf("=================================================================\n");
}

void menu_paciente (void) {
	printf("\n=================================================================\n");
    printf("-----                  Menu dos Pacientes                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Agendamentos                                      -----\n");
	printf("----- 2 - Perfil                                            -----\n");
    printf("----- 3 - Editar paciente                                   -----\n");
    printf("----- 4 - Excluir paciente                                  -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
}

void cadastro_paciente (void) {
    //variaveis
    char nome[70], cpf[11], telefone[11], doencas[250], alergias[250], nascimento[8];
    printf("\n=================================================================\n");
    printf("------                 Cadastro de Paciente                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    scanf("%s", &nome);
    getchar();
    printf("     - Data de nascimento: ");
    scanf("%s", &nascimento);
    getchar();
    printf("     - CPF: ");
    scanf("%s", &cpf);
    getchar();
    printf("     - Telefone: "); 
    scanf("%s", &telefone);
    getchar();
    printf("     - Doencas preexistentes: ");
    scanf("%s", &doencas);
    getchar();
    printf("     - Contra indicacao de remedios: ");
    scanf("%s", &alergias);
    getchar();
    printf("\n-----            Paciente cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
}

void exibir_dados_paciente (void) {
    printf("\n=================================================================\n");
    printf("------                 Dados de um Paciente                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    printf("     - Data de nascimento: ");
    printf("     - CPF: ");
    printf("     - Telefone: "); 
    printf("     - Doencas preexistentes: ");
    printf("     - Contra indicacao de remedios: ");
    printf("\n-----            Paciente cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
}

void editar_paciente (void) {
    //variaveis
    char nome, cpf, telefone, doencas, alergias, nascimento;
    printf("\n=================================================================\n");
    printf("------                 Editar de Paciente                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    scanf("%s", &nome);
    getchar();
    printf("     - Data de nascimento: ");
    scanf("%s", &nascimento);
    getchar();
    printf("     - CPF: ");
    scanf("%s", &cpf);
    getchar();
    printf("     - Telefone: "); 
    scanf("%s", &telefone);
    getchar();
    printf("     - Doencas preexistentes: ");
    scanf("%s", &doencas);
    getchar();
    printf("     - Contra indicacao de remedios: ");
    scanf("%s", &alergias);
    getchar();
    printf("\n-----            Paciente cadastrado com sucesso            -----\n");
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
        printf("n\n-----     O numero digitado n�o corresponde a nenhuma funcao!    -----\n");
    } else if (confirmacao == 0){
        printf("n\n-----     Operacao cancelada!    -----\n");
    } else{
        printf("n\n-----     Paciente excluido com sucesso!    -----\n");
    }
    printf("=================================================================\n");
}

void menu_dentista(void) {
    char op;
    printf("\n=================================================================\n");
    printf("-----                  Menu dos Dentistas                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Cadastrar novo dentista                           -----\n");
    printf("----- 2 - Visualizar dados de um dentista                   -----\n");
    printf("----- 3 - Editar dados de um dentista                       -----\n");
    printf("----- 4 - Excluir dentista                                  -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
}

void cadastro_dentista (void) {
    //variaveis
    char nome, cpf, telefone, especialidade, cro;
    printf("\n=================================================================\n");
    printf("------                 Cadastro de Dentista                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    scanf("%s", &nome);
    getchar();
    printf("     - CPF: ");
    scanf("%s", &cpf);
    getchar();
    printf("     - Telefone: "); 
    scanf("%s", &telefone);
    getchar();
    printf("     - Especialidade: "); 
    scanf("%s", &especialidade);
    getchar();
    printf("     - Numero do CRO: "); 
    scanf("%s", &cro);
    getchar();
    printf("\n-----            Dentista cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
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
    printf("\n-----            Dentista cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
}

void editar_dentista (void) {
    char nome, cpf, telefone, especialidade, cro; //variaveis

    printf("\n=================================================================\n");
    printf("------              Editar dados de um Dentista            ------\n");
    printf("=================================================================\n");
    printf("     - Nome: ");
    scanf("%s", &nome);
    getchar();
    printf("     - CPF: ");
    scanf("%s", &cpf);
    getchar();
    printf("     - Telefone: "); 
    scanf("%s", &telefone);
    getchar();
    printf("     - Especialidade: "); 
    scanf("%s", &especialidade);
    getchar();
    printf("     - Numero do CRO: "); 
    scanf("%s", &cro);
    getchar();
    printf("\n\n-----     Dados do(a) dentista editados com sucesso!    -----\n");
    printf("=================================================================\n");
}

void excluir_dentista (void) {
    int confirmacao; //variaveis
    char nome, cpf, telefone, especialidade, cro; //variaveis

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
        printf("n\n-----     O numero digitado n�o corresponde a nenhuma funcao!    -----\n");
    } else if (confirmacao == 0){
        printf("n\n-----     Operacao cancelada!    -----\n");
    } else{
        printf("n\n-----     Dentista excluido com sucesso!    -----\n");
    }
    printf("=================================================================\n");
}

void relatorios(void) {
    printf("\n=================================================================\n");
    printf("-----                  Area de Relatorios                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Todos os agendamentos                             -----\n");
    printf("----- 2 - Todos os pacientes                                -----\n");
    printf("----- 3 - Todos os dentistas                                -----\n");
    printf("----- 4 - Todos os agendamentos por dentista                -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
}

void informacoes (void) {
    printf("\n=================================================================\n");
    printf("-----                  Area de Informacoes                  -----\n");
    printf("=================================================================\n");
    printf("-----                   Projeto SIG-Dentistry:                   \n");                   
    printf("-----       Sistema de Agendamento para Clinicas Dentarias       \n");                   
    printf("-----    Desenvolvido por: Jose Salustiano e Raul Araujo    -----\n");
    printf("=================================================================\n");
}