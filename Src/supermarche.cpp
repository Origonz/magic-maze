#include "supermarche.hpp"
#include<iostream>

namespace MMaze {

SuperMarche::SuperMarche()
{
  mel = new Melangeur(sizeof(Tuile));
  map  = vector<Tuile>();
  map.push_back(Tuile(true));

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
        std::cout<<t<<std::endl<<std::endl;
    }
}


}
