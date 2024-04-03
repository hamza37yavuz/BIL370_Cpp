#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void histogramEqualization(Mat &image) {
    // 0'dan 255'e kadar gri tonlama değerlerinin frekanslarını tutacak dizi
    int hist[256] = {0};
    // Goruntutdeki toplam pixel sayisini hesaplar
    int totalPixels = image.rows * image.cols;

    // ic ice iki dongu gri tonlama değerine göre ilgili sutunun değerini arttıralım
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            hist[image.at<uchar>(i, j)]++;
        }
    }

    // Kümülatif dağılım fonksiyonunu (CDF) hesapla ve normalize et
    // 0'dan 255'e kadar olan gri tonlama değerlerinin kümülatif dağılım fonksiyonunu tutacak bir dizi tanımlanır ve tüm elemanları sifira atanır.
    float cdf[256] = {0};
    // Siyah ve gri tonlamali pixellerin  toplam pixele bölünerek kümülatif dağılım fonksiyonunun değerleri hesaplanıyor
    cdf[0] = (float) hist[0] / totalPixels;
    for (int i = 1; i < 256; ++i) {
        cdf[i] = cdf[i - 1] + (float) hist[i] / totalPixels;
    }

    // Histogram dengeleme işlemi
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            // Kümülatif dağılım değerini 0-255 arasında ölçekler sonrasında ölçeklenmiş CDF değerini en yakın tam sayıya yuvarlar.
            // Yani, pikselin yeni gri tonlama değeri bir tam sayı olacaktır.
            image.at<uchar>(i, j) = cvRound(255 * cdf[image.at<uchar>(i, j)]);
        }
    }
}

int main() {
    // Resmi yükle
    Mat image = imread("src/rural2.jpg", IMREAD_GRAYSCALE);

    // Hata Kontrol
    if (image.empty()) {
        cerr << "Resim yuklenemedi." << endl;
        return -1;
    }
    imshow("Eski Fotograf", image);

    // Bekleme
    waitKey(0);
    // Histogram dengeleme işlemi
    histogramEqualization(image);

    // Yeni fotoğrafı ekrana bastır
    imshow("Yeni Fotograf", image);

    // Bekleme
    waitKey(0);

    return 0;
}
