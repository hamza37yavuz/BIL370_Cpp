#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{	
	// Bu sekilde tek kanalli resimler olusturabiliriz
	//Mat goruntu(450,450,CV_8UC1,Scalar(150));

	// 3 Kanalli matris olusturmak istiyorsak CV_8UC3 seklinde parametre vermeliyiz
	// Bu sekilde verildiginde Scalar icinde verecegimiz parametreler BGR siralamasina gore gider
	Mat goruntu(450,450,CV_8UC3,Scalar(0,255,0)); // yesil
	
	// Standart islemler:
	namedWindow("Merhaba", WINDOW_AUTOSIZE);
	imshow("Merhaba", goruntu);
	waitKey(0);
}