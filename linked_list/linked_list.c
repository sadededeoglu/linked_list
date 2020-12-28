#include <stdio.h>
#include <stdlib.h>

typedef struct bagli_liste
{
    // bagli liste icin us ve coefficient bilgilerini iceren struct yapisi olusturulur.
    //2 adet deðiþken tanýmlanýr
    int Upper;
    int Coefficient;
    //bagli listenin bellekteki next yeri belirtiliyor.
    struct bagli_liste* next;
}BLISTE;
//biste altýndaki deðiþkenler, deðerleri ve yeni pointerlar eklendi.
BLISTE* ilk = NULL, * ilk2 = NULL, * ilk3 = NULL,
* son = NULL, * son2 = NULL, * son3 = NULL,
* yeni, * yeni2, * yeni3, * pol1, * pol2, * pol3, * pol4;

BLISTE ekle(BLISTE* yeni) // 1.polinom icin ekleme fonksiyonu
{                         // 2 polinom farkli bagli listede tutulmaktadir.
    if (ilk != NULL) {       //eðer ilk deðer null eþit deðil ise;
        printf(ilk);
        son->next = yeni;   // son deðiþkeninin next i yeniye eþitleniyor.
        son = yeni;
        son->next = NULL;   //sonun next i null a eþitleniyor
    }
    else {                //deðiþken null ise
        ilk = yeni;         // ilk yeni ye eþitlenip son da ilk e eþitleniyor
        son = ilk;
        ilk->next = NULL;
    }
}
BLISTE ekle2(BLISTE* yeni2)
{
    if (ilk2 != NULL) {
        son2->next = yeni2;
        son2 = yeni2;
        son2->next = NULL;
    }
    else {
        ilk2 = yeni2;
        son2 = ilk2;
        ilk2->next = NULL;
    }
}
BLISTE ekle3(BLISTE* yeni3)
{
    if (ilk3 != NULL) {
        son3->next = yeni3;
        son3 = yeni3;
        son3->next = NULL;
    }
    else {
        ilk3 = yeni3;
        son3 = ilk3;
        ilk3->next = NULL;
    }
}
BLISTE yazdir(BLISTE* ilk3)
{
    printf("\nPOLINOMLAR CARPIMI  H(x)=");

    while (pol3)
    {
        if (pol3->Coefficient == 0) {                     // eger katsayi 0 ise bir sonraki dugume gec
            pol3 = pol3->next;
            continue;
        }                     //donguyu basta al

        if (pol3->Upper != 0) {                      // eger us 0 dan farkli ise katsayiyi ve ussu yaz
            printf("(%dX^%d)", pol3->Coefficient, pol3->Upper);
            pol3 = pol3->next;                                // siradaki dugume gec
            if (pol3 != NULL)                                    //siradaki dugum NULL degilse + koy
                printf("+");
        }
        if (pol3->Upper == 0) {
            printf("(%d)", pol3->Coefficient);                // eger us 0 ise sadece katsayiyi yaz
            pol3 = pol3->next;                           // siradaki dugume gec
            if (pol3 != NULL)                              // siradaki dugum NULL degilse + koy
                printf("+");
        }
    }
}
int main() {

    int i = 0, sayac = 0;
    int maxus, maxus2, us1, us2, secenek;
    printf("\n1.Polinomun derecesini giriniz:");                            // 1.polinomun en buyuk ussu istenmektedir
    scanf("%d", &maxus);                                                   //bu deger maxus degiskeninde tutulmaktadir
    us1 = maxus;                                                            // maxus degeri for dongusu icinde 0 a kadar dusecegi icin

    for (i = maxus + 1; maxus + 1 > 0; maxus--)                   // baska degiskenlerde maxusun degeri saklanmaktadir
    {
        yeni = (struct bagli_liste*)malloc(sizeof(struct bagli_liste));             // dinamik bellek alani istenmektedir.
        printf("1.Polinomun X^%d ifadesinin katsayisini :", maxus);
        scanf("%d", &(yeni->Coefficient));                        // 1.polinom icin katsayi bilgisi disaridan alinmaktadir.
        yeni->Upper = maxus;                                     // 1.polinom icin us bilgisine maxus degeri atanmaktadir
        ekle(yeni);
    }
    printf("2.polinomun derecesini giriniz:");
    scanf("%d", &maxus2);
    us2 = maxus2;

    for (i = maxus2 + 1; maxus2 + 1 > 0; maxus2--)
    {
        yeni2 = (struct bagli_liste*)malloc(sizeof(struct bagli_liste));
        printf("2.Polinomun X^%d ifadesinin katsayisini giriniz:", maxus2);
        scanf("%d", &yeni2->Coefficient);
        yeni2->Upper = maxus2;
        ekle2(yeni2);
    }

    pol1 = ilk;                                    // p ye 1.polinomun ilk dugumu atanir
    printf("1.polinom  F(X)=");

    while (pol1)
    {                                           // 1.polinomun ekrana yazdirilmasi islemi
        if (pol1->Coefficient == 0)
        {                                   // eger polinomdaki ifadenin katsayisi 0 ise bir sonraki dugume gecer
            pol1 = pol1->next;
            continue;
        }                                     //  continue islemi ile islem alttaki ifadelere gecmez basa gelir
        if (pol1->Upper != 0)
        {                                         // eger dugumun ussu 0 dan farkli ise
            printf("(%dX^%d)", pol1->Coefficient, pol1->Upper);
            pol1 = pol1->next;                               //dugum atlar
            if (pol1 != NULL)                            // atladigimiz bu dugum eger en son dugum degilse
                printf("+");
        }
        if (pol1->Upper == 0)
        {                         // eger us 0 a esitse
            printf("(%d)", pol1->Coefficient);                    // sadece katsayiyi yaz
            pol1 = pol1->next;                                // siradaki dugume gec
            if (pol1 != NULL)                                 // atlanan dugum en son dugum degilse
                printf("+");
        }                                          // yani bir sonraki dugum NULL degilse

    }          // + isareti koy
    printf("\n");
    pol2 = ilk2;
    printf("2.polinom  G(x)=");

    while (pol2)
    {                               //1.polinom icin yapilan toplama mantigi ve islemler
        if (pol2->Coefficient == 0)
        {                  //2.polinom icin gecerlidir.
            pol2 = pol2->next;
            continue;
        }
        if (pol2->Upper != 0)
        {
            printf("(%dX^%d)", pol2->Coefficient, pol2->Upper);
            pol2 = pol2->next;
            if (pol2 != NULL)
                printf("+");
        }
        if (pol2->Upper == 0)
        {
            printf("(%d)", pol2->Coefficient);
            pol2 = pol2->next;
            if (pol2 != NULL)
                printf("+");
        }
    }
    pol1 = ilk;  // 1. 2. 3. polinomlarin tutuldugu bagli listelerdeki ilk dugumler p p2 ve p3 e atandi
    pol2 = ilk2;
    pol3 = ilk3;

    while (pol1)
    {
        while (pol2)
        {
            sayac++;
            i++;
            yeni3 = (struct bagli_liste*)malloc(sizeof(struct bagli_liste));
            yeni3->Upper = pol1->Upper + pol2->Upper;
            yeni3->Coefficient = (pol1->Coefficient) * (pol2->Coefficient);
            pol2 = pol2->next;
            ekle3(yeni3);

            if (i % (us2 + 1) == 0)
            {
                pol1 = pol1->next;
                pol2 = ilk2;
            }
            if (sayac == ((us2 + 1) * (us1 + 1)))
            {
                pol2 = NULL;
                pol1 = NULL;
            }
        }
    }
    pol3 = ilk3;
    yazdir(pol1);
}
