// Inclui a biblioteca padrão de entrada e saída (Standard Input-Output),
// essencial para funções como printf() e scanf().
#include <stdio.h>

// A função main() é o ponto de partida obrigatório de todo programa em C.
int main() {

    // --- VARIÁVEIS PARA A CARTA 1 ---
    // Declaração das "caixinhas" de memória para guardar os dados da primeira carta.

    char estado1;
    char codigo1[5];
    char nomeCidade1[50];
    // --- ALTERAÇÃO: A população agora é 'unsigned long int'.
    // 'long' permite números muito maiores que um 'int' normal.
    // 'unsigned' significa "sem sinal", ou seja, apenas números positivos, o que é perfeito para população.
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    // --- NOVO: Variável para guardar o resultado do cálculo do Super Poder.
    float superPoder1;

    // --- VARIÁVEIS PARA A CARTA 2 (mesma estrutura da Carta 1) ---
    char estado2;
    char codigo2[5];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    // --- NOVO: Variáveis para guardar os resultados das comparações ---
    // Elas guardarão 1 se a Carta 1 vencer, ou 0 se a Carta 2 vencer.
    int vitoriaPopulacao, vitoriaArea, vitoriaPIB, vitoriaPontos, vitoriaDensidade, vitoriaPIBpc, vitoriaSuperPoder;

    // -------------------------------------------------------------------------
    // ETAPA 1: LENDO OS DADOS DAS DUAS CARTAS
    // -------------------------------------------------------------------------
    
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1); 
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("Digite a População (sem pontos): ");
    // --- ALTERAÇÃO: Usamos o formatador "%lu" para ler um 'unsigned long int'.
    scanf("%lu", &populacao1);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Digite o N° de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a População (sem pontos): ");
    scanf("%lu", &populacao2);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Digite o N° de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // -------------------------------------------------------------------------
    // ETAPA 2: REALIZANDO TODOS OS CÁLCULOS PARA AS DUAS CARTAS
    // -------------------------------------------------------------------------

    // --- Cálculos da Carta 1 ---
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
    // --- NOVO: Cálculo do Super Poder 1 ---
    // A fórmula soma todos os atributos numéricos.
    // Convertemos os inteiros para float com (float) para garantir que a soma seja precisa.
    // O poder da densidade é o seu inverso (1 / densidade), pois quanto menor a densidade, maior o poder.
    superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000) + (float)pontosTuristicos1 + pibPerCapita1 + (1 / densidadePopulacional1);

    // --- Cálculos da Carta 2 ---
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000) + (float)pontosTuristicos2 + pibPerCapita2 + (1 / densidadePopulacional2);

    // -------------------------------------------------------------------------
    // --- NOVO: ETAPA 3: COMPARANDO AS CARTAS ---
    // Uma comparação em C (ex: x > y) resulta em 1 se for VERDADEIRA, e 0 se for FALSA.
    // Armazenamos esse resultado diretamente nas nossas variáveis de "vitória".
    // -------------------------------------------------------------------------
    
    // Regra padrão: o maior valor vence. A Carta 1 vence se seu atributo for > que o da Carta 2.
    vitoriaPopulacao = populacao1 > populacao2;
    vitoriaArea = area1 > area2;
    vitoriaPIB = pib1 > pib2;
    vitoriaPontos = pontosTuristicos1 > pontosTuristicos2;
    vitoriaPIBpc = pibPerCapita1 > pibPerCapita2;
    vitoriaSuperPoder = superPoder1 > superPoder2;
    
    // Regra especial para densidade: o MENOR valor vence. A Carta 1 vence se seu atributo for < que o da Carta 2.
    vitoriaDensidade = densidadePopulacional1 < densidadePopulacional2;

    // -------------------------------------------------------------------------
    // ETAPA 4: EXIBINDO OS RESULTADOS DA BATALHA
    // Mostramos qual carta venceu em cada categoria e o resultado numérico (1 ou 0).
    // -------------------------------------------------------------------------
    
    printf("\n\n--- Comparação de Cartas ---\n");
    
    // Para cada atributo, imprimimos o resultado.
    // Usamos o 'operador ternário' ( ... ? ... : ... ) como um if/else compacto.
    // Ele lê-se como: "A condição é verdadeira? Se sim, use o valor 1. Se não, use o valor 2."
    // Isso nos permite imprimir "Carta 1" ou "Carta 2" como a vencedora.
    printf("População: Carta %d venceu (%d)\n", vitoriaPopulacao ? 1 : 2, vitoriaPopulacao);
    printf("Área: Carta %d venceu (%d)\n", vitoriaArea ? 1 : 2, vitoriaArea);
    printf("PIB: Carta %d venceu (%d)\n", vitoriaPIB ? 1 : 2, vitoriaPIB);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", vitoriaPontos ? 1 : 2, vitoriaPontos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", vitoriaDensidade ? 1 : 2, vitoriaDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n", vitoriaPIBpc ? 1 : 2, vitoriaPIBpc);
    printf("Super Poder: Carta %d venceu (%d)\n", vitoriaSuperPoder ? 1 : 2, vitoriaSuperPoder);

    // return 0; informa ao sistema operacional que o programa foi concluído com sucesso.
    return 0; 
}
