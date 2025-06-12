# Sunucu Yük Yönetim Sistemi (C - Çift Bağlı Döngüsel Liste)

Bu proje, C dilinde yazılmış ve çift bağlı döngüsel liste kullanarak sunucu yükü ve kapasitesini yöneten bir programdır.

# Bu Projede Neler Öğrendim?

- Çift bağlı döngüsel liste yapısını nasıl tasarlayıp kullanabileceğimi öğrendim.
- Dinamik bellek yönetimi ve pointer kullanımı konusunda deneyim kazandım.
- Veri yapılarında sıralama algoritmalarının nasıl uygulanacağını gördüm.
- Kullanıcıdan alınan verilerle liste üzerinde gerçek zamanlı güncellemeler yapmayı öğrendim.
- Yazdığım fonksiyonların program akışı içerisindeki etkisini ve hata kontrolünü geliştirdim.






## Özellikler
- Sunucuların yük ve kapasite bilgilerini saklar.
- Yük ekleme (Üretici) ve yük çıkarma (Tüketici) işlemleri yapılabilir.
- Sunucular mevcut yüklerine göre sıralanır.
- Sunucular listelenebilir.

## Kullanım
Program çalıştırıldığında kullanıcıdan sunucu sayısı ve her sunucuya ait bilgiler istenir:
- Sunucu ID
- Mevcut yük
- Maksimum kapasite

Daha sonra ana menüde şu işlemler yapılabilir:
- Üretici: Sunuculara yük ekler.
- Tüketici: Sunuculardan yük çıkarır.
- Listele: Sunucuları ve durumlarını listeler.
- Çıkış: Programdan çıkar.

## Veri Yapısı
- `sunucular` struct: Sunucu bilgileri ve çift bağlı döngüsel liste için önceki ve sonraki pointerları içerir.

## Fonksiyonlar
- `anamenu()`: Ana menüyü yönetir.
- `uretici()`: Sunuculara yük ekler.
- `tuketici()`: Sunuculardan yük çıkarır.
- `listele()`: Sunucu listesini yazdırır.
- `sirala()`: Sunucuları müsaitlik durumuna göre sıralar.
- `yerac()`: Kullanıcıdan sunucu bilgilerini alır ve listeyi oluşturur.

---

## Geliştirici
Bu proje Mustafa tarafından hazırlanmıştır.
