// Inclui a biblioteca padrão de entrada e saída para usar a função printf
#include <stdio.h>

int main() {
    
    // =================================================================
    // 1. Movimento da Torre (usando o laço 'for')
    // =================================================================
    // A Torre deve se mover 5 casas para a direita.
    // O laço 'for' é a escolha ideal aqui, pois sabemos exatamente o número
    // de repetições (5). Ele agrupa a inicialização, a condição e o 
    // incremento em uma única linha, tornando o código mais limpo e legível
    // para laços contados.

    printf("--- Movimento da Torre (5 casas para a direita) ---\n");
    
    // Define o número total de casas que a torre vai andar
    int casas_a_mover_torre = 5;

    // for (inicialização; condição; incremento)
    // - int casa = 1: Inicia um contador 'casa' em 1.
    // - casa <= casas_a_mover_torre: O laço continua enquanto 'casa' for menor ou igual a 5.
    // - casa++: Incrementa 'casa' em 1 ao final de cada repetição.
    for (int casa = 1; casa <= casas_a_mover_torre; casa++) {
        // Imprime o movimento para cada casa percorrida
        printf("Torre - Casa %d: Direita\n", casa);
    }


    // =================================================================
    // 2. Movimento do Bispo (usando o laço 'while')
    // =================================================================
    // O Bispo deve se mover 5 casas na diagonal para cima e à direita.
    // Usaremos o 'while' aqui. Ele é útil quando a lógica de controle
    // pode ser mais complexa, mas para um contador simples, ele requer
    // que a variável seja inicializada ANTES do laço e incrementada DENTRO dele.

    printf("\n--- Movimento do Bispo (5 casas na diagonal) ---\n");
    
    int casas_a_mover_bispo = 5;
    int casa_atual_bispo = 1; // 1. Inicialização do contador fora do laço

    // 2. Condição: O laço continua enquanto a condição for verdadeira
    while (casa_atual_bispo <= casas_a_mover_bispo) {
        // Imprime a combinação de direções para o movimento diagonal
        printf("Bispo - Casa %d: Cima, Direita\n", casa_atual_bispo);
        
        // 3. Incremento: Essencial para não criar um loop infinito
        casa_atual_bispo++; 
    }


    // =================================================================
    // 3. Movimento da Rainha (usando o laço 'do-while')
    // =================================================================
    // A Rainha deve se mover 8 casas para a esquerda.
    // Para cumprir o requisito, usaremos o 'do-while'. A principal
    // característica deste laço é que ele executa o bloco de código
    // PELO MENOS UMA VEZ antes de verificar a condição.

    printf("\n--- Movimento da Rainha (8 casas para a esquerda) ---\n");

    int casas_a_mover_rainha = 8;
    int casa_atual_rainha = 1; // 1. Inicialização do contador

    // O bloco 'do' é executado primeiro
    do {
        // Imprime o movimento para a esquerda
        printf("Rainha - Casa %d: Esquerda\n", casa_atual_rainha);

        // 2. Incremento do contador
        casa_atual_rainha++;

    // 3. Condição é verificada no final. Note o ponto e vírgula obrigatório.
    } while (casa_atual_rainha <= casas_a_mover_rainha);


    // Retorna 0 para indicar que o programa foi executado com sucesso
    return 0;
}