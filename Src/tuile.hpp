#ifndef MMAZE_TUILE_HPP
#define MMAZE_TUILE_HPP

#include "case.hpp"
#include "couleurs.hpp"
#include "mur.hpp"
#include <ostream>
#include <vector>

using namespace std;

namespace MMaze {

  class Tuile {

  public :

    Tuile(int i = 0,bool d = false);

    void setId(int i);

    int getId(){return id;}

    //indique si deux cases voisines sont separees par un mur
    bool mur(Mur m) const ;

    //indique si une case est accessible depuis les portes ou non
    bool accessible(Case c) const ;

    //affichage
    friend std::ostream& operator<<(std::ostream& out, const Tuile& t) ;

    //Fonctions utiles
    int find(int c);
    void unionFind(int c1, int c2);
    void depart_valide();
    void classique_valide();
    void casserMur();
    void tuile_de_depart();
    void tuile_classique();
    bool isin(vector<Case> v, unsigned int index) const;
    bool estDans(vector<int> v, int i);
    void signal(int a);

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
    char sites[16];
    Couleur couleurs[16];
    Couleur joueur[16];
    bool walls[24];
    int id;
  } ;

} //end of namespace MMaze

#endif
