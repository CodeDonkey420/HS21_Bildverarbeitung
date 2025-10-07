#include "utils.h"

void reset_matrix(unsigned char in[MAXXDIM][MAXYDIM]) {
	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
			in[x][y] = 0;
		}
	}
}
int anzahl(unsigned char input[MAXXDIM][MAXYDIM]) {
	int Z�hler = 0; //Varaibale f�r das Z�hlen von nicht schwarzen Pixeln
	int x, y;

	for (x = 0; x < MAXXDIM; x++){
		for (y = 0; y < MAXYDIM; y++){
			Z�hler += input[x][y] != 0;
		}

	}
	return Z�hler;
}