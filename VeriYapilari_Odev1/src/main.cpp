/** 
* @file			: main.cpp
* @description	: Program Avl agaclarina veri ekler, en kucuk ve en buyuk 
				  sayilari kurallara uygun olarak cikarir.
* @course		: A grubu, 1.ogretim
* @assignment	: Odev2
* @date			: 05.12.2023
* @author		: Aysenur Ozkan, aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdint>

#include "AvlTree.hpp"
#include "AvlTreeList.hpp"
#include "Yigit.hpp"

using namespace std;

void openFile(ifstream& sayilarDosyasi, AvlTreeList* avlTreeList) {
    string satir;
    int agacNumarasi = 1;
    while (getline(sayilarDosyasi, satir)) {
        istringstream ss(satir);
        AvlTree* avlTree = new AvlTree();
        int sayi;
        while (ss >> sayi) {
            avlTree->kok = avlTree->sayiEkle(avlTree->kok, sayi);
        }
        avlTreeList->ekle(avlTree, agacNumarasi);
        agacNumarasi++;
    }
    sayilarDosyasi.close();
}

int main() {
    // txt dosyasindan okunan her bir satirdaki sayilar avlTree'ye eklenir,
    // her bir satir avlTree olusturur ve avlTree'lerin her biri avlTreeList'e eklenir
    AvlTreeList* avlTreeList = new AvlTreeList;

    const string dosyaYolu = "Veri.txt";
    ifstream file(dosyaYolu);
    
    if (!file.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaYolu << endl;
        return 1;
    }

    // dosyadan okunan tum sayilar avlTree'lere eklenerek avlTreeList'te tutulur
    openFile(file, avlTreeList);

    do
    {
        if(avlTreeList->bas == nullptr) {
            break;
        }
        avlTreeList->postOrder();
        avlTreeList->yigitlariGoruntule();
        int dugumCikarildiMi;
        int agacNumarasi;
        int sonKarakter;
        do
        {
            agacNumarasi = avlTreeList->bas->agacNumarasi;
            sonKarakter = avlTreeList->bas->avlToplamDugumDegeri;
            dugumCikarildiMi = avlTreeList->yigitdanMinMaxCikar();
            if(avlTreeList->bas == nullptr && dugumCikarildiMi == 1) {
                int agacNumarasiKarakterUzunlugu = to_string(agacNumarasi).length();
                cout << "==============================" << endl;
                cout << "|                            |" << endl;
                cout << "|                            |" << endl;
                cout << "|     Son Karakter: " << static_cast<char>(sonKarakter % (90-65+1)+65) << "        |" << endl;
                cout << "|     AVL No      : " << agacNumarasi;
                for(int i = 21; i < 30 - agacNumarasiKarakterUzunlugu; i++) { cout << " "; }
                cout << "|" << endl;
                cout << "|                            |" << endl;
                cout << "|                            |" << endl;
                cout << "==============================" << endl;
            }

        } while (!dugumCikarildiMi);

    } while (true);
    
    return 0;
}