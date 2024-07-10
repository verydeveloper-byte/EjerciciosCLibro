/*
 * ejercicio06.c
 *
 *  Created on: Dec 29, 2013
 *      Author: alsdk
 */

#include <stdio.h>

/*
 * Escribe un programa para contar blancos, tabuladores
 * y caracteres nueva-linea
 */
int main(int argc, char* argv[]) {
	int c;			// caracter
	int tb = 0;			// tabuladores
	int espacios = 0;	// espacios en blanco
	int nuevaLinea = 0;	// nueva linea

	printf("Introduce letra: ");
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			++tb;
		else if (c == ' ')
			++espacios;
		else if (c == '\n')
			++nuevaLinea;

		printf("Tabuladores: %d\n Espacios: %d\n Linea nueva: %d\n", tb, espacios, nuevaLinea);
	}

	return 0;
}
