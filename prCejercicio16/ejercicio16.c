/*
 * ejercicio16.c
 *
 *  Created on: Jan 1, 2014
 *      Author: alsdk
 *
 *  Escribe un programa para eliminar los blancos y los tabuladores
 *  del final de las lineas y los tabuladores de cada linea de entrada
 *  y para borrar completamente las lineas en blanco.
 *
 *  Escribe una funcion reverse(s) que invierta la cadena de caracteres
 *  s. Utilizala para escribir un programa que invierta la entrada, linea a linea.
 *
 */
#include <stdio.h>

#define		MAXFRASE	20

/*
 * devuelve la longitud de la cadena escrita en frase
 * o 0 si EOF
 */
int getlinea(char *frase, int len) {
	int c;
	int i;

	for (i = 0; i <= len && (c = getchar()) != '\n'; ++i)
		frase[i] = c;

	if (c == '\n')
		frase[i] = '\0';

	return i;
}

// elimina los blancos (&)
void desplaza(char *f, int len) {
	int i, z;

	for (i = 0; i <= len && f[i] != '\0'; ++i) {
		if (f[i] == '&') {
			for (z = 0; z <= len; ++z)
				f[z] = f[z+1];
		}
	}
	return;
}

/*
 * elimina blancos y tabuladores al principio y final de las lineas
 * devuelve el numero de caracteres borrados
 */
int trim(char *frase, int len) {
	int i;
	int borrado = 0;								// contador caracteres borrados
	int firstChar = 0;								// 1 true, 0 false
	int lastChar = 0;

	// eliminar espacios al principio de linea
	for (i = 0; i <= len && frase[i] != '\0'; ++i) {
		if (firstChar == 0 && (frase[i] == ' ' || frase[i] == '\t')) {
			frase[i] = '&';
			++borrado;
		}
		else
			firstChar = 1;
	}

	// eliminar espacios al final de linea
	for (i = len; i >= 0; --i) {
		if (lastChar == 0 && (frase[i] == '\t' || frase[i] == ' ' || frase[i] == '\0')) {
			frase[i] = '\0';
			++borrado;
		}
		else
			lastChar = 1;
	}

	// eliminar frases en blanco
	if (firstChar == 0 && lastChar == 0)
		frase[0] = '\0';

	desplaza(frase, len);
	return borrado;
}

void reverse(char *f, int len) {
	int i = 0, z = 0;
	char c;

	for (i = len; i >= 0; --i) {
		if (f[i] != '\0' && f[i] != '\n') {
			c = f[z];								// guardo posicion antes de sobreescribir
			f[z] = f[i];							// se le da la vuelta
			f[i] = c;
			++z;
		}
	}

	return;
}

int main(int argc, char *argv[]) {
	char frase[MAXFRASE];
	int len = 0;									// longitud de la linea
	int i;

	for (i = 0; i <= MAXFRASE-1; ++i)
		frase[i] = '\0';

	printf("Escribe...\n");
	while ((len = getlinea(frase, MAXFRASE-1)) > 0) {
		trim(frase, MAXFRASE-1);
		//reverse(frase, MAXFRASE-1);
		printf("%s\n", frase);
	}

	return 0;
}
