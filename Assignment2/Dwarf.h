//Name-Tasfique
//Student ID-5886429
#ifndef DWARF_H
#define DWARF_H
#include "Creature.h"

class Dwarf : public Creature {

private:
    //double n ;
    double armour;
    double invisibility;

public:
    Dwarf();
    Dwarf(string, double, double, double, double, double);
    ~Dwarf() {}; //destructor.
    Dwarf operator*(const Dwarf& d);
    //setter
    void setInvisibility(double);
    void setArmour(double);
    //getter
    double getInvisibility();
    double getArmour();
    //display
    void display() override;
};


#endif

