#include <stdio.h>

// =================================================================
// DECLARAÇÃO DAS FUNÇÕES RECURSIVAS
// Em C, é uma boa prática declarar as funções (protótipos) antes de usá-las,
// especialmente antes da função 'main'.
// =================================================================

void moverTorreRecursivo(int casas_restantes);
void moverBispoRecursivo(int casas_restantes);
void moverRainhaRecursivo(int casas_restantes);


// =================================================================
// FUNÇÃO PRINCIPAL
// =================================================================
int main() {
    
    // --- 1. Movimento da Torre (usando Recursividade) ---
    printf("--- Movimento da Torre (5 casas para a direita) ---\n");
    int casas_torre = 5;
    moverTorreRecursivo(casas_torre);


    // --- 2. Movimento do Bispo (duas implementações) ---
    int casas_bispo = 5;
    
    // 2.1) Usando Recursividade (conforme solicitado)
    printf("\n--- Movimento do Bispo (Recursivo - 5 casas na diagonal) ---\n");
    moverBispoRecursivo(casas_bispo);

    // 2.2) Usando Laços Aninhados (conforme solicitado)
    printf("\n--- Movimento do Bispo (Laços Aninhados - 5 casas na diagonal) ---\n");
    // O laço externo representa o progresso total do movimento diagonal (5 passos).
    // O laço interno simula a verificação da posição em um "grid" imaginário.
    for (int y = 1; y <= casas_bispo; y++) { // Loop vertical
        for (int x = 1; x <= casas_bispo; x++) { // Loop horizontal
            // A condição 'x == y' traça uma linha diagonal perfeita no grid.
            // A cada passo na vertical (y), damos um passo na horizontal (x).
            if (x == y) {
                printf("Bispo (Aninhado) - Passo %d: Cima, Direita\n", y);
            }
        }
    }


    // --- 3. Movimento da Rainha (usando Recursividade) ---
    printf("\n--- Movimento da Rainha (8 casas para a esquerda) ---\n");
    int casas_rainha = 8;
    moverRainhaRecursivo(casas_rainha);


    // --- 4. Movimento do Cavalo (usando Laços Complexos) ---
    printf("\n--- Movimento do Cavalo (2 para cima, 1 para a direita) ---\n");
    int passos_para_cima = 2;
    int passos_para_direita = 1;
    int total_passos_cavalo = passos_para_cima + passos_para_direita;

    // Este laço complexo simula a sequência do movimento em "L".
    // A cada iteração, uma condição interna decide qual direção imprimir.
    // O laço externo controla o número total de etapas do movimento (3).
    for (int passo_atual = 1; passo_atual <= total_passos_cavalo; passo_atual++) {
        
        // Se o passo atual está na parte vertical do movimento (passos 1 e 2)
        if (passo_atual <= passos_para_cima) {
            printf("Cavalo - Movimento: Cima\n");
            continue; // O 'continue' pula para a próxima iteração do loop,
                      // ignorando o código restante dentro do laço.
        }

        // Se o passo atual é a parte final, horizontal (passo 3)
        printf("Cavalo - Movimento: Direita\n");
    }

    return 0;
}


// =================================================================
// DEFINIÇÃO DAS FUNÇÕES RECURSIVAS
// Aqui implementamos a lógica de cada função.
// =================================================================

/**
 * @brief Move a Torre recursivamente para a direita.
 * @param casas_restantes O número de casas que ainda faltam para mover.
 */
void moverTorreRecursivo(int casas_restantes) {
    // Caso Base: A condição de parada. Se não há mais casas para mover,
    // a função simplesmente retorna, encerrando a cadeia de chamadas.
    if (casas_restantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento da casa atual.
    printf("Torre - Movimento: Direita\n");

    // Passo Recursivo: A função chama a si mesma, mas com um problema menor
    // (uma casa a menos para mover), aproximando-se do caso base.
    moverTorreRecursivo(casas_restantes - 1);
}


/**
 * @brief Move o Bispo recursivamente na diagonal (Cima, Direita).
 * @param casas_restantes O número de casas que ainda faltam para mover.
 */
void moverBispoRecursivo(int casas_restantes) {
    // Caso Base: Se não houver mais casas, a função para.
    if (casas_restantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento diagonal.
    printf("Bispo (Recursivo) - Movimento: Cima, Direita\n");

    // Passo Recursivo: Chama a si mesma com um problema menor.
    moverBispoRecursivo(casas_restantes - 1);
}


/**
 * @brief Move a Rainha recursivamente para a esquerda.
 * @param casas_restantes O número de casas que ainda faltam para mover.
 */
void moverRainhaRecursivo(int casas_restantes) {
    // Caso Base: Condição de parada da recursão.
    if (casas_restantes <= 0) {
        return;
    }

    // Ação: Imprime o movimento para a esquerda.
    printf("Rainha - Movimento: Esquerda\n");

    // Passo Recursivo: Chama a si mesma com (casas_restantes - 1).
    moverRainhaRecursivo(casas_restantes - 1);
}