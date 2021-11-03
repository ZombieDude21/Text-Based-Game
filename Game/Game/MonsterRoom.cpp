#include "MonsterRoom.h"
#include "Creatures.h"
#include "Monster.h"
#include <string>
#include <random>
#include <fstream>
using namespace std;

MonsterRoom::MonsterRoom(string name)
{
	SetName(name);
}

Player MonsterRoom::Start(Player monk)
{
	bool Loop = true;
	bool loop2;
	bool PlayerTurn = true; //False Ai. True Player
	int option;

	Monster enemy( "", 0,0, 0);
	Monster Goblin("goblin", 10, 2, 25);
	enemy = Goblin;

	ofstream logfile;
	logfile.open("Last Game log.txt", ios::app);
	system("CLS");
	cout << "-------------------------------------" << endl;
	cout << "You have entered Monster Room" << endl;
	cout << "Prepare for combat" << endl;

	logfile << "------------------------------------- " << endl;
	logfile << "You have entered Monster Room" << endl;
	logfile << "Prepare for combat" << endl;
	system("pause");


	while (Loop)
	{
		// Combat
		//player turn
		

			if (PlayerTurn)
			{
				loop2 = true;
				while (loop2)
				{
					system("CLS");
					cout << "----------------------------------" << endl;
					cout << monk.GetName() << " Hp " << monk.GetCurrentHp() << "         " << enemy.GetName() << " Hp " << enemy.GetCurrentHp() << endl;


					cout << "[1]attack" << endl << "[2]defend" << endl;

					logfile << "----------------------------------" << endl;
					logfile << monk.GetName() << " Hp " << monk.GetCurrentHp() << "         " << enemy.GetName() << " Hp " << enemy.GetCurrentHp() << endl;
					logfile << "[1]attack" << endl << "[2]defend" << endl;


					cin >> option;// 1 attack, 2 defend
					logfile << option << endl;
					if (option == 1)
					{

						std::random_device rd;
						std::mt19937 gen(rd());
						std::uniform_int_distribution<> distr(1, 2);
						option = distr(gen);

						if (option == 1)
						{
							cout << "----------------------------------" << endl;
							cout << "You hit " << enemy.GetName() << " for " << monk.GetDamage() << " damage" << endl;
							enemy.Attack(monk.GetDamage());
							cout << "The " << enemy.GetName() << " Hp is now " << enemy.GetCurrentHp() << endl;

							logfile << "----------------------------------" << endl;
							logfile << "You hit " << enemy.GetName() << " for " << monk.GetDamage() << " damage" << endl;
							logfile << "The " << enemy.GetName() << " Hp is now " << enemy.GetCurrentHp() << endl;



							system("pause");
							
						}
						else if (option == 2)
						{
							cout << "----------------------------------" << endl;
							cout << "You missed the " << enemy.GetName() << endl;


							logfile << "----------------------------------" << endl;
							logfile << "You missed the " << enemy.GetName() << endl;
							system("pause");


							


							
						}
						else 
						{
							cout << "something went wrong" <<endl;
							system("pause");
						}
						loop2 = false;

					}
					else if (option == 2)
					{

						logfile << "----------------------------------" << endl;
						logfile << "You gained 1 hp"  << endl;


						monk.Defence();
						loop2 = false;
					}
				}
			}
		

		// AI turn
		else
		{


				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> distr(1, 2);
				option = distr(gen);

				//check if AI is at full hp is yes then attack
				if (enemy.GetCurrentHp() == enemy.GetMaxHp())
				{
					option = 1;
				}
				//makes the AI decide if it want to attack or defend
				else
				{
					int DefendChance = 0;

					//increase to defend chance and attack chance
					if (enemy.GetCurrentHp() < enemy.GetMaxHp())
					{
						DefendChance += 10;
					}
					if (enemy.GetCurrentHp() <= enemy.GetMaxHp() / 2)
					{
						DefendChance += 20;
					}
					if (enemy.GetCurrentHp() <= enemy.GetMaxHp() / 4)
					{
						DefendChance += 15;
					}
					if (monk.GetCurrentHp() <= monk.GetMaxHp() /2)
					{
						DefendChance -= 5;
					}
					if (enemy.GetCurrentHp() > monk.GetCurrentHp())
					{
						DefendChance -= 10;
					}

					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> distr(1, 100);
					option = distr(gen);
					//cout << "-------" << option << "--------" << endl;
					//system("pause");
					if (option <= DefendChance)
					{
						option = 2;
					}
					else
					{
						option = 1;
					}

				}
			// Attack(1) or defend(2)
			if (option == 1)
			{
				cout << "----------------------------------" << endl;
				cout << "The " << enemy.GetName() << " attacks" << endl;

				logfile <<"----------------------------------" << endl;
				logfile << "The " << enemy.GetName() << " attacks" << endl;



				system("pause");
				std::random_device rd;
				std::mt19937 gen(rd());
				std::uniform_int_distribution<> distr(1, 2);
				option = distr(gen);

				if (option == 1)
				{
					cout << "----------------------------------" << endl;
					cout << "The " << enemy.GetName() << " Attacked you for " << enemy.GetDamage() << " Damage" << endl;
					monk.Attack(enemy.GetDamage());
					cout << "The " << monk.GetName() << " Hp is now " << monk.GetCurrentHp() << endl;


					logfile << "----------------------------------" << endl;
					logfile << "The " << enemy.GetName() << " Attacked you for " << enemy.GetDamage() << " Damage" << endl;
					logfile << "The " << monk.GetName() << " Hp is now " << monk.GetCurrentHp() << endl;

					system("pause");
				}
				else if (option == 2)
				{
					cout << "----------------------------------" << endl;
					cout <<  enemy.GetName() <<" missed the " << monk.GetName() << endl;


					logfile << "----------------------------------" << endl;
					logfile << enemy.GetName() << " missed the " << monk.GetName() << endl;
					system("pause");
				}
				else
				{
					cout << "something went wrong" << endl;
					system("pause");
				}
			}
			else if (option == 2)
			{

				logfile << "----------------------------------" << endl;
				logfile <<  enemy.GetName() <<"  gained 1 hp" << endl;

				enemy.Defence();
				system("pause");
			}
			else
			{
				cout << "Something Went Wrong" << endl;
				cout << option;
				system("pause");
			}
		}


		//Change Turn
		if (PlayerTurn)
		{
			PlayerTurn = false;
		}
		else
		{
			PlayerTurn = true;
		}

		//Checks if anyone died
		if (monk.IsDied())
		{
			Loop = false;
			logfile.close();
		}
		else if (enemy.IsDied())
		{
			monk.AddScore(enemy.GetScoreGain());
			Loop = false;
			logfile.close();
		}
	}

	return monk;
}
