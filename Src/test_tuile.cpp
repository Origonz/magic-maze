#include "supermarche.hpp"


#include <iostream>
#include <cstdlib>

using namespace MMaze ;

int main() {
  
  Tuile t(false);
  Joueur j(Couleur::JAUNE, &t, 5);
  std::cout<<t<<std::endl;
  j.calculChemin();


  /* Case *c = new Case(8);
  if (t.accessible(*c)) {
    std::cout <<"Cette case est accessible." << std::endl ;
  } else {
    std::cout <<"Cette case n'est pas accessible."<< std::endl ;
    }*/
  
  //utilisation des couleurs
  /*std::cout
    << TXT_JAUNE << "&"
    << TXT_ORANGE << "&"
    << TXT_VERT << "&"
    << TXT_VIOLET << "&"
    << TXT_CLEAR
    << BG_JAUNE << "&"
    << BG_ORANGE << "&"
    << BG_VERT << "&"
    << BG_VIOLET << "&"
    << TXT_CLEAR
    << std::endl ;*/

  return 0 ;
}
