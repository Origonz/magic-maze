#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "case.hpp"
#include "couleurs.hpp"
#include "mur.hpp"
#include<iostream>
#include <vector>
#include<fstream>

using namespace std;

namespace MMaze {

  class Tuile {

  public :

    Tuile(int i = 0,bool d = false);

    Tuile(string path);

    void setId(int i);

    int getId(){return id;}

    //indique si deux cases voisines sont separees par un mur
    bool mur(Mur m) const ;

    //indique si une case est accessible depuis les portes ou non
    bool accessible(Case c) const ;

    //affichage
    friend std::ostream& operator<<(std::ostream& out, const Tuile& t) ;

    //Fonctions utiles
    void signal(int a); //
    void importe(string path); //importe a partir d'un chemin
    void place_pion(Couleur c,int p); //palce le pion de couleur c à la place p

  private :

    //affichage
    void afficher_horizontal(std::ostream& out, unsigned int i) const ;
    void afficher_vertical(std::ostream& out, unsigned int i) const ;
    void placement_sortie();
    void placement_objectif();
    void placement_porte();
    void placement_depart();
    void placement_site();
    int getInt_string(string s); //dans l'import, converti le chiffre
    int get_place(int p) const; //donne la place du pion p
    int find(int c);
    void unionFind(int c1, int c2);
    void depart_valide();
    void classique_valide();
    void casserMur();
    void tuile_de_depart();
    void tuile_classique();
    bool isin(vector<Case> v, unsigned int index) const;
    bool estDans(vector<int> v, int i);

    int tab[16];
    char sites[16];
    Couleur couleurs[16];
    bool walls[24];
    int id;
    int pions[4]; //On va considéré que l'ordre est JAUNE, VERT, ORANGE, VIOLET (int étant la plca dans la tuile
  } ;

} //end of namespace MMaze

#endif
