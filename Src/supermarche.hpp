#ifndef MMAZE_SUPERMARCHE_HPP
#define MMAZE_SUPERMARCHE_HPP

#include "tuile.hpp"
#include "melangeur.hpp"
#include<vector>
#include<iostream>

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
    std::vector<InfoTuile> map;

public:
    SuperMarche();
    void Affiche();
    void notify(int id,int p);
    };

} //end of namespace MMaze

#endif
