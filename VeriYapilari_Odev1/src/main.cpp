/** 
* @file			: main.cpp
* @description	: Bu program bir dosyadan okudugu tam sayilari bagli listelerde tutar
* @course		: A grubu, 1.ogretim
* @assignment	: Odev1
* @date			: 08.11.2023
* @author		: Aysenur Ozkan aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>


#include "Sayi.hpp"
#include "Basamak.hpp"
#include "Dugum.hpp"
#include "SayilarListesi.hpp"

using namespace std;

void openFile(ifstream& sayilarDosyasi, SayilarListesi* sayilarListesi) {
    string satir;
    while (getline(sayilarDosyasi, satir)) {
        istringstream ss(satir);
        int sayi;
        while (ss >> sayi) {
            Sayi* yeniSayi = new Sayi();
            while (sayi > 0) {
                int basamak = sayi % 10;
                yeniSayi->ekleBasamak(basamak);
                sayi /= 10;
            }
            sayilarListesi->sayiEkle(yeniSayi);
        }
    }
    sayilarDosyasi.close();
}

int main() {
    ifstream sayilarDosyasi("sayilar.txt");
    if (!sayilarDosyasi) {
        cerr << "Dosya acilamadi." << endl;
        return 1;
    }

    SayilarListesi* sayilarListesi = new SayilarListesi();
    openFile(sayilarDosyasi, sayilarListesi);

    sayilarListesi->ekranaYaz();
    int secim;

    do {
        std::cout << "1. Tek basamaklari Basa Al\n";
        std::cout << "2. Basamaklari Tersle\n";
        std::cout << "3. En Buyuk Cikar\n";
        std::cout << "4. Cikis\n";
        std::cin >> secim;

        switch (secim) {
            case 1:
                sayilarListesi->tekleriBasaAl();
                sayilarListesi->ekranaYaz();
                break;
            case 2:
                sayilarListesi->basamaklariTersle();
                sayilarListesi->ekranaYaz();
                break;
            case 3:
                sayilarListesi->enBuyuguCikar();
                sayilarListesi->ekranaYaz();
                break;
            case 4:
                break;
            default:
                std::cout << "Geçersiz secim. Tekrar deneyin.\n";
        }

    } while (secim != 4);    
    
    return 0;
}
