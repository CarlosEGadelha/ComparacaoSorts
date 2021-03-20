#include <stdio.h>
#include <stdlib.h>

/* Recebe um vetor que está ordenado das regiões
   [ini] até [meio] e [meio+1] até [fim]
   e intercala essas regiões para que o vetor fique
   ordenado na região [ini] até [fim]
*/
void intercala(int v[], int ini, int meio, int fim) {
    int esq, dir; // percorrem pedaço esquerdo e direito, respectivamente

    int i; // percorre o vetor novo
    int n = (fim-ini+1); // tamanho do vetor novo;
    int * novo = malloc(n*sizeof (int));

    i = 0;
    esq = ini;
    dir = meio+1; 
    
    // enquanto nenhuma região acabou...
    while (esq <= meio && dir <= fim) {
        if (v[esq] < v[dir]) {
            novo[i] = v[esq];
            esq++;
        }
        else {
            novo[i] = v[dir];
            dir++;
        }
        i++;
    }

    // copia o que restou da esquerda (se houver)
    while (esq <= meio) novo[i++] = v[esq++];

    // copia o que restou da direita (se houver)
    while (dir <= fim) novo[i++] = v[dir++];

    // agora o vetor novo está ordenado.
    // copio seu conteúdo para o vetor original!
    for (i = 0; i < n; i++)
        v[ini+i] = novo[i]; // v começa em ini, não em 0

    free(novo);
}

/* Recebe um vetor e ordena sua região que vai
   do índice [ini] até o índice [fim] */
void merge_sort(int v[], int ini, int fim) {
    int meio;
    // Só preciso ordenar se o vetor tem tamanho > 1
    if (ini < fim) {
        meio = (ini+fim)/2;       // calcula meio do vetor
        merge_sort(v, ini, meio); // ordena pedaço esquerdo
        merge_sort(v, meio+1, fim); // ordena pedaço direito
        intercala(v, ini, meio, fim); // intercala pedaço
    }
}