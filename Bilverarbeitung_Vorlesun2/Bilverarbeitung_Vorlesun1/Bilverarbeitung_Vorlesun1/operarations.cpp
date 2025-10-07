#include "operarations.h"
#include <string.h>
#include "utils.h"

void dilate(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]) {
  // TODO change to -2 instead of -1
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
	// reset border pixels
	for (int j = 1; j < MAXXDIM - 1; j++) {
		out[j][0] = 0;
		out[j][MAXYDIM - 1] = 0;
		out[0][j] = 0;
		out[MAXXDIM - 1][j] = 0;
	}
	// reset corners
	out[0][0] = 0;
	out[MAXXDIM - 1][0] = 0;
	out[0][MAXYDIM - 1] = 0;
	out[MAXXDIM - 1][MAXYDIM - 1] = 0;

	for (int x = 1; x < MAXXDIM - 1; x++) {
		for (int y = 1; y < MAXYDIM - 1; y++) {
			bool has_neighbor = in[x - 1][y] == 255 && in[x][y - 1] == 255 && in[x + 1][y] == 255 && in[x][y + 1] == 255 && in[x][y] == 255;

			out[x][y] = has_neighbor * 255;
		}
	}
}

void öffnen(unsigned char in[MAXXDIM][MAXYDIM]) {
	int result;
	int schleifen;
	unsigned char temp[MAXXDIM][MAXYDIM];

	printf("Anzahl an Schleifen?\n"); //Abfrage wie oft die Funktion Öffnen durchgeführt werden soll
	scanf("%d", &schleifen);
	memcpy(temp, in, MAXXDIM * MAXYDIM); //Kopiere nach temp aus image alle Bits die image hat
                                      //
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

void Schließen(unsigned char in[MAXXDIM][MAXYDIM]) {
	int result;
	int schleifen;
	unsigned char temp[MAXXDIM][MAXYDIM];

	printf("Anzahl an Schleifen?\n"); //Abfrage wie oft die Funktion Öffnen durchgeführt werden soll
	scanf("%d", &schleifen);
	memcpy(temp, in, MAXXDIM * MAXYDIM); //Kopiere nach temp aus image alle Bits die image hat

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


int grassfire(unsigned char in[MAXXDIM][MAXYDIM], unsigned char mask[MAXXDIM][MAXYDIM]) {
  reset_matrix(mask);

  int mask_counter = 0;

	for (int x = 0; x < MAXXDIM; x++) {
		for (int y = 0; y < MAXYDIM; y++) {
      if (in[x][y] == 255) {
        grassfire_step(x, y, in, mask);

        mask_counter++;

        // save mask to file
        char	imagedir[128]="C:\\bv\\";
        char	fname[30] = "mask_";
        char  index[3];
        FILE	*fpimage;
        int		i,j;
        int		type=255;

        char	dirbvdir[256]="dir C:\\bv\\*.ppm /B";

        sprintf(index, "%d", mask_counter);
        strcat(fname, index);
        strcat(fname,".ppm");
        strcat(imagedir,fname);

        if ((fpimage = fopen(imagedir,"w+")) == NULL) {
          printf("Kann Datei <%s> nicht oeffnen!\n",imagedir);
          return 1;
        } else {
          fprintf(fpimage,"P3\n");
          fprintf(fpimage,"# Created by IrfanView\n");
          fprintf(fpimage,"%d %d\n",MAXXDIM,MAXYDIM);
          fprintf(fpimage,"%d\n",type);
        
          for (i=0;i<MAXXDIM;i++){
            for (j=0;j<MAXYDIM;j++){
              fprintf(fpimage,"%d %d %d ",mask[i][j], mask[i][j], mask[i][j]);
            }
          }
        }
        fclose(fpimage);

        // AND on input image
        matrix_xor(in, mask);

        // reset mask
        reset_matrix(mask);
      }
    }
  }

  return mask_counter;
}
