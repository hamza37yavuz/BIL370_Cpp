# BIL370_Cpp

Burada BIL370 Görüntü İşleme Dersinde yapılan işlemlerin C++ kodları paylaşılacaktır. Dosyaları derlemek için linux ortamda opencv kurulumu için aşağıdaki komutlar çalıştırılmalıdır.
```
sudo apt update
sudo apt install libopencv-dev
```

Bu repoyu indirdikten sonra `g++ ders1.cpp -o ders1 'pkg-config --cflags --libs opencv4'` komutu ile dosyalar derlenmelidir. Derleme esnasında _**fatal error: opencv2/opencv.hpp: No such file or directory**_
 hatasını alırsanız opencv yüklenme yolunuzu kontrol ediniz. Bunu kontrol etmek için `sudo find /usr -name opencv2` komutunu çalıştırıp yolu derleme komutunuza ekleyerek hatadan kurtulabilirsiniz.
Aşağıdaki dosyaları kendi lokalinizde test edebilirsiniz:

## [ Ders 1](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders1.cpp)
Örnek 2 kanallı bir matris oluşturulmuştur. Ekranda resmin nasıl gösterileceği belirtilmiştir.

## [Ders 2](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders2.cpp)
Örnek 3 kanallı bir matris oluşturulmuştur. Bu matris renkelriyle nasıl oynanacağı gösterilmiştir.

## [Ders 3](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders3.cpp)
Resim üzerine daire çizme dikdörtgen çizme yazı yazma işlemleri gösterilmiştir. Ayrıca burada resmin belirli bölgelerinin renginin nasıl değiştirileceği de belirtilmiştir.

## [Ders 4](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders4.cpp)
[ay.jpg](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ay.jpg) resmi üzerinde noktasal işlemlere giriş yapılmıştır. 2 Tane for döngüsüyle belirli işlemler yapılmıştır. Bu derste işlemler sonrası resim tekrar ölçeklenmemiştir. Ölçekleme fonksiyonu bulunmaz.

## [Ders 5](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders5.cpp)
[ay.jpg](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ay.jpg) resmi üzerinde noktasal işlemlere devam yapılmıştır. Toplama çarpma ve kare alma işlemleri yapılmıştır. Bu işlemler sonrası statik ökalıkalı
lçekleme yapılmıştır. Bu sebeple kare alma işlemi sonrası bir bozulma meydana gelir. Bu bozulma ders6 da düzeltilmiştir.

## [Ders 6](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders6.cpp)
[ay.jpg](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ay.jpg) resmi üzerinde noktasal işlemlere devam yapılmıştır. Birt önceki başlıktaki hata düzeltilmeye çalışılmıştır. Düzeltme yapılacaktır.

## [Ders 7](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders7.cpp)
src dizininde bulunan fotoğraf üzerinden histogram çizilmesi gösterilmiştir. Bu histogram renkli görüntüler üzerinden çizilmiştir. Genel olarak histogramın tanımını yapalım.
Resimler için histogramlar resimdeki renk değerlerinin konum değerlerinden bağımsız olarak grafikle görselleştirilmesini ifade eder. Bu histogram üzerinden kontrast doku ve baskın renk konusunda yorum yapılabilir.

## [Ders 8](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders8.cpp)
Resmin histogramının kümülatif dağılımı elde edilir ve kümülatif dağılım genişletilir. Sonrasında 0-1 arasında ölçeklenmiş resim ile çarpılır. src dizininde bulunan kırsal fotoğrafı üzerinden histogram dengeleme yapılarak ayrıntılar ortaya çıkarılmıştır. Ama ayrıntıların ortaya çıkarılması olayı bazı resimleri sıkıntılı duruma getirebilir. Özellikle arka planı aşırı karanlık ve aşırı aydınlık olan bulanık resimler histogram dengelemesi sonrasında olmayan renkler ve tonlamalar oluşabilir. Bu durumda adaptif histogram dengeleme işlemi devreye girer.

## [Ders 9](https://github.com/hamza37yavuz/BIL370_Cpp/blob/main/ders9.cpp)
