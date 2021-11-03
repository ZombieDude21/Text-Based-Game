// Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <stdlib.h>
#include "Creatures.h"
#include "Player.h"
#include "Rooms.h"
#include "MonsterRoom.h"
#include "EmptyRoom.h"
#include "TreasureRoom.h"
#include <random>
#include <fstream>

using namespace std;
int option;
//int option2;
int difficulty = 12;
bool StartLoop = true;
bool GameLoop = true;
bool loop;
int rooms[11];


MonsterRoom RoomMonster("Monster Room");
EmptyRoom RoomEmpty("Empty Room");
TreasureRoom RoomTreasure("Treasure Room");

Player Monk("monk", 15, 3);

void GameInPLay()
{
	system("CLS");
	//int rooms{}[11];
	int count = 0;
	int emptyChance = 0;
	for (int i = 0; i < difficulty; i++)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(1, 100);
		option = distr(gen);

		if (i == difficulty - 1)
		{
			emptyChance -= 300;
		}
		//&& rooms[i-1] != 1
		if (option <= emptyChance)
		{
			rooms[i] = 1;
			emptyChance -= 70;
		}
		else
		{
			rooms[i] = 2;
			
			if (difficulty == 4)
			{
				emptyChance += 50;
			}
			else
			{
				emptyChance += 45;
			}
		}
		


		
		
	}
	

	while (GameLoop)
	{
		if (Monk.IsDied())
		{
			system("CLS");
			cout << "-----------------------------------------" << endl;
			cout << " you lost the game" << endl;
			cout << "Your final score was: " << Monk.GetScore() << endl;
			ofstream ScoreBoard;
			ScoreBoard.open("ScoreBoard.txt", ios::app);
			ScoreBoard << Monk.GetName() << ": " << Monk.GetScore() << endl;
			ScoreBoard.close();
			system("pause");
			GameLoop = false;
		}
		else if (count == difficulty) // treasure room and end
		{
			Monk = RoomTreasure.Start(Monk);
			loop = true;
			while (loop)
			{
				system("CLS");
				cout << "-------------------------------------" << endl;
				cout << "Your current score is: " << Monk.GetScore() << endl;
				cout << "Do you want to go to another dungeon?" << endl;
				cout << "[1]yes" << endl;
				cout << "[2]no" << endl;
				cin >> option;
				if (option == 1)
				{
					Monk.ResetHP();
					GameInPLay();
					loop = false;
				}
				else if (option == 2)
				{
					ofstream ScoreBoard;
					ScoreBoard.open("ScoreBoard.txt", ios::app);
					ScoreBoard << Monk.GetName() << ": " << Monk.GetScore() << endl;
					ScoreBoard.close();
					loop = false;
				}
			}
			GameLoop = false;
			
		}
		else
		{
			if (rooms[count] == 1)//empty room
			{
				Monk.ResetHP();
				Monk = RoomEmpty.Start(Monk);
				count++;


			}
			else if (rooms[count] == 2) //monster room
			{
				Monk = RoomMonster.Start(Monk);
				count++;
			}
		}

	}
}
void MainMenu()
{
	int option2;
	while (StartLoop)
	{
		system("CLS");
		cout << "[1]Start" << endl;
		cout << "[2]Difficulty" << endl;
		cout << "[3]Score Board" << endl;
		cout << "[4]Exit" << endl;
		cin >> option2;

		if (option2 == 1)//Start Game 
		{
			bool nameLoop = true;
			string name;
			system("CLS");
			while (nameLoop)
			{
				system("CLS");
				cout << "Enter your name " << endl;
				cin >> name;
				if (!name.empty())
				{
					nameLoop = false;
				}
				else
				{

				}
			}
			
			//StartLoop = false;
			GameLoop = true;
			Monk.SetName(name);
			Monk.ResetHP();
			Monk.ResetScore();
			Monk.SetDied(false);
			ofstream logfile;
			logfile.open("Last Game log.txt");
			logfile.close();

			GameInPLay();
		}
		else if (option2 == 2) //Difficulty
		{
			loop = true;

			while (loop)
			{
				system("CLS");
				cout << "Select your difficulty" << endl;
				cout << "[1] Easy   4 rooms" << endl;
				cout << "[2] Normal 8 rooms" << endl;
				cout << "[3] Hard   12 rooms" << endl;
				cin >> option2;
				if (option2 == 1)
				{
					difficulty = 4;
					loop = false;
					break;
				}
				else if (option2 == 2)
				{
					difficulty = 8;
					loop = false;
					break;
				}
				else if (option2 == 3)
				{
					difficulty = 12;
					loop = false;
					break;
				}
			}
		}
		else if (option2 == 3)
		{
			ifstream ScoreBoard;
			ScoreBoard.open("ScoreBoard.txt", ios::app);
			system("CLS");
			cout << ScoreBoard.rdbuf() << endl;
			ScoreBoard.close();
			system("pause");
			
		}
		else if (option2 == 4) //Exit
		{
			StartLoop = false;
		}
	}
}
int main()
{



	MainMenu();
    //cout << "\n";
    //system("pause");
	return NULL;
}


