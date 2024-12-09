#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <time.h>

// <-- VALIDAR LETRA - (Autor: Flavius Gorgonio + modicação do chatGPT) -->
// <-- Referência: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util.c -->
int ehLetra(char c) {
    // Verifica letras maiúsculas e minúsculas
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }

    // Verifica caracteres acentuados comuns
    char acentuados[] = "áÁàÀãÃâÂéÉèÈêÊíÍìÌîÎóÓòÒõÕôÔúÚùÙûÛçÇ";
    for (int i = 0; acentuados[i] != '\0'; i++) {
        if (c == acentuados[i]) {
            return 1;
        }
    }

    return 0; // Não é letra
}

// <-- VALIDAR NOME - (Autor: Flavius Gorgonio) -->
// <-- Referência: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util. -->
int validarNome(char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        // Se não for letra e não for espaço, retorna 0
        if (!ehLetra(nome[i]) && nome[i] != ' ') {
            return 0; // Nome inválido
        }
    }
    return 1; // Nome válido
}

// <-- VALIDAR CPF - (Autor: João Roberto) -->
int validar_cpf(const char *cpf) {
    // Remove caracteres não numéricos e verifica o comprimento
    char numeros[12];
    int j = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            if (j < 11) {
                numeros[j++] = cpf[i];
            }
        }
    }
    numeros[j] = '\0';
    // Verifica se o CPF tem 11 dígitos e não é uma sequência repetida
    if (strlen(numeros) != 11 || (numeros[0] == numeros[1] && strncmp(numeros, numeros + 1, 10) == 0)) {
        return 0; // CPF inválido
    }
    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (numeros[i] - '0') * (10 - i);
    }
    int digito1 = 11 - (soma % 11);
    if (digito1 > 9) {
        digito1 = 0;
    }
    // Verifica o primeiro dígito verificador
    if ((numeros[9] - '0') != digito1) {
        return 0; // CPF inválido
    }
    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (numeros[i] - '0') * (11 - i);
    }
    int digito2 = 11 - (soma % 11);
    if (digito2 > 9) {
        digito2 = 0;
    }
    // Verifica o segundo dígito verificador
    if ((numeros[10] - '0') != digito2) {
        return 0; // CPF inválido
    }
    return 1; // CPF válido
} 

// Função para validar a data
int validar_data(int dia, int mes, int ano) {
   
    if (ano < 1900 || ano > 2100) return 0; // Verifica se o ano está dentro de um intervalo razoável

    if (mes < 1 || mes > 12) return 0; // Verifica se o mês é válido

    int dias_no_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Array com o número de dias de cada mês (considerando ano não bissexto)

    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) { // Ajusta fevereiro para 29 dias se o ano for bissexto
        dias_no_mes[1] = 29;
    }

    if (dia < 1 || dia > dias_no_mes[mes - 1]) return 0; // Verifica se o dia está dentro do limite para o mês dado

    // Obtém a data atual
    time_t t = time(NULL); 
    struct tm *data_atual = localtime(&t);

    int dia_atual = data_atual->tm_mday;
    int mes_atual = data_atual->tm_mon + 1; // Meses vão de 0 a 11
    int ano_atual = data_atual->tm_year + 1900;

    if (ano < ano_atual ||// Verifica se a data fornecida é anterior à data atual
        (ano == ano_atual && mes < mes_atual) ||
        (ano == ano_atual && mes == mes_atual && dia < dia_atual)) {
        return 0;
    }

    return 1; // Data válida
}

int validar_horario(const char *horario) {
    int horas, minutos;

    
    if (sscanf(horario, "%d:%d", &horas, &minutos) != 2) { // Verifica se o formato está correto e se contém o separador ':'
        return 0; // Formato inválido
    }
    
    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) { // Verifica se as horas e minutos estão dentro dos limites válidos
        return 0; // Horas ou minutos fora do intervalo permitido
    }

    // Verifica se há exatamente dois dígitos antes e depois do ':'
    char temp[6];
    snprintf(temp, sizeof(temp), "%02d:%02d", horas, minutos);

    if (strcmp(horario, temp) != 0) {
        return 0; // Formato inválido
    }

    return 1; // Horário válido
}

int validar_telefone(const char *telefone) {
    int tamanho = strlen(telefone);

    // Verifica o formato "(xx)xxxxx-xxxx"
    if (tamanho == 14 && telefone[0] == '(' && telefone[3] == ')' && telefone[9] == '-') {
        for (int i = 1; i < 3; i++) {
            if (!isdigit(telefone[i])) return 0;
        }
        for (int i = 4; i < 9; i++) {
            if (!isdigit(telefone[i])) return 0;
        }
        for (int i = 10; i < 14; i++) {
            if (!isdigit(telefone[i])) return 0;
        }
        return 1;
    }

    // Verifica o formato "xxxxxxxxxxx"
    if (tamanho == 11) {
        for (int i = 0; i < tamanho; i++) {
            if (!isdigit(telefone[i])) return 0;
        }
        return 1;
    }

    return 0; // Não está em nenhum dos formatos válidos
}

int validar_especialidades(const char *especialidades) {
    for (int i = 0; especialidades[i] != '\0'; i++) {
        char c = especialidades[i];
        if (!ehLetra(c) && c != ' ' && c != ',') {
            return 0; // Caractere inválido encontrado
        }
    }
    return 1; // Todos os caracteres são válidos
}

int ehNumero(char c) {
    return (c >= '0' && c <= '9');
}

// Função para validar o CRO
int validar_cro(const char *cro) {
    int tamanho = strlen(cro);

    // Verificar tamanho
    if (tamanho < 4 || tamanho > 8) {
        return 0; // CRO inválido
    }

    // Verificar se os primeiros caracteres são números
    int i = 0;
    while (i < tamanho - 2 && ehNumero(cro[i])) {
        i++;
    }

    // Verificar se os últimos dois caracteres são letras maiúsculas
    if (tamanho - i != 2 || !isupper(cro[i]) || !isupper(cro[i + 1])) {
        return 0; // CRO inválido
    }

    return 1; // CRO válido
}

int eh_bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função para validar a data fornecida
int validar_data_nascimento(const char *data, int *dia, int *mes, int *ano) {
    int dia_max;
    if (strlen(data) == 8) { // Formato "MMDDYYYY"
        if (sscanf(data, "%2d%2d%4d", mes, dia, ano) != 3)
            return 0;
    } else if (strlen(data) == 10) { // Formato "MM/DD/YYYY"
        if (data[2] != '/' || data[5] != '/' ||
            sscanf(data, "%2d/%2d/%4d", mes, dia, ano) != 3)
            return 0;
    } else {
        return 0; // Tamanho inválido
    }

    if (*mes < 1 || *mes > 12 || *dia < 1 || *ano < 1)
        return 0;

    switch (*mes) {
        case 4: case 6: case 9: case 11: dia_max = 30; break;
        case 2: dia_max = eh_bissexto(*ano) ? 29 : 28; break;
        default: dia_max = 31;
    }

    return *dia <= dia_max;
}

int validar_doencas_preexistentes(const char *doencas_preexistentes) {
    for (int i = 0; doencas_preexistentes[i] != '\0'; i++) {
        char c = doencas_preexistentes[i];
        if (!ehLetra(c) && c != ' ' && c != ',') {
            return 0; // Caractere inválido encontrado
        }
    }
    return 1; // Todos os caracteres são válidos
}