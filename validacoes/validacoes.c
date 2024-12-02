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
    // Verifica se o ano está dentro de um intervalo razoável
    if (ano < 1900 || ano > 2100) return 0;

    // Verifica se o mês é válido
    if (mes < 1 || mes > 12) return 0;

    // Array com o número de dias de cada mês (considerando ano não bissexto)
    int dias_no_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajusta fevereiro para 29 dias se o ano for bissexto
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) {
        dias_no_mes[1] = 29;
    }

    // Verifica se o dia está dentro do limite para o mês dado
    if (dia < 1 || dia > dias_no_mes[mes - 1]) return 0;

    // Obtém a data atual
    time_t t = time(NULL);
    struct tm *data_atual = localtime(&t);

    int dia_atual = data_atual->tm_mday;
    int mes_atual = data_atual->tm_mon + 1; // Meses vão de 0 a 11
    int ano_atual = data_atual->tm_year + 1900;

    // Verifica se a data fornecida é anterior à data atual
    if (ano < ano_atual ||
        (ano == ano_atual && mes < mes_atual) ||
        (ano == ano_atual && mes == mes_atual && dia < dia_atual)) {
        return 0;
    }

    return 1; // Data válida
}

int validar_horario(const char *horario) {
    int horas, minutos;

    // Verifica se o formato está correto e se contém o separador ':'
    if (sscanf(horario, "%d:%d", &horas, &minutos) != 2) {
        return 0; // Formato inválido
    }

    // Verifica se as horas e minutos estão dentro dos limites válidos
    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
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