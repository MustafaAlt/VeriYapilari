#include <stdio.h>
#include <stdlib.h>
typedef struct a
{
    char dersadi[15];
    int dersnot;
    int derskod;
} dersler;
typedef struct b
{
    char ogrenciadi[15];
    char ogrencisoyad[15];
    int ogrencino;
    int ogrenciort;
    dersler *alinanlar;
    struct ogrenci *next;
} ogrenci;
ogrenci* head = NULL; // listenin ilk elemanini
ogrenci* tail = NULL; // listenin son elemaninin adresini tutuyor.
void anamenu()
{
    int islem= 0,kod = 0;
    char soyisim[15];
    printf("\t1->LISTELE\n");
    printf("\t2->SILME\n");
    printf("\t3->AGIRLIKLI NOT ORTALAMASINA GORE SIRALA\n");
    printf("\t4->ARAMA\n");
    printf("\t5->CIKIS YAP\n\n");
    printf("lutfen yapmak istediginiz islemi tuslayiniz:");
    scanf("%d",&islem);
    switch(islem)
    {
    case 1:
        listeleme();
        break;
    case 2:

        printf("Lutfen silmek istediginiz kisinin soyadini giriniz: ");
        scanf("%s",&soyisim);
        silme(soyisim);
        break;
    case 3:
        siralama();
        break;
    case 4:

        printf("Lutfen aramak istediginiz dersin kodunu giriniz:");
        scanf("%d",&kod);
        arama(kod);
    case 5:
        return;
    default:
        printf("\t\t...UYGULAMADAN CIKIS YAPILIYOR...");

    }
}
void listeleme()
{
    int i =0,toplam = 0;
    ogrenci* gecici= head;
    while (gecici!=NULL)
    {
        printf("ADI:%s  ",gecici->ogrenciadi);
        printf("SOYADI:%s  ",gecici->ogrencisoyad);
        printf("NUMARASI:%d  \n\n",gecici->ogrencino);
        for(i=0; i<3; i++)
        {
            printf("DERS ADI:%s  \t",gecici->alinanlar[i].dersadi);
            printf("DERS NOTU:%d \t",gecici->alinanlar[i].dersnot);
            printf("DERS KODU:%d \t",gecici->alinanlar[i].derskod);
            printf("\n");
        }
        printf("ogrencinin not ortalamasi :%d\n\n\n",gecici->ogrenciort);
        gecici = gecici->next;
        printf("\n");
    }
    anamenu();
}
void silme(char *soyisim)
{
    struct b *gecici = NULL;
    struct b *index = head;
    if (head == NULL)
    {
        printf("liste bos..");
        anamenu();
    }
    if (!strcmp(head->ogrencisoyad,soyisim))
    {
        struct ogrenci *t = head;
        head = head->next;
        free(t);
        silme(soyisim);

    }
    while(index != NULL && strcmp(index->ogrencisoyad,soyisim ))
    {
        gecici = index;
        index = index->next;
    }
    if (index != NULL)
    {
        gecici->next = index->next;
        if(tail->ogrencisoyad== soyisim)
        {
            tail=gecici;

        }
        free(index);
        printf("Silme islemi basarili.\n");
        anamenu();
    }
    else
    {
        printf("listede þuan böyle bir eleman yok...");
    }
    anamenu();
}

void siralama() // hocam anlatması benim için de zor olacak ama burayı anlatma gereği duydum.
{
    struct b *index =head->next; //  index değişkeni ilk olarak 2. elemanı tutuyor. indexi hep ilk eleman ile karşılaştırma yapıyorum. biraz recursive mantıgı ama tam o da değil.
    struct b *gecici =head;     // gecici ve temp ve index değişkeni bağlı listede pointerların yerini değiştirken kullanıyorum.
    int *temp = NULL;

    while(index!= NULL)
    {

        if (index->ogrenciort>head->ogrenciort) // indexteki ortalama değeri ilk elemanın ortalama değerinden büyükse.
        {
            temp = index->next; // temp indexin pointer adresini tutuyor. yani listenin geri kalanın adresi.
            index->next = head; // index elemanı ilk elaman oluyor ve nexti önceki listenin ilk elemanına gidiyor.
            gecici->next = temp; // aradan eleman çıktıktan sonra indexten bi önceki elamanın nexti listenin devamını alıyor
            head = index;       // burdan sonra head değeri index elemanı ilk başa geçtiği için yeni değeri artık index oluyor.
            index = index->next; // yeni index değerini tekrar ikinci elemana alıyorum.
            gecici = head; // geciciyi de ilk basa alıyorum.
            }
           else
        {
            index = index->next;   // index değeri eğer ilk baştaki değerden büyük değilse index ve gecici değeri birer ileri atlıyor.
            gecici = gecici->next;  // daha büyük bir eleman geldiğinde index ve gecici değerleri sıfırlanıp listenin başına geçtiği için -
        }                           // liste sıralı hale geldiğinde index değeri liste sonunu yani null' değerini işaret ediyor. o zaman da while döngüsü bitiyor.
      }
    int i =0,toplam = 0;   // burdan sonra da sıralı listeyi yazıyor. tekrar listeleme fonkskiyonu ile yazdirmadim cikti ekraninda cok karistigi icin alternatif yol olarak direk listeleme fonksiyonu da çagirilabilir.
    ogrenci* yazdirg= head;
    while (yazdirg!=NULL)
    {
        printf("ADI:                             %s\n",yazdirg->ogrenciadi);
        printf("SOYADI:                          %s\n",yazdirg->ogrencisoyad);
        printf("NUMARASI:                        %d\n",yazdirg->ogrencino);
        printf("OGRENCININ GENEL NOT ORTALAMASI: %d\n\n",yazdirg->ogrenciort);
        yazdirg = yazdirg->next;
    }

    anamenu();

}
void arama(int kod)
{
    struct b * gecici = head;
    int i ;

    for (i=0; i<3; i++)
    {
        if (head->alinanlar[i].derskod == kod)
        {
            printf("\n\tDERSIN ADI:%s DERSIN KODU:%d\n\n",head->alinanlar[i].dersadi,head->alinanlar[i].derskod);

        }
    }
    while(gecici != NULL)
    {
        for (i = 0 ; i<3; i++)
        {
            if (gecici->alinanlar[i].derskod == kod)
            {
                printf("ADI:%s     \t",gecici->ogrenciadi);
                printf("SOYADI:%s  \t",gecici->ogrencisoyad);
                printf("NUMARASI:%d\t",gecici->ogrencino);
                printf("DERS NOTU:%d\t",gecici->alinanlar[i].dersnot);
                printf("\n");

            }


        }

        gecici = gecici->next;

    }
    anamenu();
}

int main()
{
    FILE *dosya ;
    dosya = fopen("21100011032.txt","r");
    if(dosya == NULL)
    {
        printf("dosya acilamadi...");
    }
    else
    {

        while (!feof(dosya))
        {
            if (head == NULL) // ilk eleman yoksa yani liste bos ise
            {
                ogrenci *new = (ogrenci *)malloc(sizeof(ogrenci));
                int i = 0,toplam = 0 ;

                fscanf(dosya, "%s", new->ogrenciadi);
                fscanf(dosya, "%s", new->ogrencisoyad);
                fscanf(dosya, "%d", &new->ogrencino);
                new->alinanlar = (dersler *)malloc(sizeof(dersler) * 3); // her ogrenci 3 ders aldigi icin boyle dinamik olmasi sarti olmadigi icin kendimi zorlamadim.
                for (i = 0; i < 3; i++)
                {
                    fscanf(dosya, "%s", new->alinanlar[i].dersadi);
                    fscanf(dosya, "%d", &new->alinanlar[i].dersnot);
                    fscanf(dosya, "%d", &new->alinanlar[i].derskod);
                    toplam += new->alinanlar[i].dersnot;           // not ortalamalarini kaydetmedim dosyaya burda her ogrenci için hesaplamak icin notlari topladim.
                }
                new->ogrenciort = toplam/3;

                new->next = NULL;
                head = tail = new; // ilk eleman oldugu icin listenin basi ve sonu bu eleman olmasi lazim.
            }
            else
            {
                int i = 0,toplam =0;
                ogrenci *new = (ogrenci *)malloc(sizeof(ogrenci));
                fscanf(dosya, "%s", new->ogrenciadi);
                fscanf(dosya, "%s", new->ogrencisoyad);
                fscanf(dosya, "%d", &new->ogrencino);
                new->alinanlar = (dersler *)malloc(sizeof(dersler) * 3);
                for (i = 0; i < 3; i++)
                {

                    fscanf(dosya, "%s", new->alinanlar[i].dersadi);
                    fscanf(dosya, "%d", &new->alinanlar[i].dersnot);
                    fscanf(dosya, "%d", &new->alinanlar[i].derskod);
                    toplam += new->alinanlar[i].dersnot;
                }
                new->ogrenciort = toplam/3;
                new->next = NULL;
                tail->next = new;
                tail = new;
            }
        }
    }

    anamenu();
    return 0;
}
