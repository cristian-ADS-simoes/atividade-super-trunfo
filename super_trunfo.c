// Inclui a biblioteca padrão de entrada e saída (Standard Input-Output),
// essencial para funções como printf() e scanf().
#include <stdio.h>

// A função main() é o ponto de partida obrigatório de todo programa em C.
int main() {

    // --- VARIÁVEIS PARA A CARTA 1 ---
    // Declaração das "caixinhas" de memória para guardar os dados da primeira carta.

    // ATENÇÃO: A variável 'estado' deve ser um array de char para funcionar corretamente com scanf.
    // Ex: "SP". Precisamos de 3 caracteres: 'S', 'P', e o caractere nulo '\0' que finaliza a string.
    char estado1[3]; 
    char codigo1[5];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    // --- VARIÁVEIS PARA A CARTA 2 (mesma estrutura da Carta 1) ---
    char estado2[3];
    char codigo2[5];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    // -------------------------------------------------------------------------
    // ETAPA 1: LENDO OS DADOS DAS DUAS CARTAS
    // -------------------------------------------------------------------------
    
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Digite a sigla do Estado (ex: SP): ");
    scanf("%s", estado1); // Alterado para ler uma string
    printf("Digite o Código da Carta (ex: SP01): ");
    scanf("%s", codigo1);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", nomeCidade1); // O espaço antes de %[^\n] limpa o buffer do teclado
    printf("Digite a População (sem pontos): ");
    scanf("%lu", &populacao1);
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Digite o N° de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Digite a sigla do Estado (ex: RJ): ");
    scanf("%s", estado2); // Alterado para ler uma string
    printf("Digite o Código da Carta (ex: RJ01): ");
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
    // ETAPA 2: REALIZANDO OS CÁLCULOS NECESSÁRIOS PARA AS DUAS CARTAS
    // -------------------------------------------------------------------------

    // --- Cálculos da Carta 1 ---
    // Evita divisão por zero se a área for 0
    if (area1 > 0) {
        densidadePopulacional1 = (float)populacao1 / area1;
    } else {
        densidadePopulacional1 = 0;
    }
    // Evita divisão por zero se a população for 0
    if (populacao1 > 0) {
       pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1;
    } else {
        pibPerCapita1 = 0;
    }
   
    // --- Cálculos da Carta 2 ---
    if (area2 > 0) {
        densidadePopulacional2 = (float)populacao2 / area2;
    } else {
        densidadePopulacional2 = 0;
    }
    if (populacao2 > 0) {
        pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;
    } else {
        pibPerCapita2 = 0;
    }
    
    // -------------------------------------------------------------------------
    // ETAPA 3: COMPARANDO AS CARTAS E EXIBINDO O RESULTADO
    // De acordo com o desafio, a escolha do atributo é feita diretamente no código.
    // Vamos usar o atributo "População" para este exemplo.
    // -------------------------------------------------------------------------

    printf("\n\n------------------------------------------------\n");
    printf("--- Comparacao de cartas (Atributo: Populacao) ---\n");
    printf("------------------------------------------------\n");
    
    // Exibe os valores que estão sendo comparados, como pedido no exemplo do desafio
    printf("Carta 1 - %s (%s): %lu\n", nomeCidade1, estado1, populacao1);
    printf("Carta 2 - %s (%s): %lu\n", nomeCidade2, estado2, populacao2);
    printf("\n"); // Linha em branco para separar

    // Estrutura de decisão IF e IF-ELSE para determinar o vencedor
    // Regra: Maior população vence.
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }
    printf("------------------------------------------------\n");

    // return 0; informa ao sistema operacional que o programa foi concluído com sucesso.
    return 0; 
}
