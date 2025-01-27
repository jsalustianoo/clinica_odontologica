#ifndef AGENDAMENTOS_H
#define AGENDAMENTOS_H

struct agendamentos{
    char* id; 
    char* cpf_paci; 
    char* cpf_dent; 
    char* data_agendamento;
    char* horario;
    char* pagamento; 
    char* situacao;
    char* nome_paci; 
    char* nome_dent; 
};

void menu_agendamento (void);
void agendar (void);
void exibir_dados_agendamento (void);
void editar_agendamento (void);
void excluir_agendamento (void);

#endif