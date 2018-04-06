#include "tuile.hpp"
#include "mur.hpp"
#include "RandomUniform.hpp"
#include "supermarche.hpp"
#include <cassert>

namespace MMaze {

  Tuile::Tuile(int i /*=0*/, bool d /*=false*/) {
    id = i;
    for (unsigned int i=0; i<4; i++) {
      for (unsigned int j=0; j<4; j++) {
        tab[4*i+j] = 4*i+j;
        couleurs[4*i+j] = Couleur::AUCUNE;
        joueur[4*i+j] = Couleur::AUCUNE;
        sites[4*i+j] = new Site();
      }
    }
    for (int i = 0; i < 24; i++) {
      walls[i] = true;
    }
    if (d) {
      tuile_de_depart();
    } else {
      tuile_classique();
    }
  }

  void Tuile::setId(int i){
      id = i;
  }

  //Trouver une case qui est sa propre représentante
  int Tuile::find(int c) {
    if (tab[c] == c) { 
      return c;
    }
    return find(tab[c]);
  }

  void Tuile::unionFind(int c1, int c2){
    int classe1 = find(c1);
    int classe2 = find(c2);
    
    if(classe1 != classe2){
      tab[classe1] = classe2;
    }
  }
  
  bool Tuile::mur(Mur m) const {
      return walls[m.index()];
  }
  
  bool Tuile::accessible(Case c) const {
    vector<Case> done;
    vector<Case> not_done;
    vector<Case> voisins;
    Direction directions[4] = {HAUT, BAS, GAUCHE, DROITE};
    not_done.push_back(c);
    for (unsigned int i=0; i<not_done.size(); i++) {
      i = 0;
      Case encours = not_done[i];
      //Trouvez tous les voisins de la case en cours
      for (int j=0; j<4; j++) {
	try {
	  Case v = encours.voisine(directions[j]);
	  if (!isin(done, v.index())) {
	    voisins.push_back(v);
	  }
	} catch (exception e) {
	  //Rien
	}
	
      }
      for (unsigned int k=0; k<voisins.size(); k++) {
	Mur *m = new Mur(encours, voisins[k]);
	if (mur(*m) == false && !isin(not_done, voisins[k].index())) {
	  not_done.push_back(voisins[k]);
	}
      }
      done.push_back(encours);
      not_done.erase(not_done.begin());
      voisins.clear();
    }
    //Si l'unes des portes a été traitée, alors elle est accessible
    int portes[4] = {2,4,11,13};
    for (int i=0; i<4; i++) {
      if (isin(done, portes[i])) {
	return true;
      }
    }
    return false;
  }

  void Tuile::placement_sortie(){
      int portes[] = {2,4,11,13};
      int p = rd.generer(3);
      sites[portes[p]] = new Sortie();
      int a = rd.generer(nb_S-1)+1;
      couleurs[portes[p]] = colorsS[a];
      colorsS[a] = colorsS[nb_S];
      nb_S--;
  }

  void Tuile::placement_depart(){
    sites[5] = new Depart();
    sites[6] = new Depart();
    sites[9] = new Depart();
    sites[10] = new Depart();
    joueur[5] = Couleur::VERT;
    joueur[6] = Couleur::JAUNE;
    joueur[9] = Couleur::VIOLET;
    joueur[10] = Couleur::ORANGE;
    couleurs[5] = Couleur::VERT;
    couleurs[6] = Couleur::JAUNE;
    couleurs[9] = Couleur::VIOLET;
    couleurs[10] = Couleur::ORANGE;
    couleurs[2] = Couleur::VERT;
    couleurs[4] = Couleur::JAUNE;
    couleurs[11] = Couleur::VIOLET;
    couleurs[13] = Couleur::ORANGE;
    placement_porte();
  }

  void Tuile::placement_objectif(){
     int o = rd.generer(15);
     while(o == 2 || o == 4 || o == 11 || o == 13){
         o = rd.generer(15);
     }
     sites[o] = new Objectif();
     int a = rd.generer((nb_O-1))+1;
     couleurs[o] = colorsO[a];
     colorsO[a] = colorsO[nb_O];
     nb_O--;
  }

  void Tuile::placement_porte(){
    sites[2] = new Porte();
    sites[4] = new Porte();
    sites[11] = new Porte();
    sites[13] = new Porte();
  }

  void Tuile::placement_site(){
    placement_porte();
    if(nb_O && rd.generer(1))
      placement_objectif();
    else if (nb_S && rd.generer(1))
      placement_sortie();
  }

  //Casser les murs
  void Tuile::casserMur() {
    Direction directions[4] = {HAUT, BAS, GAUCHE, DROITE};
    int m;
    do {
      m = rd.generer(23);
    } while (walls[m] == false);
    
    //Casser le mur
    walls[m] = false;
    
    if (m < 12) {
      try {
	Case tmp = Case(m);
	for (int i = 0; i < 4; i++) {
	  if (accessible(tmp.voisine(directions[i]))) {
	    unionFind(m, m + 4);
	  }
	}
      } catch (exception e) {
	//Rien
      }
    } else {
      int colonne = (m - 12) / 4;
      int ligne = m % 4;
      unionFind(colonne+ligne*4, colonne+ligne*4+1);
    }
  }

  //Validité de la tuile de départ 
  void Tuile::depart_valide() {
    for (int i = 0; i < 16; i++) {
      Case *c = new Case(i);
      if ((sites[i] -> affiche()) == 'd') {
	while (!accessible(*c)) {
	  casserMur();
	} 
      } 
    }
  }

  //Validité tuile classique
  void Tuile::classique_valide() {
    int t[4] = {5, 6, 9, 10};
    vector<int> s;
    //Préparation des points de départ
    for (int i = 0; i < 4; i++) {
      s.push_back(t[i]);
    }
    //validation
    for (int i = 0; i < 16; i++) {
      Case *c = new Case(i);
      if (((sites[i] -> affiche()) == 'o') ||
	  estDans(s, i) || ((sites[i] -> affiche()) == 's')) {
	while (!accessible(*c)) {
	  casserMur();
	} 
      }
    }
  }

  void Tuile::tuile_de_depart() {
    placement_depart();
    depart_valide();
  }

  void Tuile::tuile_classique() {
    placement_site();
    classique_valide();
  }

  void Tuile::afficher_horizontal(std::ostream& out, unsigned int i) const {
    assert(i < 5) ;
    if(i == 0 || i == 4) {
      out << "+---+---+---+---+" ;
    } else {
      out << "+" ;
      for(unsigned int m = 0; m < 4; ++m) {
	Case up = Case(i-1, m) ;
	Case down = Case(i, m) ;
	if(mur(Mur(up, down))) {
	  out << "---+" ;
	} else {
	  out << "   +" ;
	}
      }
    }
  }
  
  void Tuile::afficher_vertical(std::ostream& out, unsigned int i) const {
    assert(i < 4) ;
    out << "|" ;
    for(unsigned int m = 0; m < 4; ++m) {
      out << bg_colors[couleurs[4*i+m]] << sites[4*i+m]->affiche()<< " " <<TXT_CLEAR;
      if(joueur[4*i+m] != Couleur::AUCUNE){
          out << txt_colors[joueur[4*i+m]] << BG_DEFAULT << "j" << TXT_CLEAR;
      }else{
          out << bg_colors[couleurs[4*i+m]] << " " << TXT_CLEAR;
      }
      if(m < 3) {
	Case left = Case(i, m) ;
	Case right = Case(i, m+1) ;
	if(m < 3 && mur(Mur(left, right))) {
	  out << "|" ;
	} else {
	  out << " " ;
	}
      }
    }
    out << "|" ;
  }
  
  std::ostream& operator<< (std::ostream& out, const Tuile& t) {
    for(unsigned int i = 0; i < 4; ++i) {
      t.afficher_horizontal(out, i) ;
      out << std::endl ;
      t.afficher_vertical(out, i) ;
      out << std::endl ;
    }
    t.afficher_horizontal(out, 4) ;
    return out ;
  }

  bool Tuile::isin(vector<Case> v, unsigned int index) const {
    for (unsigned int i=0; i<v.size(); i++) {
      if (v[i].index() == index) {
	return true;
      }
    }
    return false;
  }

  bool Tuile::estDans(vector<int> v, int i) {
    for (unsigned int k = 0; k < v.size(); k++) {
      if (v[k] == i) {
	return true;
      }
    }
    return false;
  }
  
  void Tuile::signal(int a) {
    marche.notify(id,a);
  }
  
} //end of namespace MMaze
