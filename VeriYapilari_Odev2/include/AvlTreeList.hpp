/** 
* @file			: AvlTreeList.hpp
* @description	: Program Avl agaclarina veri ekler, en kucuk ve en buyuk 
				  sayilari kurallara uygun olarak cikarir.
* @course		: A grubu, 1.ogretim
* @assignment	: Odev2
* @date			: 05.12.2023
* @author		: Aysenur Ozkan, aysenur.ozkan6@ogr.sakarya.edu.tr
*/

#ifndef AVLTREELIST_HPP
#define AVLTREELIST_HPP

#include "AvlTree.hpp"
#include "Yigit.hpp"


class AvlTreeList {
    private:
        class AvlDugum {
            public:
                AvlDugum(AvlTree* avlTree);
                AvlTree* avlTree;
                AvlDugum* onceki;
                AvlDugum* sonraki;
                Yigit yigit;
                int avlToplamDugumDegeri;
                int agacNumarasi;
                void postOrderYigitaEkle(Dugum* dugum);
        };
        

    public:
        AvlTreeList();
        AvlDugum* bas;
        AvlDugum* son;
        void ekle(AvlTree* avlTree, int agacNumarasi);
        void agaclariGoruntule();
        void postOrder();
        void yigitlariGoruntule();
        bool yigitdanMinMaxCikar();
        bool avlDugumKaldir(AvlDugum* silinecekDugum);
};

#endif