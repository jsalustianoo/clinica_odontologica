#ifndef DENTISTAS_H
#define DENTISTAS_H

struct dentistas{
    char* nome;
    char* cpf;
    char* telefone;
    char* cro;
    char* especialidades;
};

void menu_dentista (void);
void cadastro_dentista (void);
void exibir_dados_dentista (void);
void editar_dentista (void);
void excluir_dentista (void);

#endif