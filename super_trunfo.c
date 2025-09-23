// Inclui a biblioteca padrão de entrada e saída (Standard Input-Output).
// Ela é necessária para usarmos funções como printf() para mostrar texto na tela
// e scanf() para ler o que o usuário digita.
#include <stdio.h>

// A função main() é o ponto de partida de todo programa em C.
// O código que estiver dentro de suas chaves {} será executado.
int main() {

    // --- VARIÁVEIS PARA A CARTA 1 ---
    // Aqui estamos declarando (criando) as "caixinhas" na memória para guardar os dados.

    char estado1;           // Para guardar uma única letra (ex: 'A').
    char codigo1[5];          // Para guardar um texto pequeno (string), como 'A01'.
    char nomeCidade1[50];     // Para guardar um texto maior (string), como 'Sao Paulo'.
    int populacao1;           // Para guardar um número inteiro grande.
    float area1;              // Para guardar um número com casas decimais (ponto flutuante).
    float pib1;               // Também para números com casas decimais.
    int pontosTuristicos1;  // Para guardar um número inteiro.
    
    // --- NOVO: Variáveis para guardar os resultados dos cálculos da Carta 1 ---
    float densidadePopulacional1; // Guardará o resultado de População / Área.
    float pibPerCapita1;          // Guardará o resultado de (PIB * 1 bilhão) / População.

    // --- VARIÁVEIS PARA A CARTA 2 (mesma lógica da Carta 1) ---
    char estado2;
    char codigo2[5];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    
    // --- NOVO: Variáveis para os cálculos da Carta 2 ---
    float densidadePopulacional2;
    float pibPerCapita2;

    // -------------------------------------------------------------------------
    // ETAPA 1: LENDO OS DADOS DA PRIMEIRA CARTA
    // O padrão é: mostrar uma mensagem guia (printf) e depois ler a entrada (scanf).
    // -------------------------------------------------------------------------
    
    printf("--- Cadastro da Carta 1 ---\n");

    printf("Digite o Estado (uma letra de A a H): ");
    // O espaço antes do %c serve para "limpar" qualquer Enter que tenha sobrado de leituras anteriores.
    scanf(" %c", &estado1); 

    printf("Digite o Código da Carta (ex: A01): ");
    // O %s lê uma string (texto).
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade: ");
    // O %[^\n] é um truque para ler um texto com espaços até o usuário apertar Enter.
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a População (sem pontos ou vírgulas): ");
    // O %d lê um número inteiro.
    scanf("%d", &populacao1);

    printf("Digite a Área (em km²): ");
    // O %f lê um número de ponto flutuante (com decimais).
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões, ex: 699.28): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // -------------------------------------------------------------------------
    // --- NOVO: ETAPA 1.5: CALCULANDO OS DADOS DA PRIMEIRA CARTA ---
    // Aqui usamos os operadores matemáticos para criar novas informações.
    // -------------------------------------------------------------------------

    // Fórmula da densidade: População / Área.
    // Usamos (float) para converter a população (int) para float temporariamente.
    // Isso garante que o resultado da divisão tenha casas decimais.
    densidadePopulacional1 = (float)populacao1 / area1;
    
    // Fórmula do PIB per Capita: (PIB * 1 bilhão) / População.
    // Multiplicamos por 1 bilhão pois o PIB é dado em bilhões e queremos o resultado em reais.
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;

    printf("\n"); // Apenas pula uma linha para organizar a interface.

    // -------------------------------------------------------------------------
    // ETAPA 2: LENDO E CALCULANDO OS DADOS DA SEGUNDA CARTA
    // Repetimos o processo de leitura e cálculo para a segunda carta.
    // -------------------------------------------------------------------------

    printf("--- Cadastro da Carta 2 ---\n");

    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a População (sem pontos ou vírgulas): ");
    scanf("%d", &populacao2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões, ex: 300.50): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);
    
    // Cálculos para a Carta 2
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;

    printf("\n\n"); // Pula duas linhas para organizar a saída.

    // -------------------------------------------------------------------------
    // ETAPA 3: EXIBINDO OS DADOS DAS DUAS CARTAS
    // Agora mostramos tanto os dados que foram lidos quanto os que foram calculados.
    // -------------------------------------------------------------------------
    
    printf("--- Informações Cadastradas ---\n\n");

    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    // O %.2f formata o número float para ser exibido com exatamente duas casas decimais.
    printf("Área: %.2f km²\n", area1); 
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    
    // --- NOVO: Exibindo os dados calculados da Carta 1 ---
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    
    printf("\n"); // Espaçamento entre as cartas

    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    
    // --- NOVO: Exibindo os dados calculados da Carta 2 ---
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // return 0; indica que o programa terminou sua execução com sucesso.
    return 0; 
}