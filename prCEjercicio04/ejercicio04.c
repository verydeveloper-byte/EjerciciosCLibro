/*
 * aplicacion que imprime una tabla de conversion de temperaturas Celsius-Fahrenheit
 */

#include <stdio.h>

void cel2fahr(void);	// imprime tabla celsius a fahrenheit

int main(int argc, char* argv []) {
	cel2fahr();
	return 0;
}

void cel2fahr(void) {
	float celsius = 0;
	float fahr = 0;
	int fin = 300;		// terminar en 300 celsius
	int step = 3;		// incremento

	/* la formula para convertir celsius a fahrenheit es
		 * F = (C*9/5)+32
		 */
	for (celsius=0.0; celsius<=fin; celsius+=step) {
		fahr = (celsius * 9.0 / 5.0) + 32.0;
		printf("%4.0f ºC -> %4.1f F\n", celsius, fahr);
	}

	return;
}
