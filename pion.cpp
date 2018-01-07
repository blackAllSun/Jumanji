#include "pion.h"

Pion::Pion(string name):name(name),score(0),position(0)
{
}

Pion::~Pion()
{
  //dtor
}
string Pion::getName() const {return name;}
void Pion::setName(string name){this->name=name;}
int Pion::getScore() const {return score;}
int Pion::getPosit() const {return position;}
void Pion::ajoutPoint(int pt){
   score+=pt;}
void Pion::supprPoint(int pt){
   score-=pt;}
void Pion::avance(int pos){
   ajoutPoint(pos);
   position+=pos;}
void Pion::avanceAutre(int pos,Pion p){
   supprPoint(pos);
   p.position+=pos;
   p.ajoutPoint(pos);}
void Pion::recule(int pos){
  supprPoint(pos);
  position-=pos;}
void Pion::reculeAutre(int pos,Pion p){
  ajoutPoint(pos);
  p.position-=pos;
  p.supprPoint(pos);}
void Pion::prison(int pos){
  supprPoint(pos);}
