#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void rescaleGrayImage(Mat &grayImage, double targetMin = 0, double targetMax = 255) {
    // Her piksele eklenen değeri ve hedef minimum ve maksimum değerleri belirle
    double minVal, maxVal;
    minMaxLoc(grayImage, &minVal, &maxVal);
    double scale = (targetMax - targetMin) / (maxVal - minVal);
    
    // Her piksele ölçekleme faktörünü uygula
    grayImage = (grayImage - minVal) * scale + targetMin;
}

void showImage(const std::string& windowName, const Mat& image) {
    namedWindow(windowName, WINDOW_NORMAL);
    resizeWindow(windowName, 400, 400);
    imshow(windowName, image);
    waitKey(0);
}

int main() {
    // Resmi yükle
    Mat image = imread("ay.jpg");
    
    // Hata Kontrol
    if (image.empty()) {
        std::cerr << "Resim yüklenemedi." << std::endl;
        return -1;
    }

    // Gri tonlamalıya dönüştür
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    
    // Her piksele 100 ekle
    Mat grayImage1 = grayImage.clone();
    grayImage1 += Scalar(100);        

    // Gri tonlamalı resmi yeniden ölçekle
    rescaleGrayImage(grayImage1);
    // Ekranda goster
    showImage("Toplama Islemi", grayImage1);

    // Her pixeli 10 ile carpalim
    Mat grayImage2 = grayImage.clone();
    grayImage2 *= 10; 
    // Gri tonlamalı resmi yeniden olcekle
    rescaleGrayImage(grayImage2);
    // Ekranda goster
    showImage("Carpma Islemi", grayImage2);

    // Her pixelin karesini alalim
/*
    forEach ile tüm pixeller tek tek gezilmesi saglanir. <uchar> resmin her bir pixelinin degisken tipini belirtir.
    bir lambda fonksiyonu vardir bu bir forEach dongusunden bir pixeli ve onun konumunu veren bir pointeri parametre olarak alir.
    parantezin icindeki islem pixelin karesinin alinmasini saglar. Resimde bozulmalar olacaktir bu bozulmalarin duzeltme islemi ders6
    da yapilacaktir.
*/

    grayImage.forEach<uchar>([](uchar &pixel, const int * position) -> void {
        pixel = static_cast<uchar>(pixel * pixel);
    });
    rescaleGrayImage(grayImage);
    
    // Sonucu göster
    // Standart işlemler:
    showImage("Kare Alma islemi", grayImage);
    waitKey(0);
    return 0;
}
