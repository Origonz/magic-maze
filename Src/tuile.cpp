#include "tuile.hpp"
#include "couleurs.hpp"

#include <cassert>
#include <iostream>
#include <cstdlib>

using namespace std;
const int V = 1;
const int O = 2;
const int J = 3;
const int P = 4;
const int N = 0;

namespace MMaze {

  Tuile::Tuile() {
    srand(time(NULL));
    for (unsigned int i=0; i<4; i++) {
      for (unsigned int j=0; j<4; j++) {
        tab[4*i+j] = new Case(i, j);
        couleurs[4*i+j] = N;
        sites[4*i+j] = '0';
      }
    }
    for(int i=0;i<24;i++){
        walls[i] = false;
    }
  }
  
  bool Tuile::mur(Mur m) const {
      return walls[m.index()]==true;
  }
  
  bool Tuile::accessible(Case c) const {
    /* remplacez ce code */
    return false ;
  }

  void Tuile::placement_sortie(){
      //TODO
  }

  void Tuile::placement_depart(){
      sites[5] = 'd';
      sites[6] = 'd';
      sites[9] = 'd';
      sites[10] = 'd';
      couleurs[5] = V;
      couleurs[6] = P;
      couleurs[9] = O;
      couleurs[10] = J;
      couleurs[2] = V;
      couleurs[4] = P;
      couleurs[11] = O;
      couleurs[13] = J;
      placement_porte();
  }

  void Tuile::placement_objectif(){
    //TODO
  }

  void Tuile::placement_porte(){
      sites[2] = 'p';
      sites[4] = 'p';
      sites[11] = 'p';
      sites[13] = 'p';
  }

  void Tuile::placement_site(){
    if(rand()%2)
        placement_objectif();
    else if (rand()%2)
        placement_sortie();
    while(rand()%4==0){
        placement_porte();
    }
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
