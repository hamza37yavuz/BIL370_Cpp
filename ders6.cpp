#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

void rescaleGrayImage(Mat &grayImage, double targetMin = 0, double targetMax = 255) {
    // Her piksele eklenen değeri ve hedef minimum ve maksimum degerleri belirle
    double minVal, maxVal;
    // Kokunu alarak goruntuyu normallestirelim.
    //sqrt(grayImage, grayImage);

    minMaxLoc(grayImage, &minVal, &maxVal);
    double scale = (targetMax - targetMin) / (maxVal - minVal);
    
    // Her piksele olcekleme faktorunu uygulayalim
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

    // Griye cevirelim
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    // KARE ALMA ISLEMI
    // Her pixelin veri tipini double yapalim sonra karesini alma islemini yapabiliriz
    grayImage.convertTo(grayImage, CV_64F); // Veri tipini double yapalım
    grayImage.forEach<double>([](double &pixel, const int * position) -> void {
        pixel = pixel * pixel;
    });
    
    rescaleGrayImage(grayImage);
    
    // Sonucu göster
    std::cout << "Gri tonlamalı işlenmiş resim oluşturuldu." << std::endl;
    
    // Standart islemler:
    showImage("Kare Alma Islemi", grayImage);
    return 0;
}
