#ifndef Creatures_H
#define Creatures_H

#include <iostream>
#include <string>
using namespace std;


class Creatures{
private:
	string Name;
	int Max_Hp;
	int Current_Hp;
	int Damage;
	int HitChance;
	bool Died;
public:
	string GetName();

	int GetCurrentHp();
	int GetDamage();
	int GetHitChance();
	int GetMaxHp();

	void SetDied(bool);
	void SetHitChance(int);
	void SetMaxHp(int);
	void SetDamage(int);
	void SetName(string);
	void ResetHP();
	void Attack(int);
	void Defence();

	bool IsDied();

};

#endif





