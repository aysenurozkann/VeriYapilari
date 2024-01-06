/** 
* @file			: AvlTree.hpp
* @description	: Program Avl agaclarina veri ekler, en kucuk ve en buyuk 
				  sayilari kurallara uygun olarak cikarir.
* @course		: A grubu, 1.ogretim
* @assignment	: Odev2
* @date			: 05.12.2023
* @author		: Aysenur Ozkan, aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include <cmath>
using namespace std;

class Dugum {
    public:
        int sayi;
        int yukseklik;
        Dugum* sol;
        Dugum* sag;
        Dugum(int sayi);
};

class AvlTree {
    private:
        
    
    public:
        Dugum* kok;
        AvlTree();
        Dugum* sayiEkle(Dugum* kok, int sayi);
        int getYukseklik(Dugum* dugum);
        int getDenge(Dugum* dugum);
        Dugum* sagaDondur(Dugum* dugum);
        Dugum* solaDondur(Dugum* dugum);
        Dugum* agaciDengele(Dugum* dugum);
        void agaciGoster(Dugum* kok, int seviye);
        void agaciTemizle(Dugum* dugum);
};

#endif