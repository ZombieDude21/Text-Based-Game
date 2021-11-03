#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>
#include "Creatures.h"

class Player : public Creatures
{
private:
	int Score;

public:
	Player(string, int, int);

	void AddScore(int);

	void  ResetScore();
	int GetScore();

};


#endif
