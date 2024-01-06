/** 
* @file			: Basamak.cpp
* @description	: Bu program bir dosyadan okudugu tam sayilari bagli listelerde tutar
* @course		: A grubu, 1.ogretim
* @assignment	: Odev1
* @date			: 08.11.2023
* @author		: Aysenur Ozkan, aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#include "Basamak.hpp"

Basamak::Basamak(int basamakDegeri) : basamakDegeri(basamakDegeri), sonraki(nullptr) {}

Basamak::~Basamak() {
    delete sonraki;
}