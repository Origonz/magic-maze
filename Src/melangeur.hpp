#ifndef MMAZE_MELANGEUR_HPP
#define MMAZE_MELANGEUR_HPP
#include <time.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <random>

namespace MMaze {

  class Melangeur {
    
  private :
    int nb_octets;
    char* data;
    int size;
    int capacite;
    std::default_random_engine generator;
    
  public :
    
    Melangeur(int octets) ;

    ~Melangeur() ;

    void inserer(const void* elem) ;

    void retirer(void* elem) ;

    void grandir();

    void vider() ;

    int taille() ;

  /* vos membres ici */

} ;

} //end of namespace MMaze

#endif
