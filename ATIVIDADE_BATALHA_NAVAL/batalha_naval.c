#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS

// --- Constantes Globais ---
// Definir constantes torna o código mais legível e fácil de modificar.

// Requisito: Tabuleiro 10x10
#define TAMANHO_TABULEIRO 10 
// Requisito: Navios de tamanho fixo 3
#define TAMANHO_NAVIO 3    

// Valores para representar o estado de cada célula
#define AGUA 0
#define NAVIO 3

// Constantes para orientação (mais legível do que usar 0 e 1)
#define HORIZONTAL 0
#define VERTICAL 1

// --- Protótipos das Funções ---
// Declarar as funções aqui permite que a 'main' as chame,
// mesmo que elas sejam definidas mais abaixo no arquivo.

/**
 * @brief Inicializa o tabuleiro com 'AGUA' (0).
 * @param tab O tabuleiro (matriz 2D) a ser inicializado.
 */
void inicializarTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 * @param tab O tabuleiro (matriz 2D) a ser exibido.
 */
void exibirTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

/**
 * @brief Tenta posicionar um navio no tabuleiro.
 * @param tab O tabuleiro (matriz 2D).
 * @param navio O vetor (array 1D) que representa o navio (ex: [3, 3, 3]).
 * @param linha A linha inicial para posicionar o navio (0 a 9).
 * @param coluna A coluna inicial para posicionar o navio (0 a 9).
 * @param orientacao A orientação (HORIZONTAL ou VERTICAL).
 * @return 1 (true) se o navio foi posicionado com sucesso, 0 (false) caso contrário.
 */
int posicionarNavio(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int navio[TAMANHO_NAVIO], 
                     int linha, int coluna, int orientacao);

// --- Função Principal (main) ---
int main() {
    
    // 1. Represente o Tabuleiro:
    // Cria a matriz 10x10 na memória.
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // 2. Posicione os Navios (vetores unidimensionais):
    // Como pedido na Dica, criamos um "protótipo" de navio.
    // Todos os navios de tamanho 3 serão cópias deste.
    int navio_prototipo[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Inicializa o tabuleiro com 'AGUA' (0)
    inicializarTabuleiro(tabuleiro);

    // --- Posicionamento dos Navios (Hardcoded) ---
    // Requisito: As coordenadas são definidas diretamente no código.

    // Navio 1: Horizontal
    // (linha 2, coluna 2) -> ocupará (2,2), (2,3), (2,4)
    int linha_navio1 = 2;
    int coluna_navio1 = 2;
    int orientacao_navio1 = HORIZONTAL;
    posicionarNavio(tabuleiro, navio_prototipo, linha_navio1, coluna_navio1, orientacao_navio1);

    // Navio 2: Vertical
    // (linha 4, coluna 5) -> ocupará (4,5), (5,5), (6,5)
    int linha_navio2 = 4;
    int coluna_navio2 = 5;
    int orientacao_navio2 = VERTICAL;
    posicionarNavio(tabuleiro, navio_prototipo, linha_navio2, coluna_navio2, orientacao_navio2);

    /* // ---- EXEMPLO DE VALIDAÇÃO (Teste) ----
    // Tente descomentar este bloco. O programa não deve permitir
    // a sobreposição no navio 1.
    
    int linha_navio3 = 2;
    int coluna_navio3 = 3; // Sobrepõe o navio 1
    int orientacao_navio3 = VERTICAL;
    if (!posicionarNavio(tabuleiro, navio_prototipo, linha_navio3, coluna_navio3, orientacao_navio3)) {
        printf("Falha ao posicionar Navio 3: Sobreposição detectada!\n\n");
    }
    
    // Tente descomentar este bloco. O programa não deve permitir
    // sair do tabuleiro.
    
    int linha_navio4 = 9;
    int coluna_navio4 = 0; // Tenta colocar em (9,0), (10,0), (11,0)
    int orientacao_navio4 = VERTICAL;
    if (!posicionarNavio(tabuleiro, navio_prototipo, linha_navio4, coluna_navio4, orientacao_navio4)) {
        printf("Falha ao posicionar Navio 4: Fora dos limites!\n\n");
    }
    */


    // 3. Exiba o Tabuleiro:
    printf("### Batalha Naval - Tabuleiro Inicial ###\n\n");
    exibirTabuleiro(tabuleiro);

    return EXIT_SUCCESS; // Indica que o programa terminou com sucesso
}


// --- Implementação das Funções ---

/**
 * @brief Inicializa o tabuleiro com 'AGUA' (0).
 */
void inicializarTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Loop aninhado para percorrer cada célula da matriz
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Define o valor padrão 'AGUA'
            tab[i][j] = AGUA;
        }
    }
}

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 */
void exibirTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Adiciona cabeçalho de colunas para facilitar a leitura
    printf("   "); // Espaço para o cabeçalho das linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    printf("   --------------------\n");

    // Loop aninhado para exibir cada célula
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Adiciona cabeçalho da linha
        printf("%d | ", i); 
        
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor (0 ou 3) e um espaço (Dica)
            printf("%d ", tab[i][j]);
        }
        // Pula para a próxima linha ao final de cada linha da matriz
        printf("\n");
    }
}

/**
 * @brief Tenta posicionar um navio no tabuleiro.
 */
int posicionarNavio(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int navio[TAMANHO_NAVIO], 
                     int linha, int coluna, int orientacao) {

    // --- REQUISITO: VALIDAÇÃO DE LIMITES ---
    if (orientacao == HORIZONTAL) {
        // Verifica se o navio "cai" para fora da borda direita
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Falha: Fora dos limites
        }
    } else if (orientacao == VERTICAL) {
        // Verifica se o navio "cai" para fora da borda inferior
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Falha: Fora dos limites
        }
    } else {
        return 0; // Falha: Orientação inválida
    }
    
    // Verifica se as coordenadas iniciais são válidas (redundante mas seguro)
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return 0; // Falha: Posição inicial fora do tabuleiro
    }

    // --- REQUISITO: VALIDAÇÃO DE SOBREPOSIÇÃO ---
    // (Simplificada, como pedido: apenas verificamos antes de colocar)
    // Precisamos checar se *alguma* das posições futuras já está ocupada.
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == HORIZONTAL) {
            if (tab[linha][coluna + i] == NAVIO) {
                return 0; // Falha: Sobreposição detectada
            }
        } else { // VERTICAL
            if (tab[linha + i][coluna] == NAVIO) {
                return 0; // Falha: Sobreposição detectada
            }
        }
    }

    // --- POSICIONAMENTO ---
    // Se passou em todas as validações, podemos posicionar o navio.
    // Dica: "copiando o valor 3 de cada posição do vetor do navio"
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == HORIZONTAL) {
            tab[linha][coluna + i] = navio[i]; // Copia o valor (3) do vetor para a matriz
        } else { // VERTICAL
            tab[linha + i][coluna] = navio[i]; // Copia o valor (3) do vetor para a matriz
        }
    }

    return 1; // Sucesso!
}