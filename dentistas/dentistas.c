#include <stdio.h>
#include <stdlib.h>
#include "dentistas.h"

typedef struct dentistas Dentista;

void menu_dentista(void) {
    int opcao_dentista;
    do{
        system("clear||cls");
        printf("\n");
        printf("=================================================================================\n");
        printf("------                         Menu dos Dentistas                          ------\n");
        printf("=================================================================================\n");
        printf("------                         |1| - Cadastrar                             ------\n");
        printf("------                         |2| - Visualizar                            ------\n");
        printf("------                         |3| - Editar                                ------\n");
        printf("------                         |4| - Excluir                               ------\n");
        printf("------                         |0| - Voltar                                ------\n");
        printf("=================================================================================\n");
        printf("    - (Opção desejada): ");
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
                printf("Número digitado não condiz com nenhuma opção do sistema!");
            break;
        }
    } while (opcao_dentista != 0);

}

void cadastro_dentista (void) {
    Dentista* criar;
    Dentista* ultimo;

    criar = (Dentista*)malloc(sizeof(Dentista));

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                         Cadastro de Dentista                        ------\n");
    printf("=================================================================================\n");
    salvar_nome_dentista(criar->nome);
    getchar();
    salvar_cpf_dentista(criar->cpf);
    getchar();
    salvar_telefone_dentista(criar->telefone);
    getchar();
    salvar_especialidade(criar->especialidades);
    getchar(); 
    salvar_cro(criar->cro);
    getchar(); 

    ultimo = criar;
    salvar_em_arquivo_txt(criar->nome, criar->cpf, criar->telefone, criar->especialidades, criar->cro, "dentistas.txt", ultimo);

    printf("=================================================================================\n");
    printf("-----                  Dentista Cadastrado(a) com Sucesso!                  -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void exibir_dados_dentista(void) {
    system("clear||cls");
    printf("\n");

    char cpf_procurado[15];
    char nome[100], cpf[15], telefone[20], especialidades[100], cro[20];
    int encontrado = 0;

    system("clear||cls");
    printf("\n");
    printf("===================================================================================\n");
    printf("------                        Visualizar Dentista                            ------\n");
    printf("===================================================================================\n");
    printf("      - (CPF): ");
    scanf("%s", cpf_procurado);
    getchar();  // Limpa buffer

    FILE *arquivo = fopen("dentistas.txt", "r");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    // Lê os dados do arquivo e procura pelo CPF
    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(especialidades, sizeof(especialidades), arquivo);
        fgets(cro, sizeof(cro), arquivo);

        // Remover possíveis quebras de linha nos dados lidos
        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        telefone[strcspn(telefone, "\n")] = '\0';
        especialidades[strcspn(especialidades, "\n")] = '\0';
        cro[strcspn(cro, "\n")] = '\0';

        if (strcmp(cpf, cpf_procurado) == 0) {
            encontrado = 1;
            printf("\n      - (Nome): %s\n", nome);
            printf("      - (CPF): %s\n", cpf);
            printf("      - (Telefone): %s\n", telefone);
            printf("      - (Especialidade(s)): %s\n", especialidades);
            printf("      - (Número do CRO): %s\n", cro);
            printf("=================================================================================\n");
            printf("-----                   Dentista visualizado com sucesso!                   -----\n");
            printf("=================================================================================\n");
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("\nDentista com CPF %s não encontrado.\n", cpf_procurado);
    }

    printf("\nTecle <ENTER> para continuar...");
    getchar();
}

void editar_dentista(void) {
    system("clear||cls");
    printf("\n");

    char cpf_procurado[15];
    char nome[100], cpf[15], telefone[20], especialidades[100], cro[20];
    int encontrado = 0;

    printf("==================================================================================\n");
    printf("------                            Editar Dentista                           ------\n");
    printf("==================================================================================\n");
    printf("------      (CPF): ");
    fgets(cpf_procurado, sizeof(cpf_procurado), stdin);
    cpf_procurado[strcspn(cpf_procurado, "\n")] = '\0';

    FILE *arquivo = fopen("dentistas.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(especialidades, sizeof(especialidades), arquivo);
        fgets(cro, sizeof(cro), arquivo);

        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        telefone[strcspn(telefone, "\n")] = '\0';
        especialidades[strcspn(especialidades, "\n")] = '\0';
        cro[strcspn(cro, "\n")] = '\0';

        if (strcmp(cpf, cpf_procurado) == 0) {
            encontrado = 1;
            printf("\n=================================================================================\n");
            printf("      - (Nome): %s\n", nome);
            printf("      - (CPF): %s\n", cpf);
            printf("      - (Telefone): %s\n", telefone);
            printf("      - (Especialidade(s)): %s\n", especialidades);
            printf("      - (Número do CRO): %s\n", cro);
            printf("=================================================================================\n");

            printf("\nDigite os novos dados:\n");
            salvar_nome_dentista(nome);
            getchar();
            salvar_telefone_dentista(telefone);
            getchar();
            salvar_especialidade(especialidades);
            getchar();
            salvar_cro(cro);
            getchar();

            printf("=================================================================================\n");
            printf("-----                 Dados do dentista editado com sucesso!                -----\n");
            printf("=================================================================================\n");
        }

        fprintf(temp, "%s\n%s\n%s\n%s\n%s\n", nome, cpf, telefone, especialidades, cro);
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("dentistas.txt");
        rename("temp.txt", "dentistas.txt");
    } else {
        remove("temp.txt");
        printf("\nDentista com CPF %s não encontrado.\n", cpf_procurado);
    }

    printf("\nTecle <ENTER> para continuar...");
    getchar();
}


void excluir_dentista(void) {
    system("clear||cls");
    printf("\n");

    char cpf_procurado[15];
    char nome[100], cpf[15], telefone[20], especialidades[100], cro[20];
    int encontrado = 0;
    int confirmacao;

    printf("==================================================================================\n");
    printf("------                            Excluir Dentista                          ------\n");
    printf("==================================================================================\n");
    printf("------      (CPF): ");
    fgets(cpf_procurado, sizeof(cpf_procurado), stdin);
    cpf_procurado[strcspn(cpf_procurado, "\n")] = '\0'; // Remove quebra de linha

    FILE *arquivo = fopen("dentistas.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }

    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        fgets(cpf, sizeof(cpf), arquivo);
        fgets(telefone, sizeof(telefone), arquivo);
        fgets(especialidades, sizeof(especialidades), arquivo);
        fgets(cro, sizeof(cro), arquivo);

        nome[strcspn(nome, "\n")] = '\0';
        cpf[strcspn(cpf, "\n")] = '\0';
        telefone[strcspn(telefone, "\n")] = '\0';
        especialidades[strcspn(especialidades, "\n")] = '\0';
        cro[strcspn(cro, "\n")] = '\0';

        if (strcmp(cpf, cpf_procurado) == 0) {
            printf("\n=================================================================================\n");
            printf("      - (Nome): %s\n", nome);
            printf("      - (CPF): %s\n", cpf);
            printf("      - (Telefone): %s\n", telefone);
            printf("      - (Especialidade(s)): %s\n", especialidades);
            printf("      - (Número do CRO): %s\n", cro);
            printf("=================================================================================\n");

            printf("\nDeseja realmente excluir? (1 - Sim / 0 - Não): ");
            scanf("%d", &confirmacao);
            getchar(); // Limpar buffer do teclado

            if (confirmacao == 1) {
                encontrado = 1;
                printf("=================================================================================\n");
                printf("-----                    Dentista excluido com sucesso!                     -----\n");
                printf("=================================================================================\n");
                continue;  // Pula a gravação deste registro
            } else {
                printf("\nExclusão cancelada.\n");
            }
        }

        fprintf(temp, "%s\n%s\n%s\n%s\n%s\n", nome, cpf, telefone, especialidades, cro);
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("dentistas.txt");
        rename("temp.txt", "dentistas.txt");
    } else {
        remove("temp.txt");
        printf("\nDentista com CPF %s não encontrado.\n", cpf_procurado);
    }

    printf("\nTecle <ENTER> para continuar...");
    getchar();
}


void salvar_nome_dentista(char *nome){
    int valido = 0; // Não válido
    while (!valido) {
        printf("------      (Nome do Dentista): ");
        scanf(" %[^\n]", nome);
        
        if (validarNome(nome) == 1) { 
            valido = 1; // Válido
        } else {
            printf("\n=========== Nome Inválido! Tente Novamente! ===========\n\n");
            while (getchar() != '\n'); 
        }
    }
}

void salvar_cpf_dentista(char *cpf){
    int valido = 0;
    while (!valido){
        printf("------      (CPF): ");
        scanf("%s", cpf);
        if(validar_cpf(cpf)){
            valido = 1;
        } else{
            printf("\n=========== CPF Inválido! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_telefone_dentista(char *telefone){
    int telefone_valido = 0;

    while(!telefone_valido){
        printf("------      (Telefone, (xx)xxxxx-xxxx ou xxxxxxxxxxx): ");
        scanf("%s", telefone);

        telefone_valido = validar_telefone(telefone);

        if (!telefone_valido) {
            printf("\n=========== Telefone Inválido! Tente Novamente! ===========\n\n");
        }
    }
        
}

void salvar_especialidade(char *especialidades){
    int especialidade_valida = 0;

    while(!especialidade_valida){
        printf("------      (Especialidade(s)): ");
        scanf(" %[^\n]", especialidades); // Lê uma linha inteira com espaços e vírgulas

        especialidade_valida = validar_especialidades(especialidades);

        if (!especialidade_valida) {
            printf("\n=========== Especialidade Inválida! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_cro(char *cro){
    int cro_valido = 0;

    while(!cro_valido){
        printf("------      (CRO): ");
        scanf("%s", cro);

        cro_valido = validar_cro(cro);

        if(!cro_valido){
            printf("\n=========== CRO Inválido! Tente Novamente! ===========\n\n");
        }
    }
}

void salvar_em_arquivo_txt(char *nome, char *cpf, char *telefone, char *especialidades, char *cro, char *nome_arquivo, Dentista* ultimo){
    FILE* arquivo_dentistas = fopen(nome_arquivo, "a");

    Dentista* auxiliar = ultimo;
    fprintf(arquivo_dentistas, "%s\n", auxiliar->nome);
    fprintf(arquivo_dentistas, "%s\n", auxiliar->cpf);
    fprintf(arquivo_dentistas, "%s\n", auxiliar->telefone);
    fprintf(arquivo_dentistas, "%s\n", auxiliar->especialidades);
    fprintf(arquivo_dentistas, "%s\n", auxiliar->cro);
    fclose(arquivo_dentistas);
}