#ifndef PION_H
#define PION_H

#include <iostream>
using namespace std;
class Pion
{
  public:
    Pion(string name);
    virtual ~Pion();
    string getName() const ;
    void setName(string name);
    int getScore() const ;
    int getPosit() const ;
    void ajoutPoint(int pt);
    void supprPoint(int pt);
    void avance(int pos);
    void avanceAutre(int pos,Pion p);
    void recule(int pos);
    void reculeAutre(int pos,Pion p);
    void prison(int pos);
  protected:

  private:
    string name;
    int score;
    int position;
};

#endif // PION_H
