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
        printf("-----                          Menu dos Dentistas                           -----\n");
        printf("=================================================================================\n");
        printf("------      (1) - Cadastrar Novo Dentista                                  ------\n");
        printf("------      (2) - Visualizar Dados de um Dentista                          ------\n");
        printf("------      (3) - Editar Dados de um Dentista                              ------\n");
        printf("------      (4) - Excluir Dentista                                         ------\n");
        printf("------      (0) - Retornar ao Menu Principal                               ------\n");
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
    printf("\n=================================================================================\n");
    printf("------                        Consultar Dentista                             ------\n");
    printf("===================================================================================\n");
    printf("Digite o CPF do dentista: ");
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
            printf("\n=================================================================================\n");
            printf("Nome: %s\n", nome);
            printf("CPF: %s\n", cpf);
            printf("Telefone: %s\n", telefone);
            printf("Especialidade(s): %s\n", especialidades);
            printf("Número do CRO: %s\n", cro);
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

void editar_dentista (void) {
    Dentista dentista;
    
    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                      Editar dados de um Dentista                    ------\n");
    printf("=================================================================================\n");
    salvar_nome_dentista(dentista.nome);
    getchar();
    salvar_cpf_dentista(dentista.cpf);
    getchar();
    salvar_telefone_dentista(dentista.telefone);
    getchar();
    salvar_especialidade(dentista.especialidades);
    getchar(); 
    salvar_cro(dentista.cro);
    getchar(); 
    printf("=================================================================================\n");
    printf("-----               Dados do(a) Dentista Editados com Sucesso!              -----\n");
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
    getchar();
}

void excluir_dentista (void) {
    char confirmacao; 

    system("clear||cls");
    printf("\n");
    printf("=================================================================================\n");
    printf("------                           Excluir Dentista                          ------\n");
    printf("=================================================================================\n");
    printf("------      (Nome):                                                          ------");
    printf("------      (CPF):                                                           ------");
    printf("------      (Telefone):                                                      ------"); 
    printf("------      (Especialidade):                                                 ------"); 
    printf("------      (Numero do CRO):                                                 ------"); 
    printf("------                                                                     ------\n"); 
    printf("------     Tem certeza que deseja Excluir esse Dentista? (S)IM | (N)AO     ------\n");

    scanf(" %c", confirmacao);
    if (confirmacao == 'S' || confirmacao == 's'){
        printf("------                   Dentista Excluído com Sucesso!                    ------\n");
    } else if (confirmacao == 'N' || confirmacao == 'n'){
        printf("------                        Operação Cancelada!                          ------\n");
    } else{
        printf("------      Número digitado não condiz com nenhuma opção do sistema        ------\n");
    }                     
    printf("=================================================================================\n");
    printf("      Tecle <ENTER> para continuar...");
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