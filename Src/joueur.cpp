#include "joueur.hpp"

namespace MMaze {


Joueur::Joueur(Couleur c,Tuile* t,int p){
    couleur = c;
    tuile = t;
    position = p;
    for(int i=0;i<16;i++){
        chemin[i] = 100;
    }
}

int Joueur::place_ppetit(){
    int a = 0;
    for(int i=1;i<16;i++){
        if(chemin[i]<chemin[a]){
            a = i;
        }
    }
    return a;
}

int Joueur::find(vector<Case*> v,int a){
    Case* b = new Case(a);
    int i;
    for(i=0;v[i]->index() == b->index();i++);
    return i;
}

void Joueur::calculChemin(){
    bool a_traite[16];
    vector<Case*> en_cours;
    Direction direction[4] = {HAUT, BAS, GAUCHE, DROITE};
    int pred[16];
    for(int i = 0;i<16;i++){
        a_traite[i] = true;
        pred[i] = -1;
    }
    int f;
    Case* tmp = new Case(position);
    en_cours.push_back(tmp);
    while(!en_cours.empty()){
        f = find(en_cours,place_ppetit());
        tmp = en_cours[f];
        en_cours.erase(en_cours.begin() + f);

        if(tmp->index()==position){
            chemin[position] = 0;
        }else{
            chemin[tmp->index()] = chemin[pred[tmp->index()]] + 1;
        }
        for(int i=0;i<4;i++){
            try{
                if(a_traite[tmp->voisine(direction[i]).index()]){
                        if(!tuile->mur(Mur(*tmp,tmp->voisine(direction[i]))) && chemin[tmp->voisine(direction[i]).index()] > chemin[tmp->index()]+1){
                            en_cours.push_back(new Case(tmp->voisine(direction[i]).index()));
                            pred[tmp->voisine(direction[i]).index()] = tmp->index();
                        }
                }
             }catch (exception e) {

             }
        }
        a_traite[tmp->index()] = false;
    }
    for(int i=0;i<16;i++){
        if(i%4==0){
            std::cout<<std::endl;
        }
        std::cout<<chemin[i]<<"-";
    }
}

}
