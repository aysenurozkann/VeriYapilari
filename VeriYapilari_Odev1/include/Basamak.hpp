#ifndef BASAMAK_HPP
#define BASAMAK_HPP

// Sayi class'i friend olarak gosterileceginden taniminin yapilmasi gerekiyor
class Sayi;
#include <iostream>

class Basamak {
    private:
        int basamakDegeri;
        Basamak* sonraki;

    public:
        Basamak(int basamakDegeri);
        ~Basamak();
        // Sayi class'ini friend olarak gosteriyoruz, bu sayede Sayi class'indan buradaki degerlere erisebilecegiz
        friend class Sayi;
};

#endif