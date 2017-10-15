#include "stdafx.h"
#include "Cbtw_imageDealWith.h"




Cbtw_imageDealWith::Cbtw_imageDealWith()
{
	//theFirstImage = imread("C:\\Users\\user\\Desktop\\涂胶Opencv\\x64\\Debug\\image\\A10-03-CAM1-OK#2.5#5.7#4.1-1491639-2017.05.31.08.06.01.808-2017.08.18.09.37.27.989.jpg");  //存放自己图像的路径 
//	theFirstImage = imread("C:\\Users\\user\\Desktop\\涂胶Opencv\\x64\\Debug\\image\\Testimage\\2.jpg");
	theFirstImage = imread("E:\\demon\\demo_simon_all_class\\demo_simon_all_class\\image22.jpg");
	Mat theChangeMat = theFirstImage.clone();
	imshow("theChangeMat", theChangeMat);
	waitKey(0);
	Mat mergeImg;//合并后的图像  
	vector<Mat> splitBGR(theChangeMat.channels());
	//分割通道，存储到splitBGR中  
	split(theChangeMat, splitBGR);
	//对各个通道分别进行直方图均衡化  
	for (int i = 0; i<theChangeMat.channels(); i++)
		equalizeHist(splitBGR[i], splitBGR[i]);
	//合并通道  
	merge(splitBGR, mergeImg);

	imshow("mergeImg", mergeImg);
	imshow("image", theChangeMat);
	waitKey(0);
	//Cbtw_imageSpot();
	Cbtw_imageConnect();
//	cvSnakeImage
}
void Cbtw_imageDealWith::SnakeImage(Mat& image)
{


}
void Cbtw_imageDealWith::Cbtw_imageSpot() //斑点
{
	Mat firstImage = theFirstImage.clone();
	vector<KeyPoint> keyPoints;
	SimpleBlobDetector::Params params;
	params.minThreshold = 10;
	params.maxThreshold = 255;
	//像素面积大小控制
	params.filterByArea = true;
	params.minArea = 10;
	//形状（凸）
	params.filterByCircularity = true;
	params.minCircularity = 0.7;
	//形状（凹）
	params.filterByConvexity = true;
	params.minConvexity = 0.9;
	//形状（园）
	params.filterByInertia = false;
	params.minInertiaRatio = 1;

	SimpleBlobDetector blobDetect(params);
	blobDetect.create("SimpleBlob");
	blobDetect.detect(firstImage, keyPoints);
	cout << keyPoints.size() << endl; 
	drawKeypoints(firstImage, keyPoints, firstImage, Scalar(0, 0, 255));
	namedWindow("blobs");
	imshow("blobs", firstImage);
	waitKey(0);
}
void Cbtw_imageDealWith::salt(Mat& image, int n) {
	for (int k = 0; k<n; k++) {
		int i = rand() % image.cols;
		int j = rand() % image.rows;

		if (image.channels() == 1) {   //判断是一个通道
			image.at<uchar>(j, i) = 255;
		}
		else {
			image.at<cv::Vec3b>(j, i)[0] = 255;
			image.at<cv::Vec3b>(j, i)[1] = 255;
			image.at<cv::Vec3b>(j, i)[2] = 255;
		}
	}
}
void Cbtw_imageDealWith::Cbtw_imageConnect() //联通域
{
	Mat afterDealWithImage;
	int cmin = 10;   // 最小轮廓长度
	int cmax = 100;   // 最大轮廓长度
	Mat image = theFirstImage.clone();
	Mat imageShold;
	//salt(image, 30000);
//	imshow("salt", image);
//	Mat element = getStructuringElement(0, Size(4 * 1 + 1, 4 * 1 + 1), Point(1, 1));
	//cv::erode(image, image, element);
//	cv::erode(image, image, element);
	//	cv::erode(image, image, element);
	//	cv::dilate(image, image, element);
//		cv::dilate(image, image, element);
	cv::threshold(image, image, 50, 255, CV_THRESH_BINARY_INV);
//	cv::adaptiveThreshold(image, imageShold, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY_INV, 25, 10);
//	threshold(image, imageShold, 82, 250, THRESH_BINARY);   // 必须进行二值化
	//threshold(image, imageShold, 72, 250, THRESH_BINARY);   // 必须进行二值
	imshow("threshold1", image);
	salt(image, 30000);
	blur(image, image, Size(5, 5), Point(-1, -1));
//	medianBlur(image, image, 5);
	imshow("salt", image);
	waitKey(0);
#if 0
	threshold(image, imageShold, 82, 250, CV_THRESH_TRUNC);   // 必须进行二值
	imshow("threshold3", imageShold);

	threshold(image, imageShold, 82, 250, CV_THRESH_TOZERO);   // 必须进行二值
	imshow("threshold4", imageShold);

	threshold(image, imageShold, 82, 250, CV_THRESH_TOZERO_INV);   // 必须进行二值
	imshow("threshold5", imageShold);

	threshold(image, imageShold, 82, 250, CV_THRESH_BINARY_INV);   // 必须进行二值
	imshow("threshold2", imageShold);

#endif 

	afterDealWithImage = image.clone();
//	cvtColor(imageShold, afterDealWithImage, CV_GRAY2BGR);//转化边缘检测后的图为灰度图
	int cPointR, cPointG, cPointB;
	for (int i = 0; i < afterDealWithImage.rows; i++)
	{
		for (int j = 0; j < afterDealWithImage.cols; j++)
		{

			cPointR = afterDealWithImage.at<Vec3b>(i, j)[0];
			cPointG = afterDealWithImage.at<Vec3b>(i, j)[1];
			cPointB = afterDealWithImage.at<Vec3b>(i, j)[2];
			if (cPointR == 0 && cPointG == 0 && cPointB == 0)
			{
				afterDealWithImage.at<Vec3b>(i, j)[0] = 255;
				afterDealWithImage.at<Vec3b>(i, j)[1] = 255;
				afterDealWithImage.at<Vec3b>(i, j)[2] = 255;
				//		WriteLog(cPointR, cPointG, cPointB);
			}
			else
			{
				afterDealWithImage.at<Vec3b>(i, j)[0] = 0;
				afterDealWithImage.at<Vec3b>(i, j)[1] = 0;
				afterDealWithImage.at<Vec3b>(i, j)[2] = 0;

			}
		}
	}
	imshow("dealWithImage", afterDealWithImage);

	cv::Canny(afterDealWithImage, afterDealWithImage, 20, 20 * 3, 3);
	imshow("canny", afterDealWithImage);
#if 0
	vector<vector<Point>> contours;
	//CV_CHAIN_APPROX_NONE  获取每个轮廓每个像素点
	findContours(imageShold, contours, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE, cvPoint(0, 0));
	

	
	if (contours.size() != 0)
	{
		vector<vector<Point>>::const_iterator itc = contours.begin();
		while (itc != contours.end())
		{
			if ((itc->size()) < cmin || (itc->size()) > cmax)
			{
				itc = contours.erase(itc);
			}
			else ++itc;
		}
	}


	cout << contours.size() << endl;
	Mat result(image.size(), CV_8U, Scalar(255));
	drawContours(result, contours, -1, Scalar(0), 2);   // -1 表示所有轮廓
	namedWindow("result");
	imshow("result", result);
#endif 
	namedWindow("image");
	imshow("image", image);
	waitKey(0);
}

Cbtw_imageDealWith::~Cbtw_imageDealWith()
{
}
