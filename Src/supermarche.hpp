#ifndef MMAZE_SUPERMARCHE_HPP
#define MMAZE_SUPERMARCHE_HPP

#include "tuile.hpp"
#include "melangeur.hpp"
#include "joueur.hpp"
#include<vector>

namespace MMaze {

struct InfoTuile //structure pour géré le retournement d'une tuile
{
    Tuile* tuile;
    Tuile* voisin[4];

    InfoTuile(Tuile* t) {
        tuile = t;
        for(int i=0;i<4;i++){
            voisin[i] = nullptr;
        }
    }
};

class SuperMarche{
private:
    Melangeur* mel;
    std::vector<InfoTuile> map;

public:
    SuperMarche();
    void affiche();
    void notify(int id,int p); //permet d'ajouter à la porte p la tuile suivante
    };

extern SuperMarche marche; //solution pour le design pattern observer

} //end of namespace MMaze

#endif
