#include <stdio.h>
#include <stdlib.h>

//Assinatura das funcoes
void menu_principal (void);
void cadastramento_paciente (void);
void cadastramento_dentista (void);
void menu_paciente (void);
void menu_dentista (void);
void menu_agendamento (void);
void agendar (void);
void informacoes (void);
void relatorios(void);

int main(int argc, char const *argv[]) {
	menu_principal();
	cadastramento_paciente();
	cadastramento_dentista();
	menu_paciente();
    menu_dentista();
	menu_agendamento();
	agendar();
    informacoes();
    relatorios();

    return 0;
}

void menu_principal (void) {
    char op;
    printf("\n=================================================================\n");
    printf("------                Clinica Odontologica                 ------\n");
    printf("=================================================================\n");
    printf("-----                1 - Area de Agendamentos               -----\n");
    printf("-----                2 - Area dos Pacientes                 -----\n");
    printf("-----                3 - Area dos Dentistas                 -----\n"); 
    printf("-----                4 - Area de Relatorios                 -----\n");
    printf("-----                5 - Area de Informacoes                -----\n");
    printf("-----                0 - Sair                               -----\n");
    printf("=================================================================\n");
    printf("     - Informe a opcao desejada: ");
    scanf ("%c", &op);
    getchar();
    return op;
}

void cadastramento_paciente (void) {
    //variaveis
    char nome, cpf, telefone, doencas, alergias, nascimento;
    printf("\n=================================================================\n");
    printf("------                 Cadastro de Paciente                ------\n");
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
    printf("     - Data de nascimento: ");
    scanf("%s", &nascimento);
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

void menu_dentista(void) {
    char op;
    printf("\n=================================================================\n");
    printf("-----                  Area dos Dentistas                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Cadastrar dentista                                -----\n");
    printf("----- 2 - Visualizar dados de um dentista                   -----\n");
    printf("----- 3 - Editar dentista                                   -----\n");
    printf("----- 4 - Excluir dentista                                  -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
    scanf ("%c", &op);
    getchar();
    return op;
}

void cadastramento_dentista (void) {
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
    printf("\n\n-----            Dentista cadastrado com sucesso            -----\n");
    printf("=================================================================\n");
}

void menu_paciente (void) {
    char op;
	printf("\n=================================================================\n");
    printf("-----                  Area dos pacientes                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Agendamentos                                      -----\n");
	printf("----- 2 - Perfil                                            -----\n");
    printf("----- 3 - Editar paciente                                   -----\n");
    printf("----- 4 - Excluir paciente                                  -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
    scanf ("%c", &op);
    getchar();
    return op;
}

void menu_agendamento (void) {
    char op;
    printf("\n=================================================================\n");
    printf("-----                 Area dos Agendamentos                 -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Realizar agendamento                              -----\n");
    printf("----- 2 - Visualizar agendamentos                           -----\n");
    printf("----- 3 - Editar agendamento                                -----\n");
    printf("----- 4 - Excluir agendamento                               -----\n");
    printf("----- 0 - Retornar ao menu anterior                         -----\n");
    printf("=================================================================\n");
    scanf ("%c", &op);
    getchar();
    return op;
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

void relatorios(void) {
    char op;
    printf("\n=================================================================\n");
    printf("-----                  Area de Relatorios                   -----\n");
    printf("=================================================================\n");
    printf("----- 1 - Todos os agendamentos                             -----\n");
    printf("----- 2 - Todos os pacientes                                -----\n");
    printf("----- 3 - Todos os dentistas                                -----\n");
    printf("----- 4 - Todos os agendamentos por dentista                -----\n");
    printf("----- 0 - Retornar ao Menu Principal                        -----\n");
    printf("=================================================================\n");
    scanf ("%c", &op);
    getchar();
    return op;
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