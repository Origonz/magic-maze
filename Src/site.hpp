#ifndef MMAZE_SITE_HPP
#define MMAZE_SITE_HPP

#include <iostream>

namespace MMaze {
//--------------------------------------------------------
//      Site (classe abstraite)
//--------------------------------------------------------
class Site
{
public:
    virtual ~Site(){}
    virtual void action(){return;}
    virtual char affiche(){return ' ';}
    //friend std::ostream& operator<<(std::ostream& out, const Site& s){out<<"   ";return out;}
};

//--------------------------------------------------------
//      Départ
//--------------------------------------------------------
class Depart : public Site
{
public:
    void action() const;
    char affiche(){return 'd';}
    //friend std::ostream& operator<<(std::ostream& out, const Site& s){out<<" d ";return out;}
    ~Depart(){}
};

//--------------------------------------------------------
//      Sortie
//--------------------------------------------------------
class Sortie : public Site
{
public:
    void action() const;
    char affiche(){return 's';}
    //friend std::ostream& operator<<(std::ostream& out, const Site& s){out<<" s ";return out;}
    ~Sortie(){}
};

//--------------------------------------------------------
//      Objectif
//--------------------------------------------------------
class Objectif : public Site
{
public:
    void action() const;
    char affiche(){return 'o';}
    //friend std::ostream& operator<<(std::ostream& out, const Site& s){out<<" o ";return out;}
    ~Objectif(){}
};

//--------------------------------------------------------
//      Porte
//--------------------------------------------------------
class Porte : public Site
{
public:
    void action() const;
    char affiche(){return 'p';}
    //friend std::ostream& operator<<(std::ostream& out, const Site&){out<<" p ";return out;}
    ~Porte(){}
};
}
#endif // MMAZE_SITE_HPP
