/*
 * ejercicio13.c
 *
 *  Created on: Dec 30, 2013
 *      Author: alsdk
 *
 *  Escribe un programa que convierta su entrada a minusculas
 *  utilizando la funcion lower(c), que devuelve c si c no es una letra,
 *  o la letra minuscula correspondiente si c es una letra.
 *
 */
#include <stdio.h>

int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		c += 32;

	return c;
}

int main(int argc, char* argv[]) {
	int c;

	printf("Escribe...\n");
	while ((c = getchar()) != EOF) {
		putchar(lower(c));
	}

	return 0;
}
