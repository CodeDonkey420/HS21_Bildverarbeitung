#pragma once
#include "image-io.h"

extern void reset_matrix(unsigned char in[MAXXDIM][MAXYDIM]);
extern int anzahl(unsigned char input[MAXXDIM][MAXYDIM]);
extern int grassfire_step(int x, int y, unsigned char in[MAXXDIM][MAXYDIM], unsigned char mask[MAXXDIM][MAXYDIM]);
extern void matrix_xor(unsigned char in1[MAXXDIM][MAXYDIM], unsigned char in2[MAXXDIM][MAXYDIM]);
