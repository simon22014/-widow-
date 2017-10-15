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
using namespace cv;
using namespace std;
class VIKBoardMain
{
private:

public:
	VIKBoardMain();
	~VIKBoardMain();
	void GetSkin(Mat &img);
	void GetSkin(Mat img, Mat &src);

	void SkinBoard_init();
	void Four_Point_init(Mat img);
	void Four_Point_Past_init();
	void XY_warp_init(Mat img, Mat warp_mat);
	void area_of_key_init(Mat img);
	void draw_biankuang(Mat img);

	void transform_skin_warp(Mat &img);

	vector<Point> get_Four_Point_Past();
	Mat calculate_warp_mat(vector<Point> val, Mat img);
	void warp_transform(Mat img, Mat &src, Mat warp_mat, cv::Size _size);
	int tongji_skin(Mat img);
	void Get_Key_Value(char a[]);

	vector<vector<Point>> SkinBoard;
	vector<Point> Four_Point_After;
	vector<Point> Four_Point_Past;

	vector<vector<Point>> XY_warp;
	vector<Point> Key_Range_Begin;
	vector<Point> Key_Range_End;

};
int VIKBoard_main();
