//Name-Tasfique
//Student ID-5886429
#ifndef ELF_H
#define ELF_H
#include "Creature.h"

class Elf : public Creature {

private:
    double agility;
public:
    Elf();
    Elf(string, double, double, double, double); //constructor.
    ~Elf() {}; //destructor.
    Elf operator-(const Elf& e); //operator overloading
    void setAgility(double);
    double getAgility();
    void display() override;

};

#endif
