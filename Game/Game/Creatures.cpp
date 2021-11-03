#include "Creatures.h"
#include <iostream>
#include <string>

using namespace std;
 

	void Creatures::Attack(int damage)
	{
		Current_Hp = Current_Hp - damage;
		if (Current_Hp <= 0)
		{
			Died = true;
		}
	}
	void Creatures::Defence()
	{
		if (Current_Hp < Max_Hp)
		{
			cout << "----------------------------------" << endl;
			cout << Name << " regained 1 hp" << endl;
			Current_Hp++;
		}
		else
		{
			cout << "----------------------------------" << endl;
			cout << Name << " did nothing" << endl;
		}
	}
	void Creatures::ResetHP()
	{
		Current_Hp = Max_Hp;
	}

	void Creatures::SetName(string name)
	{
		Name = name;
	}

	void Creatures::SetDamage(int d)
	{
		Damage = d;
	}
	void Creatures::SetMaxHp(int hp)
	{
		Max_Hp = hp;
	}
	void Creatures::SetHitChance(int chance)
	{
		HitChance = chance;
	}
	void Creatures::SetDied(bool died)
	{	
		Died = died;
	}
	string Creatures::GetName()
	{
		return Name;
	}
	int Creatures::GetCurrentHp()
	{
		return Current_Hp;
	}
	int Creatures::GetMaxHp()
	{
		return Max_Hp;
	}
	int Creatures:: GetDamage()
	{
		return Damage;
	}
	int Creatures::GetHitChance()
	{	
		return HitChance;
	}
	bool Creatures::IsDied()
	{	
		return Died;
	}







