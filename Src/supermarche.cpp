#include "supermarche.hpp"

namespace MMaze {

SuperMarche::SuperMarche()
{
  mel = new Melangeur(sizeof(Tuile));
  map  = std::vector<InfoTuile>();
  map.push_back(InfoTuile(new Tuile(true)));
  int i = 0;
  do{
      mel->inserer(new Tuile(i));
      i++;
      if(nb_O == 0 && nb_S == 0){
          break;
      }
  }while(1);

}

void SuperMarche::affiche(){
    Tuile t;
    int taille = mel->taille();
    std::cout<<"Nombre de Tuile : "<<taille<<std::endl<<std::endl;
    for(int i=0;i<taille;i++){
        t.setId(i);
        t.signal(10);
    }
}

void SuperMarche::notify(int id,int p){
    p = p%5;
    Tuile t;
    mel->retirer(&t);
    t.setId(map.size()-1);
    InfoTuile a(&t);
    map.push_back(a);
    map[id].voisin[p] = a.tuile;
    std::cout<<*map[id].voisin[p]<<std::endl;

}

 SuperMarche marche;

}
