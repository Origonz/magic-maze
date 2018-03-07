#ifndef SITE_H
#define SITE_H

//--------------------------------------------------------
//      Site (classe abstraite)
//--------------------------------------------------------
class Site
{
public:
    Site();
    ~Site();
    virtual void action() = 0;
};

//--------------------------------------------------------
//      Départ
//--------------------------------------------------------
class Depart : public Site
{
public:
    Depart(){}
    virtual void action();
};

//--------------------------------------------------------
//      Sortie
//--------------------------------------------------------
class Sortie : public Site
{
public:
    Sortie(){}
    virtual void action();
};

//--------------------------------------------------------
//      Objectif
//--------------------------------------------------------
class Objectif : public Site
{
public:
    Objectif(){}
    virtual void action();
};

//--------------------------------------------------------
//      Porte
//--------------------------------------------------------
class Porte : public Site
{
public:
    Porte(){}
    virtual void action();
};
#endif // SITE_H
