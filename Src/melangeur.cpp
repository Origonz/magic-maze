#include "melangeur.hpp"

using namespace std;

namespace MMaze {

Melangeur::Melangeur(int octets) {
  nb_octets = octets;
  data = (char*) malloc(nb_octets);
  size = 0;
  capacite = 1;
}

Melangeur::~Melangeur() {
  free(data);
}

void Melangeur::inserer(const void* elem) {
  if(capacite == taille()) {
    grandir() ;
  }
  std::memcpy(data + nb_octets * taille(), elem, nb_octets) ;
  ++size ;
}

void Melangeur::retirer(void* elem) {
  if (taille() == 0) {
    exit(EXIT_FAILURE);
  }
  uniform_int_distribution<int> distribution(0, taille() - 1);
  int index = distribution(generator);
  memcpy(elem, data + nb_octets * index, nb_octets);
  memcpy(data + index * nb_octets, data + nb_octets * (taille() - 1), nb_octets);
  size -= 1;
}

void Melangeur::vider() {
  free(data);
  size = 0;
}

int Melangeur::taille() {
  return size ;
}

void Melangeur::grandir(){
  capacite *= 2 ;
  char* tmp = (char*)realloc(data, capacite*nb_octets) ;
  assert(tmp) ;
  data = tmp ;
}

} //end of namespace MMaze
