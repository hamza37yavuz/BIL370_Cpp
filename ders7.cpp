#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void showImage(const std::string& windowName, const Mat& image) {
    namedWindow(windowName, WINDOW_NORMAL);
    resizeWindow(windowName, 400, 400);
    imshow(windowName, image);
    waitKey(0);
}

int main() {
    // Fotoğrafı yükle
    Mat image = imread("src/rural.jpg", IMREAD_COLOR);

    // Hata kontrolü
    if (image.empty()) {
        cerr << "Fotoğraf yüklenemedi." << endl;
        return -1;
    }
    // Fotoğrafı normal boyutları ile görselleştirelim
    imshow("Fotograf", image);

    // Renk kanallarını ayrı ayrı ayıralım çünkü her renk kanalı için histogram çizilecek
    vector<Mat> channels;
    split(image, channels);

    // Histogram boyutu ve aralığı
    int histSize = 256;
    float range[] = {0, 256};
    const float* histRange = {range};

    // Histogramlar için hesaplama yapalım
    Mat histR, histG, histB;
    /* calcHist fonksiyonu histogramı hesaplayacaktır
    1. parametre parametre renk kanalı içindir 2. ve 3. parametrelerde renk kanalı ile ilgilidir.
    4. parametre Mat opsiyonel bir maskedir. Bu maskeyi kullanmak istemediğimiz için boş bir obje geçeceğiz.
    5. parametre atama yapılacak değişkeni alır. 6. parametreye histogramımız 1 boyutlu olduğu için  1 verdik.
    7-8 parametreler aralık ve boyut için verilir.
    9. parametre True olarak ayarlandığında, histogramın genişliği piksel sayısına bölünür. (normalleştirme)
    10. parametre opsiyoneldir Eğer bu bayrak true olarak ayarlanırsa, histogramlar birbirine eklenir.
                            Bu, birden fazla görüntü için tek bir histogram hesaplamak istendiğinde kullanılır.
    */
    calcHist(&channels[0], 1, 0, Mat(), histB, 1, &histSize, &histRange, true, false);
    calcHist(&channels[1], 1, 0, Mat(), histG, 1, &histSize, &histRange, true, false);
    calcHist(&channels[2], 1, 0, Mat(), histR, 1, &histSize, &histRange, true, false);

    // Eğer siyah beyaz bir görüntünüz varsa bunun için channel kısmına direkt image verilebilir örneğin aşağıdaki şekilde kullanılabilir
    // calcHist(&imageGray, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);

    // Histogramları görselleştir
    int histWidth = 512, histHeight = 400;
    int binWidth = cvRound((double) histWidth / histSize);

    // Beyaz bir arka plan
    Mat histImage(histHeight, histWidth, CV_8UC3, Scalar(255, 255, 255));

    // Normalleştirme işlemleri
    normalize(histB, histB, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(histG, histG, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(histR, histR, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    // Histogramları çiz (Bu kısım için tekrar 2-3. derslere bakabilirsiniz)
    for (int i = 1; i < histSize; i++) {
        line(histImage, Point(binWidth * (i - 1), histHeight - cvRound(histB.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(histB.at<float>(i))),
             Scalar(255, 0, 0), 2, LINE_AA); // Mavi
        line(histImage, Point(binWidth * (i - 1), histHeight - cvRound(histG.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(histG.at<float>(i))),
             Scalar(0, 255, 0), 2, LINE_AA); // Yeşil
        line(histImage, Point(binWidth * (i - 1), histHeight - cvRound(histR.at<float>(i - 1))),
             Point(binWidth * (i), histHeight - cvRound(histR.at<float>(i))),
             Scalar(0, 0, 255), 2, LINE_AA); // Kırmızı
    }

    // Histogramları ekrana bastır
    showImage("Histogram", histImage);
    return 0;
}
