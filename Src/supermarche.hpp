#ifndef MMAZE_SUPERMARCHE_HPP
#define MMAZE_SUPERMARCHE_HPP

#include "melangeur.hpp"
#include "tuile.hpp"

namespace MMaze {

struct InfoTuile
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
    vector<InfoTuile> map;

public:
    SuperMarche();
    void Affiche();
    };

} //end of namespace MMaze

#endif
