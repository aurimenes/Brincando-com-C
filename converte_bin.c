#include "stdio.h"
#include "stdlib.h"

int main(int argc, char **argv) {  // Recebimento de par�metros do sistema operacional
	register int cont = 0; // Vari�vel register tem um acesso mais r�pido que as normais
	                       // embora, com os computadores r�pidos que temos hoje, n�o
	                       // fa�a tanta diferen�a...
	int valor;
	char result[17];       // matriz de caracteres onde o valor bin�rio ficar� guardado          
	
	if (argc != 2) {
		printf("Modo de uso:\n");
		printf("%s <numero inteiro>\n\n", argv[0]);
		return(1);
	}
	
	valor = atoi(argv[1]); // Converte o valor recebido no par�metro em inteiro
	
	// Converte o n�mero para bin�rio, dividindo por 2 e guardando 1 caso tenha
  // resto, ou 0 caso n�o tenha. Esta � a f�rmula b�sica de convers�o de
  // decimal em bin�rio
	while (valor > 0) { // Enquanto existir valor a dividir,
	  // Nesta pr�xima linha, tem v�rios conceitos envolvidos (e isso � muito legal
	  // na linguagem C.
	  // Primeiro, cont � usado para determinar a posi��o na matriz, iniciando em zero
	  // (o valor foi atribu�do na linha 5).
	  // Depois o valor de cont � incrementado
	  // Em seguida, o resto da divis�o do valor por 2 (que pode ser zero ou um)
	  // � acrescido de 48, que � a posi��o do zero na tabela ASCII, � atibu�do �
	  // posi��o em result[]
		result[cont++] = (valor % 2) + 48; 
		
		// E aqui, mais uma funcionalidade bacana de C, que � a troca de lugar dos 
		// bytes, fazendo com que o valor seja dividido por 2. Exemplo:
		// Imagine o n�mero 15, que em bin�rio, � representado por 1111. 
		// Se eu pego todos os bytes e movo 1 para a direita, o �ltimo byte �
		// "perdido" e o valor fica 0111, que � 7 (ou seja, � 15 / 2, desprezando-se
		// as casas decimais). Se eu fizer o contr�rio, e mover 1111 um bit para 
		// a esquerda, o valor se torna 11110, que � 30 em decimais - ou seja, o 
		// n�mero foi multiplicado por 2. 
		valor = valor >> 1; // Divide valor por 2
	}
	
	cont--; // aqui eu "acerto" o contador, que ficou acrescido de 1 ao final do loop
	
	while(cont >= 0) // E aqui eu exibo, de tr�s pra frente, os zeros e uns do n�mero
		putchar(result[cont--]); // bin�rio. C permite a cria��o de c�digos compactos!
		
	putchar('\n');	
};


