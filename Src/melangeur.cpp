#include "melangeur.hpp"

namespace MMaze {

Melangeur::Melangeur(int octets) {
  /* votre code ici */
}

Melangeur::~Melangeur() {
  free(data);
}

void Melangeur::inserer(const void* elem) {
  if(capacite == taille) {
        grandir() ;
    }
    std::memcpy(data + octets * taille, elem, octets) ;
    ++taille ;
}

void Melangeur::retirer(void* elem) {
  /* votre code ici */
}

void Melangeur::vider() {
  free(data)
  taille = 0;
}

int Melangeur::taille() {
  return taille ;
}

void Melangeur::grandir(){
  capacite *= 2 ;
  char* tmp = (char*)realloc(data, capacite*octets) ;
  assert(tmp) ;
  data = tmp ;
}

} //end of namespace MMaze
