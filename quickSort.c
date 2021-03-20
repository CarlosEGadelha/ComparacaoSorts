#include <stdio.h>
#include <stdlib.h>

/* Recebe vetor e dois índice; troca o conteúdo entre as
   duas posições. */
void swap_Qs(int vetor[], int i, int j) {
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

/* Recebe vetor v e índice ini e fim, que são o primeiro e o último índice válido, respectivamente.

   Particiona o vetor em duas regiões:
   A região inicial contém valores menores do que o pivô;
   a região final contém valores maiores que o pivô.

   Retorna a posição em que o pivô ficou.

   Obs.: essa implementação específica usa v[fim] como pivô.
   Isso não é obrigatório. */
int particiona(int v[], int ini, int fim) {
    int i, j;
    int pivo = v[fim];
    
    // i é sempre a próxima posição a ser preenchida da parte esquerda
    i = ini;

    // esse for preenche o pedaço esquerdo da partição
    for (j = ini; j < fim; j++) {
        if (v[j] < pivo) {
            swap_Qs(v, i, j);
            i++; // incremento o i pois coloquei mais um elemento na esquerda
        }
    }
    
    // temos que posicionar o pivô logo depois do pedaço esquerdo.
    swap_Qs(v, i, fim); // pivô é o valor em v[fim]
    return i;
}

/* Ordena o vetor v da posição ini até a posição fim. */
void quicksort(int v[], int ini, int fim) {
    // se o vetor tiver tamanho 1 ou 0, não faz nada
    if ((fim-ini+1) <= 1) return;

    // i é a posição em que o pivô ficou
    int i = particiona(v, ini, fim);

    // ordeno as duas partes (obs: pivô não entra em nenhuma)
    quicksort(v, ini, i-1);
    quicksort(v, i+1, fim);
}