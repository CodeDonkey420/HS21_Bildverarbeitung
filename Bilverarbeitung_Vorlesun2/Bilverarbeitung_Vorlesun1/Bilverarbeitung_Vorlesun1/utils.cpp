#include "utils.h"
#include <string.h>

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

int grassfire_step(int x, int y, unsigned char in[MAXXDIM][MAXYDIM], unsigned char mask[MAXXDIM][MAXYDIM]) {

  if (x != 0) {
    if (in[x-1][y] == 255 && mask[x-1][y] != 255) {
      mask[x-1][y] = 255;
      grassfire_step(x-1, y, in, mask);
    }
  }

  if (y != 0) {
    if (in[x][y-1] == 255 && mask[x][y-1] != 255) {
      mask[x][y-1] = 255;
      grassfire_step(x, y-1, in, mask);
    }
  }

  if (x != MAXXDIM - 1) {
    if (in[x+1][y] == 255 && mask[x+1][y] != 255) {
      mask[x+1][y] = 255;
      grassfire_step(x+1, y, in, mask);
    }
  }

  if (y != MAXYDIM - 1) {
    if (in[x][y+1] == 255 && mask[x][y+1] != 255) {
      mask[x][y+1] = 255;
      grassfire_step(x, y+1, in, mask);
    }
  }

  return 0;
}

void matrix_xor(unsigned char in1[MAXXDIM][MAXYDIM], unsigned char in2[MAXXDIM][MAXYDIM]) {
  unsigned char out[MAXXDIM][MAXYDIM];

	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
			out[x][y] = ((in1[x][y] == 255) ^ (in2[x][y] == 255)) * 255;
		}
	}

  memcpy(in1, out, MAXXDIM * MAXYDIM);
}
  
