/** 
* @file			: Yigit.hpp
* @description	: Program Avl agaclarina veri ekler, en kucuk ve en buyuk 
				  sayilari kurallara uygun olarak cikarir.
* @course		: A grubu, 1.ogretim
* @assignment	: Odev2
* @date			: 05.12.2023
* @author		: Aysenur Ozkan, aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#ifndef YIGIT_HPP
#define YIGIT_HPP

#include <iostream>
using namespace std;

class YigitDugumu {
    private:

    public:
        int sayi;
        YigitDugumu* sonraki;
        YigitDugumu(int sayi, YigitDugumu* sonraki = nullptr);
};

class Yigit {
    private:
        YigitDugumu* yigitBasi;

    public:
        Yigit();
        ~Yigit();
        bool yigitBosMu();
        void ekle(const int sayi);
        void cikar();
        int getYigitBasi();
        void yigitiBosalt();
        void yigitiGoruntule();
};

#endif