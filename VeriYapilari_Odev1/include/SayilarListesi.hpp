#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include "Dugum.hpp"
#include <cstdint>
#include <sstream>


class SayilarListesi {
    private:
        Dugum* ilk;
        Dugum* son;

    public:
        SayilarListesi();
        ~SayilarListesi();
        void sayiEkle(Sayi* yeniSayi);
        void ekranaYaz();
        void tekleriBasaAl();
        void basamaklariTersle();
        void enBuyuguCikar();
};

#endif