#pragma once
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include<opencv2/nonfree/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace::std;
using namespace::cv;
class Cbtw_imageDealWith
{
public:
	Cbtw_imageDealWith();
	~Cbtw_imageDealWith();
	void Cbtw_imageSpot();
	void Cbtw_imageConnect(); //°ßµã
	void salt(Mat& image, int n);
	void SnakeImage(Mat& image);

private:
	Mat theFirstImage;
	Mat dealWithImage;
};

