#include<iostream>
#include<opencv.hpp>
using namespace cv;
int main()
{
	cv::Mat srcMat=imread("test.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;
	int height = srcMat.rows;  //��������ͼƬ�ĸ�
	int width = srcMat.cols;   //��������ͼƬ�Ŀ�
	uchar threshold = 100;     //�趨��ֵ
	srcMat.copyTo(deepMat);
	shallowMat = srcMat;
	for (int j = 0; j < height; j++) {
		//���д������
		for (int i = 0; i < width; i++) {
			//------��ʼ����ÿ������------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] +
				srcMat.at<Vec3b>(j, i)[1] +
				srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold) {
				average = 255;
			}
			else {
				average = 0;
			}
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
			//-----����ÿ�����صĴ���-----------
		}
	}
	imshow("deepsrc", deepMat);
	imshow("shallowsrc", shallowMat);
	waitKey(0);
	return 0;

}