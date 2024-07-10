/*
 * ejercicio15.c
 *
 *  Created on: Dec 30, 2013
 *      Author: alsdk
 *
 *  Escribe un programa para imprimir todas las lineas
 *  que tengan mas de 80 caracteres de longitud.
 *
 */
#include <stdio.h>

#define		MAXFRASE	1000
#define		MAXCHAR		10

/*
 * devuelve la longitud de la cadena escrita en frase
 * o 0 si EOF
 */
int getlinea(char *frase, int len) {
	int c;
	int i;

	for (i = 0; i < len-1 && (c = getchar()) != '\n'; ++i)
		frase[i] = c;

	if (c == '\n')
		frase[i] = '\0';

	return i;
}

int main(int argc, char *argv[]) {
	char frase[MAXFRASE];				// frase leida
	int longitud = 0;					// longitud de la frase

	printf("Escribe...\n");
	while ((longitud = getlinea(frase, MAXFRASE)) > 0) {
		if (longitud >= MAXCHAR) {
			printf("%s\n", frase);
		}
	}

	return 0;
}
