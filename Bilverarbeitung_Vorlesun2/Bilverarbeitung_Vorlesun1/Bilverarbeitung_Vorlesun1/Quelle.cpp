#include <stdio.h>
#include "image-io.h"
#include "operarations.h"
#include "utils.h"
#include "menu.h"

void main() {
	int chosen_option;
	unsigned char image[MAXXDIM][MAXYDIM]; //Speicherplatz f�r das Bild erzeugen
	unsigned char out[MAXXDIM][MAXYDIM]; //Speicherplatz f�r das Bild erzeugen
	unsigned char temp[MAXXDIM][MAXYDIM];
	int _result;
	int eingelesen = 0;

	reset_matrix(out);

	do {
		chosen_option = menu();

		switch (chosen_option) {
			case readImage:
				_result = readImage_ppm(image); //Bild ausw�hlen und in den Buffer laden

				if (_result == 0) {
					printf("Bild erfolgreich eingelesen.\n");
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
					out[MAXXDIM][MAXYDIM]; //Speicherplatz f�r das Bild erzeugen
					dilate(image, out);
					_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				}
				break;

			case erodeImage:
				if (!eingelesen) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					out[MAXXDIM][MAXYDIM]; //Speicherplatz f�r das Bild erzeugen

					erode(image, out);
					_result = writeImage_ppm(out, MAXXDIM, MAXYDIM);
				}				
				break;
			case 6: //Pixel z�hlen
				readImage_ppm(image);
				int Z�hler = anzahl(image);
				printf("Anzahl der Pixel: %d\n", Z�hler);
				break;
			case 7: //Open Function
				if (!eingelesen) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					�ffnen(image, temp);
				}
				break;
			case 8:
				if (!eingelesen) {
					printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
				}
				else{
					Schlie�en(image, temp);
				}
				break;

			default:
				break;
		}

	} while (chosen_option != 0);
}
