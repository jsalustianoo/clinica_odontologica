#ifndef AGENDAMENTOS_H
#define AGENDAMENTOS_H

struct agendamentos{
    char id[10]; 
    char nome[45]; 
    char cpf[14]; 
    char dentista[45]; 
    char horario[6];
    char pagamento[9]; 
    char situacao[11];
    int dia, mes, ano;
};

void menu_agendamento (void);
void agendar (void);
void exibir_dados_agendamento (void);
void editar_agendamento (void);
void excluir_agendamento (void);

#endif