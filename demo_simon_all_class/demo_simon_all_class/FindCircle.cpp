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
		namedWindow("dst");          //即新建立一个窗口进行输出结果
		imshow("dst", dstImage1);
		waitKey(0);
	}
	else if (event == CV_EVENT_RBUTTONDOWN)
	{
		resize(img, dstImage1, Size(img.cols *0.1, img.rows*0.1), (0, 0), (0, 0), 3);
		namedWindow("dst ");          //即新建立一个窗口进行输出结果
		imshow("dst", dstImage1);
		waitKey(0);
	}


}
void FindCircle::find_Circle()
{
	img = imread("E:\\demon\\demo_simon_all_class\\demo_simon_all_class\\image\\circle.bmp", 0);
	namedWindow("窗口名",  0);//创建窗口
	setMouseCallback("窗口名", on_mousesimon, 0);//调用回调函数  
	imshow("窗口名", img);

	waitKey(0);

}