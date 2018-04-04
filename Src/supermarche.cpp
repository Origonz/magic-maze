#include "supermarche.hpp"
#include<iostream>

namespace MMaze {

SuperMarche::SuperMarche()
{
  mel = new Melangeur(sizeof(Tuile));
  map  = vector<Tuile>();
  map.push_back(Tuile(true));
  for(int i=0;i<10;i++){
      mel->inserer(new Tuile());
  }
}

void SuperMarche::Affiche(){
    Tuile t;
    for(int i=0;i<10;i++){
        mel->retirer(&t);
        std::cout<<t<<std::endl<<std::endl;
    }
}


}
