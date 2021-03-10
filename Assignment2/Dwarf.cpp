//Name-Tasfique
//Student ID-5886429
#include <iostream>
#include "Dwarf.h"

Dwarf::Dwarf() : Creature()
{
	invisibility = 0.0;
	armour = 0.0;
}

Dwarf::Dwarf(string name, double strength, double hitPoints, double health, double invisibility, double armour) : Creature(name, strength, hitPoints, health), invisibility(invisibility), armour(armour) {}

void Dwarf::setInvisibility(double invisibility)
{
	this->invisibility = invisibility;
}

void Dwarf::setArmour(double armour)
{
	this->armour = armour;
}

double Dwarf::getInvisibility()
{
	return invisibility;
}

double Dwarf::getArmour()
{
	return armour;
}

Dwarf Dwarf::operator*(Dwarf const &e) //arithmetic operator overloading.
{
	return Dwarf(getName(), getStrength(), getHitPoints(), getHealth(), invisibility*e.invisibility, armour*e.armour);
}

void Dwarf::display() //display
{
	cout << "Name : " << getName() << endl;
	cout << "Strength : " << getStrength() << endl;
	cout << "Hit Points : " << getHitPoints() << "/" << getHealth() << endl;
	cout << "Invisibility : " << invisibility << endl;
	cout << "Armour : " << armour << endl;
}
