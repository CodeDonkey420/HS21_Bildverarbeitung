#include <stdio.h>
#include"image-io.h"

int menu() {
	int i;
	printf("--------------Menue---------------\n");
	printf("1. Bild einlesen\n");
	printf("2. Kopie erstellen\n");
	printf("3. Orginalbild anzeigen lassen\n");
	printf("0. Ende\n");
	printf("Wahl : ");
	scanf("%i", &i);
	getchar();
	return i;
}

void main() {
	int wahl;
	unsigned char image[MAXXDIM][MAXYDIM]; //Speicherplatz für das Bild erzeugen
	int result;
	int eingelesen = 0;

	do
	{
		wahl = menu();
		switch (wahl)
		{
		case 1:
			result = readImage_ppm(image); //Bild auswählen und in den Buffer laden
			if (result == 0) {
				printf("Bild erfolgreich eingelesen.\n");
				eingelesen = 1;
			}
			else
			{
				printf("Fehler beim einlesen");
			}
			break;
		case 2:
			if (!eingelesen) {
				printf("Kein Bild geladen! Bitte zuerst ein Bild einlesen.\n");
			}
			else {
				printf("Welches Bild ist zu kopieren? \n");
				readImage_ppm(image);
				printf("Dateiname:\n");
				result = writeImage_ppm(image, MAXXDIM, MAXYDIM);
				if (result == 0)
				{
					printf("Bild speichern war erfolgreich.\n");
				}
				else
				{
					printf("Ein Fehler ist aufgetreten.\n");
				}
			}
			break;
		case 3:
			viewImage_ppm();
			break;

		default:
			break;
		}
	} while (wahl != 0);
}

// Menü erstellen



//if (result == 0) {
	//printf("Bild erfolgreich gespeichert.\n");
//}
//else {
	//printf("Fehler beim Speichern des Bildes!\n");
//}


//printf("Programm beendet.\n");

