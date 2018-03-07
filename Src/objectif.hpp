#ifndef OBJECTIF_H
#define OBJECTIF_H
#include "site.hpp"
#include "couleurs.hpp"

class Objectif : public Site
{
public:
    Objectif();
    Objectif(Couleur c);
    void action();
};

#endif // OBJECTIF_H
