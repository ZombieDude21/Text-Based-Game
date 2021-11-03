#include "Monster.h"
#include <string>

Monster::Monster(string name, int hp, int damage, int gain)
{
	SetName(name);
	SetMaxHp(hp);
	SetDamage(damage);
	ResetHP();
	SetHitChance(50);
	SetDied(false);
	SetScoreGain(gain);
}

void Monster::SetScoreGain(int gain)
{
	ScoreGain = gain;
}
int Monster::GetScoreGain()
{
	return ScoreGain;
}