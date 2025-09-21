// Inclui a biblioteca padrão de entrada e saída, que nos dá acesso
// a funções como printf (para mostrar na tela) e scanf (para ler do teclado).
#include <stdio.h>

// Esta é a função principal, onde a execução do nosso programa começa.
int main() {

    // --- VARIÁVEIS PARA A CARTA 1 ---
    // Aqui estamos declarando (criando) as "caixinhas" para guardar os dados da primeira carta.
    char estado1;
    char codigo1[5]; // Um pouco mais de espaço para o código (ex: A01) e o caractere final
    char nomeCidade1[50]; // Espaço para um nome de cidade de até 49 letras
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // --- VARIÁVEIS PARA A CARTA 2 ---
    // Fazemos o mesmo para a segunda carta.
    char estado2;
    char codigo2[5];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // -------------------------------------------------------------------------
    // ETAPA 1: LENDO OS DADOS DA PRIMEIRA CARTA
    // -------------------------------------------------------------------------
    
    printf("--- Cadastro da Carta 1 ---\n"); // \n pula uma linha

    printf("Digite o Estado (uma letra de A a H): ");
    // O espaço antes de %c é um truque para limpar o buffer do teclado e evitar erros de leitura.
    scanf(" %c", &estado1); 

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1); // Para strings (char[]), não usamos o &

    printf("Digite o Nome da Cidade: ");
    scanf("%s", nomeCidade1);

    printf("Digite a População: ");
    scanf("%d", &populacao1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB: ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n"); // Pula uma linha para separar os cadastros

    // -------------------------------------------------------------------------
    // ETAPA 2: LENDO OS DADOS DA SEGUNDA CARTA
    // -------------------------------------------------------------------------

    printf("--- Cadastro da Carta 2 ---\n");

    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf("%s", nomeCidade2);

    printf("Digite a População: ");
    scanf("%d", &populacao2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB: ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    printf("\n\n"); // Pula duas linhas para organizar a saída

    // -------------------------------------------------------------------------
    // ETAPA 3: EXIBINDO OS DADOS DAS DUAS CARTAS
    // -------------------------------------------------------------------------

    printf("--- Informações Cadastradas ---\n\n");

    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1); // %.2f mostra o número com apenas 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    
    printf("\n"); // Espaçamento

    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

    // Retorna 0 para indicar que o programa terminou com sucesso.
    return 0; 
}
