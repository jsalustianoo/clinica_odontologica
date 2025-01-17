#ifndef DENTISTAS_H
#define DENTISTAS_H

struct dentistas{
    char nome[45];
    char cpf[14];
    char telefone[15];
    char especialidades[70];
    char cro[7];
};

void menu_dentista (void);
void cadastro_dentista (void);
void exibir_dados_dentista (void);
void editar_dentista (void);
void excluir_dentista (void);

#endif