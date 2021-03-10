//Name-Tasfique
//Student ID-5886429
#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
#include <ctime>

using namespace std;

class Creature {

private:
    string name;
    double strength;
    double hitPoints;
    double health;

public:
    Creature(); // Default constructor initialization

    Creature(string, double, double, double); // non-default constructor.
    ///setters
    void setName(string);
    void setStrength(double);
    void setHitPoints(double);
    void setHealth(double);
    ///getters
    string getName();
    double getStrength();
    double getHealth();
    double getHitPoints();
    virtual ~Creature(); // virtual destructor
    virtual void display();

};


#endif // CREATURE_H


