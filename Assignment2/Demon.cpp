//Name-Tasfique
//Student ID-5886429
#include <iostream>
#include "Demon.h"

Demon::Demon() : Creature()
{
	speed = 0.0;
	armour = 0.0;
}

Demon::Demon(string name, double strength, double hitPoints, double health, double speed, double armour) : Creature(name, strength, hitPoints, health), speed(speed), armour(armour) {}

void Demon::setSpeed(double speed)
{
	this->speed = speed;
}

void Demon::setArmour(double armour)
{
	this->armour = armour;
}

double Demon::getSpeed()
{
	return speed;
}

double Demon::getArmour()
{
	return armour;
}

void Demon::display()
{
	cout << "Name : " << getName() << endl;
	cout << "Strength : " << getStrength() << endl;
	cout << "Hit Point : " << getHitPoints() << "/" << getHealth() << endl;
	cout << "Speed : " << speed << endl;
	cout << "Armour : " << armour << endl;
}
