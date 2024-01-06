#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp" // Basamak sınıfını dahil ettik.
#include <iostream>
#include <iomanip> 

class Sayi {
    private:
        Basamak* ilk;

    public:
        Sayi();
        ~Sayi();

        void ekleBasamak(int deger);
        int tamSayiDegeri();
        void adresleriYaz() const;
        void ekranaYaz() const;
        void tekBasamaklariBasaAl();
        void basamaklariTersle();
        
};

#endif
