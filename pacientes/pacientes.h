#ifndef PACIENTES_H
#define PACIENTES_H

struct pacientes{
    char *nome_paciente;
    char *cpf_paciente;
    char telefone_paciente[15];
    char doencas_preexistentes[200]; 
    char contraindicacao[200];
    int dia, mes, ano;
};

void menu_paciente (void);
void cadastro_paciente (void);
void exibir_dados_paciente (void);
void editar_paciente (void);
void excluir_paciente (void);

#endif