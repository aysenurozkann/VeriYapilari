/** 
* @file			: Yigit.cpp
* @description	: Program Avl agaclarina veri ekler, en kucuk ve en buyuk 
				  sayilari kurallara uygun olarak cikarir.
* @course		: A grubu, 1.ogretim
* @assignment	: Odev2
* @date			: 05.12.2023
* @author		: Aysenur Ozkan, aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#include "Yigit.hpp"

YigitDugumu::YigitDugumu(int sayi, YigitDugumu* sonraki) {
    this->sayi = sayi;
    this->sonraki = sonraki;
}

Yigit::Yigit() {
    yigitBasi = nullptr;
}

Yigit::~Yigit() {
    yigitiBosalt();
	system("cls");
}

void Yigit::ekle(int sayi) {
    yigitBasi = new YigitDugumu(sayi, yigitBasi);
}

void Yigit::cikar() {
    if(yigitBosMu()) {
        cout <<  "Yigit bos\n";
        return;
    }
    YigitDugumu* silinecekDugum = yigitBasi;
    // Yığıtta sadece bir düğüm varsa
    if (yigitBasi->sonraki == nullptr) {
        delete silinecekDugum;
        yigitBasi = nullptr;  // Yığıt boşaldı, başı null olmalı
    } else {
        yigitBasi = yigitBasi->sonraki;
        delete silinecekDugum;
		
    }
}

int Yigit::getYigitBasi() {
    if(yigitBosMu()) {
        cout <<  "Yigit bos\n";
        return -1;
    } else {
        return yigitBasi->sayi;
    }
}

void Yigit::yigitiBosalt() {
    while(!yigitBosMu()) {
        cikar();
    }
}

bool Yigit::yigitBosMu() {
    if(yigitBasi == nullptr) {
        return true;
    } else {
        return false;
    }
}

void Yigit::yigitiGoruntule() {
    if(yigitBasi == nullptr) {
        cout <<  "Yigit bos\n";
        return;
    } else {
        YigitDugumu* geciciDugum = yigitBasi;
        
        cout << "Yigit: ";
        while(geciciDugum) {
            cout << geciciDugum->sayi << " ";
            geciciDugum = geciciDugum->sonraki;
        }
    }
}