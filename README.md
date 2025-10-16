# Super Trunfo em C - Nível Mestre (Desafio Final)

Este projeto é a versão final do jogo Super Trunfo em linguagem C, como parte de um desafio da faculdade de Análise e Desenvolvimento de Sistemas.

Nesta versão, o programa atinge sua complexidade máxima, permitindo que o jogador escolha dois atributos distintos para uma comparação avançada. A carta vencedora é determinada pela maior soma dos valores dos atributos escolhidos.

## Como Compilar e Executar

Para compilar o programa, use o seguinte comando no terminal:

```bash
gcc super_trunfo.c -o super_trunfo

#### Como Jogar

Ao executar o programa, você passará por dois menus para escolher os atributos de comparação:

Escolha do Primeiro Atributo: Um menu apresentará todos os atributos disponíveis.

Escolha do Segundo Atributo: Um menu dinâmico será exibido, omitindo a opção escolhida anteriormente.

Resultado: O programa exibirá os valores de cada atributo para as duas cartas, a soma total para cada uma, e declarará a carta vencedora com base na maior soma total.

Atributos Disponíveis:
População

Área

PIB

Pontos Turísticos

Densidade Demográfica

Observação: A regra "menor vence" para a Densidade Demográfica se aplicaria em uma comparação de atributo único. Neste nível, a regra final é sempre a maior soma dos valores brutos dos dois atributos escolhidos.