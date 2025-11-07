#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS e abs()

// --- Constantes Globais do Tabuleiro ---
#define TAMANHO_TABULEIRO 10 
#define TAMANHO_NAVIO 3    

// Valores do Tabuleiro Principal
#define AGUA 0
#define NAVIO 3
// --- NOVO NÍVEL MESTRE: Valor da Habilidade ---
#define EFEITO_HABILIDADE 5

// Orientações dos Navios
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL_PRINCIPAL 2
#define DIAGONAL_SECUNDARIA 3

// --- NOVO NÍVEL MESTRE: Constantes das Habilidades ---
#define TAMANHO_HABILIDADE 5 // Tamanho fixo (5x5) para as matrizes de habilidade
#define HAB_AGUA 0           // Valor '0' na matriz de habilidade
#define HAB_EFEITO 1         // Valor '1' na matriz de habilidade

// --- Protótipos das Funções ---
void inicializarTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibirTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
int posicionarNavio(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int navio[TAMANHO_NAVIO], 
                     int linha, int coluna, int orientacao);

// --- NOVOS PROTÓTIPOS (NÍVEL MESTRE) ---

/**
 * @brief Cria uma matriz 5x5 com um padrão de Cone (1s).
 * @param matriz A matriz de habilidade 5x5 a ser preenchida.
 */
void criarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

/**
 * @brief Cria uma matriz 5x5 com um padrão de Cruz (1s).
 * @param matriz A matriz de habilidade 5x5 a ser preenchida.
 */
void criarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

/**
 * @brief Cria uma matriz 5x5 com um padrão de Octaedro/Losango (1s).
 * @param matriz A matriz de habilidade 5x5 a ser preenchida.
 */
void criarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

/**
 * @brief "Carimba" uma matriz de habilidade no tabuleiro principal.
 * @param tab O tabuleiro principal 10x10.
 * @param hab A matriz de habilidade 5x5 preenchida (o "molde").
 * @param linha_origem A linha do tabuleiro onde o *centro* da habilidade será aplicado.
 * @param coluna_origem A coluna do tabuleiro onde o *centro* da habilidade será aplicado.
 */
void sobreporHabilidade(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                        int hab[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                        int linha_origem, int coluna_origem);


// --- Função Principal (main) ---
int main() {
    
    // --- NÍVEL AVENTUREIRO (Base) ---
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int navio_prototipo[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    inicializarTabuleiro(tabuleiro);

    // Posiciona os 4 navios (2 normais, 2 diagonais)
    posicionarNavio(tabuleiro, navio_prototipo, 0, 0, HORIZONTAL);
    posicionarNavio(tabuleiro, navio_prototipo, 2, 0, VERTICAL);
    posicionarNavio(tabuleiro, navio_prototipo, 2, 2, DIAGONAL_PRINCIPAL);
    posicionarNavio(tabuleiro, navio_prototipo, 0, 9, DIAGONAL_SECUNDARIA);
    
    // --- NOVO NÍVEL MESTRE: Lógica de Habilidades ---

    // 1. Criar Matrizes de Habilidade
    int matriz_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // 2. Preencher as matrizes com os padrões
    criarMatrizCone(matriz_cone);
    criarMatrizCruz(matriz_cruz);
    criarMatrizOctaedro(matriz_octaedro);

    // 3. Integrar Habilidades ao Tabuleiro (Sobrepor)
    // Coordenadas de origem (centro) definidas no código
    
    // Sobrepõe o Cone centrado em (linha 2, coluna 5)
    sobreporHabilidade(tabuleiro, matriz_cone, 2, 5);
    
    // Sobrepõe a Cruz centrada em (linha 7, coluna 2)
    sobreporHabilidade(tabuleiro, matriz_cruz, 7, 2);

    // Sobrepõe o Octaedro centrado em (linha 6, coluna 7)
    sobreporHabilidade(tabuleiro, matriz_octaedro, 6, 7);

    // 4. Exibir o Tabuleiro Final
    printf("### Batalha Naval - Nível Mestre (Habilidades) ###\n\n");
    exibirTabuleiro(tabuleiro); // Esta função agora mostra ~, N e *

    return EXIT_SUCCESS;
}


// --- Implementação das Funções (Nível Mestre) ---

/**
 * @brief Cria uma matriz 5x5 com um padrão de Cone (1s).
 * (Requisito: Usar loops aninhados e condicionais)
 */
void criarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Ponto de origem (topo do cone) está na linha 0, centro da coluna
    int centro = TAMANHO_HABILIDADE / 2; // Para 5, centro = 2

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) { // Linhas
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) { // Colunas
            
            // Condicional: A área de efeito (j) se expande baseado na linha (i)
            // Linha 0: j >= (2-0) e j <= (2+0) -> j == 2
            // Linha 1: j >= (2-1) e j <= (2+1) -> 1 <= j <= 3
            // Linha 2: j >= (2-2) e j <= (2+2) -> 0 <= j <= 4
            if (j >= (centro - i) && j <= (centro + i)) {
                matriz[i][j] = HAB_EFEITO; // 1
            } else {
                matriz[i][j] = HAB_AGUA;   // 0
            }
        }
    }
}

/**
 * @brief Cria uma matriz 5x5 com um padrão de Cruz (1s).
 * (Requisito: Usar loops aninhados e condicionais)
 */
void criarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Para 5, centro = 2

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condicional: Está na linha central (i==2) OU na coluna central (j==2)
            if (i == centro || j == centro) {
                matriz[i][j] = HAB_EFEITO; // 1
            } else {
                matriz[i][j] = HAB_AGUA;   // 0
            }
        }
    }
}

/**
 * @brief Cria uma matriz 5x5 com um padrão de Octaedro/Losango (1s).
 * (Requisito: Usar loops aninhados e condicionais)
 */
void criarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Para 5, centro = 2

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condicional: Distância de Manhattan (dist. em linha + dist. em coluna)
            // do centro deve ser <= ao raio (centro).
            // Ex: (0,0) -> |0-2| + |0-2| = 4. (Fora)
            // Ex: (0,2) -> |0-2| + |2-2| = 2. (Dentro)
            // Ex: (1,1) -> |1-2| + |1-2| = 2. (Dentro)
            int dist = abs(i - centro) + abs(j - centro);
            if (dist <= centro) {
                matriz[i][j] = HAB_EFEITO; // 1
            } else {
                matriz[i][j] = HAB_AGUA;   // 0
            }
        }
    }
}


/**
 * @brief "Carimba" uma matriz de habilidade no tabuleiro principal.
 * (Requisito: Usar condicionais para validar limites)
 */
void sobreporHabilidade(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                        int hab[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], 
                        int linha_origem, int coluna_origem) {
    
    int centro_hab = TAMANHO_HABILIDADE / 2; // 2

    // Percorre a matriz de habilidade 5x5
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // 1. Verifica se esta parte da habilidade deve ter efeito
            if (hab[i][j] == HAB_EFEITO) {
                
                // 2. Calcula a coordenada correspondente no tabuleiro 10x10
                // (i - centro_hab) dá a posição relativa ao centro (ex: -2, -1, 0, 1, 2)
                int linha_tabuleiro = linha_origem + (i - centro_hab);
                int coluna_tabuleiro = coluna_origem + (j - centro_hab);

                // 3. Condicional (Validação de Limites):
                // Só aplica se a coordenada calculada estiver DENTRO do 10x10
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) 
                {
                    // 4. Marca o tabuleiro principal com o valor da habilidade
                    // (Sobrescreve 0 ou 3, como pedido, para visualização)
                    tab[linha_tabuleiro][coluna_tabuleiro] = EFEITO_HABILIDADE;
                }
            }
        }
    }
}


// --- Funções dos Níveis Anteriores (Atualizadas/Mantidas) ---

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
 * @brief Exibe o estado atual do tabuleiro (ATUALIZADO para caracteres).
 */
void exibirTabuleiro(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Imprime cabeçalho da coluna
    printf("   "); 
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); 
    }
    printf("\n");
    printf("   --------------------\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i); // Imprime cabeçalho da linha
        
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            
            // Condicional para exibir o caractere correto
            switch(tab[i][j]) {
                case AGUA:
                    printf("~ "); // Água
                    break;
                case NAVIO:
                    printf("N "); // Navio
                    break;
                case EFEITO_HABILIDADE:
                    printf("* "); // Habilidade
                    break;
                default:
                    printf("? "); // Desconhecido
            }
        }
        printf("\n"); // Pula para a próxima linha
    }
}

/**
 * @brief Tenta posicionar um navio (Nível Aventureiro - sem alterações).
 */
int posicionarNavio(int tab[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int navio[TAMANHO_NAVIO], 
                     int linha, int coluna, int orientacao) {

    // --- VALIDAÇÃO DE LIMITES ---
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return 0;
    }
    switch (orientacao) {
        case HORIZONTAL:
            if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
            break;
        case VERTICAL:
            if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
            break;
        case DIAGONAL_PRINCIPAL:
            if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
                coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
            break;
        case DIAGONAL_SECUNDARIA:
            if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || 
                coluna - (TAMANHO_NAVIO - 1) < 0) return 0;
            break;
        default:
            return 0;
    }

    // --- VALIDAÇÃO DE SOBREPOSIÇÃO ---
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        switch (orientacao) {
            case HORIZONTAL:
                if (tab[linha][coluna + i] == NAVIO) return 0;
                break;
            case VERTICAL:
                if (tab[linha + i][coluna] == NAVIO) return 0;
                break;
            case DIAGONAL_PRINCIPAL:
                if (tab[linha + i][coluna + i] == NAVIO) return 0;
                break;
            case DIAGONAL_SECUNDARIA:
                if (tab[linha + i][coluna - i] == NAVIO) return 0;
                break;
        }
    }

    // --- POSICIONAMENTO ---
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