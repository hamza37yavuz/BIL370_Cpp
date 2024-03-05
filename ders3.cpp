#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

/*
YAZI TIPLERI:
	FONT_HERSHEY_SIMPLEX
	FONT_HERSHEY_SCRIPT_SIMPLEX
	FONT_HERSHEY_PLAIN
	FONT_HERSHEY_DUPLEX
	FONT_ITALIC
*/


int main()
{	
	// Bu sekilde tek kanalli resimler olusturabiliriz
	//Mat goruntu(450,450,CV_8UC1,Scalar(150));
	
	// 3 Kanalli matris olusturmak istiyorsak CV_8UC3 seklinde parametre vermeliyiz
	// Bu sekilde verildiginde Scalar icinde verecegimiz parametreler BGR siralamasina gore gider
	Mat goruntu(450,450,CV_8UC3,Scalar(0,150,50)); // yesil
	
	// colRange x ekseni uzerinde islem
	goruntu.colRange(350,450).setTo(CV_8UC1);
	goruntu.colRange(50,75).setTo(Scalar(255,255,255));

	// rowRange y ekseni uzerinde islem
	// Ornek olarak Hollanda bayragini cizidirelim
	goruntu.rowRange(0,150).setTo(Scalar(0,0,200));
	goruntu.rowRange(151,300).setTo(Scalar(255,255,255));
	goruntu.rowRange(301,450).setTo(Scalar(255,0,0));	

	// Dogru cizdirme 
	line(goruntu, Point(92,100), Point(410,400), Scalar(0,0,0), 3);

	// Dikdortgen cizdirme
	// Rect icinden bir nesne uretelim birinci ve ikinci parametre koordinat ucuncu genislik ve dorduncu boy parametresidir. 
	Rect dikdortgen(50,100,45,80);
	// Bu nesneyi kullanarak dikdortgeni goruntuleyelim
	rectangle(goruntu,dikdortgen, Scalar(0,0,0),2); 
	
	// Daire cizdirme
	circle(goruntu,Point(150,100),40,Scalar(0,0,0),5);
	
	// Yazi yazdirma
	putText(goruntu,"Hello", Point(200,220), FONT_HERSHEY_SCRIPT_SIMPLEX, 2, Scalar(0,0,50),2);

	// Standart islemler:
	namedWindow("Merhaba", WINDOW_AUTOSIZE);
	imshow("Merhaba", goruntu);
	waitKey(0);
}