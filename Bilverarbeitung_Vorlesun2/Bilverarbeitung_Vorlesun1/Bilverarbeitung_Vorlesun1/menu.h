#pragma once

enum MenuOpts {
	quit,
	readImage,
	copyImage,
	viewImage,
	dilateImage,
	erodeImage,
	countPixels,
	openOp,
	closeOp,
	grassFire,
	
} menuOpts;

extern int menu();
