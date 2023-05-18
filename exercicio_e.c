#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Curso {
    char codigo[6];
    char nome[26];
    int anos;
    struct Curso *proximo;
};

struct Curso *inicio = NULL;

void add() {
    // Criando um novo nó
    struct Curso *novo = malloc(sizeof(struct Curso));
    if (novo == NULL) {
        printf("Não foi possível alocar memória para o novo curso.\n");
        return;
    }

    // Lendo os dados do curso a ser adicionado
    printf("Código do curso (máximo de 5 caracteres): ");
    scanf("%5s", novo->codigo);
    printf("Nome do curso (máximo de 25 caracteres): ");
    scanf("%25s", novo->nome);
    printf("Número de anos: ");
    scanf("%d", &novo->anos);

    // Inserindo o novo nó no início da lista
    novo->proximo = inicio;
    inicio = novo;

    printf("O curso foi adicionado com sucesso!\n");
}

// Função para remover um curso da lista
void remover(char codigo[6]) {
    struct Curso *anterior = NULL;
    struct Curso *atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->codigo, codigo) == 0) {
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("O curso com código %s não foi encontrado.\n", codigo);
        return;
    }

    // Removendo o curso da lista
    if (anterior == NULL) {
        inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);

    printf("O curso com código %s foi removido com sucesso!\n", codigo);
}

void listarCursos() {
    if (inicio == NULL) {
        printf("Não há cursos na lista.\n");
        return;
    }

    printf("Lista de cursos:\n");
    struct Curso *atual = inicio;
    while (atual != NULL) {
        printf("Código: %s | Nome: %s | Anos: %d\n", atual->codigo, atual->nome, atual->anos);
        atual = atual->proximo;
    }
}

int procurar(char codigo[6]) {
    struct Curso *atual = inicio;
    while (atual != NULL) {
        if (strcmp(atual->codigo, codigo) == 0) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int main() {
    int opcao;
    char codigo[6];
    
    //menu
    do {
        printf("\n");
        printf("Escolha uma opção:\n");
        printf("1 - Adicionar curso\n");
        printf("2 - Remover curso\n");
        printf("3 - Listar cursos\n");
        printf("4 - Procurar curso\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("clear");
                add();
                break;
            case 2:
                system("clear");
                printf("Código do curso a ser removido: ");
                scanf("%5s", codigo);
                remover(codigo);
                break;
            case 3:
                system("clear");
                listarCursos();
                break;
            case 4:
                system("clear");
                printf("Código do curso a ser procurado: ");
                scanf("%5s", codigo);
                if (procurar(codigo)) {
                    printf("O curso com código %s foi encontrado.\n", codigo);
                } else {
                    printf("O curso com código %s não foi encontrado.\n", codigo);
                }
                break;
            case 0:
                system("clear");
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    // Liberando a memória alocada
    struct Curso *atual = inicio;
    while (atual != NULL) {
        struct Curso *prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    return 0;
}
