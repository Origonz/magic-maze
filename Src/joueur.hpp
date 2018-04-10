#ifndef MMAZE_JOUEUR_HPP
#define MMAZE_JOUEUR_HPP
#include "couleurs.hpp"
#include "tuile.hpp"

namespace MMaze {

class Joueur
{
private:
    Couleur couleur;
    Tuile* tuile;
    int position;

public:
    Joueur();
};

#endif // JOUEUR_HPP
