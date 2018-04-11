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
    unsigned int position;

    int chemin[16];
    int pred[16];
    int cheminG[16];


    int place_ppetit();
    int find(vector<Case*> v,int a);

public:
    void calculChemin();
    void calculCheminG();
    Joueur(Couleur c,Tuile* t,int p);
    void afficheChemin();
    void afficheCheminG();
    void affichePred();

};

}

#endif // JOUEUR_HPP
