#ifndef SITE_H
#define SITE_H

class Site
{
public:
    Site(){}
    virtual void action();
    Couleur getCouleur();
    void setCouleur(Couleur c);

protected:
    Couleur couleur;
};

#endif // SITE_H
