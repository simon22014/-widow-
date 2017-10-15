#include "stdafx.h"
#include"imageDealWith.h"
/****************************************************************************/
/**************************image remap **************************************/
/****************************************************************************/
imageRamp::imageRamp()
{
	Mat image = imread("image22.jpg");
	if (!image.data)
	{
		cout << "image hav't data" << endl;
		return ;
	}
	Mat resultImage(image.size(), image.type());
	Mat xMapImage(image.size(), CV_32FC1);
	Mat yMapImage(image.size(), CV_32FC1);
	int rows = image.rows;
	int cols = image.cols;

	for (int j = 0;j < rows; j++)
	{
		for (int i = 0; i < cols;i++)
		{
			xMapImage.at<float>(j, i) = cols - i;
			yMapImage.at<float>(j, i) = rows - j;
		}
	}
	remap(image, resultImage, xMapImage, yMapImage,
		CV_INTER_LINEAR, BORDER_CONSTANT,
		Scalar(0, 0, 0));
	imageChange = resultImage.clone();

	imshow("resultimage", resultImage);
	imshow("not change image", image);
	waitKey(0);
	return;
}
imageRamp::~imageRamp()
{

}
/****************************************************************************/
/**************************image offset *************************************/
/****************************************************************************/
imageOffset::imageOffset() {
	xOffset = 10;
	yOffset = 10;
	image = imread("image22.jpg");
	imageTranslarion1();
	imageTranslarion2();
	
	


}
void imageOffset::imageTranslarion1()
{
	int nRows = image.rows;
	int nCols = image.cols;
	Mat resultImage(image.size(), image.type());
	for (int i = 0;i < nRows; i++)
	{
		for (int j = 0; j < nCols;j++)
		{
			int x = j - xOffset;
			int y = i - yOffset;
			if (x >= 0 && y >= 0 && x < nCols && y < nRows)
			{
				resultImage.at<Vec3b>(i, j) =
					image.ptr<Vec3b>(y)[x];
			}
		}
	}
	imageChange = resultImage.clone();
	imshow("imageChange1", resultImage);
	waitKey(0);
	return;

}
void imageOffset::imageTranslarion2()
{
	cout << "23" << endl;
	xOffset = 80;
	yOffset = 10;
	int nRows = image.rows + abs(yOffset);
	int nCols = image.cols + abs(xOffset);
	Mat resultImage(nRows,nCols,image.type());
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0;j < nCols; j++)
		{
			int x = j - xOffset;
			int y = i - yOffset;
			if (x >= 0 && y >= 0 && x < nCols && y < nRows)
			{
				resultImage.at<Vec3b>(i, j) =
					image.ptr<Vec3b>(y)[x];
			}
		
		}
	
	}
	cout << "3" << endl;
	imageChange = resultImage.clone();
	imshow("imageChange2", resultImage);
	waitKey(0);

}
imageOffset::~imageOffset()
{


}
/****************************************************************************/
/**************************image Zoom ***************************************/
/****************************************************************************/
void imageZoom::imageReduction1()
{
	float kx = 1;
	float ky = 1;
	int nRows = cvRound(image.rows * kx);
	int nCols = cvRound(image.cols * ky);
	Mat resultImage(nRows, nCols, image.type());
	for (int i = 0;i < nRows;i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			//int x = static_cast<int>((i + 1) / kx + 0.5) - 1;
		//	int y = static_cast<int>((j + 1) / ky + 0.5) - 1;
			int x = static_cast<int>(i / kx);
			int y = static_cast<int>(j / ky);
			resultImage.at<Vec3b>(i, j) = image.at<Vec3b>(x, y);
		}
	}
	imageChange = resultImage.clone();
//	imshow("imageChange1", imageChange);
//	waitKey(0);
}
void imageZoom::imageReduction2()
{
	image = imread("12.png");
	if (!image.data)
	{
		return;
	}
	double kx = 1;
	double ky = 1;
	cout << "3" << endl;
	int nRows = cvRound(image.rows * kx);
	int nCols = cvRound(image.cols * ky);
	Mat resultImage(nRows, nCols, image.type());

	int leftRowCoordinate = 0;
	int leftColCoordinate = 0;
	for (int i = 0;i < nRows; i++)
	{
		int x = static_cast<int> ((i + 1) / kx + 0.5) - 1;
		for (int j = 0; j < nCols;j++)
		{
			int y = static_cast<int>((j + 1) / ky + 0.5) - 1;
	//		cout << "x" << x << "leftRowCoordinate" << leftRowCoordinate << endl;
	resultImage.at<Vec3b>(i, j) = areaAverage(Point_<int>(leftRowCoordinate, leftColCoordinate), Point_ <int>(x, y));
		//	resultImage.at<Vec3b>(i, j) = image.at<Vec3b>(x, y);
		//	resultImage.at<Vec3b>(i, j) = areaAverage(Point_<int>(leftRowCoordinate, leftColCoordinate),
			//	Point_ <int>(x, y));
		}	
	}
	cout << "2" << endl;
	imageChange = resultImage.clone();
	imshow("image", image);
	imshow("imageChange2", resultImage);
	waitKey(0);

}
Vec3b imageZoom::areaAverage(Point_<int> leftPoint, Point_<int> rightPoint)
{
	int temp1 = 0 ,temp2 = 0,temp3 = 0;
	int nPix = (rightPoint.x - leftPoint.x + 1) * (rightPoint.y - leftPoint.y + 1);
//	cout << "x" << (rightPoint.x - leftPoint.x + 1) << "y" << (rightPoint.y - leftPoint.y + 1) << endl;
	if ( 0 == nPix)
	{
	//	cout << "123sdw" << endl;
		return{0,0,0};
	}
	for (int i = leftPoint.x; i <= rightPoint.x;i++)
	{
		for (int j = leftPoint.y;j <= rightPoint.y; j++)
		{
			temp1 += image.at<Vec3b>(i, j)[0];
			temp2 += image.at<Vec3b>(i, j)[1];
			temp3 += image.at<Vec3b>(i, j)[2];

		}
	}
	Vec3b vecTemp;
	vecTemp[0] = temp1 / nPix;
	vecTemp[1] = temp2 / nPix;
	vecTemp[2] = temp2 / nPix;
	return vecTemp;
}
imageZoom::imageZoom()
{
	image = imread("image22.jpg");
}
imageZoom::~imageZoom()
{
}
/******************************************************************************/
/**************************image rotate ***************************************/
/******************************************************************************/
void imageRotate::angelRotate()
{
	float alpha = angle * CV_PI / 180; //CV_PI 

	float rotateMat[3][3] = {
		{cos(alpha),-sin(alpha),0},
		{sin(alpha),cos(alpha),0},
		{0,0,1}
	};
	int nSrcRows = image.rows;
	int nSrcCols = image.cols;

	float a1 = nSrcCols * rotateMat[0][0];
	float b1 = nSrcCols * rotateMat[1][0];
	float a2 = nSrcCols * rotateMat[0][0] + nSrcRows * rotateMat[0][1];
	float b2 = nSrcCols * rotateMat[1][0] + nSrcRows * rotateMat[1][1];
	float a3 = nSrcRows * rotateMat[0][1];
	float b3 = nSrcRows * rotateMat[1][1];

	float kxMin = min(min(min(0.0f, a1), a2), a3);
	float kxMax = max(max(max(0.0f, a1), a2), a3);
	float kyMin = min(min(min(0.0f, b1), b2), b3);
	float kyMax = max(max(max(0.0f, b1), b2), b3);

	int nRows = abs(kxMax - kxMin);
	int nCols = abs(kyMax - kyMin);
	Mat dst(nRows, nCols, image.type(), Scalar::all(0));
	for (int i=0; i < nRows; i++) 
	{
		for (int j=0;j < nCols;j++)
		{
			int x = (j + kxMin) * rotateMat[0][0] -
				(i + kyMin) * rotateMat[0][1];
			int y = -(j + kxMin) * rotateMat[1][0] +
				(i + kyMin) * rotateMat[1][1];

			if ((x >= 0) && (x < nSrcCols) && (y >= 0) && (y < nSrcRows))
			{
				dst.at<Vec3b>(i, j) = image.at<Vec3b>(y, x);
			}
		
		}
	
	}
	imshow("dst", dst);
	waitKey(0);





}
imageRotate::imageRotate()
{
	image = imread("image22.jpg");
	if (!image.data)
	{
		cout << "the image data have not data"<< endl;
		return;		
	}
	angle = 30;
}
imageRotate:: ~imageRotate()
{
}

	