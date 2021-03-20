#include <stdio.h>
#include <stdlib.h>

/* Recebe vetor e dois índice; troca o conteúdo entre as
   duas posições. */
void swapRand(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

/*Particiona o vetor em duas regiões:
  A região inicial contém valores menores do que o pivô e a região final contém valores maiores que o pivô.*/
int particionaRandom(int v[], int ini, int fim) {
    //sorteia um índice aleatório entre inicio e fim
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (fim - ini + 1);
    int randomPivo = ini + k;
    
    //coloca o pivô aleatório no fim para aplicar a partição de Cormen
    swapRand(v, randomPivo, fim);
        
    //o pivo é o elemento final
    int pivo = v[fim];
    int i = ini - 1;
    int j;
    /*
    Este for irá varrer os vetores da esquerda para direira procurando os elementos que são menores ou iguais ao pivô.
    Esses elementos são colocados na partição esquerda.
    */
    for (j = ini; j <= fim - 1; j++) {
        if (v[j] <= pivo) {
            i = i + 1;
            swapRand(v, i, j);
        }
    }
    //coloca o pivô na posição de ordenação
    swapRand(v, i + 1, fim);
    return i + 1; //retorna a posição do pivô
}

void quicksortAleatorio(int v[], int ini, int fim) {
    if (ini < fim) {
        //realiza a partição
        int q = particionaRandom(v, ini, fim);
        //ordena a partição esquerda
        quicksortAleatorio(v, ini, q - 1);
        //ordena a partição direita
        quicksortAleatorio(v, q + 1, fim);
    }
}