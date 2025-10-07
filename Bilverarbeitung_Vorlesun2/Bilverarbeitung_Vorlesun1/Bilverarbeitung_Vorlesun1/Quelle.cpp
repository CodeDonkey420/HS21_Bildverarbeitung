#include <stdio.h>
#include "image-io.h"
#include "operarations.h"
#include "utils.h"
#include "menu.h"

void main() {
	int chosen_option;
	unsigned char image[MAXXDIM][MAXYDIM]; //Speicherplatz für das Bild erzeugen
	unsigned char out[MAXXDIM][MAXYDIM]; //Speicherplatz für das Bild erzeugen
	unsigned char mask[MAXXDIM][MAXYDIM]; //Speicherplatz für das Bild erzeugen
	unsigned char temp[MAXXDIM][MAXYDIM];
	int _result;
	int count;
	int eingelesen = 0;

	reset_matrix(out);

	do {
		chosen_option = menu();

		switch (chosen_option) {
			case readImage:
				_result = readImage_ppm(image); //Bild auswählen und in den Buffer laden

				if (_result == 0) {
					printf("Bild erfolgreich eingelesen.\n");
					eingelesen = 1;
				}

				else {
					printf("Fehler beim einlesen");
				}

				break;

			case copyImage:
				printf("Welches Bild ist zu kopieren? \n");
				readImage_ppm(image);
				printf("Neuer Dateiname:\n");
				_result = writeImage_ppm(image, MAXXDIM, MAXYDIM);
				break;

			case viewImage:
				viewImage_ppm();
				break;

			case dilateImage:
				if (!eingelesen) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else {
					dilate(image, out);
					_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				}
				break;

			case erodeImage:
				if (!eingelesen) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					erode(image, out);
					_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				}				
				break;

			case countPixels: //Pixel zählen
				readImage_ppm(image);
				count = anzahl(image);
				printf("Anzahl der Pixel: %d\n", count);
				break;

			case openOp: //Open Function
				if (!eingelesen) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					öffnen(image);
				}
				break;

			case closeOp:
				if (!eingelesen) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					Schließen(image);
				}
				break;

			case grassFire:
        count = grassfire(image, mask);
        printf("Es gibt %d Objekte\n", count);
				break;

			default:
				break;
		}

	} while (chosen_option != 0);
}
