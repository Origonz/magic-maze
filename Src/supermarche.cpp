#include "supermarche.hpp"

namespace MMaze {

SuperMarche::SuperMarche()
{
  mel = new Melangeur(sizeof(Tuile));
  map  = std::vector<InfoTuile>();
  map.push_back(InfoTuile(new Tuile(0,true)));

  do{
      mel->inserer(new Tuile());
      if(nb_O == 0 && nb_S == 0){
          break;
      }
  }while(1);

}

void SuperMarche::Affiche(){
    Tuile t;
    std::cout<<"Nombre de Tuile : "<<mel->taille()<<std::endl<<std::endl;
    for(int i=0;i<10;i++){
        mel->retirer(&t);
        map.push_back(InfoTuile(&t));
        std::cout<<*map[i].tuile<<std::endl<<std::endl;
    }
}

void SuperMarche::notify(int id,int p){
    /*Tuile t(this,0);
    mel->retirer(&t);
    t.setId(map.size());
    InfoTuile a(&t);
    map.push_back(a);
    map[id].voisin[p] = a.tuile;*/
    std::cout<<"ça notifie !!!!!!!"<<std::endl;

}

}
