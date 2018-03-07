#include "tuile.hpp"
#include "couleurs.hpp"

#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace MMaze {

  Tuile::Tuile(bool d) {
    srand(time(NULL));
    for (unsigned int i=0; i<4; i++) {
      for (unsigned int j=0; j<4; j++) {
        tab[4*i+j] = new Case(i, j);
        couleurs[4*i+j] = Couleur::AUCUNE;
      }
    }
    for(int i=0;i<24;i++){
        walls[i] = true;
    }
    if(d){
         placement_depart();
    }else {
        placement_site();
    }

  }
  
  bool Tuile::mur(Mur m) const {
      return walls[m.index()];
  }
  
  bool Tuile::accessible(Case c) const {
    /* remplacez ce code */
    return false ;
  }

  void Tuile::placement_sortie(){
      int portes[] = {2,4,11,13};
      int p = rand()%4;
      sites[portes[p]] = new Sortie();
      //TODO -> voir pour la gestion des couleurs
  }

  void Tuile::placement_depart(){
      sites[5] = new Depart();
      sites[6] = new Depart();
      sites[9] = new Depart();
      sites[10] = new Depart();
      couleurs[5] = Couleur::VERT;
      couleurs[6] = Couleur::JAUNE;
      couleurs[9] = Couleur::VIOLET;
      couleurs[10] = Couleur::ORANGE;
      couleurs[2] = Couleur::VERT;
      couleurs[4] = Couleur::JAUNE;
      couleurs[11] = Couleur::VIOLET;
      couleurs[13] = Couleur::ORANGE;
      placement_porte();
  }

  void Tuile::placement_objectif(){
     int o = rand()%16;
     sites[o] = new Objectif();
    //TODO -> voir pour la gestion des couleurs
  }

  void Tuile::placement_porte(){
      sites[2] = new Porte();
      sites[4] = new Porte();
      sites[11] = new Porte();
      sites[13] = new Porte();
  }

  void Tuile::placement_site(){
    placement_porte();
    if(rand()%2)
        placement_objectif();
    else if (rand()%2)
        placement_sortie();
  }
  
  void Tuile::afficher_horizontal(std::ostream& out, unsigned int i) const {
    assert(i < 5) ;
    if(i == 0 || i == 4) {
      out << "+---+---+---+---+" ;
    } else {
      out << "+" ;
      for(unsigned int m = 0; m < 4; ++m) {
	Case up = Case(i-1, m) ;
	Case down = Case(i, m) ;
	if(mur(Mur(up, down))) {
	  out << "---+" ;
	} else {
	  out << "   +" ;
	}
      }
    }
  }
  
  void Tuile::afficher_vertical(std::ostream& out, unsigned int i) const {
    assert(i < 4) ;
    out << "|" ;
    for(unsigned int m = 0; m < 4; ++m) {
      out << "   " ;
      if(m < 3) {
	Case left = Case(i, m) ;
	Case right = Case(i, m+1) ;
	if(m < 3 && mur(Mur(left, right))) {
	  out << "|" ;
	} else {
	  out << " " ;
	}
      }
    }
    out << "|" ;
  }
  
  std::ostream& operator<< (std::ostream& out, const Tuile& t) {
    for(unsigned int i = 0; i < 4; ++i) {
      t.afficher_horizontal(out, i) ;
      out << std::endl ;
      t.afficher_vertical(out, i) ;
      out << std::endl ;
    }
    t.afficher_horizontal(out, 4) ;
    return out ;
  }
  
} //end of namespace MMaze
