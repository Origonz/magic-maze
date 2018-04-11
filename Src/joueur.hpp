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


    int place_ppetit(); //renvoie la place de la valeur du plus petit chemin
    int find(vector<Case*> v,int a); //renvoie l'indice de la valeur a dans v

public:
    Joueur(Couleur c,Tuile* t,int p); //initialise le joueur avec sa couleur, la tuile et la position du pion
    void calculChemin(); //remplis le tableau chemin avec le plus court chemin
    void calculCheminG(); //remplis le tableau chemin avec le plus court chemin graph (Non fonctionnel)
    void afficheChemin();
    void afficheCheminG();
    void affichePred();

};

}

#endif // JOUEUR_HPP
