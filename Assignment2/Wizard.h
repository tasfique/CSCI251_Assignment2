//Name-Tasfique
//Student ID-5886429
#ifndef WIZARD_H
#define WIZARD_H
#include <iostream>
#include <ctime>
#include "Creature.h"

class Wizard : public Creature
{
private:
    double magicalDamage;
    bool wand;
    double armour;

public:
    Wizard();
    Wizard(string, double, double, double, double, bool, double);
    ~Wizard() {};
    Wizard operator+(const Wizard &w);
    void setMagicalDamage(double);
    void setWand(bool);
    void setArmour(double);
    double getMagicalDamage();
    bool getWand();
    double getArmour();
    void display() override;
    friend void wizardMagicalPower(const Wizard &w);
};


#endif // CREATURE_H
