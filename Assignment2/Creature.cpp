//Name-Tasfique
//Student ID-5886429
///CREATURE CLASS.
#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature() // Default constructor
{
	name = "";
	strength = 0.0;
	hitPoints = 0.0;
	health = 0.0;
}

Creature::Creature(string name, double strength, double hitPoints, double health) : name(name), strength(strength), hitPoints(hitPoints), health(health) {
}

void Creature::setName(string name) {
    this->name = name;
}

void Creature::setStrength(double strength) {
    this->strength = strength;
}

void Creature::setHitPoints(double hitPoints) {
    this->hitPoints = hitPoints;
}

void Creature::setHealth(double health) {
    this->health = health;
}

string Creature::getName() {
    return name;
}

double Creature::getStrength() {
    return strength;
}

double Creature::getHitPoints() {
    return hitPoints;
}

double Creature::getHealth() {
    return health;
}

Creature::~Creature() {}
void Creature::display() {}


