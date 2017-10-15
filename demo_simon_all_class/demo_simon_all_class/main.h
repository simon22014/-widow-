#pragma once
#include "stdafx.h"
enum Image_DealWith {
	IMAGE_RAMP,
	IMAGEOFFSET,
	IMAGEZOOM,
	IMAGEROTATE,
};
void feaPointOrb(FILE* fp);
void imageDealWith();
void image_Ramp();
void image_Offset();
void image_Zoom();
void image_rotate();
void image_inpaint();
