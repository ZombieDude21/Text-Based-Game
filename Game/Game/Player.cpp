
#include "Player.h"
#include "Creatures.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(string name, int hp, int damage)
{ 
	SetName(name);
	SetMaxHp(hp);
	SetDamage(damage);
	ResetHP();
	SetHitChance(50);
	SetDied(false);
	Score = 0;
}
void Player::AddScore(int score)
{
	Score = Score + score;
}

void Player::ResetScore()
{
	Score = 0;
}

int Player::GetScore()
{
	return(Score);
}
