#ifndef SORTIE_H
#define SORTIE_H
#include "site.hpp"


class Sortie : public Site
{
public:
    Sortie();
    Sortie(Couleur c);
    void action();
};

#endif // SORTIE_H
