//Name-Tasfique
//Student ID-5886429
#include <iostream>
#include "Wizard.h"

using namespace std;

Wizard::Wizard() : Creature() {
    magicalDamage = 0.0;
    wand = false;
    armour = 0.0;
}

Wizard::Wizard(string name, double strength, double hitPoints, double health, double magicalDamage, bool wand, double armour) : Creature(name, strength, hitPoints, health), wand(wand), magicalDamage(magicalDamage), armour(armour) {
} //Wizard wizard1("Wizard1", 12, 100, 100, 10, true, 1);

void Wizard::setMagicalDamage(double magicalDamage) {
    this->magicalDamage = magicalDamage;
}

void Wizard::setWand(bool wand) {
    this->wand = wand;
}

void Wizard::setArmour(double armour) {
    this->armour = armour;
}

double Wizard::getMagicalDamage()
{
	return magicalDamage;
}

bool Wizard::getWand()
{
	return wand;
}

double Wizard::getArmour()
{
	return armour;
}

Wizard Wizard::operator+(Wizard const &w)
{
	return Wizard(getName(), getStrength(), getHitPoints(), getHealth(), magicalDamage+w.magicalDamage, wand, armour+w.armour);
}

void Wizard::display()
{
	cout << "Name of the Wizard : " << getName() << endl;
	cout << "Strength : " << getStrength() << endl;
	cout << "Hit Points : " << getHitPoints() << "/" << getHealth() << endl;
	cout << "Magical Damage : " << getMagicalDamage() << endl;
	if(wand) cout << "Possesion of Wand : TRUE " << endl;
	else cout << "POSSESSION OF WAND : FALSE " << endl;
	cout << "Armour : " << getArmour() << endl;
}

void wizardMagicalPower(Wizard const &w)
{
	cout << "+-----------------------------------------+" << endl;
	cout << "|   WIZARD MAGICAL DAMAGE WAS INFLICTED!  |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "Wizard Magical Damage : " << w.magicalDamage << endl;
}
