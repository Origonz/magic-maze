#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "case.hpp"
#include "mur.hpp"
#include "couleurs.hpp"

#include <vector>
#include <iostream>

namespace MMaze {

  class Tuile {

  public :

    Tuile() ;

    //indique si deux cases voisines sont separees par un mur
    bool mur(Mur m) const ;

    //indique si une case est accessible depuis les portes ou non
    bool accessible(Case c) const ;

    //affichage
    friend std::ostream& operator<<(std::ostream& out, const Tuile& t) ;

  private :

    //affichage
    void afficher_horizontal(std::ostream& out, unsigned int i) const ;
    void afficher_vertical(std::ostream& out, unsigned int i) const ;
    void placement_sortie();
    void placement_objectif();
    void placement_porte();
    void placement_depart();
    void placement_site();

    Case* tab[16];
    char sites[16];
    Couleur couleurs[16];
    bool walls[24];
  } ;

} //end of namespace MMaze

#endif
