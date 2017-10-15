#include "stdafx.h"
#include"main.h"
#include "peaPointORB.h"
#include "imageDealWith.h"
#include "inpaintClass.h"
void image_inpaint()
{
	inpaintClass* inpaintImage = new inpaintClass();
	return;
	
}
void feaPointOrb(FILE* fp)
{
	peaPointORB* PointORB = new peaPointORB(fp);
	PointORB->theAlgFunction();
}
void image_Ramp()
{
	imageRamp * ramp = new imageRamp();
	return;
}
void image_Offset()
{
	imageOffset*  Offset = new imageOffset();
	return;

}
void image_Zoom()
{
	imageZoom * Zoom = new imageZoom();
	Zoom->imageReduction1();
//	Zoom->imageReduction2();

	return;
}
void image_rotate()
{
	imageRotate * Rotate = new imageRotate();
	Rotate->angelRotate();
	return;

}
void imageDealWith()
{
	bool ifOrQuit = true;
	cout << "0:×ø±êÓ³Éä,1:Imageoffset,2:Ëõ·Å,3:Ðý×ª" << endl;
	int dealWithNum;
	cin >> dealWithNum;
	while (ifOrQuit)
	{
		switch (dealWithNum)
		{
		case IMAGE_RAMP:
			image_Ramp();
			ifOrQuit = false;
			break;
		case IMAGEOFFSET:
			image_Offset();
			ifOrQuit = false;
			break;
		case IMAGEZOOM:
			image_Zoom();
			ifOrQuit = false;
			break;
		case IMAGEROTATE:
			image_rotate();
			ifOrQuit = false;
			break;






		
		
		
		}
	
	
	}


}