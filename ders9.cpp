#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void adaptiveHistogramEqualization(Mat &image, int tile_size) {
    Mat equalized_image;
    // adaptif histogram dengeleme nesnesi oluştur
    Ptr<CLAHE> clahe = createCLAHE();
    // Blok boyutunu ayarla
    clahe->setClipLimit(4); // Clip limit değerini isteğe bağlı olarak ayarlayabilirsiniz
    clahe->setTilesGridSize(Size(tile_size, tile_size));
    // Adaptif histogram dengeleme uygula
    clahe->apply(image, equalized_image);
    // Eşitlenmiş resmi geri döndür
    image = equalized_image.clone();
}

int main() {
    // Resmi yükle
    Mat image = imread("src/moon1.jpg", IMREAD_GRAYSCALE);

    // Hata Kontrol
    if (image.empty()) {
        cerr << "Resim yuklenemedi." << endl;
        return -1;
    }
    imshow("Eski Fotograf", image);

    // Bekleme
    waitKey(0);

    // Adaptif histogram dengeleme işlemi
    adaptiveHistogramEqualization(image, 8); // Blok boyutunu 8x8 olarak ayarla

    // Yeni fotoğrafı ekrana bastır
    imshow("Yeni Fotograf", image);

    // Bekleme
    waitKey(0);

    return 0;
}
