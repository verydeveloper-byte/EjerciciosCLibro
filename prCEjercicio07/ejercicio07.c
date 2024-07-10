/*
 * escribe un programa que copie su entrada a su salida,
 * reemplazando cada cadena de uno o mas blancos por uno solo.
 */

#include <stdio.h>

int main(int argc, char* argv[]) {
	int c;
	int blanco = 0;

	printf("Escribe ...\n");

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++blanco;
			if (blanco < 2)
				putchar(c);
		}
		else {
			putchar(c);
			blanco = 0;
		}
	}

	return 0;
}
