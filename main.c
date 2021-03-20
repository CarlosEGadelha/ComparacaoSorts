#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "bubbleSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "quickSortRandomico.h"

/* Recebe um inteiro N, gera um vetor com N posições e preenche o vetor com valores randômicos entre 1 até 2N*/
int * gera_vetor(int N) {
    int i;
    int *vetor;
    vetor = (int *) malloc(N*sizeof (int));
    srand(time(0));
    
    for (i = 0; i < N; i++){
      vetor[i] = rand() % (2*N)+1;
    }

    return vetor;
}

// Função que faz copias com base no vetor original
int * copia(int * original, int N){
  int i;
  int *vetor_copia;
  vetor_copia = (int *) malloc(N*sizeof (int));
  for(i=0; i<N; i++){
    vetor_copia[i] = original[i];
  }
  
  return vetor_copia;
}

int main(void) {
  int vTamanho[] = {10, 20, 100, 200, 1000, 2000, 10000, 20000, 100000, 200000, 1000000, 2000000};
  
  for(int j=0; j<12; j++){
    float mediaBubble = 0, mediaMerge = 0, mediaQuick = 0, mediaQuickRand = 0;

    int *vetor, *copia1, *copia2, *copia3;

    for(int i=0; i<10;i++){
      vetor = gera_vetor(vTamanho[j]);
      copia1 = copia(vetor, vTamanho[j]);
      copia2 = copia(vetor, vTamanho[j]);
      copia3 = copia(vetor, vTamanho[j]);
      sleep(1);
      
      clock_t inicio, final;
      double tempo;

      if(vTamanho[j]<100000){
        inicio = clock(); // mede tempo antes da tarefa
        bubble_rec(copia3, vTamanho[j]);
        final = clock(); // mede tempo logo após a tarefa
        tempo = ((double) (final-inicio)/CLOCKS_PER_SEC);
        mediaBubble += tempo;
      }

      inicio = clock();
      merge_sort(copia1, 0, vTamanho[j]-1);
      final = clock(); 
      tempo = ((double) (final-inicio)/CLOCKS_PER_SEC);
      mediaMerge += tempo;

      inicio = clock(); 
      quicksort(vetor, 0, vTamanho[j]-1);
      final = clock();
      tempo = ((double) (final-inicio)/CLOCKS_PER_SEC);
      mediaQuick += tempo;

      inicio = clock();
      quicksortAleatorio(copia2, 0, vTamanho[j]-1);
      final = clock();
      tempo = ((double) (final-inicio)/CLOCKS_PER_SEC);
      mediaQuickRand += tempo;

      free(vetor);
      free(copia1);
      free(copia2);
      free(copia3);
    }
         
    mediaBubble = mediaBubble/10;
    mediaMerge = mediaMerge/10;
    mediaQuick = mediaQuick/10;
    mediaQuickRand = mediaQuickRand/10;

    printf("N = %d\n", vTamanho[j]);
    printf("Bubble: %f segundos em media\n", mediaBubble);
    printf("Merge: %f segundos em media\n", mediaMerge);
    printf("Quick: %f segundos em media\n", mediaQuick);
    printf("Quick Rand: %f segundos em media\n\n",mediaQuickRand);
  }

  return 0;
}