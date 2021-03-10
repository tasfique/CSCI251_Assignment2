//Name- Tasfique Enam
//Student ID- 5886429

#include <iostream>
#include <ctime>
#include "Creature.h"
#include "Wizard.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Demon.h"
using namespace std;

int main() //main method.
{
    Creature* creatures[4]; //creature array
	int creature1, creature2; // the selection of the creature the player selects.
	int input;
	int player1_input, player2_input; //player 1 and 2 inputs.
	int winner; //the winner of the game.
	int round=0; //the number of rounds there are.
	int wizardMagicalPowerMissNextAttack=0; //the wizard can cause the opponent to miss their next attack
	bool creatureLost[4] = { false };
	bool creatureWin[4] = { false };
	string name;
	//double strength, hitPoints, magicalDamage, armor, shield, height, speed; //creatures attributes.
	double wizard_armor, elf_agility, dwarf_armor, demon_armor; //spcial ability of each creature.
	int wandCheck; //checking if the wizard have a wand or not?
	string creature1_name, creature2_name, wandDetermine; //creature names.
	bool wand; //used for wand validation if the wizard have the wand or not?

	// DECLARE WIZARDS

	Wizard wizard1("Wizard1", 12, 100, 100, 10, wand, 1);
	//string name, double strength, double hitPoints, double health, double magicalDamage, bool wand, double armour
	Wizard wizard2("Wizard2", 20, 200, 200, 20, wand, 5);


	// Used for Operator overloading due to the requirement
	Wizard wizard3=wizard1+wizard2;

	// Declare elfs
	Elf elf1("Elf1", 15, 100, 100, 3);
	//string name, double strength, double hitPoints, double health, double agility
	Elf elf2("Elf2", 20, 200, 200, 2);

	// Used for Operator overloading due to the requirement
	Elf elf3=elf1-elf2;

	// DECLARE DWARFS
	Dwarf dwarf1("Dwarf1", 20, 40, 10, 10, 10);
	//string name, double strength, double hitPoints, double health, double invisibility, double armour
	Dwarf dwarf2("Dwarf2", 25, 3, 10, 2, 2);

	// Used for Operator overloading due to the requirement
	Dwarf dwarf3=dwarf1*dwarf2;

	// DECLARE DEMON
	Demon demon1("Demon1", 25, 140, 140, 10, 5);

	// POINT EACH OBJECT USING POLYMORPHISM
	creatures[0] = &wizard3; // Pointing to wizard
	creatures[1] = &elf3; // Pointing to elf
	creatures[2] = &dwarf3; // Pointing to dwarf
	creatures[3] = &demon1; // Pointing to a demon

	//Dynamic Cast
	Wizard* casted_wizard = dynamic_cast<Wizard*>(creatures[0]);
	Elf* casted_elf = dynamic_cast<Elf*>(creatures[1]);
	Dwarf* casted_dwarf = dynamic_cast<Dwarf*>(creatures[2]);
	Demon* casted_demon = dynamic_cast<Demon*>(creatures[3]);

	// Selection of two creatures to fight.
	cout << "+-----------------------------------------+" << endl;
	cout << "|      WELCOME TO THE ULTIMATE BATTLE     |" << endl;
	cout << "+-----------------------------------------+" << endl;
	cout << endl;

	cout << "+-----------------------------------------+" << endl;
	cout << "|   Please, choose the FIRST creature.    |" << endl;
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
		cout << "|              WRONG INPUT                |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "|   Please, choose the FIRST creature.    |" << endl;
		cout << "|   1) Wizard                             |" << endl;
		cout << "|   2) Elf                                |" << endl;
		cout << "|   3) Dwarf                              |" << endl;
		cout << "|   4) Demon                              |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "> ";
		cin >> creature1;
	}

	cout << "+-----------------------------------------+" << endl;
	cout << "|   Please, choose the SECOND creature.   |" << endl;
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
		cout << "|              WRONG INPUT                |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "|   Please, choose the SECOND creature.   |" << endl;
		cout << "|   1) Wizard                             |" << endl;
		cout << "|   2) Elf                                |" << endl;
		cout << "|   3) Dwarf                              |" << endl;
		cout << "|   4) Demon                              |" << endl;
		cout << "+-----------------------------------------+" << endl;
		cout << "> ";
		cin >> creature2;
	}

	// fight between creatures.
	do
	{
		// Keeping the track of the rounds.
		round++;

		// G
		if (creature1 == 1)
		{
			creature1_name = "Wizard";
			wizard_armor = casted_wizard->getArmour();

			do{
                cout << "Does the Wizard have a Wand? Enter '0' for No or '1' for Yes"<< endl;
                cin >> wandCheck;
                if(wandCheck == 0) {
                    wand = false;
                } else if (wandCheck == 1) {
                    wand = true;
                }
            } while(wandCheck < 0 || wandCheck >1);
		}

		else if (creature1 == 2)
		{
			creature1_name = "Elf";
			elf_agility = elf3.getAgility();
		}

		else if (creature1 == 3)
		{
			creature1_name = "Dwarf";
			dwarf_armor = dwarf3.getArmour();
		}

		else if (creature1 == 4)
		{
			creature1_name = "Demon";
			demon_armor = demon1.getArmour();
		}


		if (creature2 == 1)
		{
			creature2_name = "Wizard";
			wizard_armor = wizard3.getArmour();
		}

		else if (creature2 == 2)
		{
			creature2_name = "Elf";
			elf_agility = elf3.getAgility();
		}

		else if (creature2 == 3)
		{
			creature2_name = "Dwarf";
			dwarf_armor = dwarf3.getArmour();
		}

		else if (creature2 == 4)
		{
			creature2_name = "Demon";
			demon_armor = demon1.getArmour();
		}

		//
		double creatureAbilitiesArr[4]={wizard_armor, elf_agility, dwarf_armor, demon_armor};

		// Getting hit points from the creatures.
		double hp1 = creatures[creature1 - 1]->getHitPoints();
		double hp2 = creatures[creature2 - 1]->getHitPoints();

		// Battle menu
		while (hp1 > 0 && hp2 > 0)
		{
			cout << "+-----------------------------------------+" << endl;
			cout << "|            FIGHT INFORMATION            |" << endl;
			cout << "+-----------------------------------------+" << endl;
			cout << "PLAYER 1 : " << creature1_name << endl;
			cout << "PLAYER 2 : " << creature2_name << endl;

			// LET THE USER CHOOSE THE OPTION
			cout << "+-----------------------------------------+" << endl;
			cout << "|    Please, choose PLAYER 1's options    |" << endl;
			cout << "|          1) ATTACK   2) ESCAPE          |" << endl;
			cout << "+-----------------------------------------+" << endl;
			cout << "> ";
			cin >> player1_input;

			if (player1_input == 1) // ATTACK
			{
				if(wizardMagicalPowerMissNextAttack==1)
				{
					cout << "+-----------------------------------------------------------------------------+" << endl;
					cout << "| WIZARD'S MAGICAL POWER CAUSES THE OPPONENT TO MISS THEIR NEXT ATTACK        |" << endl;
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
								hp2 += creatureAbilitiesArr[creature2 - 1];
								wizardMagicalPowerMissNextAttack=1;
								wizardMagicalPower(*casted_wizard); // calling the friend function
							}

							else
							{
								hp2 = creatures[creature2 - 1]->getHitPoints();
								hp2 -= creatures[creature1 - 1]->getStrength();
								hp2 += creatureAbilitiesArr[creature2 - 1];
							}
						}

						// if the wizard have a wand.
						else
						{
							if(randomNumber>0&&randomNumber<=90)
							{
								hp2 = creatures[creature2 - 1]->getHitPoints();
								hp2 -= casted_wizard->getMagicalDamage();
								hp2 += creatureAbilitiesArr[creature2 - 1];
								wizardMagicalPowerMissNextAttack=1;
								wizardMagicalPower(*casted_wizard); // calling the friend function
							}

							else
							{
								hp2 = creatures[creature2 - 1]->getHitPoints();
								hp2 -= creatures[creature1 - 1]->getStrength();
								hp2 += creatureAbilitiesArr[creature2 - 1];
							}
						}
					}

					else if(creature1==2) // elf
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += creatureAbilitiesArr[creature2 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|   ELF'S AGILITY ALLOWS DOUBLE ATTACK!!  |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += creatureAbilitiesArr[creature2 - 1];
						}
					}

					else if(creature1==3) // dwarf
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= (creatures[creature1 - 1]->getStrength()*2);
							hp2 += creatureAbilitiesArr[creature2 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|      DWARF INFLICTS DOUBLE DAMAGE!!     |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += creatureAbilitiesArr[creature2 - 1];
						}
					}
					else if(creature1==4) // demon
					{
						if(randomNumber>0&&randomNumber<=5)
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= (creatures[creature1 - 1]->getStrength()+50);
							hp2 += creatureAbilitiesArr[creature2 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|  DEMONS INFLICTS 50 ADDTIONATL DAMAGE!  |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp2 = creatures[creature2 - 1]->getHitPoints();
							hp2 -= creatures[creature1 - 1]->getStrength();
							hp2 += creatureAbilitiesArr[creature2 - 1];
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
			else // validation
			{
				cout << "Your input is wrong!" << endl;
			}

			// validation for checking if the player 2 health is zero or not.
			if (hp2 <= 0)
			{
				cout << "Player 1 wins!" << endl;
				cout << "Player 2 is defeated!" << endl;

				creatureLost[creature2 - 1] = true;
				creatureWin[creature1 - 1] = true;
				winner=1;

				if (creature2 == 1) void *wizard3=NULL;
				else if (creature2 == 2) void *elf3=NULL;
				else if (creature2 == 3) void *dwarf3=NULL;
				else if (creature2 == 4) void *demon1=NULL;
				break;
			}

			// Player 2 options.
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
					cout << "| WIZARD'S MAGICAL POWER CAUSES THE OPPONENT TO MISS THEIR NEXT ATTACK        |" << endl;
					cout << "+-----------------------------------------------------------------------------+" << endl;
					wizardMagicalPowerMissNextAttack=0;
				}

				else
				{
					// generation random number for the probability
					srand(time(0));
					int randomNumber=(rand()%100)+1;
					cout << "+-----------------------------------------+" << endl;
					cout << "|     Player 2 attacks Player 1 !!!       |" << endl;
					cout << "+-----------------------------------------+" << endl;

					if(creature2==1)
					{
						// Wizard doesn't have a wand, 50% chance
						if(casted_wizard->getWand()==false)
						{
							if(randomNumber>0&&randomNumber<=50)
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= casted_wizard->getMagicalDamage();
								hp1 += creatureAbilitiesArr[creature1 - 1];
								wizardMagicalPowerMissNextAttack=1;
								cout << "+-----------------------------------------+" << endl;
								cout << "|   WIZARD MAGICAL DAMAGE WAS INFLICTED!  |" << endl;
								cout << "+-----------------------------------------+" << endl;
							}

							else
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= creatures[creature2 - 1]->getStrength();
								hp1 += creatureAbilitiesArr[creature1 - 1];
							}
						}

						// if the wizard have a wand the opponents attack will be missed for 90%
						else
						{
							if(randomNumber>0&&randomNumber<=90)
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= casted_wizard->getMagicalDamage();
								hp1 += creatureAbilitiesArr[creature1 - 1];
								wizardMagicalPowerMissNextAttack=1;
								cout << "+-----------------------------------------+" << endl;
								cout << "|   WIZARD MAGICAL DAMAGE WAS INFLICTED!  |" << endl;
								cout << "+-----------------------------------------+" << endl;
							}

							else
							{
								hp1 = creatures[creature1 - 1]->getHitPoints();
								hp1 -= creatures[creature2 - 1]->getStrength();
								hp1 += creatureAbilitiesArr[creature1 - 1];
							}
						}
					}
					else if(creature2==2) // elf
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += creatureAbilitiesArr[creature1 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|   ELF'S AGILITY ALLOWS DOUBLE ATTACK!!  |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += creatureAbilitiesArr[creature1 - 1];
						}
					}
					else if(creature2==3) // dwarf.
					{
						if(randomNumber>0&&randomNumber<=10)
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += creatureAbilitiesArr[creature1 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|      DWARF INFLICTS DOUBLE DAMAGE!!     |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += creatureAbilitiesArr[creature1 - 1];
						}
					}
					else if(creature2==4) // demon
					{
						if(randomNumber>0&&randomNumber<=5)
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= (creatures[creature2 - 1]->getStrength()+50);
							hp1 += creatureAbilitiesArr[creature1 - 1];
							cout << "+-----------------------------------------+" << endl;
							cout << "|  DEMONS INFLICTS 50 ADDITIONAL DAMAGE!  |" << endl;
							cout << "+-----------------------------------------+" << endl;
						}

						else
						{
							hp1 = creatures[creature1 - 1]->getHitPoints();
							hp1 -= creatures[creature2 - 1]->getStrength();
							hp1 += creatureAbilitiesArr[creature1 - 1];
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

			else if (player2_input == 2)
			{
				cout << "Player 2 escapes!" << endl;
				break;
			}

			else
			{
				cout << "Your input is wrong!" << endl;
			}

			// to check if the player's hp is below 0 or not.
			if (hp1 <= 0)
			{
				cout << endl;
				cout << "Player 2 wins!" << endl;
				cout << "Player 1 is defeated!" << endl;

				creatureLost[creature1 - 1] = true;
				creatureWin[creature2 - 1] = true;
				winner=2;

				// Making objects of creatures which are killed to NULL.
				if (creature1 == 1) void *wizard3=NULL;
				else if (creature1 == 2) void *elf3=NULL;
				else if (creature1 == 3) void *dwarf3=NULL;
				else if (creature1 == 4) void *demon1=NULL;
				break;
			}
		}

		// ASsking users if they want to continue or not?
		if(round<3)
		{
			cout << "\nDo you want to continue? Enter '1' for YES OR '0' for NO : ";
			cin >> input;

			if(input==1)
			{
				if(winner==1)
				{
				    cout << "\nThe "<< creature1_name << " will fight the next opponent.\n" << endl;
					cout << "+----------------------------------------------------------+" << endl;
					cout << "|   Please, select a NEW opponent for the winner to fight. |" << endl;
					cout << "|   1) Wizard                                              |" << endl;
					cout << "|   2) Elf                                                 |" << endl;
					cout << "|   3) Dwarf                                               |" << endl;
					cout << "|   4) Demon                                               |" << endl;
					cout << "+----------------------------------------------------------+" << endl;
					cout << "> ";
					cin >> creature2;

					while (creatureLost[creature2 - 1] == true || creature2 < 1 || creature2 > 4 || creature1 == creature2) ///creature 1 has been changed.
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
					cout << "The "<< creature2_name << " will fight the next opponent." << endl;
					cout << "+----------------------------------------------------------+" << endl;
					cout << "|   Please, select a NEW opponent for the winner to fight. |" << endl;
					cout << "|   1) Wizard                                              |" << endl;
					cout << "|   2) Elf                                                 |" << endl;
					cout << "|   3) Dwarf                                               |" << endl;
					cout << "|   4) Demon                                               |" << endl;
					cout << "+----------------------------------------------------------+" << endl;
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
				cout << "THE END OF THE GAME." << endl;
			}
		}

		else
		{
			cout << "A total round of games are completed! Thank you very much!" << endl;
		}
	} while (input != 0 && round!=3);

	return 0;
}
