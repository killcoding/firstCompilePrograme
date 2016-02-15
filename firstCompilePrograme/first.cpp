#include "cv.h"  
#include "highgui.h"  
#include <opencv2\core\core.hpp>
#include <opencv2\objdetect.hpp>//分类器casecadeclassifier

#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//摄像头的capture
	CvCapture* pcapture = 0;
	//摄像头一帧数据存放
	IplImage* frame;
	const char* casecade_name = "E:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
	CascadeClassifier casecade;
	//导入分类器并判断是否导入成功
	if (!casecade.load(casecade_name)){
		cerr << "Could not load casecadeclassifier" << endl;
		return -1;
	}
	//打开摄像头
	pcapture = cvCaptureFromCAM(0);
	cvNamedWindow("result", 1);//1不允许改变窗口大小
	if (pcapture)//摄像头打开
	{
		for (;;)
		{
			frame = cvQueryFrame(pcapture);//抓取一帧数据放入frame
			if (!frame)  break;

			cvShowImage("result", frame);
			char c = cvWaitKey(10);
			if (c == 27) break;
		}
		cvReleaseCapture(&pcapture);
		cvDestroyWindow("result");
	}
	
}