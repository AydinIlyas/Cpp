/************************************************************************************************************************************************
**                                                     SAKARYA ÜNİVERSİTESİ
**                                             BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                                             BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                                             PROGRAMLAMAYA GİRİŞ DERSİ
**                                             ÖDEV NUMARASI:    1
**                                             ÖĞRENCİ ADI: İLYAS AYDIN
**                                             ÖĞRENCİ NUMARASI: B211210101
**                                             DERS GRUBU:  1-A
************************************************************************************************************************************************/


#include <iostream>
#include <string>
#include<time.h>     //rand() için
#include<cstdlib>    //srand(time(0)) için
#include<locale.h>   //setlocale için
#include<iomanip>    //setw için

using namespace std;

int main()
{
    setlocale(LC_ALL, "Turkish");
    const int Max = 81;   //toplam il sayısı kadar arrayde yer acmak için. Max il sayisini ifade eder
    string il[Max] = {
        "ADANA", "ADIYAMAN", "AFYONKARAHİSAR", "AĞRI", "AKSARAY", "AMASYA", "ANKARA", "ANTALYA", "ARDAHAN",
        "ARTVİN", "AYDIN", "BALIKESİR", "BARTIN", "BATMAN", "BAYBURT", "BİLECİK", "BİNGÖL", "BİTLİS", "BOLU", "BURDUR",
        "BURSA", "ÇANAKKALE", "ÇANKIRI", "ÇORUM", "DENİZLİ", "DİYARBAKIR", "DÜZCE", "EDİRNE", "ELAZIĞ",
        "ERZİNCAN", "ERZURUM", "ESKİŞEHIR", "GAZİANTEP", "GİRESUN", "GÜMÜŞHANE", "HAKKÂRİ", "HATAY", "IĞDIR", "ISPARTA",
        "İSTANBUL", "İZMİR", "KAHRAMANMARAŞ","KARABÜK", "KARAMAN", "KARS", "KASTAMONU", "KAYSERİ", "KİLİS", "KIRIKKALE",
        "KIRKLARELİ", "KIRŞEHİR", "KOCAELİ", "KONYA", "KÜTAHYA","MALATYA", "MANİSA", "MARDİN", "MERSİN", "MUĞLA", "MUŞ",
        "NEVŞEHİR", "NİĞDE", "ORDU", "OSMANİYE", "RİZE", "SAKARYA", "SAMSUN", "ŞANLIURFA","SİİRT", "SİNOP", "SİVAS", "ŞIRNAK",
        "TEKİRDAĞ", "TOKAT", "TRABZON", "TUNCELİ", "UŞAK", "VAN", "YALOVA", "YOZGAT", "ZONGULDAK"
    };

    string enbuyuk = il[0];                     //En büyük ili tutacak string oluşturuldu.
    string enkucuk = il[0];                    //En küçük ili tutacak string oluşturuldu.
    int enKisa;                           //en kısa ilin uzunluğunu tutar
    int enUzun;                           //en uzun ilin uzunluğunu tutar

    //Tüm illerin uzunluklarını karşılaştırabilmek için döngü kullanıldı
    for (int i = 0; i < Max; i++)
    {
        //enbuyuk stringin uzunluğu ile illerin uzunlukları karşılaştırılır ve en uzun il enbuyuk stringine atılır,uzunluğu da enUzun a atılır
        if (il[i].length() > enbuyuk.length())
        {
            enbuyuk = il[i];
            enUzun = enbuyuk.length();
        }
        //enkucuk stringin uzunluğu ile illerin uzunlukları karşılaştırılır ve en kısa il enkucuk stringine atılır, uzunluğu da enKisa ya atılır
        if (il[i].length() < enkucuk.length())
        {
            enkucuk = il[i];
            enKisa = enkucuk.length();
        }
    }
    //en kısa ve uzun iller yazdırılır ve uzunlukları da belirtilir
    cout << left << setw(30) << "En kısa karakterli ilimiz:" << left << setw(15) << enkucuk << right << setw(10) << enKisa << " karakterli" << endl;
    cout << left << setw(30) << "En uzun karakterli ilimiz:" << left << setw(15) << enbuyuk << right << setw(10) << enUzun << " karakterli" << endl;

    const int x = 20;           //arrayde en az en uzun ilin uzunluğu kadar yer olmalı
    int denemeSayisi = 100000;
    string elemanlar[x];      //rastgele seçilen illeri tutar
    string bulunan;           //seçilen illerin indislerin birleşimini tutar
    string sonuc;             //eğer indislerin birleşimi il olursa bu stringe atılır

    srand(time(0));
    //100000 denemeden sonra harf sayısını artırır ve enUzun ile geldiğinde sona erer
    //e döngüde aranılan ilin harf sayısını ifade eder ve kac ilin secileceğini de belirler
    for (int e = enKisa; e <= enUzun; e++)
    {
        //il bulana kadar döner bulursa ili yazdırır,bulamadığı sürece devam eder. 100000 defa döndükten sonra sona erer ve bulamadı yazdırır
        for (int i = 1; i <= denemeSayisi; i++)
        {
            //aranan ilin uzunluğu kadar  kadar il rastgele seçer
            for (int a = 0; a < e; a++)
            {
                elemanlar[a] = il[rand() % 81];
            }

            int secilenin_ek = enUzun;                       //seçilen illerin en kısasının uzunluğunu tutması için oluşturuldu
            //seçilen illleri karşılaştırır
            for (int b = 0; b < e; b++)
            {
                //rastgele seçilen iller arasında en kısa ilin uzunluğunu bulur
                if (elemanlar[b].length() < secilenin_ek)
                {
                    secilenin_ek = elemanlar[b].length();
                }
            }
            //en kısa ilin son indisine kadar indisleri birleştirir
            for (int j = 0; j < secilenin_ek; j++)
            {
                bulunan.clear(); //bulunan stringini boşaltır

                //illerin indisleri alinarak birleştirilir. c Kelime hangi kelimenin, j harf indisini belirtir.
                for (int c = 0; c < e; c++)
                {
                    bulunan += elemanlar[c][j];
                }

                //bulunan stringi il oluşturdu mu diye diğer illerle karşılaştırılır.Eğer bulursa sonuc stringine atar
                for (int d = 0; d < Max; d++)
                {
                    //bulursa sonuc stringine atar ve yazdırabilmek için döngülerden break ile cıkılılır
                    if (bulunan.compare(il[d]) == 0)
                    {
                        sonuc = bulunan;
                        break;
                    }
                }
                //döngüden cıkar
                if (sonuc == bulunan)
                {
                    break;
                }
            }
            //ili yazdırır ve aranacak ilin harf sayısını artırır.Ardından döngüden çıkarak işlemleri tekrarlar
            if (sonuc == bulunan)
            {
                cout << e << " harfli il:" << endl;
                cout << sonuc << endl;
                break;
            }
        }
        //Bulamadıysa 100000.denemeden sonra bulunamadıysa bulunamadı yazdırır, aranan ilin harf sayısını artırır.
        if (sonuc!=bulunan)
        {
            cout << e << " harfli il:" << endl;
            cout << "Bulunamadı" << endl;
        }
    }
    system("PAUSE");  //sonucun açık kalmasını sağlar
    return 0;
}
