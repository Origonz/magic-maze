#ifndef SITE_H
#define SITE_H

//--------------------------------------------------------
//      Site (classe abstraite)
//--------------------------------------------------------
class Site
{
public:
    virtual ~Site(){}
    virtual void action() = 0;
};

//--------------------------------------------------------
//      Départ
//--------------------------------------------------------
class Depart : public Site
{
public:
    void action() const;
    ~Depart(){}
};

//--------------------------------------------------------
//      Sortie
//--------------------------------------------------------
class Sortie : public Site
{
public:
    void action() const;
    ~Sortie(){}
};

//--------------------------------------------------------
//      Objectif
//--------------------------------------------------------
class Objectif : public Site
{
public:
    void action() const;
    ~Objectif(){}
};

//--------------------------------------------------------
//      Porte
//--------------------------------------------------------
class Porte : public Site
{
public:
    void action() const;
    ~Porte(){}
};
#endif // SITE_H
