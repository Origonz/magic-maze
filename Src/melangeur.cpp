#include "melangeur.hpp"
#include <time.h>

namespace MMaze {

Melangeur::Melangeur(int octets) {
  this.octets = octets;
  data = (char*) malloc(octets);
  taille = 0;
  capacite = 1;
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
  if (taille == 0) {
    exit(EXIT_FAILURE);
  }
  srand(time(NULL));
  int index = rand()%taille;
  memcpy(elem, data + octets * index, octets);
  memcpy(data + index * octets, data + octets * (taille - 1), octets);
  taille -= 1;
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
