#include "cv.h"  
#include "highgui.h"  
#include <opencv2\core\core.hpp>
#include <opencv2\objdetect.hpp>//������casecadeclassifier

#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//����ͷ��capture
	CvCapture* pcapture = 0;
	//����ͷһ֡���ݴ��
	IplImage* frame;
	const char* casecade_name = "E:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
	CascadeClassifier casecade;
	//������������ж��Ƿ���ɹ�
	if (!casecade.load(casecade_name)){
		cerr << "Could not load casecadeclassifier" << endl;
		return -1;
	}
	//������ͷ
	pcapture = cvCaptureFromCAM(0);
	cvNamedWindow("result", 1);//1������ı䴰�ڴ�С
	if (pcapture)//����ͷ��
	{
		for (;;)
		{
			frame = cvQueryFrame(pcapture);//ץȡһ֡���ݷ���frame
			if (!frame)  break;

			cvShowImage("result", frame);
			char c = cvWaitKey(10);
			if (c == 27) break;
		}
		cvReleaseCapture(&pcapture);
		cvDestroyWindow("result");
	}
	
}