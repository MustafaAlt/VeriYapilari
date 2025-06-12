# İfade Dönüştürücü ve Hesaplayıcı (C Projesi)

Bu proje, infix (ara) biçimindeki matematiksel ifadeleri postfix (sondan yazım) biçimine çeviren ve bu ifadeleri hesaplayan bir C uygulamasıdır. Program aynı zamanda her adımı bir dosyaya loglayarak işlem sürecini analiz etmeye imkân tanır.

## 📌 Özellikler

- İnfix ifadeleri analiz eder ve postfix'e dönüştürür.
- Postfix ifadeyi hesaplar ve sonucu verir.
- Stack (yığın) veri yapısı kullanılarak işlem önceliği kurallarına uyulur.
- Her adım detaylı bir şekilde `veriler.txt` dosyasına yazılır.

## ⚙️ Derleme ve Çalıştırma

```bash
gcc main.c -o ifade_cevirici
./ifade_cevirici
```

> Not: Program çalışmadan önce, `veriler.txt` dosyasının içinde bir infix ifade bulunmalıdır. Örnek içerik:
>
> ```
> (3+5)*2
> ```
    |

## 📚 Öğrendiklerim

Bu projeyle birlikte şunları öğrendim:

- C dilinde stack (yığın) veri yapısının nasıl oluşturulup kullanıldığını,
- İfade dönüştürme algoritmalarını (infix → postfix),
- Postfix ifade çözümlemesini (değerlendirme algoritması),
- `malloc`, `calloc`, `free` gibi bellek yönetim fonksiyonlarını,
- C'de dosya işlemlerini (`fopen`, `fgetc`, `fprintf`, `fclose`),
- Hataları yönetme ve debug etme becerilerimi geliştirdim.

## 🛠️ Geliştirme Önerileri

- Daha karmaşık ifadeler ve hata denetimi eklenebilir.
- GUI arayüzüyle desteklenebilir.
- Çoklu ifade desteği ve otomatik sonuç raporlama eklenebilir.

## 📄 Lisans

Bu proje eğitim amaçlıdır ve kişisel kullanım için özgürdür.