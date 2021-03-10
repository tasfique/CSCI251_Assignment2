#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// BASE CLASS CREATURE
class Creature
{
	private:
		string name; // CREATURE NAME
		double strength; // CREATURE STRENGTH
		double hitPoints; // CREATURE HIT POINTS (PHYSICAL)
		double originalHP; // CREATURE ORIGINAL HP

	public:
		Creature(); // DEFAULT CONSTRUCTOR
		virtual ~Creature() {}; // DESTRUCTOR
		Creature(string, double, double, double); // NON-DEFAULT CONSTRUCTOR
		void setName(string);
		void setStrength(double);
		void setHitPoints(double);
		void setOriginalHP(double);
		string getName();
		double getStrength();
		double getHitPoints();
		double getOriginalHP();
		virtual void display() {};
};

Creature::Creature() // DEFAULT CONSTRUCTOR
{
	name = "";
	strength = 0.0;
	hitPoints = 0.0;
	originalHP = 0.0;
}

Creature::Creature(string n, double s, double hp1, double hp2) : name(n), strength(s), hitPoints(hp1), originalHP(hp2) {} // NON-DEFAULT CONSTRUCTOR

void Creature::setName(string n)
{
	name = n;
}

void Creature::setStrength(double s)
{
	strength = s;
}

void Creature::setHitPoints(double hp1)
{
	hitPoints = hp1;
}

void Creature::setOriginalHP(double hp2)
{
	originalHP = hp2;
}

string Creature::getName()
{
	return name;
}

double Creature::getStrength()
{
	return strength;
}

double Creature::getHitPoints()
{
	return hitPoints;
}

double Creature::getOriginalHP()
{
	return originalHP;
}

// WIZARD CLASS
class Wizard : public Creature
{
	private:
		double magicalDamage;
		bool wand;
		double armor;

	public:
		Wizard();
		Wizard(string, double, double, double, double, bool, double);
		~Wizard() {};
		Wizard operator+(const Wizard &w);
		void setMagicalDamage(double);
		void setWand(bool);
		void setArmor(double);
		double getMagicalDamage();
		bool getWand();
		double getArmor();
		void display() override;
		friend void wizardMagicalPower(const Wizard &w);
};

Wizard::Wizard() : Creature()
{
	magicalDamage = 0.0;
	wand = false;
	armor = 0.0;
}

Wizard::Wizard(string n, double s, double hp1, double hp2, double m, bool w, double a) : Creature(n, s, hp1, hp2), wand(w), magicalDamage(m), armor(a) {}

void Wizard::setMagicalDamage(double m)
{
	magicalDamage = m;
}

void Wizard::setWand(bool w)
{
	wand = w;
}

void Wizard::setArmor(double a)
{
	armor = a;
}

double Wizard::getMagicalDamage()
{
	return magicalDamage;
}

bool Wizard::getWand()
{
	return wand;
}

double Wizard::getArmor()
{
	return armor;
}

Wizard Wizard::operator+(Wizard const &w)
{
	return Wizard(getName(), getStrength(), getHitPoints(), getOriginalHP(), magicalDamage+w.magicalDamage, wand, armor+w.armor);
}

void Wizard::display()
{
	cout << "NAME : " << getName() << endl;
	cout << "STRENGTH : " << getStrength() << endl;
	cout << "HIT POINTS : " << getHitPoints() << "/" << getOriginalHP() << endl;
	cout << "MAGICAL DAMAGE : " << magicalDamage << endl;
	if(wand) cout << "POSSESSION OF WAND : TRUE " << endl;
	else cout << "POSSESSION OF WAND : FALSE " << endl;
	cout << "ARMOR : " << armor << endl;
}

void wizardMagicalPower(Wizard const &w)
{
	cout << "+-----------------------------------------+" << endl;
	cout << "|   WIZARD MAGICAL DAMAGE WAS INFLICTED!  |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "Wizard Magical Damage : " << w.magicalDamage << endl;
}

// ELF CLASS
class Elf : public Creature
{
	private:
		double armor;

	public:
		Elf();
		Elf(string, double, double, double, double);
		~Elf() {};
		Elf operator-(const Elf& e);
		void setArmor(double);
		double getArmor();
		void display() override;
};

Elf::Elf() : Creature()
{
	armor = 0.0;
}

Elf::Elf(string n, double s, double hp1, double hp2, double a) : Creature(n, s, hp1, hp2), armor(a) {}

void Elf::setArmor(double a)
{
	armor = a;
}

double Elf::getArmor()
{
	return armor;
}

Elf Elf::operator-(Elf const &e)
{
	return Elf(getName(), getStrength(), getHitPoints(), getOriginalHP(), armor-e.armor);
}

void Elf::display()
{
	cout << "NAME : " << getName() << endl;
	cout << "STRENGTH : " << getStrength() << endl;
	cout << "HIT POINTS : " << getHitPoints() << "/" << getOriginalHP() << endl;
	cout << "ARMOR : " << armor << endl;
}

// DWARF CLASS
class Dwarf : public Creature
{
	private:
		double height;
		double speed;
		double armor;

	public:
		Dwarf();
		Dwarf(string, double, double, double, double, double, double);
		~Dwarf() {};
		Dwarf operator*(const Dwarf& d);
		void setHeight(double);
		void setSpeed(double);
		void setArmor(double);
		double getHeight();
		double getSpeed();
		double getArmor();
		void display() override;
};

Dwarf::Dwarf() : Creature()
{
	height = 0.0;
	speed = 0.0;
	armor = 0.0;
}

Dwarf::Dwarf(string n, double s, double hp1, double hp2, double h, double sp, double a) : Creature(n, s, hp1, hp2), height(h), speed(sp), armor(a) {}

void Dwarf::setHeight(double h)
{
	height = h;
}

void Dwarf::setSpeed(double sp)
{
	speed = sp;
}

void Dwarf::setArmor(double a)
{
	armor = a;
}

double Dwarf::getHeight()
{
	return height;
}

double Dwarf::getSpeed()
{
	return speed;
}

double Dwarf::getArmor()
{
	return armor;
}

Dwarf Dwarf::operator*(Dwarf const &e)
{
	return Dwarf(getName(), getStrength(), getHitPoints(), getOriginalHP(), height*e.height, speed*e.speed, armor*e.armor);
}

void Dwarf::display()
{
	cout << "NAME : " << getName() << endl;
	cout << "STRENGTH : " << getStrength() << endl;
	cout << "HIT POINTS : " << getHitPoints() << "/" << getOriginalHP() << endl;
	cout << "HEIGHT : " << height << endl;
	cout << "SPEED : " << speed << endl;
	cout << "ARMOR : " << armor << endl;
}

class Demon : public Creature
{
	private:
		double speed;
		double armor;

	public:
		Demon();
		Demon(string, double, double, double, double, double);
		~Demon() {};
		void setSpeed(double);
		void setArmor(double);
		double getSpeed();
		double getArmor();
		void display() override;
};

Demon::Demon() : Creature()
{
	speed = 0.0;
	armor = 0.0;
}

Demon::Demon(string n, double s, double hp1, double hp2, double sp, double a) : Creature(n, s, hp1, hp2), speed(sp), armor(a) {}

void Demon::setSpeed(double sp)
{
	speed = sp;
}

void Demon::setArmor(double a)
{
	armor = a;
}

double Demon::getSpeed()
{
	return speed;
}

double Demon::getArmor()
{
	return armor;
}

void Demon::display()
{
	cout << "NAME : " << getName() << endl;
	cout << "STRENGTH : " << getStrength() << endl;
	cout << "HIT POINTS : " << getHitPoints() << "/" << getOriginalHP() << endl;
	cout << "SPEED : " << speed << endl;
	cout << "ARMOR : " << armor << endl;
}

int main()
{
	Creature* creatures[4];
	int creature1, creature2;
	int input, player1_input, player2_input;
	int winner;
	int round=0;
	int wizardMagicalPowerMissNextAttack=0;
	bool creatureLost[4] = { false };
	bool creatureWin[4] = { false };
	string name;
	//double strength, hitPoints, magicalDamage, armor, shield, height, speed;
	double wizard_armor, elf_armor, dwarf_armor, demon_armor;
	string creature1_name, creature2_name, wandDetermine;
	bool wand;


	// DECLARE WIZARDS
	Wizard wizard1("Wizard1", 12, 100, 100, 10, true, 1);
	Wizard wizard2("Wizard2", 20, 200, 200, 20, true, 5);

	// PLUS OPERATOR OVERLOADING
	Wizard wizard3=wizard1+wizard2;

	// DECLARE ELFS
	Elf elf1("Elf1", 15, 100, 100, 3);
	Elf elf2("Elf2", 20, 200, 200, 2);

	// MINUS OPERATOR OVERLOADING
	Elf elf3=elf1-elf2;

	// DECLARE DWARFS
	Dwarf dwarf1("Dwarf1", 20, 150, 150, 10, 10, 2);
	Dwarf dwarf2("Dwarf2", 25, 175, 175, 2, 2, 3);

	// MULTIPLICATION OPERATOR OVERLOADING
	Dwarf dwarf3=dwarf1*dwarf2;

	// DECLARE DEMON
	Demon demon1("Demon1", 25, 140, 140, 10, 5);

	// POINT EACH OBJECT USING POLYMORPHISM
	creatures[0] = &wizard3; // POINT TO A WIZARD
	creatures[1] = &elf3; // POINT TO AN ELF
	creatures[2] = &dwarf3; // POINT TO A DWARF
	creatures[3] = &demon1; // POINT TO A DEMON

	// DYNAMIC CAST
	Wizard* casted_wizard = dynamic_cast<Wizard*>(creatures[0]);
	//Elf* casted_elf = dynamic_cast<Elf*>(creatures[1]);
	//Dwarf* casted_dwarf = dynamic_cast<Dwarf*>(creatures[2]);
	//Demon* casted_demon = dynamic_cast<Demon*>(creatures[3]);


	// FIRST, SELECT TWO CREATURES TO FIGHT.
	cout << "+-----------------------------------------+" << endl;
	cout << "| Welcome to fight game between creatures |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << endl;

	cout << "+-----------------------------------------+" << endl;
	cout << "|   Please, choose the first creature.    |" << endl;
	cout << "|   1) Wizard                             |" << endl;
	cout << "|   2) Elf                                |" << endl;
	cout << "|   3) Dwarf                              |" << endl;
	cout << "|   4) Demon                              |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "> ";
	cin >> creature1;

	// VALIDATION
	while (creatureLost[creature1-1] == true || creature1 < 1 || creature1 > 4) // FIRST CREATURE VALIDATION
	{
		cout << "+-----------------------------------------+" << endl;
		cout << "|   Your input is wrong!!!                |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "|   Please, choose the first creature.    |" << endl;
		cout << "|   1) Wizard                             |" << endl;
		cout << "|   2) Elf                                |" << endl;
		cout << "|   3) Dwarf                              |" << endl;
		cout << "|   4) Demon                              |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "> ";
		cin >> creature1;
	}

	cout << "+-----------------------------------------+" << endl;
	cout << "|   Please, choose the opponent creature. |" << endl;
	cout << "|   1) Wizard                             |" << endl;
	cout << "|   2) Elf                                |" << endl;
	cout << "|   3) Dwarf                              |" << endl;
	cout << "|   4) Demon                              |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << "> ";
	cin >> creature2;

	// VALIDATION
	while (creatureLost[creature2 - 1] == true || creature2 < 1 || creature2 > 4 || creature1 == creature2)
	{
		cout << "+-----------------------------------------+" << endl;
		cout << "|   Your input is wrong!!!                |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "|   Please, choose the second creature.   |" << endl;
		cout << "|   1) Wizard                             |" << endl;
		cout << "|   2) Elf                                |" << endl;
		cout << "|   3) Dwarf                              |" << endl;
		cout << "|   4) Demon                              |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "> ";
		cin >> creature2;
	}

	// FIGHT BETWEEN TWO CREATURES
	do
	{
		// EACH ROUND
		round++;

		// GIVE NAMES
		if (creature1 == 1)
		{
			creature1_name = "Wizard";
			wizard_armor = wizard3.getArmor();
		}

		else if (creature1 == 2)
		{
			creature1_name = "Elf";
			elf_armor = elf3.getArmor();
		}

		else if (creature1 == 3)
		{
			creature1_name = "Dwarf";
			dwarf_armor = dwarf3.getArmor();
		}

		else if (creature1 == 4)
		{
			creature1_name = "Demon";
			demon_armor = demon1.getArmor();
		}


		if (creature2 == 1)
		{
			creature2_name = "Wizard";
			wizard_armor = wizard3.getArmor();
		}

		else if (creature2 == 2)
		{
			creature2_name = "Elf";
			elf_armor = elf3.getArmor();
		}

		else if (creature2 == 3)
		{
			creature2_name = "Dwarf";
			dwarf_armor = dwarf3.getArmor();
		}

		else if (creature2 == 4)
		{
			creature2_name = "Demon";
			demon_armor = demon1.getArmor();
		}

		// ARMOR ARRAY
		double armorArr[4]={wizard_armor, elf_armor, dwarf_armor, demon_armor};

		// GET HIT POINTS FROM THE CURRENT CREATURES
		double hp1 = creatures[creature1 - 1]->getHitPoints();
		double hp2 = creatures[creature2 - 1]->getHitPoints();

		// FIGHT BETWEEN TWO CREATURES
		while (hp1 > 0 && hp2 > 0)
		{
			cout << "+-----------------------------------------+" << endl;
			cout << "|            FIGHT INFORMATION            |" << endl;
			cout << "+-----------------------------------------+" << endl;
			cout << "PLAYER 1 : " << creature1_name << endl;
			cout << "PLAYER 2 : " << creature2_name << endl;

			// LET THE USER CHOOSE THE OPTION
			cout << "+-----------------------------------------+" << endl;
			cout << "|    Please, choose PLAYER 1's option     |" << endl;
			cout << "|          1) ATTACK   2) ESCAPE          |" << endl;
			cout << "+-----------------------------------------+" << endl;
			cout << "> ";
			cin >> player1_input;

			if (player1_input == 1) // ATTACK
			{
				if(wizardMagicalPowerMissNextAttack==1)
				{
					cout << "+-----------------------------------------------------------------------------+" << endl;
					cout << "| BECAUSE OF WIZARD MAGICAL POWER, THIS TURN, YOU CANNOT ATTACK THE OPPONENT  |" << endl;
					cout << "+-----------------------------------------------------------------------------+" << endl;
					wizardMagicalPowerMissNextAttack=0;
				}

				else
				{
					// GENERATE THE RANDOM NUMBER BETWEEN 1 TO 100 FOR PROBABILITY
					srand(time(0));
					int randomNumber=(rand()%100)+1;
					cout << "+-----------------------------------------+" << endl;
					cout << "|     Player 1 attacks Player 2 !!!       |" << endl;
					cout << "+-----------------------------------------+" << endl;

					if(creature1==1) // IF THE CREATURE IS WIZARD
					{
						// IF THE WIZARD DOES NOT HAVE THE WAND, 50% chance
						if(casted_wizard->getWand()==false)
						{
							if(randomNumber>0&&randomNumber<=50)
							{
								hp2 = creatures[creature2 - 1]->getHitPoints();
								hp2 -= casted_wizard->getMagicalDamage();
								hp2 += armorArr[creature2 - 1];
								wizardMagicalPowerMissNextAttack=1;
								wizardMagicalPower(*casted_wizard); // CALL THE FRIEND FUNCTION
							}

							else
							{
								hp2 = creatures[creature2 - 1]->getHitPoints();
								hp2 -= creatures[creature1 - 1]->getStrength();
								hp2 += armorArr[creature2 - 1];
							}
						}

						// IF THE WIZARD HAS THE WAND, 90% chance
						else
						{
							if(randomNumber>0&&randomNumber<=90)
							{
								hp2 = creatures[creature2 - 1]->getHitPoints();
								hp2 -= casted_wizard->getMagicalDamage();
								hp2 += armorArr[creature2 - 1];
								wizardMagicalPowerMissNextAttack=1;
								wizardMagicalPower(*casted_wizard); // CALL THE FRIEND FUNCTION
							}

							else
							{
								hp2 = creatures[creature2 - 1]->getHitPoints();
								hp2 -= creatures[creature1 - 1]->getStrength();
								hp2 += armorArr[creature2 - 1];
							}
						}
					}

					else if(creature1==2) // IF THE CREATURE IS ELF
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += armorArr[creature2 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|   ELF ARE VERY FAST TO ATTACK TWICE!!   |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += armorArr[creature2 - 1];
						}
					}

					else if(creature1==3) // IF THE CREATURE IS DWARF
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= (creatures[creature1 - 1]->getStrength()*2);
							hp2 += armorArr[creature2 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|      DWARF INFLICTS DOUBLE DAMAGE!!     |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += armorArr[creature2 - 1];
						}
					}
					else if(creature1==4) // IF THE CREATURE IS DEMON
					{
						if(randomNumber>0&&randomNumber<=5)
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= (creatures[creature1 - 1]->getStrength()+50);
							hp2 += armorArr[creature2 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|  DEMONS INFLICTS 50 ADDTIONATL DAMAGE!  |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += armorArr[creature2 - 1];
						}
					}
				}

				if(hp2<0) hp2=0;
				creatures[creature2 - 1]->setHitPoints(hp2);

				cout << "+-----------------------------------------+" << endl;
				cout << "|           Player 1 Information          |" << endl;
				cout << "+-----------------------------------------+" << endl;
				creatures[creature1 - 1]->display();

				cout << "+-----------------------------------------+" << endl;
				cout << "|           Player 2 Information          |" << endl;
				cout << "+-----------------------------------------+" << endl;
				creatures[creature2 - 1]->display();
			}
			else if (player1_input == 2) // ESCAPE
			{
				cout << "Player 1 escapes!" << endl;
				break;
			}
			else // VALIDATION
			{
				cout << "Your input is wrong!" << endl;
			}

			// CHECK WHETHER PLAYER 2 HP IS BELOW 0
			if (hp2 <= 0)
			{
				cout << "Player 1 wins!" << endl;
				cout << "Player 2 is defeated!" << endl;

				creatureLost[creature2 - 1] = true;
				creatureWin[creature1 - 1] = true;
				winner=1;

				// MAKE THE DEAD OBJECT NULL
				if (creature2 == 1) void *wizard3=NULL;
				else if (creature2 == 2) void *elf3=NULL;
				else if (creature2 == 3) void *dwarf3=NULL;
				else if (creature2 == 4) void *demon1=NULL;
				break;
			}

			// LET THE USER (PLAYER 2) CHOOSE THE OPTION
			cout << "+-----------------------------------------+" << endl;
			cout << "|    Please, choose PLAYER 2's option     |" << endl;
			cout << "|          1) ATTACK   2) ESCAPE          |" << endl;
			cout << "+-----------------------------------------+" << endl;
			cout << "> ";
			cin >> player2_input;

			if (player2_input == 1) // ATTACK
			{
				if(wizardMagicalPowerMissNextAttack==1)
				{
					cout << "+-----------------------------------------------------------------------------+" << endl;
					cout << "| BECAUSE OF WIZARD MAGICAL POWER, THIS TURN, YOU CANNOT ATTACK THE OPPONENT  |" << endl;
					cout << "+-----------------------------------------------------------------------------+" << endl;
					wizardMagicalPowerMissNextAttack=0;
				}

				else
				{
					// GENERATE THE RANDOM NUMBER BETWEEN 1 TO 100 FOR PROBABILITY
					srand(time(0));
					int randomNumber=(rand()%100)+1;
					cout << "+-----------------------------------------+" << endl;
					cout << "|     Player 2 attacks Player 1 !!!       |" << endl;
					cout << "+-----------------------------------------+" << endl;

					if(creature2==1) // IF THE CREATURE IS WIZARD
					{
						// IF THE WIZARD DOES NOT HAVE THE WAND, 50% chance
						if(casted_wizard->getWand()==false)
						{
							if(randomNumber>0&&randomNumber<=50)
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= casted_wizard->getMagicalDamage();
								hp1 += armorArr[creature1 - 1];
								wizardMagicalPowerMissNextAttack=1;
								cout << "+-----------------------------------------+" << endl;
								cout << "|   WIZARD MAGICAL DAMAGE WAS INFLICTED!  |" << endl;
								cout << "+-----------------------------------------+" << endl;
							}

							else
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= creatures[creature2 - 1]->getStrength();
								hp1 += armorArr[creature1 - 1];
							}
						}

						// IF THE WIZARD HAS THE WAND, 90% chance
						else
						{
							if(randomNumber>0&&randomNumber<=90)
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= casted_wizard->getMagicalDamage();
								hp1 += armorArr[creature1 - 1];
								wizardMagicalPowerMissNextAttack=1;
								cout << "+-----------------------------------------+" << endl;
								cout << "|   WIZARD MAGICAL DAMAGE WAS INFLICTED!  |" << endl;
								cout << "+-----------------------------------------+" << endl;
							}

							else
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= creatures[creature2 - 1]->getStrength();
								hp1 += armorArr[creature1 - 1];
							}
						}
					}
					else if(creature2==2) // IF THE CREATURE IS ELF
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += armorArr[creature1 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|   ELF ARE VERY FAST TO ATTACK TWICE!!   |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += armorArr[creature1 - 1];
						}
					}
					else if(creature2==3) // IF THE CREATURE IS DWARF
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += armorArr[creature1 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|      DWARF INFLICTS DOUBLE DAMAGE!!     |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += armorArr[creature1 - 1];
						}
					}
					else if(creature2==4) // IF THE CREATURE IS DEMON
					{
						if(randomNumber>0&&randomNumber<=5)
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= (creatures[creature2 - 1]->getStrength()+50);
							hp1 += armorArr[creature1 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|  DEMONS INFLICTS 50 ADDTIONATL DAMAGE!  |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += armorArr[creature1 - 1];
						}
					}
				}

				if(hp1<0) hp1=0;
				creatures[creature1 - 1]->setHitPoints(hp1);

				cout << "+-----------------------------------------+" << endl;
				cout << "|           Player 1 Information          |" << endl;
				cout << "+-----------------------------------------+" << endl;
				creatures[creature1 - 1]->display();

				cout << "+-----------------------------------------+" << endl;
				cout << "|           Player 2 Information          |" << endl;
				cout << "+-----------------------------------------+" << endl;
				creatures[creature2 - 1]->display();
			}

			else if (player2_input == 2) // ESCAPE
			{
				cout << "Player 2 escapes!" << endl;
				break;
			}

			else // VALIDATION
			{
				cout << "Your input is wrong!" << endl;
			}

			// CHECK WHETHER PLAYER 2 HP IS BELOW 0
			if (hp1 <= 0)
			{
				cout << endl;
				cout << "Player 2 wins!" << endl;
				cout << "Player 1 is defeated!" << endl;

				creatureLost[creature1 - 1] = true;
				creatureWin[creature2 - 1] = true;
				winner=2;

				// MAKE THE DEAD OBJECT NULL
				if (creature1 == 1) void *wizard3=NULL;
				else if (creature1 == 2) void *elf3=NULL;
				else if (creature1 == 3) void *dwarf3=NULL;
				else if (creature1 == 4) void *demon1=NULL;
				break;
			}
		}

		// ASK WHETHER TO CONTINUE OR NOT
		if(round<3)
		{
			cout << "Do you want to continue? If yes, input 1. If no, input 0 : ";
			cin >> input;

			if(input==1)
			{
				if(winner==1)
				{
					cout << "+-----------------------------------------+" << endl;
					cout << "|   Please, choose the next opponent.     |" << endl;
					cout << "|   1) Wizard                             |" << endl;
					cout << "|   2) Elf                                |" << endl;
					cout << "|   3) Dwarf                              |" << endl;
					cout << "|   4) Demon                              |" << endl;
					cout << "+-----------------------------------------+" << endl;
					cout << "> ";
					cin >> creature2;

					while (creatureLost[creature2 - 1] == true || creature2 < 1 || creature2 > 4 || creature1 == creature2)
					{
						cout << "+-----------------------------------------+" << endl;
						cout << "|   Your input is wrong!!!                |" << endl;
						cout << "+-----------------------------------------+" << endl;
						cout << "|   Please, choose the second creature.   |" << endl;
						cout << "|   1) Wizard                             |" << endl;
						cout << "|   2) Elf                                |" << endl;
						cout << "|   3) Dwarf                              |" << endl;
						cout << "|   4) Demon                              |" << endl;
						cout << "+-----------------------------------------+" << endl;
						cout << "> ";
						cin >> creature2;
					}
				}

				else if(winner==2)
				{
					cout << "+-----------------------------------------+" << endl;
					cout << "|   Please, choose the next opponent.     |" << endl;
					cout << "|   1) Wizard                             |" << endl;
					cout << "|   2) Elf                                |" << endl;
					cout << "|   3) Dwarf                              |" << endl;
					cout << "|   4) Demon                              |" << endl;
					cout << "+-----------------------------------------+" << endl;
					cout << "> ";
					cin >> creature1;

					while (creatureLost[creature1 - 1] == true || creature1 < 1 || creature1 > 4 || creature1 == creature2)
					{
						cout << "+-----------------------------------------+" << endl;
						cout << "|   Your input is wrong!!!                |" << endl;
						cout << "+-----------------------------------------+" << endl;
						cout << "|   Please, choose the second creature.   |" << endl;
						cout << "|   1) Wizard                             |" << endl;
						cout << "|   2) Elf                                |" << endl;
						cout << "|   3) Dwarf                              |" << endl;
						cout << "|   4) Demon                              |" << endl;
						cout << "+-----------------------------------------+" << endl;
						cout << "> ";
						cin >> creature1;
					}
				}
			}

			else if(input==0)
			{
				cout << "End the game." << endl;
			}
		}

		else
		{
			cout << "A total round of games are completed! Thank you very much!" << endl;
		}
	} while (input != 0 && round!=3);

	return 0;
}
