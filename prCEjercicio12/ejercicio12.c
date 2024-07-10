/*
 * ejercicio12.c
 *
 *  Created on: Dec 29, 2013
 *      Author: alsdk
 */
/* ejercicio arreglos

#include <stdio.h>

int main(int argc, char* argv[]) {
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != '-') {
		if (c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}

	printf("digits =");
	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf("\nwhite space = %d, other = %d\n", nwhite, nother);


	return 0;
}
*/

/*
 * Escribe un programa que imprima un histograma con la longitud
 * de las palabras de su entrada. Lo mas facil es dibujar un histograma
 * horizontal, pero una orientacion vertical es mas interesante.
 */
#include <stdio.h>

#define		PALABRA		50

int main(int argc, char* argv[]) {
	int c;
	int i, z;
	int palabra[PALABRA];

	for (i = 0; i < PALABRA; ++i)
		palabra[i] = 0;

	printf("Escribe una frase...\n");
	for (i = 0; i < PALABRA && (c = getchar()) != EOF; ++i) {
		if (c != ' ' && c != '\n' && c != '\t') {
			//guardo letra
			palabra[i] = c;
		}
		else {
			// imprimo palabra
			for (z = 0; z < i; ++z)
				putchar(palabra[z]);
			printf(" tiene %d caracteres\n", i);

			for (z = i; z >= 0; --z)
				palabra[z] = 0;

			i = -1;
		}
	}
	return 0;
}
