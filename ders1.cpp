#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	// 4*4 bir matris (goruntu) olusturalim ve olusturdugumuz matrise renk boyutu verelim
	Mat goruntu(4,4,CV_8UC1,Scalar(150));

	// Matrisi ekranda goruntuleyelim 
	// Merhaba isminde pencere varsayilan boyutta olusturulacak
	namedWindow("Merhaba", WINDOW_AUTOSIZE);
	// Ekranda gosterebilmemiz icin
	imshow("Merhaba", goruntu);
	// Ekranda devali kalmasi icin
	waitKey(0);
	cout <<"Goruntu dizisinin degerleri:" << goruntu << endl;
}