#include <stdio.h>

int main() {
    // Declaração e inicialização das variáveis
    int idade = 17;
    float altura = 1.75;

    // Estrutura condicional para verificar os critérios
    if (idade >= 18 && idade <= 30 && altura > 1.70) {
        printf("Você está na faixa etária e tem a altura adequada\n");
    } else {
        printf("Você não atende aos critérios\n");
    }

    // Indica que o programa foi concluído com sucesso
    return 0;
}