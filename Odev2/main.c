// 21100011032 Mustafa Altıparmak veri yapilari 2.ödevi
#include <stdio.h>
#include <stdlib.h>
typedef struct sunucular
{
    int sunucuid;
    int yuk;
    int maxkapasite;
    int musaitlik;
    struct sunucular * onceki;
    struct sunucular* sonraki;

} sunucular;
struct sunucular *head= NULL;
struct sunucular *tail= NULL;

void anamenu(){
    int islem;
   printf("\t1-URETICI\n\t2->TUKETICI\n\t3->LISTELE\n\t4->EXIT\n\tYapmak istediginiz islemi seciniz:");
   scanf("%d",&islem);
   switch (islem){
   case 1:
        uretici();
        break;
   case 2:
        tuketici();
        break;
   case 3:
        listele();
        break;
   case 4:
            return;
            break;
   default:
    printf("yanlis tuslama yaptiniz..!");
    anamenu();
    }
   }
void tuketici()
{
    int eyuk=0;
    printf("ne kadar yuk cikarmak istiyorsunuz?");
    scanf("%d",&eyuk);
    sunucular* ptr1;
    ptr1 = head;
    int sayi =0,toplam = 0;
    while(ptr1 !=head || sayi == 0 ){
        sayi = 1;
        toplam += ptr1->yuk;
    }
    if (toplam<eyuk){
        printf("\t\tsunucuda yeterli yuk yok...\n\n");
        anamenu();
    }
    sunucular* ptr;
    ptr = tail;
    do{
        if(ptr->yuk>eyuk){
                ptr->yuk -= eyuk;
                ptr->musaitlik = ptr->maxkapasite-ptr->yuk;
                eyuk=0;

        }
        else{
                int gecici = ptr->yuk;

                ptr->yuk = 0;
                ptr->musaitlik = ptr->maxkapasite-ptr->yuk;
                eyuk -= gecici;

          }

         ptr = ptr->sonraki;

    }while( ptr !=head && eyuk != 0);
    sirala(); anamenu();
}
void uretici()
{
    int eyuk=0;
    printf("ne kadar yuk eklemek istiyorsunuz:");
    scanf("%d",&eyuk);
    sunucular* ptr1;
    ptr1 = head;
    int sayi =0,toplam = 0;
    while(ptr1 !=head || sayi == 0 ){
        sayi = 1;
        toplam += ptr1->musaitlik;
    }
    if (toplam<eyuk){
        printf("\t\tsunucu kapasitesini asildi..!\n\n");
        anamenu();
    }
    sunucular* ptr;
    ptr = tail;
    do{
         if(eyuk<=ptr->musaitlik){
                ptr->musaitlik =ptr->musaitlik - eyuk;
                ptr->yuk += eyuk;
                sirala();
                anamenu();
                return;
          }
            else{
                                int gecici = eyuk;
                                eyuk -=ptr->musaitlik;
                                ptr->musaitlik =0;
                                ptr->yuk += gecici-eyuk;
                    }
        ptr = ptr->onceki;
         }while( ptr != tail );

}

void listele()
{
    if(head== NULL)
    {
        printf("suan tanimli sunucu yok..");
        return;
    }
    struct sunucular * gecici = head;

    do
    {
        printf("ID: %d    Mevcut Yuk: %d    Maks kapasitesi: %d\n",gecici->sunucuid,gecici->yuk,gecici->maxkapasite);
        gecici = gecici->sonraki;



    }
    while(gecici != head);
    printf("\n\n");
    anamenu();
}

void sirala()
{
    sunucular* index;
    sunucular * prev;
    sunucular *temp;
        sunucular * prev2;
  sunucular* index2;
  sunucular* ilk = head;
  int sayi =0;
 for (index = ilk->sonraki;index!=head|| sayi ==0;index=index->sonraki){
            sayi=1;

         for (index2 = index->onceki;index2 != tail && index->musaitlik <index2->musaitlik;index2=index2->onceki ){
                if(index == tail){
                        tail = index->onceki;

                    }
                    prev = index->onceki;
                    temp = index->sonraki;
                    prev->sonraki = temp;
                    temp->onceki = prev;
                    prev2 = index2->onceki;
                    prev2->sonraki = index;
                    index->onceki= prev2;
                    index->sonraki = index2;
                    index2->onceki = index;
                      if (index2 == head){
                        head= index;
                    }
                    if (index2 == tail){
                        index2 = index;
                    }


                    index = head->sonraki;
                    index2 = index;
         }
       }

}

void yerac(int adet)
{
    for (int i =0 ; i<adet; i++)
    {
        struct sunucular *new = (sunucular*)calloc(1,sizeof(sunucular));
        printf("sunucunun id bilgisini giriniz:");
        scanf("%d",&new->sunucuid);
        printf("Sunucunun suanki yuk drumunu giriniz.");
        scanf("%d",&new->yuk);
        printf("sunucunun max yuk kapasitesini giriniz:");
        scanf("%d",&new->maxkapasite);
        new->musaitlik = (new->maxkapasite)-(new->yuk);



        if(head==NULL)
        {
            new->onceki = new;
            new->sonraki = new;
            head = tail = new;
        }
        else
        {
            if (head->sonraki == head)
            {
                new->onceki = head;
                new->sonraki =head;
                head->sonraki = new;
                head->onceki = new;
            }
            else
            {

                tail->sonraki = new;
                new->onceki=tail;
                new->sonraki = head;
                head->onceki = new;
            }
            tail = new;
        }
    }
}
int main()
{
    int adet;
    printf("Kac adet sunucu var ? ");
    scanf("%d",&adet);
    yerac(adet);
    sirala();
    anamenu();

    return 0;
}
