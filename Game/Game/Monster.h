#pragma once
#include "Creatures.h"
#include <string>
class Monster : public Creatures
{	
private:
	int ScoreGain;
public:
	Monster(string, int, int, int);
	int GetScoreGain();
	void SetScoreGain(int);
};

