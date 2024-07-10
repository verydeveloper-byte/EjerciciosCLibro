/*
 * ejercicio10.c
 *
 *  Created on: Dec 29, 2013
 *      Author: alsdk
 *
 *  Escribe un programa que escriba las palabras que lea,
 *  una en cada linea.
 */
#include <stdio.h>

int main(int argc, char* argv[]) {
	int c;
	int nl;							// nueva linea

	printf("Escribe... \n");
	while((c = getchar()) != EOF) {
		if (c == ' ' && !nl) {
			++nl;
			printf("\n");
		}
		else {
			putchar(c);
			nl = 0;
		}
	}

	return 0;
}

