#include<stdio.h>
#include<stdlib.h>

// Dugum yapisi atanir
struct dugum {
    int veri;            // dugumun sakladigi deger atanir
    struct dugum* sonraki;  // sonraki dugumun pointer'i
};

// Kuyrugun basi ve sonu
struct dugum* on = NULL;
struct dugum* arka = NULL;

// Kuyruga eleman ekleme fonksiyonu olusturulur
void kuyrugaEkle(int veri) {
    struct dugum* yeniDugum = (struct dugum*)malloc(sizeof(struct dugum)); // Yeni bir dugum icin bellekte yer acilir
    yeniDugum->veri = veri; // Dugumun verisi atanir
    yeniDugum->sonraki = NULL; // Yeni dugumun sonraki pointer'i NULL olarak ayarlanir
    if (arka == NULL) {  // Kuyruk bos ise yeni dugum hem bas hem de son olur
        on = arka = yeniDugum;
        return;
    }
    arka->sonraki = yeniDugum;  // Kuyrugun sonuna yeni dugum eklenir
    arka = yeniDugum;  // Yeni dugum artik son eleman olarak atanir
}

// Kuyruktan eleman cikarma fonksiyonu olusturulur
void kuyruktanCikar() {
    if (on == NULL) { // Kuyruk bos ise islem yapilamaz
        printf("Kuyruk bos\n");
        printf("\n");
        return;
    }
    struct dugum* temp = on;  // Cikarilacak eleman gecici bir pointer ile tutulur
    on = on->sonraki;  // Kuyruktan bas elemani cikarilir
    if (on == NULL)
        arka = NULL;  // Kuyruk bos ise arka da NULL yapilir
    printf("Silinen eleman: %d\n", temp->veri); // Silinen eleman ekrana yazdirilir
    printf("\n");
    free(temp); // Bellekten silinir
}

// Kuyruk elemanlarini ekrana yazdirma fonksiyonu olusturulur
void kuyrukGoruntule() {
    if (on == NULL) { // Kuyruk bos ise islem yapilamaz
        printf("Kuyruk bos\n");
        printf("\n");
        return;
    }
    struct dugum* temp = on; // Kuyruktaki elemanlar gecici bir pointer ile tutulur
    while (temp != NULL) { // Kuyruktaki elemanlar dongu ile yazdirilir
        printf("Kuyruktaki veriler: %d ", temp->veri);
        printf("\n");
        temp = temp->sonraki;
    }
    printf("\n");
}

int main() {
    int secim, veri; // Degiskenler atanir
    while (1) {
        printf("1. Eleman ekle\n"); // Secenekler yazdirilir
        printf("2. Eleman sil\n");
        printf("3. Kuyruk goruntule\n");
        printf("4. Cikis\n\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim); // Kullanici secim yapar
        printf("\n");
        switch (secim){  //Kullanicinin secimine gore islem yapilir
            case 1:
                printf("Eklenecek elemani girin: "); // Kullanici eger eleman eklemek isterse bu kýsým calisir ve eleman girmesi istenir
                scanf("%d", &veri);
                printf("\n");
                kuyrugaEkle(veri); // Ekleme fonksiyonu cagirilir
                break;
            case 2:
                kuyruktanCikar(); // Eðer eleman silmek isterse bu kisim calisir ve ilk girdigi eleman silinir
                break;
            case 3:
                kuyrukGoruntule();  // Eðer girilen elemanlari görmek isterse bu kisim calisir ve elemanlar gozukur
                break;
            case 4:
            	printf("Programdan cikis yapildi"); // Eðer programdan cikis yapmak isterse bu kisim calisir ve programdan cikis yapilir
                  
                printf("\n\n");
                printf("ISIM: TAHA YASIN\n");
	            printf("SOYISIM: CICEK\n");
            	printf("OGRENCI NO: 1220505012\n");
                printf("PROGRAMIN YAPTIGI ISLEM: Kuyruklarin baglantili liste uygulamasini gostermek");
    
				exit(0);
                
            default: // Eger kullanici 1-4 disinda bir karekter girerse uyari alir
            	printf("\n");
                printf("Gecersiz secim\n");
                printf("\n");
        }
    }
    
   
    
    
    return 0;
}

