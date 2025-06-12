# Öğrenci ve Ders Takip Sistemi (C - Linked List)

Bu proje, C dilinde yazılmış, bağlı liste kullanarak öğrenci ve ders bilgilerini okuyan ve yöneten bir programdır.

## Özellikler
- Öğrencileri ve derslerini listeleyebilir.
- Öğrencileri soyadlarına göre silebilir.
- Not ortalamalarına göre öğrencileri sıralayabilir.
- Ders koduna göre arama yapabilir.

## Dosya Formatı
Program, aşağıdaki formatta öğrenci bilgilerini içeren bir dosyadan veri okur:

```
[ogrenciadi] [ogrencisoyad] [ogrencino]
[dersadi1] [dersnot1] [derskod1]
[dersadi2] [dersnot2] [derskod2]
[dersadi3] [dersnot3] [derskod3]
```

## Kullanım
Programı derlemek için:

```
gcc main.c -o ogrenci_programi
```

Çalıştırmak için:

```
./ogrenci_programi
```

## Veri Yapıları
- `dersler` struct: Ders adı, kodu ve notu.
- `ogrenci` struct: Öğrenci bilgileri, aldığı dersler ve bağlı liste yapısı.

## Fonksiyonlar
- `anamenu()`: Ana menü işlemleri.
- `listeleme()`: Öğrencileri ve dersleri listeler.
- `silme()`: Öğrenci silme işlemi.
- `siralama()`: Öğrencileri not ortalamasına göre sıralar.
- `arama()`: Ders koduna göre arama yapar.

---

## Geliştirici
Bu proje Mustafa tarafından hazırlanmıştır.
