#include <stdio.h>
#include <stdlib.h>

int N = 5;
int* matrix(int A[N][N]);


int main(){
    int A[5][5] = {
        {3, 2, 6, 4, 8},
        {2, 5, 9, 1, 7},
        {4, 2, 6, 9, 3},
        {3, 1, 5, 3, 5},
        {5, 4, 8, 6, 7}};
    int* B = matrix(A);

    printf("Tendo a matriz A[5][5]:\n\n");

    for (int j = 0; j < N; j++) {
        if (j==0) {
                printf("A[][] = {\n");
            }
        for (int i = 0; i < N; i++) {
            if (i==0) {
                printf("   {");
            }
            printf("%d", A[j][i]);
            if (i<=N-2) {
                printf(", ");
            }
            if (i==N-1) {
                printf("}");
            }
        }
        printf("\n");
        if (j==N-1) {
                printf("}");
            }
    }
    printf("\n\nO resultado retornado:\n\n");

    for (int i = 0; i < N; i++) {
        if (i==0) {
            printf("   B[] = {");
        }
        printf("%d", B[i]);
        if (i<=N-2) {
            printf(", ");
        }
        if (i==N-1) {
            printf("}");
        }
    }
    printf("\n\n");
    free(B);
    return 0;

    
}

int* matrix(int A[N][N]){
    int* B = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            B[i] += A[i][j];
        }
    }
    return B;
}