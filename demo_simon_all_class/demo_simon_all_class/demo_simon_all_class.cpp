// demo_simon_all_class.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "main.h"
#include "vedio.h"
#include"faceTest.h"
#include "VIKBoardMain.h"
#include "FindCircle.h"
#include"Cbtw_imageDealWith.h"
#include"HumanBodyDetection.h"
#include <iostream>

using namespace std;
FILE* fp;
enum choice_num
{
	FEAPOINTORB, //0
	DEALWITHIMAGE, //1
	IMAGE_INPAINT, //2
	QUIT, //3
	VIKBoard, //������� //4
	IMAGECONNECT ,//��ͨ //5
	IMAGEHUMANBODY,//����������� //6
	VIDEOTRACK,//��Ƶ����
};

int main()
{
	errno_t err;
	bool is_quit = true;
	err = fopen_s(&fp, "test.txt", "r+");
	if (err != 0)
	{
		cout << "open the file is error " << endl;
		exit(-1);
	}

//	fprintf(fb, "%d\n", point_cha);
	cout <<  "please input the choice " << endl;
	cout << "0:feapointORB,1:dealwithImage,2:image inpaint,3:QUiT��5��������ͨ" << endl;
	int choice_num;
	Cbtw_imageDealWith* Cbtw_image;
	HumanBodyDetection* HumanBody;
	FindCircle* FCircle;
//	cin >> choice_num;
	choice_num = IMAGEHUMANBODY;
	while (is_quit)
	{
		switch (choice_num)
		{
		case FEAPOINTORB:
			feaPointOrb(fp);
			break;
		case DEALWITHIMAGE:
			imageDealWith();
			break;
		case IMAGE_INPAINT:
			image_inpaint();
			break;
		case  QUIT:
			return 0;

		case 44:
			vedio_DealWith();
			break;
		case 111:
			main_face();
			break;
		case VIKBoard:
			VIKBoard_main();
			break;

		case IMAGECONNECT: //������������ͨ
			Cbtw_image = new Cbtw_imageDealWith();
			is_quit = false;
			break;
		case IMAGEHUMANBODY:
			HumanBody  = new HumanBodyDetection();

			break;
		case 24:
			FCircle = new FindCircle();
			FCircle->find_Circle();
			break;
		case VIDEOTRACK:


		default:
			break;

		}

	}
    return 0;
	
	
}

