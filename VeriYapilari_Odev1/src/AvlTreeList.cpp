/** 
* @file			: AvlTreeList.cpp
* @description	: Program Avl agaclarina veri ekler, en kucuk ve en buyuk 
				  sayilari kurallara uygun olarak cikarir.
* @course		: A grubu, 1.ogretim
* @assignment	: Odev2
* @date			: 05.12.2023
* @author		: Aysenur Ozkan, aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#include "AvlTreeList.hpp"
#include <iostream>

AvlTreeList::AvlDugum::AvlDugum(AvlTree* avlTree) : avlTree(avlTree), onceki(nullptr), sonraki(nullptr),
avlToplamDugumDegeri(0), agacNumarasi(0) {}

AvlTreeList::AvlTreeList() : bas(nullptr) {}

// avl agaclarini en sona ekler, while dongusu kullanmak yerine son isminde en sondaki
// avl agacinin adresini gosteren bir pointer kullanilir, bu sayede gereksiz yere
// while dongulerinde dolasip en sona eklemeye gerek kalmaz
void AvlTreeList::ekle(AvlTree* avlTree, int agacNumarasi) {
    AvlDugum* yeniDugum = new AvlDugum(avlTree);
    if (bas == nullptr) {
        // daha once hic agac eklenmemisse bas ve son pointerlari yeni dugumu gosterir
        bas = yeniDugum;
        son = yeniDugum;
    } else {
        // yeni gelen dugum son pointerinin sonraki adresine eklenir ve son pointeri bir sonraki adresini gosterir
        yeniDugum->onceki = son;
        son->sonraki = yeniDugum;
        son = son->sonraki;
    }
    yeniDugum->agacNumarasi = agacNumarasi;
}

// avl agaclarindaki datalar ekrana bastirilir
void AvlTreeList::agaclariGoruntule() {
    AvlDugum* current = bas;
    while (current != nullptr) {
        current->avlTree->agaciGoster(current->avlTree->kok, 0);
        current = current->sonraki;
    }
}

// postorder olarak avl agaci taranir ve yapraklar yigit'a eklenir,
// sagda ve solda dugum olan (yaprak olmayan) dugumlerin sayi degeri
// avlToplamDugumDegeri degiskeninde toplanir
void AvlTreeList::AvlDugum::postOrderYigitaEkle(Dugum* dugum) {
    if(dugum != nullptr) {
        postOrderYigitaEkle(dugum->sol);
        postOrderYigitaEkle(dugum->sag);
        if(dugum->sag == nullptr && dugum->sol == nullptr) {
            yigit.ekle(dugum->sayi);
        } else {
            avlToplamDugumDegeri += dugum->sayi;
        }
    }
}

// her bir avl agaci icin postOrderYigitaEkle fonksiyonu cagirilir ve
// postorder algoritmasiyla avl agaclari taranir
void AvlTreeList::postOrder() {
    if(bas == nullptr) {
        return;
    }

    AvlDugum* temp = bas;
    while(temp) {
        temp->yigit.yigitiBosalt();
        temp->avlToplamDugumDegeri = 0;
        temp->postOrderYigitaEkle(temp->avlTree->kok);
        temp = temp->sonraki;
    }
}

// avl agaclarinin yapraklariyla olusturulan yigitlar ekranda gosterilir
void AvlTreeList::yigitlariGoruntule() {
    AvlDugum* temp = bas;
    while(temp) {
        cout << static_cast<char>(temp->avlToplamDugumDegeri % (90-65+1)+65);
        // temp->yigit.yigitiGoruntule();
        temp = temp->sonraki;
    }
}

// gonderilen avl agaci, avl agaclarinin bulundugu avlTreeList'ten kaldirilir ve silinir
bool AvlTreeList::avlDugumKaldir(AvlDugum* silinecekDugum) {
    if(bas == nullptr) {
        return false;
    }
    // dugum listenin basindaysa listenin basi guncellenir
    if(silinecekDugum == bas) {
        bas = silinecekDugum->sonraki;
    }
    // dugum listenin sonundaysa listenin sonu guncellenir
    if(silinecekDugum == son) {
        son = silinecekDugum->onceki;
        // bu dugum listede bulunan tek dugumse bas da nullptr yapilir
        if(silinecekDugum->onceki == nullptr) {
            bas = nullptr;
        }
    }
    // dugum aradan cikarilir ve silinir
    if(silinecekDugum->onceki != nullptr) {
        silinecekDugum->onceki->sonraki = silinecekDugum->sonraki;
    } if(silinecekDugum->sonraki != nullptr) {
        silinecekDugum->sonraki->onceki = silinecekDugum->onceki;
    }
    delete silinecekDugum;
    return true;
}

// yigitlardan sirasiyla en kucuk ve en buyuk sayilar cikarilarak islemler uygulanir
bool AvlTreeList::yigitdanMinMaxCikar() {
    if(bas == nullptr) {
        return false;
    }

    AvlDugum* temp = bas;
    int enKucukSayi = bas->yigit.getYigitBasi();
    int enBuyukSayi = bas->yigit.getYigitBasi();
    // en kucuk sayi bulunduktan sonra tum yigitlari tekrar tarayip fazladan while
    // dongusune girmek yerine en kucuk sayinin bulundugu yigit bir pointera atanir
    // ve en kucuk sayinin arandigi while dongusu tamamlandiktan sonra bu yigit'a
    // cikar (pop) islemi uygulanir. en buyuk sayi icin de ayni mantik uygulanir
    AvlDugum* enKucukYigit = temp;
    AvlDugum* enBuyukYigit = temp;
    // en basta en kucuk olan sayi oldugu stackden cikartilir
    while(temp) {
        // daha kucuk degere sahip yigit bulundu
        if(temp->yigit.getYigitBasi() < enKucukSayi) {
            enKucukSayi = temp->yigit.getYigitBasi();
            enKucukYigit = temp;
        }
        // enBuyukSayi ve yigit guncellenir ancak enKucukSayi'nin bulundugu yigit'a pop
        // islemi uygulandiktan sonra en buyuk sayinin degisip degismedigine bakilir ve
        // duruma gore enBuyukSayi'nin bulundugu yigit'a pop islemi uygulanir.
        // bu sayede en buyuk sayiyi bulmak icin baska bir dongu kullanilmamis olur
        if(temp->yigit.getYigitBasi() > enBuyukSayi) {
            enBuyukSayi = temp->yigit.getYigitBasi();
            enBuyukYigit = temp;
        }
        temp = temp->sonraki;
    }

    // cout << "Bulunan en kucuk deger: " << enKucukSayi << endl;
    // en kucuk sayi yigitdan cikartilir
    enKucukYigit->yigit.cikar();

    // yigitdan en kucuk sayi cikartilinca yigit'in bos olma durumu kontrol edilir
    if(enKucukYigit->yigit.yigitBosMu()) {
        avlDugumKaldir(enKucukYigit);
        return true;
    }

    // en buyuk sayi bulunmasina ragmen pop isleminden sonra, yigitdaki deger en buyuk
    // oldugundan en buyuk yigit guncellenir
    if(enBuyukSayi < enKucukYigit->yigit.getYigitBasi()) {
        enBuyukYigit = enKucukYigit;
    }

    // cout << "Bulunan en buyuk deger: " << enBuyukYigit->yigit.getYigitBasi() << endl;
    // en buyuk sayi yigitdan cikartilir
    enBuyukYigit->yigit.cikar();

    // yigitdan en buyuk sayi cikartilinca yigit'in bos olma durumu kontrol edilir
    if(enBuyukYigit->yigit.yigitBosMu()) {
        avlDugumKaldir(enBuyukYigit);
        return true;
    }
    return false;
}