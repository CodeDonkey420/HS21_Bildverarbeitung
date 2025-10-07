#include "utils.h"

void reset_matrix(unsigned char in[MAXXDIM][MAXYDIM]) {
	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
			in[x][y] = 0;
		}
	}
}
int anzahl(unsigned char input[MAXXDIM][MAXYDIM]) {
	int Zähler = 0; //Varaibale für das Zählen von nicht schwarzen Pixeln
	int x, y;

	for (x = 0; x < MAXXDIM; x++){
		for (y = 0; y < MAXYDIM; y++){
			Zähler += input[x][y] != 0;
		}

	}
	return Zähler;
}