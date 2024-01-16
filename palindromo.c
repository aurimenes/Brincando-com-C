#include "stdio.h"

#define FALSO 0
#define VERDADE 1

int palindromo(char *str1);

void main(void) {
	if (palindromo("socorram me subi no onibus em marrocos"))	
		printf("\nVerdadeiro!");
	else
	  printf("\nFalso!");
	  
	if (palindromo("essa frase não é um palíndromo"))	
		printf("\nVerdadeiro!");
	else
	  printf("\nFalso!");
	  
}

int palindromo(char *str1) {
	int inicio = 0;
	int fim = strlen(str1) - 1;
	
	while (inicio < fim) {
		// Ignora os espaços
		while (str1[inicio] == ' ')
			inicio++;
			
		while (str1[fim] == ' ')
			fim--;
		
		if (str1[inicio++] != str1[fim--])
			return FALSO;
	}
	
	return VERDADE;
}



