#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Recebe vetor e dois índices; troca o conteúdo entre as duas posições. */
void swap(int vetor[], int i, int j) {
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

/* Outra solução (by Vand): recursivo!! */
void bubble_rec(int v[], int n) {
    if (n <= 1) return;

    int i;

    /* esse for deixa o maior elemento no final */
    for (i = 0; i < n-1; i++)
        if (v[i] > v[i+1])
            swap(v, i, i+1);
    
    /* Só resta ordenar do 0 até o n-1 */
    bubble_rec(v, n-1);
}


/* imprime vetor v de tamanho n */
void imprime(int v[], int n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}