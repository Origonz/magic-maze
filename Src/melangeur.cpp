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
  /* votre code ici */
}

void Melangeur::inserer(const void* elem) {
  /* votre code ici */
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
  /* votre code ici */
}

int Melangeur::taille() {
  /* votre code ici */
  return 0 ; /* a remplacer */
}

} //end of namespace MMaze
