// Inclui a biblioteca padrão de entrada e saída para usar a função printf
#include <stdio.h>

int main() {
    
    // =================================================================
    // 1. Movimento da Torre (usando o laço 'for')
    // =================================================================
    printf("--- Movimento da Torre (5 casas para a direita) ---\n");
    int casas_a_mover_torre = 5;
    for (int casa = 1; casa <= casas_a_mover_torre; casa++) {
        printf("Torre - Casa %d: Direita\n", casa);
    }


    // =================================================================
    // 2. Movimento do Bispo (usando o laço 'while')
    // =================================================================
    printf("\n--- Movimento do Bispo (5 casas na diagonal) ---\n");
    int casas_a_mover_bispo = 5;
    int casa_atual_bispo = 1;
    while (casa_atual_bispo <= casas_a_mover_bispo) {
        printf("Bispo - Casa %d: Cima, Direita\n", casa_atual_bispo);
        casa_atual_bispo++; 
    }


    // =================================================================
    // 3. Movimento da Rainha (usando o laço 'do-while')
    // =================================================================
    printf("\n--- Movimento da Rainha (8 casas para a esquerda) ---\n");
    int casas_a_mover_rainha = 8;
    int casa_atual_rainha = 1;
    do {
        printf("Rainha - Casa %d: Esquerda\n", casa_atual_rainha);
        casa_atual_rainha++;
    } while (casa_atual_rainha <= casas_a_mover_rainha);


    // =================================================================
    // 4. Movimento do Cavalo (usando laços aninhados 'for' e 'while')
    // =================================================================
    // O Cavalo se move em "L": 2 casas em uma direção e 1 em outra.
    // O desafio pede para simular 2 casas para baixo e 1 para a esquerda,
    // usando um laço 'for' aninhado com um 'while' ou 'do-while'.
    
    // Imprime o cabeçalho para o movimento do Cavalo
    printf("\n--- Movimento do Cavalo (2 para baixo, 1 para a esquerda) ---\n");

    // Define o número de passos em cada direção
    int passos_para_baixo = 2;
    int passos_para_esquerda = 1;

    // Laço Externo (obrigatório ser 'for'): controla a parte vertical do movimento.
    // Ele irá iterar a quantidade de vezes definida em 'passos_para_baixo'.
    for (int i = 1; i <= passos_para_baixo; i++) {
        // Para cada iteração do laço externo, imprimimos "Baixo".
        printf("Cavalo - Movimento: Baixo\n");
    }

    // Laço Interno (pode ser 'while' ou 'do-while'): controla a parte horizontal.
    // Este laço é executado APÓS o laço vertical ter sido completado.
    // Juntos, eles formam a sequência do movimento em "L".
    int j = 1; // Inicialização do contador do while
    while (j <= passos_para_esquerda) {
        // Imprime a parte final do movimento "L"
        printf("Cavalo - Movimento: Esquerda\n");
        j++; // Incrementa para o laço finalizar
    }


    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}