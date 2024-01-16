#include "stdio.h"
#include "stdlib.h"

int main(int argc, char **argv) {  // Recebimento de parâmetros do sistema operacional
	register int cont = 0; // Variável register tem um acesso mais rápido que as normais
	                       // embora, com os computadores rápidos que temos hoje, não
	                       // faça tanta diferença...
	int valor;
	char result[17];       // matriz de caracteres onde o valor binário ficará guardado          
	
	if (argc != 2) {
		printf("Modo de uso:\n");
		printf("%s <numero inteiro>\n\n", argv[0]);
		return(1);
	}
	
	valor = atoi(argv[1]); // Converte o valor recebido no parâmetro em inteiro
	
	// Converte o número para binário, dividindo por 2 e guardando 1 caso tenha
  // resto, ou 0 caso não tenha. Esta é a fórmula básica de conversão de
  // decimal em binário
	while (valor > 0) { // Enquanto existir valor a dividir,
	  // Nesta próxima linha, tem vários conceitos envolvidos (e isso é muito legal
	  // na linguagem C.
	  // Primeiro, cont é usado para determinar a posição na matriz, iniciando em zero
	  // (o valor foi atribuído na linha 5).
	  // Depois o valor de cont é incrementado
	  // Em seguida, o resto da divisão do valor por 2 (que pode ser zero ou um)
	  // é acrescido de 48, que é a posição do zero na tabela ASCII, é atibuído à
	  // posição em result[]
		result[cont++] = (valor % 2) + 48; 
		
		// E aqui, mais uma funcionalidade bacana de C, que é a troca de lugar dos 
		// bytes, fazendo com que o valor seja dividido por 2. Exemplo:
		// Imagine o número 15, que em binário, é representado por 1111. 
		// Se eu pego todos os bytes e movo 1 para a direita, o último byte é
		// "perdido" e o valor fica 0111, que é 7 (ou seja, é 15 / 2, desprezando-se
		// as casas decimais). Se eu fizer o contrário, e mover 1111 um bit para 
		// a esquerda, o valor se torna 11110, que é 30 em decimais - ou seja, o 
		// número foi multiplicado por 2. 
		valor = valor >> 1; // Divide valor por 2
	}
	
	cont--; // aqui eu "acerto" o contador, que ficou acrescido de 1 ao final do loop
	
	while(cont >= 0) // E aqui eu exibo, de trás pra frente, os zeros e uns do número
		putchar(result[cont--]); // binário. C permite a criação de códigos compactos!
		
	putchar('\n');	
};


