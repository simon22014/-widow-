#pragma once
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/nonfree/features2d.hpp>
#include<opencv2/nonfree/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/legacy/legacy.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include "c4-pedestrian-detector.h"
using namespace::std;
using namespace::cv;
class HumanBodyDetection
{
public:
	HumanBodyDetection();
	~HumanBodyDetection();
};

