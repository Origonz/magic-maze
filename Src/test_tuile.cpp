#include "tuile.hpp"
#include "melangeur.hpp"
#include "couleurs.hpp"

#include <iostream>
#include <cstdlib>

using namespace MMaze ;

int main() {
  Tuile t(false);
  std::cout << t << std::endl ;
  Tuile* tab[5];
  for (int i=0; i<5; i++) {
    tab[i] = new Tuile();
    std::cout << *tab[i] << std::endl ;
  }

  /* Case *c = new Case(8);
  if (t.accessible(*c)) {
    std::cout <<"Cette case est accessible." << std::endl ;
  } else {
    std::cout <<"Cette case n'est pas accessible."<< std::endl ;
    }*/
  
  //utilisation des couleurs
  std::cout
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
    << std::endl ;

  return 0 ;
}
