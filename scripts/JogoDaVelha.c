#include <stdio.h>

#define SIZE 3

void jogodavelha(char quadro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", quadro[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

int seganhou(char quadro[SIZE][SIZE]) {
    // Verificar linhas
    for (int i = 0; i < SIZE; i++) {
        if (quadro[i][0] == quadro[i][1] && quadro[i][1] == quadro[i][2] && quadro[i][0] != ' ') {
            return quadro[i][0];
        }
    }
    // Verificar colunas
    for (int i = 0; i < SIZE; i++) {
        if (quadro[0][i] == quadro[1][i] && quadro[1][i] == quadro[2][i] && quadro[0][i] != ' ') {
            return quadro[0][i];
        }
    }
    // Verificar diagonais
    if (quadro[0][0] == quadro[1][1] && quadro[1][1] == quadro[2][2] && quadro[0][0] != ' ') {
        return quadro[0][0];
    }
    if (quadro[0][2] == quadro[1][1] && quadro[1][1] == quadro[2][0] && quadro[0][2] != ' ') {
        return quadro[0][2];
    }
    return 0;
}

int jogocompleto(char quadro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (quadro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void jogar(char quadro[SIZE][SIZE], int Jogador) {
    int linha, coluna;
    char simbolo = (Jogador == 1) ? 'X' : 'O';
    while (1) {
        printf("Jogador %d (%c), Faca sua Jogada (Linha e coluna): ", Jogador, simbolo);
        scanf("%d %d", &linha, &coluna);
        if (linha >= 1 && linha <= SIZE && coluna >= 1 && coluna <= SIZE && quadro[linha-1][coluna-1] == ' ') {
            quadro[linha-1][coluna-1] = simbolo;
            break;
        } else {
            printf("Movimento invalido, Tente novamente.\n");
        }
    }
}

int main() {
    char quadro[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int JogadorAtual = 1;
    int vencedor = 0;

    while (!vencedor && !jogocompleto(quadro)) {
        jogodavelha(quadro);
        jogar(quadro, JogadorAtual);
        vencedor = seganhou(quadro);
        if (!vencedor) {
            JogadorAtual = (JogadorAtual == 1) ? 2 : 1;
        }
    }

    jogodavelha(quadro);

    if (vencedor) {
        printf("Jogador %d vence!\n", (vencedor == 'X') ? 1 : 2);
    } else {
        printf("Deu velha!\n");
    }

    return 0;
}
