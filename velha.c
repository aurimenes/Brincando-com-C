#include "stdio.h"
#include "stdlib.h"
#include <locale.h>

char matrix[3][3];

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void display_matrix(void);

void main(void) {
	char done;

	setlocale(LC_ALL, "pt-BR");

	printf("Este é o jogo da velha.\n");
	printf("Você estará jogando contra o computador.\n");

	done = ' ';
	init_matrix();

	do {
		display_matrix();
		get_player_move();
		done = check();

		if (done != ' ')
			break;

		get_computer_move();
		done = check();

		if (done != ' ')
			break;

	} while (done == ' ');

	display_matrix();

	if (done == 'X')
		printf("Você ganhou! \\o/\n\n");
	else
		printf("Eu ganhei!\n\n");

}

void init_matrix(void) {
	int i, j;

	for (i = 0; i < 3; i++)	 {
		for (j = 0; j < 3; j++) {
			matrix[i][j] = ' ';
		}
	}
}

void get_player_move(void) {
	int x, y;
	printf("Entre com as coordenadas para o X: ");
	scanf("%d%d", &x, &y);

	x--; y--;

	if (matrix[x][y] != ' ') {
		printf("Posicao inválida! Tente novamente.\n\n");
		get_player_move();
	} else 
		matrix[x][y] = 'X';
}

int conta_ln(int x, char letra) {
	int y, soma = 0;

	for (y = 0; y < 3; y++)
		if (matrix[x][y] == letra)
			soma++;

	return(soma);
}

int conta_col(int y, char letra) {
	int x, soma = 0;

	for (x = 0; x < 3; x++)
		if (matrix[x][y] == letra)
			soma++;

	return(soma);
}

void get_computer_move(void) {
	int i, j;
	int cont;

	// Verifica se falta somente um para ganhar (linhas)
	for (i = 0; i < 3; i++) {
		if (conta_ln(i, 'O') == 2) {
			for (j = 0; j < 3; j++) {
				if (matrix[i][j] == ' ') {
					matrix[i][j] = 'O';
					return;
				}
			}
		}
	}

	// Verifica se falta somente um para ganhar (colunas)
	for (j = 0; j < 3; j++) {
		if (conta_col(j, 'O') == 2) {
			for (i = 0; i < 3; i++) {
				if (matrix[i][j] == ' ') {
					matrix[i][j] = 'O';
					return;
				}
			}
		}
	}

	// Verifica se falta somente um para ganhar (Diagonal 1,1/3,3)
	cont = 0;

	for (j = 0; j < 3; j++) {
		if (matrix[j][j] == 'O')
			cont++;
	}

	if (cont == 2) {
		for (j = 0; j < 3; j++) {
			if (matrix[j][j] == ' ') {
				matrix[j][j] = 'O';
				return;
			}
		}
	}

	// Verifica se falta somente um para ganhar (Diagonal 1,3/3,1)	
	cont = 0;

	for (j = 0; j < 3; j++) {
		if (matrix[abs(j - 2)][j] == 'O')
			cont++;
	}

	if (cont == 2) {
		for (j = 0; j < 3; j++) {
			if (matrix[abs(j - 2)][j] == ' ') {
				matrix[abs(j - 2)][j] = 'O';
				return;
			}
		}
	}

	// Verifica se falta um para o oponente ganhar (linhas)
	for (i = 0; i < 3; i++) {
		if (conta_ln(i, 'X') == 2) {
			for (j = 0; j < 3; j++) {
				if (matrix[i][j] == ' ') {
					matrix[i][j] = 'O';
					return;
				}
			}
		}
	}

	// Verifica se falta um para o oponente ganhar (colunas)
	for (j = 0; j < 3; j++) {
		if (conta_col(j, 'X') == 2) {
			for (i = 0; i < 3; i++) {
				if (matrix[i][j] == ' ') {
					matrix[i][j] = 'O';
					return;
				}
			}
		}
	}

	// Dá preferência pelo centro (2,2)
	if (matrix[1][1] == ' ') {
		matrix[1][1] = 'O';
		return;
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			if (matrix[i][j] == ' ')
				break;
		if (matrix[i][j] == ' ')
			break;
	}

	if (i * j == 9) {
		display_matrix();
		printf("Empate!\n\n");
		exit(0);
	} else 
		matrix[i][j] = 'O';
}

void display_matrix(void) {
	int t;

	printf("\n\n");

	for (t =0; t < 3; t++) {
		printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);

		if (t != 2)
			printf("\n---|---|---\n");
	}
	printf("\n\n");
}


char check(void) {
	int i;

	for (i = 0; i < 3; i++) {
		if ((matrix[i][0] == matrix[i][1]) && (matrix[i][0] == matrix[i][2]))
			return(matrix[i][0]);

		if ((matrix[0][i] == matrix[1][i]) && (matrix[0][i] == matrix[2][i]))
			return(matrix[0][i]);
	}

	if ((matrix[0][0] == matrix[1][1]) && (matrix[0][0] == matrix[2][2]))
		return(matrix[0][0]);

	if ((matrix[0][2] == matrix[1][1]) && (matrix[2][0] == matrix[1][1]))
		return(matrix[1][1]);

	return(' ');
}