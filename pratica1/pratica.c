#include <stdio.h>
#include <stdlib.h>

void corrigeMatriz(int **image, int M, int N, int X, int Y) {
    int **temp = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        temp[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) {
            int ni = (i + Y + M) % M;
            int nj = (j - X + N) % N;
            temp[i][j] = image[ni][nj];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            image[i][j] = temp[i][j];
        }
        free(temp[i]);
    }
    free(temp);
}

int main() {
    int M, N;
    int **image;
    int teste = 1;

    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        image = (int **)malloc(M * sizeof(int *));
        for (int i = 0; i < M; i++) {
            image[i] = (int *)malloc(N * sizeof(int));
            for (int j = 0; j < N; j++) {
                scanf("%d", &image[i][j]);
            }
        }

        int X, Y;
        while (1) {
            scanf("%d %d", &X, &Y);
            if (X == 0 && Y == 0) break;
            corrigeMatriz(image, M, N, X, Y);
        }

        printf("Teste %d\n", teste ++);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", image[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for (int i = 0; i < M; i++) {
            free(image[i]);
        }
        free(image);
    }

    return 0;
}
