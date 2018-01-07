#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include "pion.h"
using namespace std;
int const taillePlateau(66);
//TODO faire deplacer pion sur plateau selon nbre de cases
//TODO penser à struct prison
// WARNINGS le nbre de case est ptete + petit/gd que le nbre de tours joué par pions
string generAleat(int nbreFace){
    std::random_device rd;
    std::stringstream ss;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, nbreFace);
    for(int n=0; n<taillePlateau; ++n){
      ss<<dis(gen);}
    return ss.str();}
void dispatchPionDsTableau(Pion pion,char val,vector<Pion> pions){
  switch(val){
    case '0':
      cout<<"avance de 3 cases"<<endl;
      pion.avance(3);
      break;
    case '1':
      cout<<"avance de 1 cases"<<endl;
      pion.avance(1);
      break;
    case '2':
      cout<<"recule de 1 cases"<<endl;
      pion.recule(1);
      break;
    case '3':
      cout<<"recule de 2 cases"<<endl;
      pion.recule(2);
      break;
    case '4':
      cout<<"passe par la case prison pendant 2 tours"<<endl;
      pion.prison(0);
      break;
    case '5':
      cout<<"passe par la case prison pendant 5 tours"<<endl;
      pion.prison(0);
      break;
    case '6':
      cout<<"fais avancer ts les autres de 2 tours"<<endl;
      for (Pion p : pions)
        pion.avanceAutre(2,p);
      break;
    case '7':
      cout<<"fais reculer ts les autres de 2 tours"<<endl;
      for (Pion p : pions)
        pion.reculeAutre(2,p);
      break;
    case '8':
      cout<<"fais avancer ts les autres de 5 tours"<<endl;
      for (Pion p : pions)
        pion.avanceAutre(5,p);
      break;
    case '9':
      cout<<"fais reculer ts les autres de 5 tours"<<endl;
      for (Pion p : pions)
        pion.reculeAutre(5,p);
      break;
   }
   cout<<"Pion : "<<pion.getName()<<" i : "<<pion.getPosit()<<" xp : "<<pion.getScore()<<endl;
}
int main(){
    Pion p1("Theo"),p2("Luka"),p3("Chloe"),p4("Clovis"),joueur("Moi");
    vector<Pion> pions;
    pions.push_back(p1);pions.push_back(p2);
    pions.push_back(p3);pions.push_back(p4);
    string plateau= generAleat(10);
    for(int i=0;i<taillePlateau;i++){
    std::cout << i<<" "<<plateau.at(i)<<endl;
    dispatchPionDsTableau(joueur,plateau[i],pions);
    }
    return 0;
}
