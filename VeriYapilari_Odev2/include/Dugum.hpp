#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp" // Sayi sınıfını dahil ettik.

class SayilarListesi;

class Dugum {
    private:
        Sayi* sayi;      // Her düğümde bir Sayi nesnesi saklanacak
        Dugum* sonraki;  // Sonraki düğümün adresi

    public:
        // Düğüm sınıfının constructor'ı
        Dugum(Sayi* sayi);
        ~Dugum();
        friend class SayilarListesi;
};

#endif
