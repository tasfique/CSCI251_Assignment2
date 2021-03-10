//Name-Tasfique
//Student ID-5886429

#include "Elf.h"

Elf::Elf(string name, double strength, double hitPoints, double health, double agility) : Creature(name, strength, hitPoints, health), agility(agility) {}

void Elf::setAgility(double agility)
{
	this->agility = agility;
}

double Elf::getAgility()
{
	return agility;
}

Elf Elf::operator-(Elf const &e)
{
	return Elf(getName(), getStrength(), getHitPoints(), getHealth(), agility-e.agility);
}

void Elf::display() //display method.
{
	cout << "NAME : " << getName() << endl;
	cout << "STRENGTH : " << getStrength() << endl;
	cout << "HIT POINTS : " << getHitPoints() << "/" << getHealth() << endl;
	cout << "ARMOR : " << agility << endl;
}

