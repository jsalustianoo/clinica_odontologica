#include <stdio.h>
#include <stdlib.h>

//Assinatura das funcoes
void menu_principal (void);
void cadastramento_paciente (void);
void cadastramento_dentista (void);
void menu_paciente (void);
void menu_agendamento (void);
void agendar (void);

int main(int argc, char const *argv[]) {
	menu_principal();
	cadastramento_paciente();
	cadastramento_dentista();
	menu_paciente();
	menu_agendamento();
	agendar();

    printf("=================================================================\n");
    printf("-----                  Area dos Dentistas                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Cadastrar dentista                                -----\n");
    printf("----- 2 - Visualizar dados de um dentista                   -----\n");
    printf("----- 3 - Editar dentista                                   -----\n");
    printf("----- 4 - Excluir dentista                                  -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
    

    printf("=================================================================\n");
    printf("-----                  Area de Relatorios                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Todos os agendamentos                             -----\n");
    printf("----- 2 - Todos os pacientes                                -----\n");
    printf("----- 3 - Todos os dentistas                                -----\n");
    printf("----- 4 - Todos os agendamentos por dentista                -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");


    printf("=================================================================\n");
    printf("-----                  Area de Informacoes                  -----\n");
    printf("=================================================================\n");
    printf("-----                   Projeto SIG-Dentistry:                   \n");                   
    printf("-----       Sistema de Agendamento para Clínicas Dentárias       \n");                   
    printf("-----    Desenvolvido por: José Salustiano e Raul Araújo    -----\n");
    printf("=================================================================\n");

    return 0;
}

void menu_principal (void) {
    printf("=================================================================\n");
    printf("------                Clinica Odontologica                 ------\n");
    printf("=================================================================\n");
    printf("-----                1 - Area de Agendamentos               -----\n");
    printf("-----                2 - Area dos Pacientes                 -----\n");
    printf("-----                3 - Area dos Dentistas                 -----\n"); 
    printf("-----                4 - Area de Relatorios                 -----\n");
    printf("-----                5 - Area de Informacoes                -----\n");
    printf("-----                0 - Sair                               -----\n");
    printf("=================================================================\n");
}

void cadastramento_paciente (void) {
    printf("=================================================================\n");
    printf("------                 Cadastro de Paciente                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: \n");
    printf("     - CPF: \n");
    printf("     - Telefone: \n"); 
    printf("     - Data de nascimento: \n");
    printf("     - Doenças: \n");
    printf("     - Contra indicacao de remedios: \n");
    printf("=================================================================\n");
    printf("-----            Paciente cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
}

void cadastramento_dentista (void) {
    printf("=================================================================\n");
    printf("------                 Cadastro de Dentista                ------\n");
    printf("=================================================================\n");
    printf("     - Nome: \n");
    printf("     - CPF: \n");
    printf("     - Telefone: \n"); 
    printf("     - Data de nascimento: \n");
    printf("     - Especialidade: \n");
    printf("     - Número do CRO: \n");
    printf("=================================================================\n");
    printf("-----            Dentista cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
}

void menu_paciente (void) {
	printf("=================================================================\n");
    printf("-----                      Bem-Vindo                        -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Agendamentos                                      -----\n");
	printf("----- 2 - Ver cadastro                                      -----\n");
    printf("----- 3 - Editar cadastro                                   -----\n");
    printf("----- 4 - Excluir cadastro                                  -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
}

void menu_agendamento (void) {
    printf("=================================================================\n");
    printf("-----                 Area dos Agendamentos                 -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Realizar agendamento                              -----\n");
    printf("----- 2 - Visualizar agendamentos                           -----\n");
    printf("----- 3 - Editar agendamento                                -----\n");
    printf("----- 4 - Excluir agendamento                               -----\n");
    printf("----- 0 - Retornar ao menu anterior                         -----\n");
    printf("=================================================================\n");
}

void agendar (void) {
    printf("=================================================================\n");
    printf("------                 Realizar Agendamento                ------\n");
    printf("=================================================================\n");
    printf("     - ID: \n");
    printf("     - Nome: \n");
    printf("     - CPF: \n"); 
    printf("     - Data: \n");
    printf("     - Horário: \n");
    printf("     - Situação: \n");
    printf("     - O que foi feito: \n");
    printf("     - Pagamento: \n");
    printf("=================================================================\n");
    printf("-----           Agendamento realizado com sucesso           -----\n");
    printf("=================================================================\n");
}