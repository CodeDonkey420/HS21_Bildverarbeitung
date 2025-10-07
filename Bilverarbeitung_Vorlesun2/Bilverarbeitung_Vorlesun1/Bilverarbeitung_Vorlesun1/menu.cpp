#include <stdio.h>

int menu() {
	int i;
	printf("--------------Menu---------------\n");
	printf("1. Bild einlesen\n");
	printf("2. Kopie erstellen\n");
	printf("3. Orginalbild anzeigen lassen\n");
	printf("4. Dilate\n");
	printf("5. Erosion\n");
	printf("0. Ende\n");
	printf("Wahl : ");
	scanf("%i", &i);
	getchar();
	return i;
}
