#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "image-io.h"


extern void dilate(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]);
extern void erode(unsigned char in[MAXXDIM][MAXYDIM], unsigned char out[MAXXDIM][MAXYDIM]);
extern void �ffnen(unsigned char in[MAXXDIM][MAXYDIM]);
extern void Schlie�en(unsigned char in[MAXXDIM][MAXYDIM]);
extern int grassfire(unsigned char in[MAXXDIM][MAXYDIM], unsigned char mask[MAXXDIM][MAXYDIM]);
