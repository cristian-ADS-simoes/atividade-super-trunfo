#include <stdio.h>
#include <string.h> // Necessário para usar a função strcpy

// --- DOCUMENTAÇÃO ---
// Projeto: Jogo Super Trunfo - Nível Aventureiro
// Autor: Cristian Simoes
// Disciplina: Super Trunfo em C: desenvolvendo a lógica do Jogo NIVEL AVENTUREIRO
// Instituição: ESTACIO

// --- ESTRUTURA DA CARTA (struct) ---
struct Carta {
    char nomePais[50];
    unsigned long int populacao;
    float area;
    float pib; // Em trilhões de USD
    int pontosTuristicos;
    float densidadeDemografica; // (calculado) População / Área
};

// --- FUNÇÃO PRINCIPAL ---
int main() {
    // --- CADASTRO DAS CARTAS ---
    struct Carta carta1;
    strcpy(carta1.nomePais, "Brasil");
    carta1.populacao = 215300000;
    carta1.area = 8516000;
    carta1.pib = 1.609;
    carta1.pontosTuristicos = 25;

    struct Carta carta2;
    strcpy(carta2.nomePais, "Argentina");
    carta2.populacao = 45810000;
    carta2.area = 2780000;
    carta2.pib = 0.487;
    carta2.pontosTuristicos = 18;

    carta1.densidadeDemografica = (float)carta1.populacao / carta1.area;
    carta2.densidadeDemografica = (float)carta2.populacao / carta2.area;

    printf("--- JOGO SUPER TRUNFO ---\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n", carta2.nomePais);
    printf("---------------------------\n\n");

    int escolha;
    printf("Escolha o atributo para comparar:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica (menor valor vence)\n");
    printf("\nDigite o número da sua escolha: ");
    scanf("%d", &escolha);

    printf("\n---------------------------\n");

    switch (escolha) {
        case 1:
            printf("Atributo: População\n%s: %lu\n%s: %lu\n\n", carta1.nomePais, carta1.populacao, carta2.nomePais, carta2.populacao);
            if (carta1.populacao > carta2.populacao) printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.populacao > carta1.populacao) printf("Resultado: %s venceu!\n", carta2.nomePais);
            else printf("Resultado: Empate!\n");
            break;
        case 2:
            printf("Atributo: Área (km²)\n%s: %.2f\n%s: %.2f\n\n", carta1.nomePais, carta1.area, carta2.nomePais, carta2.area);
            if (carta1.area > carta2.area) printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.area > carta1.area) printf("Resultado: %s venceu!\n", carta2.nomePais);
            else printf("Resultado: Empate!\n");
            break;
        case 3:
            printf("Atributo: PIB (em trilhões de USD)\n%s: %.3f\n%s: %.3f\n\n", carta1.nomePais, carta1.pib, carta2.nomePais, carta2.pib);
            if (carta1.pib > carta2.pib) printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.pib > carta1.pib) printf("Resultado: %s venceu!\n", carta2.nomePais);
            else printf("Resultado: Empate!\n");
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n%s: %d\n%s: %d\n\n", carta1.nomePais, carta1.pontosTuristicos, carta2.nomePais, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos) printf("Resultado: %s venceu!\n", carta2.nomePais);
            else printf("Resultado: Empate!\n");
            break;
        case 5:
            printf("Atributo: Densidade Demográfica (hab/km²)\nREGRA: O MENOR VALOR VENCE!\n\n%s: %.2f\n%s: %.2f\n\n", carta1.nomePais, carta1.densidadeDemografica, carta2.nomePais, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) printf("Resultado: %s venceu!\n", carta1.nomePais);
            else if (carta2.densidadeDemografica < carta1.densidadeDemografica) printf("Resultado: %s venceu!\n", carta2.nomePais);
            else printf("Resultado: Empate!\n");
            break;
        default:
            printf("Opção inválida! Por favor, escolha um número de 1 a 5.\n");
            break;
    }
    printf("---------------------------\n");
    return 0;
}