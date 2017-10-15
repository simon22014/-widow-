#include "stdafx.h"
#include "peaPointORB.h"
peaPointORB::peaPointORB()
{

}
peaPointORB::peaPointORB(FILE* fp)
	:fp(fp)
{
	Mat image_obj = imread("image22.jpg");
	Mat image_scene = imread("scene.bmp");
	obj = image_obj.clone();
	scene = image_scene.clone();
//	imshow("image",image);
//	waitKey(0);

}
peaPointORB::~peaPointORB()
{
}
void peaPointORB::theAlgFunction()
{
	Mat obj_i = obj.clone();
	Mat scene_i = obj.clone();
	if (obj_i.empty() || scene_i.empty())
	{
		cout << "Can't open the picture!\n";
		return;
	}
	Mat obj_frame = obj_i.clone();
	Mat scene_frame = scene_i.clone();
	Mat obj_edges;
	Mat scene_edges;
	Mat obj, scene;

	cvtColor(obj_frame, obj_edges, CV_RGB2GRAY);
	GaussianBlur(obj_edges, obj_edges, Size(7, 7), 1.5, 1.5);
	//	Canny(obj_edges, obj_edges, 0, 30, 3);
	cvtColor(scene_frame, scene_edges, CV_RGB2GRAY);
	GaussianBlur(scene_edges, scene_edges, Size(7, 7), 1.5, 1.5);
	//	Canny(scene_edges, scene_edges, 0, 30, 3);
	obj = obj_edges.clone();
	scene = scene_edges.clone();




	vector<KeyPoint> obj_keypoints, scene_keypoints;
	obj_keypoints.reserve(100000);
	scene_keypoints.reserve(100000);
	Mat obj_descriptors, scene_descriptors;
	ORB detector;     //����ORB�㷨��ȡ������  
	detector.detect(obj, obj_keypoints);
	detector.detect(scene, scene_keypoints);
	detector.compute(obj, obj_keypoints, obj_descriptors);
	detector.compute(scene, scene_keypoints, scene_descriptors);
	imshow("obj_descriptors", obj_descriptors);
	vector <Point2f> pointObj;
	Point2f pointOne;

	vector<KeyPoint> ::iterator  iter;
	for (iter = (scene_keypoints).begin();iter != (scene_keypoints).end();iter++)
	{
		//	fprintf(fp, "x = %.2f    y = %.2f\n", (*iter).pt.x, (*iter).pt.y);
		pointOne.x = (*iter).pt.x;
		pointOne.y = (*iter).pt.y;
		pointObj.push_back(pointOne);
		//	cout << "secene_keypoints:" << (*iter).pt << endl;

	}

	//	fprintf(fp, "the size %d:\n", pointObj.size());
	vector <Point2f>::iterator it;
	Point2f start;
	Point2f end;
	it = pointObj.begin();
	while (it != pointObj.end())
	{
		if (it != pointObj.end())
		{
			start = *it;
			//	fprintf(fb_data, "x=%d,y=%d,\n", start.x,start.y);
			it++;
		}
		if (it != pointObj.end())
		{
			end = *it;
		}
		//	line(scene, start, end, Scalar(255, 255, 255), 1, 0);

	}
	cv::imshow("obj", obj);
	cv::imshow("scene", scene);




	BFMatcher matcher(NORM_HAMMING, true); //����������Ϊ���ƶȶ���  
	vector<DMatch> matches;
	matches.reserve(100000);
	matcher.match(obj_descriptors, scene_descriptors, matches);
	Mat match_img;
	cv::drawMatches(obj, obj_keypoints, scene, scene_keypoints, matches, match_img);
	//	cv::imshow("�˳���ƥ��ǰ", match_img);

	


	vector <KeyPoint>::iterator  scene_iter;
	vector <KeyPoint>::iterator obj_iter;
	Point2f obj_start;
	Point2f scene_end;
	obj_iter = (obj_keypoints).begin();
	scene_iter = (scene_keypoints).begin();

	//����ƥ������  
	vector<int> queryIdxs(matches.size()), trainIdxs(matches.size());
	for (size_t i = 0; i < matches.size(); i++)
	{
		queryIdxs[i] = matches[i].queryIdx;
		trainIdxs[i] = matches[i].trainIdx;
		obj_start.x = (*(obj_iter + queryIdxs[i])).pt.x;
		obj_start.y = (*(obj_iter + queryIdxs[i])).pt.y;
		scene_end.x = (*(scene_iter + trainIdxs[i])).pt.x + obj.rows;
		scene_end.y = (*(scene_iter + trainIdxs[i])).pt.y;

		fprintf(fp, "queryIdxs %d:   trainIdxs %d\n", queryIdxs[i], trainIdxs[i]);

		line(match_img, obj_start, scene_end, Scalar(255, 255, 255), 1, 0);

	}


	cv::imshow("�˳���ƥ��ǰ123", match_img);
	cout << "match_img.cols" << match_img.cols << "match_img.rows" << match_img.rows << endl;
	cout << "obj.cols" << obj.cols << "obj.rows" << obj.rows << endl;
	cout << "scene.cols" << scene.cols << "scene.rows" << scene.rows << endl;

	Mat H12;   //�任����  

	vector<Point2f> points1; KeyPoint::convert(obj_keypoints, points1, queryIdxs);
	vector<Point2f> points2; KeyPoint::convert(scene_keypoints, points2, trainIdxs);
	int ransacReprojThreshold = 5;  //�ܾ���ֵ  

									//findHomography()����ֱ��ͨ������ƽ������ƥ�������������任��ʽ��
									//֮������ֶ�ԭͼ���ĸ���Ե����б任������ͼ�ϻ�����Ӧ�ľ��Ρ����ͼҲ�ܺõؽ�������ν͸�ӱ任�ġ�Viewing Plane����
	H12 = findHomography(Mat(points1), Mat(points2), CV_RANSAC, ransacReprojThreshold);
	//
	vector<char> matchesMask(matches.size(), 0);
	Mat points1t;
	cv::perspectiveTransform(Mat(points1), points1t, H12);

	for (size_t i1 = 0; i1 < points1.size(); i1++)  //���桮�ڵ㡯  
	{
		if (norm(points2[i1] - points1t.at<Point2f>((int)i1, 0)) <= ransacReprojThreshold) //���ڵ������  
		{
			matchesMask[i1] = 1;
		}
	}
}