#ifndef MMAZE_SUPERMARCHE_HPP
#define MMAZE_SUPERMARCHE_HPP

#include "melangeur.hpp"
#include "tuile.hpp"

namespace MMaze {

class SuperMarche{
private:
    Melangeur* mel;
    vector<Tuile> map;

public:
    SuperMarche();
    void Affiche();
    };

} //end of namespace MMaze

#endif
