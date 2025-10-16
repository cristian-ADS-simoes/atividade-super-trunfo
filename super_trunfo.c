#include <stdio.h>
#include <string.h> // Necessário para strcpy

// --- DOCUMENTAÇÃO ---
// Projeto: Jogo Super Trunfo - Nível Mestre
// Propósito: Implementar uma comparação avançada com a escolha de dois atributos,
//            menus dinâmicos e soma de valores para determinar o vencedor.
// Autor: Cristian Simoes
// Disciplina: Super Trunfo em C: desenvolvendo a lógica do Jogo NIVEL MESTRE
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

    // --- CADASTRO DAS CARTAS (Pré-definidas) ---
    struct Carta carta1;
    strcpy(carta1.nomePais, "Brasil");
    carta1.populacao = 215300000;
    carta1.area = 8516000;
    carta1.pib = 1.609;
    carta1.pontosTuristicos = 25;

    struct Carta carta2;
    strcpy(carta2.nomePais, "Japão");
    carta2.populacao = 125700000;
    carta2.area = 377975;
    carta2.pib = 5.065;
    carta2.pontosTuristicos = 42;

    // --- CÁLCULOS ADICIONAIS ---
    carta1.densidadeDemografica = (float)carta1.populacao / carta1.area;
    carta2.densidadeDemografica = (float)carta2.populacao / carta2.area;

    // --- INÍCIO DO JOGO ---
    printf("--- JOGO SUPER TRUNFO - DESAFIO FINAL ---\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n", carta2.nomePais);
    printf("-----------------------------------------\n\n");

    // --- REQUISITO 1: ESCOLHA DE DOIS ATRIBUTOS ---
    int escolha1, escolha2;
    float valorCarta1_Attr1 = 0, valorCarta1_Attr2 = 0;
    float valorCarta2_Attr1 = 0, valorCarta2_Attr2 = 0;
    char nomeAttr1[30], nomeAttr2[30];

    // --- Menu para o PRIMEIRO atributo ---
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("\nDigite o número da sua escolha: ");
    scanf("%d", &escolha1);

    // Armazena o valor e o nome do primeiro atributo escolhido
    switch (escolha1) {
        case 1: strcpy(nomeAttr1, "População"); valorCarta1_Attr1 = carta1.populacao; valorCarta2_Attr1 = carta2.populacao; break;
        case 2: strcpy(nomeAttr1, "Área"); valorCarta1_Attr1 = carta1.area; valorCarta2_Attr1 = carta2.area; break;
        case 3: strcpy(nomeAttr1, "PIB"); valorCarta1_Attr1 = carta1.pib; valorCarta2_Attr1 = carta2.pib; break;
        case 4: strcpy(nomeAttr1, "Pontos Turísticos"); valorCarta1_Attr1 = carta1.pontosTuristicos; valorCarta2_Attr1 = carta2.pontosTuristicos; break;
        case 5: strcpy(nomeAttr1, "Densidade Demográfica"); valorCarta1_Attr1 = carta1.densidadeDemografica; valorCarta2_Attr1 = carta2.densidadeDemografica; break;
        default:
            printf("\nErro: Opção inválida!\n");
            return 1; // Encerra o programa com erro
    }

    // --- REQUISITO 5: MENUS DINÂMICOS ---
    printf("\nEscolha o SEGUNDO atributo para comparar (não pode ser %s):\n", nomeAttr1);
    if (escolha1 != 1) printf("1. População\n");
    if (escolha1 != 2) printf("2. Área\n");
    if (escolha1 != 3) printf("3. PIB\n");
    if (escolha1 != 4) printf("4. Pontos Turísticos\n");
    if (escolha1 != 5) printf("5. Densidade Demográfica\n");
    printf("\nDigite o número da sua escolha: ");
    scanf("%d", &escolha2);

    // Validação para garantir que os atributos são diferentes
    if (escolha1 == escolha2) {
        printf("\nErro: Você não pode escolher o mesmo atributo duas vezes!\n");
        return 1;
    }

    // Armazena o valor e o nome do segundo atributo escolhido
    switch (escolha2) {
        case 1: strcpy(nomeAttr2, "População"); valorCarta1_Attr2 = carta1.populacao; valorCarta2_Attr2 = carta2.populacao; break;
        case 2: strcpy(nomeAttr2, "Área"); valorCarta1_Attr2 = carta1.area; valorCarta2_Attr2 = carta2.area; break;
        case 3: strcpy(nomeAttr2, "PIB"); valorCarta1_Attr2 = carta1.pib; valorCarta2_Attr2 = carta2.pib; break;
        case 4: strcpy(nomeAttr2, "Pontos Turísticos"); valorCarta1_Attr2 = carta1.pontosTuristicos; valorCarta2_Attr2 = carta2.pontosTuristicos; break;
        case 5: strcpy(nomeAttr2, "Densidade Demográfica"); valorCarta1_Attr2 = carta1.densidadeDemografica; valorCarta2_Attr2 = carta2.densidadeDemografica; break;
        default:
            printf("\nErro: Opção inválida!\n");
            return 1;
    }

    // --- REQUISITO 2, 3 e 4: COMPARAÇÃO, SOMA E EMPATE ---
    printf("\n-----------------------------------------\n");
    printf("           RESULTADO DA RODADA\n");
    printf("-----------------------------------------\n");

    // Exibição dos valores individuais
    printf("Países: %s vs %s\n", carta1.nomePais, carta2.nomePais);
    printf("Atributos: %s e %s\n\n", nomeAttr1, nomeAttr2);

    printf("--- %s ---\n", carta1.nomePais);
    printf("  %s: %.2f\n", nomeAttr1, valorCarta1_Attr1);
    printf("  %s: %.2f\n", nomeAttr2, valorCarta1_Attr2);

    printf("\n--- %s ---\n", carta2.nomePais);
    printf("  %s: %.2f\n", nomeAttr1, valorCarta2_Attr1);
    printf("  %s: %.2f\n", nomeAttr2, valorCarta2_Attr2);

    // Cálculo da soma
    float somaCarta1 = valorCarta1_Attr1 + valorCarta1_Attr2;
    float somaCarta2 = valorCarta2_Attr1 + valorCarta2_Attr2;

    printf("\n-----------------------------------------\n");
    printf("Soma dos Atributos (%s): %.2f\n", carta1.nomePais, somaCarta1);
    printf("Soma dos Atributos (%s): %.2f\n", carta2.nomePais, somaCarta2);
    printf("-----------------------------------------\n");

    // Lógica final para determinar o vencedor com base na MAIOR SOMA
    if (somaCarta1 == somaCarta2) {
        printf("\nResultado Final: EMPATE!\n");
    } else {
        // Uso do operador ternário para deixar o código mais elegante
        const char* vencedor = (somaCarta1 > somaCarta2) ? carta1.nomePais : carta2.nomePais;
        printf("\nResultado Final: %s VENCEU!\n", vencedor);
    }
    printf("-----------------------------------------\n");

    return 0; // Indica que o programa terminou com sucesso
}