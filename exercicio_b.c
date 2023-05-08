#include <stdio.h>
#include <stdlib.h>

/*
    Programa que declara, define e chama uma função que receba como parâmetro dois arrays de
    inteiros, A e B, de tamanho N. A função deve retornar um ponteiro para um array C de tamanho N
    alocado dinamicamente, em que C[i] = A[i] * B[i].
*/
int* produto(int a[], int b[]);
int N = 5;


int main() {

    int A[] = {3, 5, 7, 9, 11};
    int B[] = {2, 4, 6, 8, 10};
    int* C = produto(A, B);

    printf("Tendo os dois vetores A & B:\n\n");

    for (int i = 0; i < N; i++) {
        if (i==0) {
            printf("   A[] = {");
        }
        printf("%d", A[i]);
        if (i<=N-2) {
            printf(", ");
        }
        if (i==N-1) {
            printf("}");
        }
    }
    printf("\n");
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
    printf("\n");
    printf("\nO produto retornado entre os vetores A[] && B[]:\n\n");

    for (int i = 0; i < N; i++) {
        if (i==0) {
            printf("   C[] = {");
        }
        printf("%d", C[i]);
        if (i<=N-2) {
            printf(", ");
        }
        if (i==N-1) {
            printf("}");
        }
    }
    printf("\n\n");
    free(C);
    return 0;
}

int* produto(int* a, int* b){
    int* c = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        c[i] = a[i] * b[i];
    }
    return c;
}