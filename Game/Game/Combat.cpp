#include <iostream>
#include <stdlib.h>
#include "Creatures.cpp"
using namespace std;

void PlayerTurnScreen()
{
	cout
		<< "[1] Attack\n"
		<< "[2] Defend\n"
		<< "What do you choose? ";

}
void StartFight()
{
	Creatures Monk("Monk", 6, 1);
	Creatures Goblin("goblin", 6, 1);

	int Option;
	bool CombatLoop = true;
	bool PlayerTurn = true;
	Goblin.ResetHP();
	while (CombatLoop)
	{
		system("CLS");
		if (PlayerTurn)
		{
			//PlayerTurnScreen();
			cin >> Option;
			if (Option == 1)
			{
				Goblin.Attack(Monk.GetDamage());
			}
			if (Option == 2)
			{
				Monk.Defence();
			}
			system("pause");
			PlayerTurn = false;
		}
		else
		{
			int Random;
			//srand(time(0));
			Random = 1;
			if (Option == 1)
			{
				Monk.Attack(Goblin.GetDamage());
			}
			if (Option == 2)
			{
				Goblin.Defence();
			}
			system("pause");
			PlayerTurn = true;
		}
		if (Monk.IsDied())
		{
			CombatLoop = false;
			cout << Monk.GetMonsterName() << " Wins";
		}
		else if (Goblin.IsDied())
		{
			CombatLoop = false;
			cout << Goblin.GetMonsterName() << " Wins";
		}
	}


}


int main2()
{
	system("pause");
	return NULL;
}

