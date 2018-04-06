#include "supermarche.hpp"

namespace MMaze {

SuperMarche::SuperMarche()
{
  mel = new Melangeur(sizeof(Tuile));
  map  = std::vector<InfoTuile>();
  map.push_back(InfoTuile(new Tuile(true)));
  do{
      mel->inserer(new Tuile(0));
      if(nb_O == 0 && nb_S == 0){
          break;
      }
  }while(1);

}

void SuperMarche::affiche(){
    Tuile t;
    std::cout<<"Nombre de Tuile : "<<mel->taille()<<std::endl<<std::endl;
    for(int i=0;i<10;i++){
        mel->retirer(&t);
        t.signal(10);
    }
}

void SuperMarche::notify(int id,int p){
    /*Tuile t(this,0);
    mel->retirer(&t);
    t.setId(map.size());
    InfoTuile a(&t);
    map.push_back(a);
    map[id].voisin[p] = a.tuile;*/
    std::cout<<"Tuile "<<id<<" : ça notifie la porte "<<p<<std::endl;

}

 SuperMarche marche;

}
