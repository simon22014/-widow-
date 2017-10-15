#include "stdafx.h"
#include "inpaintClass.h"

inpaintClass::inpaintClass()
{
	beforeImage = imread("E:\\demon\\demo_simon_all_class\\testmap\\1.bmp");
	afterImage = imread("E:\\demon\\demo_simon_all_class\\testmap\\2.bmp");
	if (!beforeImage.data)
	{
		return ;
	}
	Mat imageGray;
	//ת��Ϊ�Ҷ�ͼ
	cvtColor(beforeImage, imageGray, CV_RGB2GRAY, 0);
	Mat imageMask = Mat(beforeImage.size(), CV_8UC1, Scalar::all(0));

	//ͨ����ֵ��������Mask
	threshold(imageGray, imageMask, 100, 255, CV_THRESH_BINARY);
	Mat Kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	//��Mask���ʹ�������Mask���
	dilate(imageMask, imageMask, Kernel);

	//ͼ���޸�
	inpaint(beforeImage, imageMask, beforeImage, 5, INPAINT_TELEA);
	imshow("before", beforeImage);
	imshow("after", imageMask);
	waitKey(0);


}
inpaintClass::~inpaintClass()
{
}
