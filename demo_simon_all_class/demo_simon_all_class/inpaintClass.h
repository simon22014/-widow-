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
class inpaintClass
{
public:
	inpaintClass();
	virtual~inpaintClass();
private:
	Mat beforeImage;
	Mat afterImage;
};

