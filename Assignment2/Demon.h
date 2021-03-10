//Name-Tasfique
//Student ID-5886429
#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"

class Demon : public Creature
{
	private:
		double speed;
		double armour;

	public:
		Demon();
		Demon(string, double, double, double, double, double);
		~Demon() {};
		void setSpeed(double);
		void setArmour(double);
		double getSpeed();
		double getArmour();
		void display() override;
};

#endif
