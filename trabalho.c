#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de Recursão para calcular o produto escalar entre uma linha de A e uma coluna de B
int produto_escalar_recursivo(int *A, int *B, int i, int j, int k, int n, int r) {
    if (k == n) return 0;
    return A[i * n + k] * B[k * r + j] + produto_escalar_recursivo(A, B, i, j, k + 1, n, r);
}

// Função para calcular matriz C = A x B
void calcular_matriz(int *A, int *B, int *C, int m, int n, int r) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < r; j++) {
            C[i * r + j] = produto_escalar_recursivo(A, B, i, j, 0, n, r);
        }
    }
}

// Função para exibir uma matriz
void exibir_matriz(int *matriz, int linhas, int colunas, char nome) {
    printf("Matriz %c:\n", nome);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%4d ", matriz[i * colunas + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para preencher matriz manualmente ou aleatoriamente
void preencher_matriz(int *matriz, int linhas, int colunas, char nome, int modo) {
    if (modo == 1) {
        printf("Digite os elementos da matriz %c:\n", nome);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                scanf("%d", &matriz[i * colunas + j]);
            }
        }
    } else {
        printf("Gerando matriz %c com valores aleatórios...\n", nome);
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                matriz[i * colunas + j] = rand() % 10; // valores de 0 a 9
            }
        }
    }
}

int main() {
    int m, n, r, escolha;

    // Semente do gerador aleatório
    srand(time(NULL));

    // Lê dimensões das matrizes
    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &m);
    printf("Digite o número de colunas da matriz A (e número de linhas da matriz B): ");
    scanf("%d", &n);
    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &r);

    // Aloca memória para as matrizes
    int *A = (int *)malloc(m * n * sizeof(int));
    int *B = (int *)malloc(n * r * sizeof(int));
    int *C = (int *)malloc(m * r * sizeof(int));

    if (!A || !B || !C) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    // Escolha de preenchimento
    printf("Deseja preencher as matrizes manualmente (1) ou aleatoriamente (2)? ");
    scanf("%d", &escolha);

    // Preencher as matrizes
    preencher_matriz(A, m, n, 'A', escolha);
    preencher_matriz(B, n, r, 'B', escolha);

    // Exibir matrizes
    exibir_matriz(A, m, n, 'A');
    exibir_matriz(B, n, r, 'B');

    // Calcular C = A x B
    calcular_matriz(A, B, C, m, n, r);

    // Exibir resultado
    exibir_matriz(C, m, r, 'C');

    // Liberar memória
    free(A);
    free(B);
    free(C);

    return 0;
}
