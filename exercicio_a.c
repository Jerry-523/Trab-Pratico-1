
#include <stdio.h>
#include <stdlib.h>

int* criarArray(int N){
	if(N <= 0 ){
		return NULL;
	}
	
	int* array = (int*) malloc(N * sizeof(int));
	if (array == NULL){
		return NULL;
	}
	for(int i = 0; i < N; i++){
		array[i] = i+2;
	}
	return array;
}

int main(){
	int N;
	int* array;
	printf("Insira o tamanho do Array: ");
	scanf("%d", &N);
	
	array = criarArray(N);
	
	if (array == NULL){
		printf("Erro: não foi possível alocar o array.\n");
		return 1;
	}
	// imprime os elementos do array
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array); // libera a memória alocada dinamicamente para o array

    return 0;
}
