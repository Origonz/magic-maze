#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "case.hpp"
#include "RandomUniform.hpp"
#include "mur.hpp"
#include "site.hpp"
#include "couleurs.hpp"
#include <vector>
#include <iostream>

using namespace std;

namespace MMaze {

  class Tuile {

  public :

    Tuile(bool d = false);

    //indique si deux cases voisines sont separees par un mur
    bool mur(Mur m) const ;

    //indique si une case est accessible depuis les portes ou non
    bool accessible(Case c) const ;

    //affichage
    friend std::ostream& operator<<(std::ostream& out, const Tuile& t) ;

    //Fonctions utiles
    int find(int c);
    void unionFind(int c1, int c2);
    bool valide();
    void casserMur();
    void tuile_de_depart();
    void tuile_classique();
    bool isin(vector<Case> v, unsigned int index) const;

  private :

    //affichage
    void afficher_horizontal(std::ostream& out, unsigned int i) const ;
    void afficher_vertical(std::ostream& out, unsigned int i) const ;
    void placement_sortie();
    void placement_objectif();
    void placement_porte();
    void placement_depart();
    void placement_site();

    int tab[16];
    Site* sites[16];
    Couleur couleurs[16];
    Couleur joueur[16];
    bool walls[24];
  } ;

} //end of namespace MMaze

#endif
