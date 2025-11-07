#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS

// --- Constantes Globais ---
#define TAMANHO_TABULEIRO 10 
#define TAMANHO_NAVIO 3    

// Valores para representar o estado de cada célula
#define AGUA 0
#define NAVIO 3

// --- ALTERAÇÃO NÍVEL AVENTUREIRO ---
// Adicionamos as novas orientações diagonais
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL_PRINCIPAL 2   // (Ex: [0][0], [1][1], [2][2])
#define DIAGONAL_SECUNDARIA 3  // (Ex: [0][9], [1][8], [2][7])

// --- Protótipos das Funções ---
void inicializarTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibirTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

/**
 * @brief Tenta posicionar um navio no tabuleiro (ATUALIZADO PARA DIAGONAIS).
 * @param tab O tabuleiro (matriz 2D).
 * @param navio O vetor (array 1D) que representa o navio (ex: [3, 3, 3]).
 * @param linha A linha inicial para posicionar o navio (0 a 9).
 * @param coluna A coluna inicial para posicionar o navio (0 a 9).
 * @param orientacao A orientação (HORIZONTAL, VERTICAL, DIAGONAL_PRINCIPAL, DIAGONAL_SECUNDARIA).
 * @return 1 (true) se o navio foi posicionado com sucesso, 0 (false) caso contrário.
 */
int posicionarNavio(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int navio[TAMANHO_NAVIO], 
                     int linha, int coluna, int orientacao);

// --- Função Principal (main) ---
int main() {
    
    // 1. Represente o Tabuleiro:
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // 2. Posicione os Navios (vetor protótipo):
    int navio_prototipo[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Inicializa o tabuleiro com 'AGUA' (0)
    inicializarTabuleiro(tabuleiro);

    // --- REQUISITO: Posicionar Quatro Navios ---
    // (Coordenadas definidas diretamente no código)

    // Navio 1: Horizontal (como no nível anterior)
    // (linha 0, coluna 0) -> ocupará (0,0), (0,1), (0,2)
    posicionarNavio(tabuleiro, navio_prototipo, 0, 0, HORIZONTAL);

    // Navio 2: Vertical (como no nível anterior)
    // (linha 2, coluna 0) -> ocupará (2,0), (3,0), (4,0)
    posicionarNavio(tabuleiro, navio_prototipo, 2, 0, VERTICAL);

    // Navio 3: Diagonal Principal
    // (linha 2, coluna 2) -> ocupará (2,2), (3,3), (4,4)
    posicionarNavio(tabuleiro, navio_prototipo, 2, 2, DIAGONAL_PRINCIPAL);

    // Navio 4: Diagonal Secundária
    // (linha 0, coluna 9) -> ocupará (0,9), (1,8), (2,7)
    posicionarNavio(tabuleiro, navio_prototipo, 0, 9, DIAGONAL_SECUNDARIA);

    /* // ---- EXEMPLO DE VALIDAÇÃO (Teste) ----
    // Tente descomentar este bloco. Deve falhar por sobreposição com o Navio 4.
    
    int navio5_linha = 2;
    int navio5_coluna = 7; // Sobrepõe o (2,7) do Navio 4
    if (!posicionarNavio(tabuleiro, navio_prototipo, navio5_linha, navio5_coluna, HORIZONTAL)) {
        printf("Falha ao posicionar Navio 5: Sobreposição detectada!\n\n");
    }
    */


    // 3. Exiba o Tabuleiro:
    printf("### Batalha Naval - Nível Aventureiro (Diagonais) ###\n\n");
    exibirTabuleiro(tabuleiro);

    return EXIT_SUCCESS;
}


// --- Implementação das Funções ---

/**
 * @brief Inicializa o tabuleiro com 'AGUA' (0). (Sem alterações)
 */
void inicializarTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tab[i][j] = AGUA;
        }
    }
}

/**
 * @brief Exibe o estado atual do tabuleiro no console. (Sem alterações)
 */
void exibirTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   "); // Espaço para o cabeçalho das linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        // Imprime cabeçalho de coluna formatado
        printf("%d ", j); 
    }
    printf("\n");
    
    printf("   --------------------\n"); // 10 * 2 = 20 traços

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i); // Cabeçalho da linha
        
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Tenta posicionar um navio no tabuleiro (ATUALIZADO PARA DIAGONAIS).
 */
int posicionarNavio(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int navio[TAMANHO_NAVIO], 
                     int linha, int coluna, int orientacao) {

    // --- REQUISITO: VALIDAÇÃO DE LIMITES (Agora com diagonais) ---
    // Checagem inicial de coordenadas (redundante, mas boa prática)
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return 0; // Falha: Posição inicial fora do tabuleiro
    }

    // Checagem de limites com base na orientação
    switch (orientacao) {
        case HORIZONTAL:
            // Verifica se o navio "cai" para fora da borda direita
            if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
            break;
        case VERTICAL:
            // Verifica se o navio "cai" para fora da borda inferior
            if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
            break;
        case DIAGONAL_PRINCIPAL:
            // Verifica se "cai" para fora da borda inferior OU direita
            if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
                coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
            break;
        case DIAGONAL_SECUNDARIA:
            // Verifica se "cai" para fora da borda inferior OU esquerda
            // (coluna - (TAMANHO_NAVIO - 1)) deve ser >= 0
            if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
                coluna - (TAMANHO_NAVIO - 1) < 0) return 0;
            break;
        default:
            return 0; // Falha: Orientação inválida
    }

    // --- REQUISITO: VALIDAÇÃO DE SOBREPOSIÇÃO (Agora com diagonais) ---
    // Precisamos checar se *alguma* das posições futuras já está ocupada.
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        switch (orientacao) {
            case HORIZONTAL:
                if (tab[linha][coluna + i] == NAVIO) return 0; // Falha: Sobreposição
                break;
            case VERTICAL:
                if (tab[linha + i][coluna] == NAVIO) return 0; // Falha: Sobreposição
                break;
            case DIAGONAL_PRINCIPAL:
                if (tab[linha + i][coluna + i] == NAVIO) return 0; // Falha: Sobreposição
                break;
            case DIAGONAL_SECUNDARIA:
                if (tab[linha + i][coluna - i] == NAVIO) return 0; // Falha: Sobreposição
                break;
        }
    }

    // --- POSICIONAMENTO (Agora com diagonais) ---
    // Se passou em todas as validações, podemos posicionar o navio.
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        switch (orientacao) {
            case HORIZONTAL:
                tab[linha][coluna + i] = navio[i];
                break;
            case VERTICAL:
                tab[linha + i][coluna] = navio[i];
                break;
            case DIAGONAL_PRINCIPAL:
                tab[linha + i][coluna + i] = navio[i];
                break;
            case DIAGONAL_SECUNDARIA:
                tab[linha + i][coluna - i] = navio[i];
                break;
        }
    }

    return 1; // Sucesso!
}