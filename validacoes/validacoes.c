#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include <string.h>
#include <ctype.h>
#include <stdint.h>

// <-- VALIDAR LETRA - (Autor: Flavius Gorgonio) -->
// <-- Referência: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util.c -->
int ehLetra(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

// <-- VALIDAR NOME - (Autor: Flavius Gorgonio) -->
// <-- Referência: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util. -->
int validarNome(char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) { // percorre até o \0
        if (!ehLetra(nome[i]) && nome[i] != ' ') { // Se não for letra e não for espaço, retorna 0
            return 0; // Nome inválido
        }
    }
    return 1; // Nome válido
} 

// <-- VALIDAR CPF - (Autor: João Roberto) -->
int validarCpf(const char *cpf) {
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