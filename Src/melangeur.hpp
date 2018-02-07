#ifndef MMAZE_MELANGEUR_HPP
#define MMAZE_MELANGEUR_HPP

namespace MMaze {

class Melangeur {

  private :
    int octets;
    void* tab;

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
