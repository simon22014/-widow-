#include"stdafx.h"
#include"FindCircle.h"
Mat img;
FindCircle::FindCircle()
{


}
void on_mousesimon(int event, int x, int y, int flags, void *ustc)
{
	Mat dstImage1;

	if (event == CV_EVENT_LBUTTONDOWN)
	{	
		resize(img, dstImage1, Size(img.cols *0.5, img.rows*0.5), (0, 0), (0, 0), 3);
		namedWindow("dst");          //���½���һ�����ڽ���������
		imshow("dst", dstImage1);
		waitKey(0);
	}
	else if (event == CV_EVENT_RBUTTONDOWN)
	{
		resize(img, dstImage1, Size(img.cols *0.1, img.rows*0.1), (0, 0), (0, 0), 3);
		namedWindow("dst ");          //���½���һ�����ڽ���������
		imshow("dst", dstImage1);
		waitKey(0);
	}


}
void FindCircle::find_Circle()
{
	img = imread("E:\\demon\\demo_simon_all_class\\demo_simon_all_class\\image\\circle.bmp", 0);
	namedWindow("������",  0);//��������
	setMouseCallback("������", on_mousesimon, 0);//���ûص�����  
	imshow("������", img);

	waitKey(0);

}