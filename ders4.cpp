#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // Resmi yükle
    Mat image = imread("ay.jpg");
    
    // Resim var mi
    if (image.empty()) {
        std::cerr << "Resim yüklenemedi." << std::endl;
        return -1;
    }

    // Gri tonlamalıya dönüştür
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    

    // Asagida pizel bazli toplama cikarma carpma bolme islemleri gosterilmistir.
    for (int y = 0; y < grayImage.rows; ++y) {
        for (int x = 0; x < grayImage.cols; ++x) {
		// UNSIGNED char veri tipinde bir pointer olusturalim
		uchar &pixel = grayImage.at<uchar>(y, x);

		// Pixel degerine 100 ekleyelim alt ve ust siniri asmamasi saturate_cast donusum fonksiyonu kullanildi.
		// 255 i asan pixeller 255 degerine esitlenir.
		/*
		pixel = saturate_cast<uchar>(pixel + 100);
		*/

		// 50 den kucuk pixel degerlerini 10 ile carpalim
		if(pixel<50 && pixel!=0){
			pixel = saturate_cast<uchar>(pixel + 20);
			pixel = saturate_cast<uchar>(pixel*5);
			
			}
		}	
	}
    // Standart islemler:
    namedWindow("Merhaba", WINDOW_AUTOSIZE);
    imshow("Merhaba", grayImage);
    waitKey(0);
    
    return 0;
}