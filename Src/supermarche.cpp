#include "supermarche.hpp"
#include<iostream>

namespace MMaze {

SuperMarche::SuperMarche()
{
  mel = new Melangeur(sizeof(Tuile));
  map  = vector<InfoTuile>();
  map.push_back(InfoTuile(new Tuile(true)));

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


}
