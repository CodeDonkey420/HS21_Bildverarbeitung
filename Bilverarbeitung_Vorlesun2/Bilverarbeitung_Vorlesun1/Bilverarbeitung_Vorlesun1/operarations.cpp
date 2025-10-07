#include "operarations.h"
#include <string.h>

void dilate(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]) {
	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
			bool has_neighbor = false;

			if (x != 0) {
				has_neighbor |= in[x - 1][y] == 255;
			}

			if (y != 0) {
				has_neighbor |= in[x][y - 1] == 255;
			}

			if (x != MAXXDIM - 1) {
				has_neighbor |= in[x + 1][y] == 255;
			}

			if (y != MAXYDIM - 1) {
				has_neighbor |= in[x][y + 1] == 255;
			}

			bool is_filled = in[x][y] == 255;
			
			out[x][y] = (has_neighbor || is_filled) * 255;
		}
	}
}

void erode(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]) {
	for (int x = 1; x < MAXXDIM - 1; x++) {
		for (int y = 1; y < MAXYDIM - 1; y++) {
			bool has_neighbor = in[x - 1][y] == 255 && in[x][y - 1] == 255 && in[x + 1][y] == 255 && in[x][y + 1] == 255 && in[x][y] == 255;

			out[x][y] = has_neighbor * 255;
		}
	}
}

void öffnen(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]) {
	int result;
	int schleifen;
	unsigned char temp[MAXXDIM][MAXYDIM];
	unsigned char image[MAXXDIM][MAXYDIM];

	printf("Anzahl an Schleifen?\n"); //Abfrage wie oft die Funktion Öffnen durchgeführt werden soll
	scanf("%d", &schleifen);
	memcpy(temp, image, sizeof(image)); //Kopiere nach temp aus image alle Bits die image hat
	for (int i = 0; i < schleifen; i++) {
		unsigned char eroded[MAXXDIM][MAXYDIM]; //Speicherpaltz erzeugen
		erode(temp, eroded);
		memcpy(temp, eroded, MAXXDIM * MAXYDIM);
	}
	for (int i = 0; i < schleifen; i++) {
		unsigned char dilated[MAXXDIM][MAXYDIM];
		dilate(temp, dilated);
		memcpy(temp, dilated, MAXXDIM * MAXYDIM);
	}
	result = writeImage_ppm(temp, MAXXDIM, MAXYDIM);
}

void Schließen(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]) {
	int result;
	int schleifen;
	unsigned char temp[MAXXDIM][MAXYDIM];
	unsigned char image[MAXXDIM][MAXYDIM];

	printf("Anzahl an Schleifen?\n"); //Abfrage wie oft die Funktion Öffnen durchgeführt werden soll
	scanf("%d", &schleifen);
	memcpy(temp, image, sizeof(image)); //Kopiere nach temp aus image alle Bits die image hat
	for (int i = 0; i < schleifen; i++) {
		unsigned char dilated[MAXXDIM][MAXYDIM];
		dilate(temp, dilated);
		memcpy(temp, dilated, MAXXDIM * MAXYDIM);
	}
	for (int i = 0; i < schleifen; i++) {
		unsigned char eroded[MAXXDIM][MAXYDIM];
		erode(temp, eroded);
		memcpy(temp, eroded, MAXXDIM * MAXYDIM);
	}
	result = writeImage_ppm(temp, MAXXDIM, MAXYDIM);
}