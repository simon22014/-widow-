#pragma once
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include<opencv2/nonfree/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include<cstdio>
#include"main.h"
using namespace std;
using namespace cv;
class imageRamp {
public:
	imageRamp();
	virtual ~imageRamp();
private:
	Mat imageChange;
};
class imageOffset {
public:
	imageOffset();
	virtual ~imageOffset();
	void imageTranslarion1();
	void imageTranslarion2();
private:
	Mat imageChange;
	Mat image;
	int xOffset;
	int yOffset;
};
class imageZoom {
public:
	imageZoom();
	virtual ~imageZoom();
	void  imageReduction1();
	Vec3b areaAverage(Point_<int>,Point_<int>);
	void imageReduction2();

private:
	Mat imageChange;
	Mat image;

};
class imageRotate {
public:
	imageRotate();
	void angelRotate();
	virtual ~imageRotate();

private:
	Mat imageChange;
	int angle;
	Mat image;

};