/************************************************************************************************************************************************
**                                                     SAKARYA UNIVERSITESI
**                                             BILGISAYAR VE BILISIM BILIMLERI FAKULTESI
**                                             BILGISAYAR MUHENDISLIGI BOLUMU
**                                             PROGRAMLAMAYA GIRIS DERSI
**                                             ODEV NUMARASI:    3/ Proje
**                                             OGRENCI ADI: ILYAS AYDIN
**                                             OGRENCI NUMARASI: B211210101
**                                             DERS GRUBU:  1-A
************************************************************************************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include<iomanip>
#include<cstring>



using namespace std;
class dosyalama
{
private:
	//urun.txt icin
	string UrunKodu;
	string UrunAdi;
	string Ureticisi;
	string TeminSuresi;
	string UretimTarihi;
	string Fiyat;
	string FiyatOzel;
	string KdvOrani;
	string StokAdedi;
	//cari.txt icin
	string FirmaNo;
	string FirmaAdi;
	string FirmaTelefon;
	string FirmaSorumlusu;
	string MusteriKategorisi;
	string Adres;
	string siparisNo;
	string siparisTarihi;
	string siparisTutari;
	string siparisAlan;
	string UrunKoduSiparis;
	//Siparislistesi dosyasyi
	string UrunAdedi;
	string UrunAdedi_1;
	float ffiyat;
	int fUrunAdedi;
	int fgUrunAdet;
	int faUrunAdet;
	string bossatir;
	int kontrol = 0;
	int musterikategorisi;
	
	string aranan;
	char devam;
	char uruntekrar;
	char menu;
	string Error;
	string delimiter = "****************************************************************************";
	string Bul;
	int Adet;
	int AdetAl;
	int AdetVer;
	int deneme;
	string UrunKodu1;
	string tarih;
	string kodsor;
	//int q = 0;
	//int k = 1;
public:
	void urunekle()
	{
		do {
			ofstream Yaz("urun.txt", ios::app);


			do {
				ifstream Oku("urun.txt");
				cout << left << setw(15) << "Urun Kodu: "; getline(cin, UrunKodu);
				while (!Oku.eof())
				{

					getline(Oku, Error);
					getline(Oku, UrunAdi);
					getline(Oku, Ureticisi);
					getline(Oku, UretimTarihi);
					getline(Oku, TeminSuresi);
					getline(Oku, Fiyat);
					getline(Oku, FiyatOzel);
					getline(Oku, KdvOrani);
					getline(Oku, StokAdedi);
					getline(Oku, bossatir);




					if (Error == UrunKodu)
					{
						cout << "Error! Baska bir urun kodu kullaniniz" << endl;
						break;
					}

				}
				Oku.close();
			} while (Error == UrunKodu);

			cout << left << setw(15) << "Urun Adi: "; getline(cin, UrunAdi);
			cout << left << setw(15) << "Uretici: "; getline(cin, Ureticisi);
			cout << left << setw(15) << "Uretim tarihi: "; getline(cin, UretimTarihi);
			cout << left << setw(15) << "Temin Suresi: "; getline(cin, TeminSuresi);
			cout << left << setw(15) << "Fiyat: "; getline(cin, Fiyat);
			cout << left << setw(15) << "Fiyat Ozel: "; getline(cin, FiyatOzel);
			cout << left << setw(15) << "KDV Orani: "; getline(cin, KdvOrani);
			cout << left << setw(15) << "Stok Adedi: "; getline(cin, StokAdedi);

			Yaz << UrunKodu << "\n" << UrunAdi << "\n" << Ureticisi
				<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
				<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << StokAdedi << "\n" << delimiter << "\n";
			Yaz.close();
			cout << "Baska Kayit yapmak istiyor musunuz?(e/h)\n";
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');
	}
	void urunArama()
	{
		do {
			ifstream Oku("urun.txt");
			cout << "Aramak istediginiz urunun kodunu giriniz" << endl;
			getline(cin, aranan);
			kontrol = 0;
			while (!Oku.eof())
			{


				getline(Oku, UrunKodu);
				getline(Oku, UrunAdi);
				getline(Oku, Ureticisi);
				getline(Oku, UretimTarihi);
				getline(Oku, TeminSuresi);
				getline(Oku, Fiyat);
				getline(Oku, FiyatOzel);
				getline(Oku, KdvOrani);
				getline(Oku, StokAdedi);
				getline(Oku, bossatir);


				if (aranan == UrunKodu)
				{
					kontrol = 1;
					cout << left << setw(15) << "Urun Kodu: " << UrunKodu << endl;
					cout << left << setw(15) << "Urun Adi: " << UrunAdi << endl;
					cout << left << setw(15) << "Ureticisi: " << Ureticisi << endl;
					cout << left << setw(15) << "Uretim Tarihi: " << UretimTarihi << endl;
					cout << left << setw(15) << "Temin Suresi: " << TeminSuresi << endl;
					cout << left << setw(15) << "Fiyat: " << Fiyat << endl;
					cout << left << setw(15) << "Fiyat Ozel: " << FiyatOzel << endl;
					cout << left << setw(15) << "KDV Orani: " << KdvOrani << endl;
					cout << left << setw(15) << "Stok Adedi: " << StokAdedi << endl;
					cout << delimiter << endl;

				}


				if (Oku.eof())
				{
					break;
				}

			}
			if (kontrol == 0)
			{
				cout << "Urun Bulunamadi." << endl;
			}
			Oku.close();
			cout << "Tekrar aramak istiyor musunuz?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		} while (devam == 'e');
	}
	void urunlisteleme()
	{
		do {

			ifstream Oku("urun.txt");

			while (!Oku.eof())
			{

				getline(Oku, UrunKodu);
				getline(Oku, UrunAdi);
				getline(Oku, Ureticisi);
				getline(Oku, UretimTarihi);
				getline(Oku, TeminSuresi);
				getline(Oku, Fiyat);
				getline(Oku, FiyatOzel);
				getline(Oku, KdvOrani);
				getline(Oku, StokAdedi);
				getline(Oku, bossatir);
				if (Oku.eof())
				{
					break;
				}

				cout << left << setw(15) << "Urun Kodu: " << UrunKodu << endl;
				cout << left << setw(15) << "Urun Adi: " << UrunAdi << endl;
				cout << left << setw(15) << "Ureticisi: " << Ureticisi << endl;
				cout << left << setw(15) << "Uretim Tarihi: " << UretimTarihi << endl;
				cout << left << setw(15) << "Temin Suresi: " << TeminSuresi << endl;
				cout << left << setw(15) << "Fiyat: " << Fiyat << endl;
				cout << left << setw(15) << "Fiyat Ozel: " << FiyatOzel << endl;
				cout << left << setw(15) << "KDV Orani: " << KdvOrani << endl;
				cout << left << setw(15) << "Stok Adedi: " << StokAdedi << endl;
				cout << bossatir << endl;;


			}
			Oku.close();
			cout << "Islemi tekrarlamak istiyor musunuz?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
		} while (devam == 'e');
	}
	void urundegistirme()
	{
		do {
			ifstream Oku("urun.txt");
			ofstream Yaz("urun.tmp");
			cout << "Degistirmek istediginiz urunun kodunu giriniz" << endl;
			getline(cin, aranan);
			kontrol = 0;

			while (!Oku.eof())
			{
				getline(Oku, UrunKodu);
				getline(Oku, UrunAdi);
				getline(Oku, Ureticisi);
				getline(Oku, UretimTarihi);
				getline(Oku, TeminSuresi);
				getline(Oku, Fiyat);
				getline(Oku, FiyatOzel);
				getline(Oku, KdvOrani);
				getline(Oku, StokAdedi);
				getline(Oku, bossatir);
				if (Oku.eof())
				{
					break;
				}

				if (aranan == UrunKodu)
				{
					kontrol = 1;
					cout << "ESKI BILGILER" << endl;
					cout << left << setw(15) << "Urun Kodu: " << UrunKodu << endl;
					cout << left << setw(15) << "Urun Adi: " << UrunAdi << endl;
					cout << left << setw(15) << "Ureticisi: " << Ureticisi << endl;
					cout << left << setw(15) << "Uretim Tarihi: " << UretimTarihi << endl;
					cout << left << setw(15) << "Temin Suresi: " << TeminSuresi << endl;
					cout << left << setw(15) << "Fiyat: " << Fiyat << endl;
					cout << left << setw(15) << "Fiyat Ozel: " << FiyatOzel << endl;
					cout << left << setw(15) << "KDV Orani: " << KdvOrani << endl;
					cout << left << setw(15) << "Stok Adedi: " << StokAdedi << endl;


					cout << "BILGILERI GUNCELLEYINIZ" << endl;
					cout << left << setw(20) << "Yeni Urun Kodu: "; getline(cin, UrunKodu);
					cout << left << setw(20) << "Yeni Urun Adi: "; getline(cin, UrunAdi);
					cout << left << setw(20) << "Yeni Uretici Adi: "; getline(cin, Ureticisi);
					cout << left << setw(20) << "Yeni Uretim Tarihi: "; getline(cin, UretimTarihi);
					cout << left << setw(20) << "Yeni Temin Suresi: "; getline(cin, TeminSuresi);
					cout << left << setw(20) << "Yeni Fiyat: "; getline(cin, Fiyat);
					cout << left << setw(20) << "Yeni Ozel Fiyat: "; getline(cin, FiyatOzel);
					cout << left << setw(20) << "Yeni Kdv Orani: "; getline(cin, KdvOrani);
					cout << left << setw(20) << "Yeni Stok Adedi: "; getline(cin, StokAdedi);


					Yaz << UrunKodu << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << StokAdedi << "\n" << bossatir << "\n";
				}
				else
				{
					Yaz << UrunKodu << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << StokAdedi << "\n" << bossatir << "\n";
				}



			}
			if (kontrol == 0)
			{
				cout << "Urun Bulunamadi." << endl;
			}
			Oku.close();
			Yaz.close();
			remove("urun.txt");
			rename("urun.tmp", "urun.txt");
			cout << "Degistirmek istediginiz baska urun var mi?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');
	}
	void urunSilme()
	{
		do {
			kontrol = 0;
			ifstream Oku("urun.txt");
			ofstream Yaz("urun.tmp");
			cout << "Silmek istediginiz urunun kodunu giriniz" << endl;
			getline(cin,aranan);

			while (!Oku.eof())
			{

				getline(Oku, UrunKodu);
				getline(Oku, UrunAdi);
				getline(Oku, Ureticisi);
				getline(Oku, UretimTarihi);
				getline(Oku, TeminSuresi);
				getline(Oku, Fiyat);
				getline(Oku, FiyatOzel);
				getline(Oku, KdvOrani);
				getline(Oku, StokAdedi);
				getline(Oku, bossatir);

				if (Oku.eof())
				{
					break;
				}

				if (aranan == UrunKodu)
				{
					kontrol = 1;
					cout << "SILINEN URUN" << endl;
					cout << left << setw(15) << "Urun Kodu: " << UrunKodu << endl;
					cout << left << setw(15) << "Urun Adi: " << UrunAdi << endl;
					cout << left << setw(15) << "Ureticisi: " << Ureticisi << endl;
					cout << left << setw(15) << "Uretim Tarihi: " << UretimTarihi << endl;
					cout << left << setw(15) << "Temin Suresi: " << TeminSuresi << endl;
					cout << left << setw(15) << "Fiyat: " << Fiyat << endl;
					cout << left << setw(15) << "Fiyat Ozel: " << FiyatOzel << endl;
					cout << left << setw(15) << "KDV Orani: " << KdvOrani << endl;
					cout << left << setw(15) << "Stok Adedi: " << StokAdedi << endl;
				}
				else
				{
					Yaz << UrunKodu << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << StokAdedi << "\n" << delimiter << "\n";
				}

			}
			if (kontrol == 0)
			{
				cout << "Urun Bulunamadi." << endl;
			}
			Oku.close();
			Yaz.close();
			remove("urun.txt");
			rename("urun.tmp", "urun.txt");
			cout << "Silmek istediginiz baska urun var mi?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');
	}

	void musteriEkle()
	{
		

		do {
			ofstream Yaz("cari.txt", ios::app);
			ifstream Oku("cari.txt");
			do {
				
				cout << left << setw(20) << "Firma No: "; getline(cin, FirmaNo);
				while (!Oku.eof())
				{

					getline(Oku, Error);
					getline(Oku, FirmaAdi);
					getline(Oku, FirmaTelefon);
					getline(Oku, FirmaSorumlusu);
					getline(Oku, MusteriKategorisi);
					getline(Oku, Adres);
					getline(Oku, bossatir);




					if (Error == FirmaNo)
					{
						cout << "Error! Baska bir Firma kodu kullaniniz" << endl;
						break;
					}

				}
			} while (Error == FirmaNo);


			cout << left << setw(20) << "Firma Adi: "; getline(cin, FirmaAdi);
			cout << left << setw(20) << "Firma Telefon: "; getline(cin, FirmaTelefon);
			cout << left << setw(20) << "Firma Sorumlusu: "; getline(cin, FirmaSorumlusu);
			cout << "GENEL MUSTERI icin(1)e, OZEL MUSTERI icin(2)ye basiniz" << endl;
			cout << left << setw(20) << "Musteri Kategorisi: "; getline(cin, MusteriKategorisi);
			cout << left << setw(20) << "Adres: "; getline(cin, Adres);


			Yaz << FirmaNo << "\n" << FirmaAdi << "\n" << FirmaTelefon
				<< "\n" << FirmaSorumlusu << "\n" << MusteriKategorisi << "\n" << Adres << "\n" << delimiter << endl;
			Oku.close();
			Yaz.close();
			cout << "Baska Kayit yapmak istiyor musunuz?(e/h)\n";
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');
	}

	void musteriArama()
	{
		do {
			ifstream Oku("cari.txt");
			cout << "Aramak istediginiz Musteri kodunu giriniz" << endl;
			getline(cin,aranan);
			kontrol = 0;

			while (!Oku.eof())
			{
				getline(Oku, FirmaNo);
				getline(Oku, FirmaAdi);
				getline(Oku, FirmaTelefon);
				getline(Oku, FirmaSorumlusu);
				getline(Oku, MusteriKategorisi);
				getline(Oku, Adres);
				getline(Oku, bossatir);

				if (Oku.eof())
				{
					break;
				}

				if (aranan == FirmaNo)
				{
					kontrol++;
					cout << left << setw(20) << "Firma No: " << FirmaNo << endl;
					cout << left << setw(20) << "Firma Adi: " << FirmaAdi << endl;
					cout << left << setw(20) << "Firma Telefon: " << FirmaTelefon << endl;
					cout << left << setw(20) << "Firma Sorumlusu: " << FirmaSorumlusu << endl;
					cout << left << setw(20) << "Musteri Kategorisi: " << MusteriKategorisi << endl;
					cout << left << setw(20) << "Adres: " << Adres << endl;

				}

			}
			if (kontrol == 0)
			{
				cout << "Musteri mevcut degil." << endl;
			}

			Oku.close();
			cout << "Baska aramak istediginz Musteri var mi?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');
	}
	void musteriDuzenle()
	{
		do {
			kontrol = 0;
			
			cout << "Degistirmek istediginiz Musterinin Firma kodunu giriniz" << endl;
			getline(cin,aranan);

			ifstream Oku("cari.txt");
			ofstream Yaz("cari.tmp");
			while (!Oku.eof())
			{
				getline(Oku, FirmaNo);
				getline(Oku, FirmaAdi);
				getline(Oku, FirmaTelefon);
				getline(Oku, FirmaSorumlusu);
				getline(Oku, MusteriKategorisi);
				getline(Oku, Adres);
				getline(Oku, bossatir);
				if (Oku.eof())
				{
					break;
				}

				if (aranan == FirmaNo)
				{
					kontrol=1;
					cout << "ESKI MUSTERI BILGILERI" << endl;
					cout << left << setw(20) << "Firma No: " << FirmaNo << endl;
					cout << left << setw(20) << "Firma Adi: " << FirmaAdi << endl;
					cout << left << setw(20) << "Firma Telefon: " << FirmaTelefon << endl;
					cout << left << setw(20) << "Firma Sorumlusu: " << FirmaSorumlusu << endl;
					cout << left << setw(20) << "Musteri Kategorisi: " << MusteriKategorisi << endl;
					cout << left << setw(20) << "Adres: " << Adres << endl;

					cout << "BILGILERI GUNCELLEYINIZ" << endl;
					cout << left << setw(20) << "Firma No: "; getline(cin, FirmaNo);
					cout << left << setw(20) << "Firma Adi: "; getline(cin, FirmaAdi);
					cout << left << setw(20) << "Firma Telefon: "; getline(cin, FirmaTelefon);
					cout << left << setw(20) << "Firma Sorumlusu: "; getline(cin, FirmaSorumlusu);
					cout << "GENEL MUSTERI icin (1)e,OZEL MUSTERI icin (2)ye basiniz" << endl;
					cout << left << setw(20) << "Musteri Kategorisi: "; getline(cin, MusteriKategorisi);
					cout << left << setw(20) << "Adres: "; getline(cin, Adres);

					Yaz << FirmaNo << "\n" << FirmaAdi << "\n" << FirmaTelefon
						<< "\n" << FirmaSorumlusu << "\n" << MusteriKategorisi << "\n" << Adres << "\n" << bossatir << endl;;
				}
				else
				{
					Yaz << FirmaNo << "\n" << FirmaAdi << "\n" << FirmaTelefon
						<< "\n" << FirmaSorumlusu << "\n" << MusteriKategorisi << "\n" << Adres << "\n" << bossatir << endl;
				}

			}
			if (kontrol == 0)
			{
				cout << "Aradiginiz Musteri mevcut degil." << endl;
			}
			Oku.close();
			Yaz.close();
			remove("cari.txt");
			rename("cari.tmp", "cari.txt");
			cout << "Degistirmek istediginiz baska Musteri var mi?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');
	}

	void musteriSil()
	{
		do {
			ifstream Oku("cari.txt");
			ofstream Yaz("cari.tmp");
			cout << "Silmek istediginiz musterinin firma kodunu giriniz" << endl;
			getline(cin,aranan);

			while (!Oku.eof())
			{

				getline(Oku, FirmaNo);
				getline(Oku, FirmaAdi);
				getline(Oku, FirmaTelefon);
				getline(Oku, FirmaSorumlusu);
				getline(Oku, MusteriKategorisi);
				getline(Oku, Adres);
				getline(Oku, bossatir);
				if (Oku.eof())
				{
					break;
				}

				if (aranan == FirmaNo)
				{
					cout << "SILINEN MUSTERININ BILGILERI" << endl;
					cout << FirmaNo << endl;
					cout << FirmaAdi << endl;
					cout << FirmaTelefon << endl;
					cout << FirmaSorumlusu << endl;
					cout << MusteriKategorisi << endl;
					cout << Adres << endl;
				}
				else
				{
					Yaz << FirmaNo << "\n" << FirmaAdi << "\n" << FirmaTelefon
						<< "\n" << FirmaSorumlusu << "\n" << MusteriKategorisi << "\n" << Adres << "\n" << bossatir << endl;
				}

			}
			Oku.close();
			Yaz.close();
			remove("cari.txt");
			rename("cari.tmp", "cari.txt");
			cout << "Baska silmek istediginiz musteri var mi?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');
	}

	void siparisOlustur()
	{
		do {
			kontrol = 0;
			do {
				//Firma kontrol
				cout << left << setw(18) << "Firma No: "; getline(cin, FirmaNo);
				ifstream Okum("cari.txt");
				while (!Okum.eof())
				{

					getline(Okum, Error);
					getline(Okum, FirmaAdi);
					getline(Okum, FirmaTelefon);
					getline(Okum, FirmaSorumlusu);
					getline(Okum, MusteriKategorisi);
					getline(Okum, Adres);
					getline(Okum, bossatir);

					if (Error == FirmaNo)
					{
						kontrol = 1;
						musterikategorisi = stoi(MusteriKategorisi);
						break;
					}


				}Okum.close();
				if (kontrol == 0) {
					cout << "Boyle bir Firma bulunamadi!" << endl;
				}
			} while (kontrol == 0);

			cout << left << setw(18) << "Siparis Tarihi: "; getline(cin, siparisTarihi);
			kontrol = 0;
			do { //urun kontrol ve deger cekme
				cout << left << setw(18) << "Urun Kodu: "; getline(cin, UrunKoduSiparis);

				ifstream Oku("urun.txt");
				while (!Oku.eof())
				{

					getline(Oku, UrunKodu);
					getline(Oku, UrunAdi);
					getline(Oku, Ureticisi);
					getline(Oku, UretimTarihi);
					getline(Oku, TeminSuresi);
					getline(Oku, Fiyat);
					getline(Oku, FiyatOzel);
					getline(Oku, KdvOrani);
					getline(Oku, StokAdedi);
					getline(Oku, bossatir);

					if (UrunKoduSiparis == UrunKodu)
					{
						kontrol = 1;
					
						if (musterikategorisi == 2)
						{
							ffiyat = stof(FiyatOzel);
						}
						else
						{
							ffiyat = stof(Fiyat);
						}
						
						siparisAlan = FirmaSorumlusu;
						break;
					}

				}
				if (kontrol == 0)
				{
					cout << "Aradiginz urun mevcut degil!" << endl;
				}
				Oku.close();
			} while (kontrol == 0);
			cout << left << setw(18) << "Urun Adedi: "; getline(cin, UrunAdedi);
			fUrunAdedi = stoi(UrunAdedi);
			cout << left << setw(18) << "Siparisi Tutari: " << ffiyat * fUrunAdedi << endl;
			cout << left << setw(18) << "Siparis Alan: " << siparisAlan << endl;

			ofstream Yaz("siparis.txt", ios::app);
			Yaz << FirmaNo << "\n" << siparisTarihi << "\n" << UrunKodu << "\n" << UrunAdedi
				<< "\n" << ffiyat * fUrunAdedi << "\n" << siparisAlan << "\n" << delimiter << endl;
			Yaz.close();
			cout << "Baska siparis vermek istiyor musunuz?(e/h)\n";
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			ifstream OkuU("urun.txt");
			ofstream YazU("urun.tmp");

			while (!OkuU.eof())
			{
				getline(OkuU, Bul);
				getline(OkuU, UrunAdi);
				getline(OkuU, Ureticisi);
				getline(OkuU, UretimTarihi);
				getline(OkuU, TeminSuresi);
				getline(OkuU, Fiyat);
				getline(OkuU, FiyatOzel);
				getline(OkuU, KdvOrani);
				getline(OkuU, StokAdedi);
				getline(OkuU, bossatir);
				if (OkuU.eof())
				{
					break;
				}

				if (Bul == UrunKodu)
				{
					Adet = stoi(StokAdedi);

					YazU << UrunKodu << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << Adet - fUrunAdedi << "\n" << bossatir << "\n";
				}
				else
				{
					YazU << Bul << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << StokAdedi << "\n" << bossatir << "\n";
				}



			}
			OkuU.close();
			YazU.close();
			remove("urun.txt");
			rename("urun.tmp", "urun.txt");
		} while (devam == 'e');
	}
	void siparisArama()
	{
		do {
			ifstream Oku("siparis.txt");
			cout << "Aramak istediginiz siparislerin Firma kodunu giriniz" << endl;
			getline(cin,aranan);

			while (!Oku.eof())
			{
				getline(Oku, FirmaNo);
				getline(Oku, siparisTarihi);
				getline(Oku, UrunKodu);
				getline(Oku, UrunAdedi);
				getline(Oku, siparisTutari);
				getline(Oku, siparisAlan);
				getline(Oku, bossatir);

				if (Oku.eof())
				{
					break;
				}

				if (aranan == FirmaNo)
				{

					cout << left << setw(18) << "Firma No: " << FirmaNo << endl;
					cout << left << setw(18) << "Siparis Tarihi: " << siparisTarihi << endl;
					cout << left << setw(18) << "Urun Kodu: " << UrunKodu << endl;
					cout << left << setw(18) << "Urun Adedi: " << UrunAdedi << endl;
					cout << left << setw(18) << "Siparis Tutari: " << siparisTutari << endl;
					cout << left << setw(18) << "Siparis Alan: " << siparisAlan << endl;
					cout << delimiter << endl;
				}
			}
			Oku.close();
			cout << "Baska aramak istediginiz siparis var mi?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		} while (devam == 'e');
	}
	void siparisdegistir()
	{

		do {
			ifstream Okudeneme("siparis.txt");
			
			cout << "Degistirmek istediginiz siparisin Firma kodunu giriniz" << endl;
			getline(cin, aranan);
			while (!Okudeneme.eof())
			{
				getline(Okudeneme, FirmaNo);
				getline(Okudeneme, siparisTarihi);
				getline(Okudeneme, UrunKodu);
				getline(Okudeneme, UrunAdedi);
				getline(Okudeneme, siparisTutari);
				getline(Okudeneme, siparisAlan);
				getline(Okudeneme, bossatir);

				if (Okudeneme.eof())
				{
					break;
				}

				if (aranan == FirmaNo)
				{

					cout << left << setw(18) << "Firma No: " << FirmaNo << endl;
					cout << left << setw(18) << "Siparis Tarihi: " << siparisTarihi << endl;
					cout << left << setw(18) << "Urun Kodu: " << UrunKodu << endl;
					cout << left << setw(18) << "Urun Adedi: " << UrunAdedi << endl;
					cout << left << setw(18) << "Siparis Tutari: " << siparisTutari << endl;
					cout << left << setw(18) << "Siparis Alan: " << siparisAlan << endl;
					cout << delimiter << endl;
				}
			}Okudeneme.close();
			cout << "Degistirmek istediginiz siparisin tarihini giriniz" << endl;
			getline(cin, tarih);
			cout << "Degistirmek istediginiz siparisin Urun Kodunu giriniz" << endl;
			getline(cin, kodsor);

			ofstream Yaz("siparis.tmp");
			ifstream Oku("siparis.txt");
			while (!Oku.eof())
			{
				getline(Oku, FirmaNo);
				getline(Oku, siparisTarihi);
				getline(Oku, UrunKodu1);
				getline(Oku, UrunAdedi);
				getline(Oku, siparisTutari);
				getline(Oku, siparisAlan);
				getline(Oku, bossatir);
				if (Oku.eof())
				{
					break;
				}

				if (aranan == FirmaNo && tarih == siparisTarihi && kodsor == UrunKodu1)
				{
					cout << "ESKI SIPARIS BILGILERI" << endl;
					cout << left << setw(18) << "Firma No: " << FirmaNo << endl;
					cout << left << setw(18) << "Siparis Tarihi: " << siparisTarihi << endl;
					cout << left << setw(18) << "Urun Kodu: " << UrunKodu1 << endl;
					cout << left << setw(18) << "Urun Adedi: " << UrunAdedi << endl;
					fgUrunAdet = stoi(UrunAdedi);
					cout << left << setw(18) << "Siparis Tutari: " << siparisTutari << endl;
					cout << left << setw(18) << "Siparis Alan: " << siparisAlan << endl;

					cout << "BILGILERI GUNCELLEYINIZ" << endl;

					kontrol = 0;
					do {//\firmanin gecerli bir firma oldugunu dogrulama
						cout << left << setw(18) << "Firma No: "; getline(cin, FirmaNo);
						ifstream Okum("cari.txt");
						while (!Okum.eof())
						{

							getline(Okum, Error);
							getline(Okum, FirmaAdi);
							getline(Okum, FirmaTelefon);
							getline(Okum, FirmaSorumlusu);
							getline(Okum, MusteriKategorisi);
							getline(Okum, Adres);
							getline(Okum, bossatir);

							if (Error == FirmaNo)
							{
								kontrol = 1;
								musterikategorisi = stoi(MusteriKategorisi);
								break;
							}


						}Okum.close();
						if (kontrol == 0) {
							cout << "Boyle bir Firma bulunamadi!" << endl;
						}
					} while (kontrol == 0);
					cout << left << setw(18) << "Siparis Tarihi: "; getline(cin, siparisTarihi);

					kontrol = 0;
					do {//Urun Kodunun gecerli olmasi
						cout << left << setw(18) << "Urun Kodu: "; getline(cin, UrunKoduSiparis);

						ifstream Oku("urun.txt");
						while (!Oku.eof())
						{

							getline(Oku, Error);
							getline(Oku, UrunAdi);
							getline(Oku, Ureticisi);
							getline(Oku, UretimTarihi);
							getline(Oku, TeminSuresi);
							getline(Oku, Fiyat);
							getline(Oku, FiyatOzel);
							getline(Oku, KdvOrani);
							getline(Oku, StokAdedi);
							getline(Oku, bossatir);




							if (UrunKoduSiparis == Error)
							{
								kontrol = 1;
								if (musterikategorisi == 1)
								{
									ffiyat = stof(Fiyat);
								}
								else {
									ffiyat = stof(FiyatOzel);
								}
								siparisAlan = FirmaSorumlusu;
								break;
							}

						}
						if (kontrol == 0)
						{
							cout << "Aradiginz urun mevcut degil!" << endl;
						}
						Oku.close();
					} while (kontrol == 0);



					cout << left << setw(18) << "Urun Adedi: "; getline(cin, UrunAdedi_1);
					faUrunAdet = stoi(UrunAdedi_1);

					cout << left << setw(18) << "Siparis Tutari: " << ffiyat * faUrunAdet << endl;
					cout << left << setw(18) << "Siparis Alan: " << siparisAlan << endl;

					Yaz << FirmaNo << "\n" << siparisTarihi << "\n" << UrunKoduSiparis << "\n" << UrunAdedi_1
						<< "\n" << ffiyat * faUrunAdet << "\n" << siparisAlan << "\n" << delimiter << endl;
				}
				else
				{
					Yaz << FirmaNo << "\n" << siparisTarihi << "\n" << UrunKodu1 << "\n" << UrunAdedi
						<< "\n" << siparisTutari << "\n" << siparisAlan << "\n" << delimiter << endl;
				}

			}
			Oku.close();
			Yaz.close();
			remove("siparis.txt");
			rename("siparis.tmp", "siparis.txt");

			// stokun eski haline getirilmesi
			ifstream Oku2("urun.txt");
			ofstream Yaz2("urun.tmp");

			while (!Oku2.eof())
			{
				getline(Oku2, Bul);
				getline(Oku2, UrunAdi);
				getline(Oku2, Ureticisi);
				getline(Oku2, UretimTarihi);
				getline(Oku2, TeminSuresi);
				getline(Oku2, Fiyat);
				getline(Oku2, FiyatOzel);
				getline(Oku2, KdvOrani);
				getline(Oku2, StokAdedi);
				getline(Oku2, bossatir);
				if (Oku2.eof())
				{
					break;
				}

				if (Bul == UrunKodu1 && UrunKodu1 == UrunKoduSiparis)
				{
					AdetVer = stoi(StokAdedi);

					Yaz2 << UrunKodu1 << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << AdetVer + fgUrunAdet - faUrunAdet << "\n" << bossatir << "\n";
				}
				else if (Bul == UrunKodu1)
				{
					AdetVer = stoi(StokAdedi);

					Yaz2 << UrunKodu1 << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << AdetVer + fgUrunAdet << "\n" << bossatir << "\n";
				}
				else if (Bul == UrunKoduSiparis)
				{
					AdetAl = stoi(StokAdedi);

					Yaz2 << UrunKoduSiparis << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << (AdetAl - faUrunAdet) << "\n" << bossatir << "\n";
				}
				else
				{
					Yaz2 << Bul << "\n" << UrunAdi << "\n" << Ureticisi
						<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
						<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << StokAdedi << "\n" << bossatir << "\n";
				}



			}
			Oku2.close();
			Yaz2.close();
			remove("urun.txt");
			rename("urun.tmp", "urun.txt");

			cout << "Degistirmek istediginiz baska siparis var mi?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		} while (devam == 'e');
	}
	void siparisSil()
	{
		do {
			kontrol = 0;
			

			ifstream Okudeneme("siparis.txt");

			cout << "Silmek istediginiz siparisin Firma kodunu giriniz" << endl;
			getline(cin,aranan);
			while (!Okudeneme.eof())
			{
				getline(Okudeneme, FirmaNo);
				getline(Okudeneme, siparisTarihi);
				getline(Okudeneme, UrunKodu);
				getline(Okudeneme, UrunAdedi);
				getline(Okudeneme, siparisTutari);
				getline(Okudeneme, siparisAlan);
				getline(Okudeneme, bossatir);

				if (Okudeneme.eof())
				{
					break;
				}

				if (aranan == FirmaNo)
				{

					cout << left << setw(18) << "Firma No: " << FirmaNo << endl;
					cout << left << setw(18) << "Siparis Tarihi: " << siparisTarihi << endl;
					cout << left << setw(18) << "Urun Kodu: " << UrunKodu << endl;
					cout << left << setw(18) << "Urun Adedi: " << UrunAdedi << endl;
					cout << left << setw(18) << "Siparis Tutari: " << siparisTutari << endl;
					cout << left << setw(18) << "Siparis Alan: " << siparisAlan << endl;
					cout << delimiter << endl;
				}
			}Okudeneme.close();
			cout << "Silmek istediginiz siparisin tarihini giriniz" << endl;
			getline(cin,tarih);
			cout << "Silmek istediginiz siparisin Urun Kodunu giriniz" << endl;
			getline(cin,kodsor);

			ifstream Oku("siparis.txt");
			ofstream Yaz("siparis.tmp");
			while (!Oku.eof())
			{
				getline(Oku, FirmaNo);
				getline(Oku, siparisTarihi);
				getline(Oku, UrunKodu);
				getline(Oku, UrunAdedi);
				getline(Oku, siparisTutari);
				getline(Oku, siparisAlan);
				getline(Oku, bossatir);
				if (Oku.eof())
				{
					break;
				}

				if (aranan == FirmaNo && tarih==siparisTarihi && kodsor==UrunKodu)
				{
					kontrol = 1;
					cout << left << setw(18) << "Firma No: " << FirmaNo << endl;
					cout << left << setw(18) << "Siparis Tarihi: " << siparisTarihi << endl;
					cout << left << setw(18) << "Urun Kodu: " << UrunKodu << endl;
					cout << left << setw(18) << "Urun Adedi: " << UrunAdedi << endl;
					fUrunAdedi = stoi(UrunAdedi);
					cout << left << setw(18) << "Siparis Tutari: " << siparisTutari << endl;
					cout << left << setw(18) << "Siparis Alan: " << siparisAlan << endl;
					cout << delimiter << endl;
					ifstream OkuU("urun.txt");
					ofstream YazU("urun.tmp");

					while (!OkuU.eof())
					{
						getline(OkuU, Bul);
						getline(OkuU, UrunAdi);
						getline(OkuU, Ureticisi);
						getline(OkuU, UretimTarihi);
						getline(OkuU, TeminSuresi);
						getline(OkuU, Fiyat);
						getline(OkuU, FiyatOzel);
						getline(OkuU, KdvOrani);
						getline(OkuU, StokAdedi);
						getline(OkuU, bossatir);
						if (OkuU.eof())
						{
							break;
						}

						if (Bul == UrunKodu)
						{
							Adet = stoi(StokAdedi);

							YazU << UrunKodu << "\n" << UrunAdi << "\n" << Ureticisi
								<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
								<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << Adet + fUrunAdedi << "\n" << bossatir << "\n";
						}
						else
						{
							YazU << Bul << "\n" << UrunAdi << "\n" << Ureticisi
								<< "\n" << UretimTarihi << "\n" << TeminSuresi << "\n" << Fiyat
								<< "\n" << FiyatOzel << "\n" << KdvOrani << "\n" << StokAdedi << "\n" << bossatir << "\n";
						}



					}
					OkuU.close();
					YazU.close();
					remove("urun.txt");
					rename("urun.tmp", "urun.txt");
				}
				else
				{
					Yaz << FirmaNo << "\n" << siparisTarihi << "\n" << UrunKodu << "\n" << UrunAdedi
						<< "\n" << siparisTutari << "\n" << siparisAlan << "\n" << delimiter << endl;
				}

			}
			if (kontrol == 0)
			{
				cout << "Aradiginiz siparis bulunamadi!" << endl;
			}
			else if (kontrol == 1)
			{
				cout << "Silme islemi basariyla gerceklestirildi" << endl;
			}

			Oku.close();
			Yaz.close();
			remove("siparis.txt");
			rename("siparis.tmp", "siparis.txt");

			cout << "Baska Siparis silmek istiyor musunuz?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		} while (devam == 'e');
	}
	void siparisraporla()
	{
		do {
			cout << left << setw(20) << "Siparis Tarihi" << left << setw(20) << "Firma No" << left << setw(20) << "Siparisi Alan " <<
				left << setw(13) << "Urun Kodu" << left << setw(13) << "Urun Adedi" << left << setw(14) << "Topl. Fiyat " << endl;
			ifstream Oku("siparis.txt");
			ofstream Yaz("rapor.txt", ios::out);
			Yaz << left << setw(20) << "Siparis Tarihi" << left << setw(20) << "Firma No" << left << setw(20) << "Siparisi Alan " <<
				left << setw(13) << "Urun Kodu" << left << setw(13) << "Urun Adedi" << left << setw(14) << "Topl. Fiyat " << endl;

			while (!Oku.eof())
			{
				getline(Oku, FirmaNo);
				getline(Oku, siparisTarihi);
				getline(Oku, UrunKodu);
				getline(Oku, UrunAdedi);
				getline(Oku, siparisTutari);
				getline(Oku, siparisAlan);
				getline(Oku, bossatir);
				if (Oku.eof())
				{
					break;
				}


				cout << left << setw(20) << siparisTarihi << left << setw(20) << FirmaNo << left << setw(20) << siparisAlan <<
					left << setw(13) << UrunKodu << left << setw(13) << UrunAdedi << left << setw(14) << siparisTutari << endl;

				Yaz << left << setw(20) << siparisTarihi << left << setw(20) << FirmaNo << left << setw(20) << siparisAlan <<
					left << setw(13) << UrunKodu << left << setw(13) << UrunAdedi << left << setw(14) << siparisTutari << endl;


			}
			Oku.close();
			Yaz.close();
			cout << endl;
			cout << "Islemi tekrarlamak istiyor musunuz?(e/h)" << endl;
			cin >> devam;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (devam == 'e');

	}


};



int main()
{
	int secim;
	int icsecim;
	dosyalama islem;

		do {
			cout << "Lutfen sayi girerek islem seciniz: \n";
			cout << "1- Urun Islemleri" << endl;
			cout << "2- Musteri Dosyasi Islemleri" << endl;
			cout << "3- Siparis Islemleri" << endl;
			cout << "0- Programi Sonlandir" << endl;
			cin >> secim;

			switch (secim)
			{

			case 1:
			{

				do {

					cout << "Lutfen sayi girerek islem seciniz" << endl;
					cout << "1- Urun Ekleme" << endl;
					cout << "2- Urun Arama" << endl;
					cout << "3- Urun Listeleme" << endl;
					cout << "4- Urun Duzeltme" << endl;
					cout << "5- Urun Silme" << endl;
					cout << "0- Menu" << endl;
					cin >> icsecim;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (icsecim == 1)
					{
						islem.urunekle();
					}
					else if (icsecim == 2)
					{
						islem.urunArama();

					}

					else if (icsecim == 3)
					{
						islem.urunlisteleme();
					}

					else if (icsecim == 4)
					{
						islem.urundegistirme();
					}

					else if (icsecim == 5)
					{
						islem.urunSilme();
					}
				} while (icsecim != 0);
				break;
			}
			case 2:
			{

				do {
					cout << "Lutfen sayi girerek islem seciniz" << endl;
					cout << "1- Musteri Ekleme" << endl;
					cout << "2- Musteri Arama" << endl;
					cout << "3- Musteri Duzeltme" << endl;
					cout << "4- Musteri Silme" << endl;
					cout << "0- Menu" << endl;

					cin >> icsecim;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (icsecim == 1)
					{
						islem.musteriEkle();
					}
					else if (icsecim == 2)
					{
						islem.musteriArama();
					}

					else if (icsecim == 3)
					{
						islem.musteriDuzenle();
					}

					else if (icsecim == 4)
					{
						islem.musteriSil();
					}

				} while (icsecim != 0);
				break;


			}
			case 3:
			{

				do {
					cout << "Lutfen sayi girerek islem seciniz" << endl;
					cout << "1- Siparis Olustur" << endl;
					cout << "2- Siparis Arama" << endl;
					cout << "3- Siparis Duzeltme" << endl;
					cout << "4- Siparis Silme" << endl;
					cout << "5- Siparis Raporlama" << endl;
					cout << "0- Menu" << endl;

					cin >> icsecim;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					if (icsecim == 1)
					{
						islem.siparisOlustur();
					}
					else if (icsecim == 2)
					{
						islem.siparisArama();

					}

					else if (icsecim == 3)
					{
						islem.siparisdegistir();
					}

					else if (icsecim == 4)
					{
						islem.siparisSil();
					}
					else if (icsecim == 5)
					{
						islem.siparisraporla();
					}
				} while (icsecim != 0);
				break;
			}

			}

		}while (secim != 0);
	}


